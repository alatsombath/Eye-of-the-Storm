-- EyeoftheStorm v1.5
-- LICENSE: Creative Commons Attribution-Non-Commercial-Share Alike 3.0

local Measure,Meter,OldValue,StartAngle,RotationTable,OldBassSum={},{},{},{},{},0

function Initialize()
	
	Direction,ResetAngle=SKIN:ReplaceVariables("#Direction#"),math.rad(360)
	
	-- See Variables.inc
	Constant,Sustain,Attack=SKIN:ParseFormula(SKIN:ReplaceVariables("#Constant#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#Sustain#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#Attack#"))
	AverageSustain,AverageAttack=SKIN:ParseFormula(SKIN:ReplaceVariables("#AverageSustain#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#AverageAttack#"))
	
	AngleFillMinLowFreq,AngleFillMinHighFreq=SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMinLowFreq#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMinHighFreq#"))
	AngleFillMaxLowFreq,AngleFillMaxHighFreq=SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMaxLowFreq#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMaxHighFreq#"))
	
	-- Iteration control variables
	Sub,Index,Limit=SELF:GetOption("Sub"),SKIN:ParseFormula(SELF:GetNumberOption("Index")),SKIN:ParseFormula(SELF:GetOption("Limit"))
	local MeasureName,MeterName,gsub,random=SELF:GetOption("MeasureName"),SELF:GetOption("MeterName"),string.gsub,math.random
	
	-- Angle increments for one band
	local AngleFillMinAdd,AngleFillMaxAdd=math.abs(AngleFillMinLowFreq-AngleFillMinHighFreq)*(1/Limit),math.abs(AngleFillMaxLowFreq-AngleFillMaxHighFreq)*(1/Limit)
	
	-- For each band
	for i=Index,Limit do
	
		local MeasureNameSub=(gsub(MeasureName,Sub,i))
		
		local AngleFillMin,AngleFillMax
		
		-- Retrieve measures and meter names, store in tables
		OldValue[i],StartAngle[i],Measure[i],Meter[i]=0,0,SKIN:GetMeasure(MeasureNameSub),(gsub(MeterName,Sub,i))
		
		-- If the minimum angle for the lowest frequency is less than the minimum angle for the highest frequency
		if AngleFillMinLowFreq<AngleFillMinHighFreq then
		
			-- Increment the minimum angle for this band
			AngleFillMin=AngleFillMinLowFreq+(AngleFillMinAdd*i)
			
		else
		
			-- Decrement the minimum angle for this band
			AngleFillMin=AngleFillMinLowFreq-(AngleFillMinAdd*i)
			
		end
		
		-- If the maximum angle for the highest frequency is greatest than the maximum angle for the lowest frequency
		if AngleFillMaxHighFreq>AngleFillMaxLowFreq then
			
			-- Decrement the maximum angle for this band
			AngleFillMax=AngleFillMaxHighFreq-(AngleFillMaxAdd*i)
			
		else
			
			-- Increment the maximum angle for this band
			AngleFillMax=AngleFillMaxHighFreq+(AngleFillMaxAdd*i)
			
		end
		
		-- Minimum fill angle as a measure value
		local AngleFillRatio=AngleFillMin/AngleFillMax
		
		-- Set the maximum fill angle
		SKIN:Bang("!SetOption",Meter[i],"RotationAngle",AngleFillMax)
		
		-- Set the roundline measure as a formula that checks if the current measure value is less than the minimum
		SKIN:Bang("!SetOption","MeasureAudioMin"..i,"Formula","("..MeasureNameSub.." < "..AngleFillRatio.." ? "..AngleFillRatio.." : "..MeasureNameSub..")")
		
		-- Set the roundline rotation for this band as either clockwise or counter-clockwise
		if Direction=="Random" then
			RotationTable[i]=random(0,1)
		end
		
	end
	
end

function Update()

	local TrebleSum,BassSum=0,0
	
	-- For each band
	for i=Index,Limit do
		
		local Value=Measure[i]:GetValue()
		
		-- Calculate spectrum rotation control variables
		-- Based on the indexed measure value and the indexed band's position relative to the treble and bass
		local TrebleValue,BassValue=Value^((Limit/i)/AverageSustain),Value^((i/Limit)/AverageAttack)
		
		-- Check if the calculated variables are greater than the defined maximum
		if TrebleValue>AverageSustain then TrebleValue=AverageSustain  end
		if BassValue>AverageAttack then BassValue=AverageAttack end
		
		TrebleSum=TrebleSum+TrebleValue
		BassSum=BassSum+BassValue
		
	end
	
	local TrebleAvgValue,BassAvgDifference=TrebleSum,BassSum-OldBassSum
	OldBassSum=BassSum
	
	-- If average bass value is less than the old, prevent backwards rotation
	if BassAvgDifference<0 then BassAvgDifference=0 end
	
	-- For each band
	for i=Index,Limit do
		
		-- Retrieve the measure value and difference from the old measure value
		local Value,Difference=Measure[i]:GetValue(),Measure[i]:GetValue()-OldValue[i]
		OldValue[i]=Value
		
		-- If the current measure value is less than the old, prevent backwards rotation
		if Difference<0 then Difference=0 end
		
		-- Calculate band rotation control variables
		-- Based on the current measure value and the current band's position relative to the treble and bass
		local Value,Difference=Value^((Limit/i)/Sustain),Difference^((i/Limit)/Attack)
		
		-- Check if the calculated variables are greater than the defined maximum
		if Value>Sustain then Value=Sustain end
		if Difference>Attack then Difference=Attack end
		
		if RotationTable[i]==0 or Direction=="Clockwise" then
		
			-- Increase the roundline angle position
			StartAngle[i]=(StartAngle[i] + Value + Difference + TrebleAvgValue + BassAvgDifference + Constant)%ResetAngle
			
		elseif RotationTable[i]==1 or Direction=="CounterClockwise" then
		
			-- Decrease the roundline angle position
			StartAngle[i]=(StartAngle[i] - Value - Difference - TrebleAvgValue - BassAvgDifference - Constant)%ResetAngle
			
		end
		
		-- Set the roundline angle position
		SKIN:Bang("!SetOption",Meter[i],"StartAngle",StartAngle[i])
		
	end
	
end