-- EyeoftheStorm v1.3
-- LICENSE: Creative Commons Attribution-Non-Commercial-Share Alike 3.0

local Measure,Meter,OldValue,StartAngle,RotationTable={},{},{},{},{}
function Initialize()
	Sub,Index,Limit=SELF:GetOption("Sub"),SKIN:ParseFormula(SELF:GetOption("Index")),SKIN:ParseFormula(SELF:GetOption("Limit"))
	Direction,ResetAngle=SKIN:ReplaceVariables("#Direction#"),math.rad(360)
	Constant,Sustain,Attack=SKIN:ReplaceVariables("#Constant#"),SKIN:ReplaceVariables("#Sustain#"),SKIN:ReplaceVariables("#Attack#")
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
	for i=Index,Limit do 
		local Value,Difference=Measure[i]:GetValue(),Measure[i]:GetValue()-OldValue[i]
		OldValue[i]=Value
		
		if Difference<0 then Difference=0 end
			
		if RotationTable[i]==0 or Direction=="Clockwise" then
			StartAngle[i]=(StartAngle[i] + Value^((Limit/i)/Sustain) + Difference^((i/Limit)/Attack) + Constant)%ResetAngle
		elseif RotationTable[i]==1 or Direction=="CounterClockwise" then
			StartAngle[i]=(StartAngle[i] - Value^((Limit/i)/Sustain) - Difference^((i/Limit)/Attack) - Constant)%ResetAngle end
		
		SKIN:Bang("!SetOption",Meter[i],"StartAngle",StartAngle[i])
	end
end