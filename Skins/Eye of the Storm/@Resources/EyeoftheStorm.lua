-- EyeoftheStorm v1.4
-- LICENSE: Creative Commons Attribution-Non-Commercial-Share Alike 3.0

local Measure,Meter,OldValue,StartAngle,RotationTable,OldBassSum={},{},{},{},{},0
function Initialize()
	Sub,Index,Limit=SELF:GetOption("Sub"),SKIN:ParseFormula(SELF:GetOption("Index")),SKIN:ParseFormula(SELF:GetOption("Limit"))
	Direction,ResetAngle=SKIN:ReplaceVariables("#Direction#"),math.rad(360)
	Constant,Sustain,Attack=SKIN:ParseFormula(SKIN:ReplaceVariables("#Constant#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#Sustain#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#Attack#"))
	AverageSustain,AverageAttack=SKIN:ParseFormula(SKIN:ReplaceVariables("#AverageSustain#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#AverageAttack#"))
	AngleFillMinLowFreq,AngleFillMinHighFreq=SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMinLowFreq#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMinHighFreq#"))
	AngleFillMaxLowFreq,AngleFillMaxHighFreq=SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMaxLowFreq#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMaxHighFreq#"))
	
	local MeasureName,MeterName,gsub,random=SKIN:ReplaceVariables("#MeasureName#"),SKIN:ReplaceVariables("#MeterName#"),string.gsub,math.random
	local AngleFillMinAdd,AngleFillMaxAdd=math.abs(AngleFillMinLowFreq-AngleFillMinHighFreq)*(1/Limit),math.abs(AngleFillMaxLowFreq-AngleFillMaxHighFreq)*(1/Limit)
	for i=Index,Limit do
		local MeasureNameSub=(gsub(MeasureName,Sub,i))
		local AngleFillMin,AngleFillMax
		OldValue[i],StartAngle[i],Measure[i],Meter[i]=0,0,SKIN:GetMeasure(MeasureNameSub),(gsub(MeterName,Sub,i))
		
		if AngleFillMinLowFreq<AngleFillMinHighFreq then AngleFillMin=AngleFillMinLowFreq+(AngleFillMinAdd*i)
		else AngleFillMin=AngleFillMinLowFreq-(AngleFillMinAdd*i) end
		
		if AngleFillMaxHighFreq>AngleFillMaxLowFreq then AngleFillMax=AngleFillMaxHighFreq-(AngleFillMaxAdd*i)
		else AngleFillMax=AngleFillMaxHighFreq+(AngleFillMaxAdd*i) end
		
		local AngleFillRatio=AngleFillMin/AngleFillMax
		SKIN:Bang("!SetOption",Meter[i],"RotationAngle",AngleFillMax)
		SKIN:Bang("!SetOption","MeasureAudioMin"..i,"Formula","("..MeasureNameSub.." < "..AngleFillRatio.." ? "..AngleFillRatio.." : "..MeasureNameSub..")")
		
		if Direction=="Random" then RotationTable[i]=random(0,1) end end end

function Update()
	local TrebleSum,BassSum=0,0
	for i=Index,Limit do
		local Value=Measure[i]:GetValue()
		local TrebleValue,BassValue=Value^((Limit/i)/AverageSustain),Value^((i/Limit)/AverageAttack)
		if TrebleValue>AverageSustain then TrebleValue=AverageSustain  end
		if BassValue>AverageAttack then BassValue=AverageAttack end
		
		TrebleSum=TrebleSum+TrebleValue
		BassSum=BassSum+BassValue
	end
	
	local TrebleAvgValue,BassAvgDifference=TrebleSum,BassSum-OldBassSum
	OldBassSum=BassSum
	if BassAvgDifference<0 then BassAvgDifference=0 end
	
	for i=Index,Limit do
		local Value,Difference=Measure[i]:GetValue(),Measure[i]:GetValue()-OldValue[i]
		OldValue[i]=Value
		if Difference<0 then Difference=0 end
		
		local Value,Difference=Value^((Limit/i)/Sustain),Difference^((i/Limit)/Attack)
		if Value>Sustain then Value=Sustain end
		if Difference>Attack then Difference=Attack end
		
		if RotationTable[i]==0 or Direction=="Clockwise" then
			StartAngle[i]=(StartAngle[i] + Value + Difference + TrebleAvgValue + BassAvgDifference + Constant)%ResetAngle
		elseif RotationTable[i]==1 or Direction=="CounterClockwise" then
			StartAngle[i]=(StartAngle[i] - Value - Difference - TrebleAvgValue - BassAvgDifference - Constant)%ResetAngle end
		
		SKIN:Bang("!SetOption",Meter[i],"StartAngle",StartAngle[i])
	end
end