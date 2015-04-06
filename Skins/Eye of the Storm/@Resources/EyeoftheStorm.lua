-- EyeoftheStorm v1.2
-- LICENSE: Creative Commons Attribution-Non-Commercial-Share Alike 3.0

local Measure,Meter,OldValue,StartAngle,RotationTable={},{},{},{},{}
function Initialize()
	Sub,Index,Limit=SELF:GetOption("Sub"),SKIN:ParseFormula(SELF:GetOption("Index")),SKIN:ParseFormula(SELF:GetOption("Limit"))
	Direction,ResetAngle=SKIN:ReplaceVariables("#Direction#"),math.rad(360)
	Constant,Sustain,Decay=SKIN:ReplaceVariables("#Constant#"),SKIN:ReplaceVariables("#Sustain#"),SKIN:ReplaceVariables("#Decay#")
	AngleFillMinLowFreq,AngleFillMinHighFreq=SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMinLowFreq#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMinHighFreq#"))
	AngleFillMaxLowFreq,AngleFillMaxHighFreq=SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMaxLowFreq#")),SKIN:ParseFormula(SKIN:ReplaceVariables("#AngleFillMaxHighFreq#"))
	
	local MeasureName,MeterName,gsub,random=SKIN:ReplaceVariables("#MeasureName#"),SKIN:ReplaceVariables("#MeterName#"),string.gsub,math.random
	local AngleFillMinAdd,AngleFillMaxAdd=math.abs(AngleFillMinLowFreq-AngleFillMinHighFreq)*(1/Limit),math.abs(AngleFillMaxLowFreq-AngleFillMaxHighFreq)*(1/Limit)
	for i=Index,Limit do
		local MeasureNameSub,AngleFillRatio=(gsub(MeasureName,Sub,i)),(AngleFillMinAdd*i)/(AngleFillMaxAdd*i)
		OldValue[i],StartAngle[i],Measure[i],Meter[i]=0,0,SKIN:GetMeasure(MeasureNameSub),(gsub(MeterName,Sub,i))
		SKIN:Bang("!SetOption","MeasureAudioMin"..i,"Formula","("..MeasureNameSub.." < "..AngleFillRatio.." ? "..AngleFillRatio.." : "..MeasureNameSub..")")
		if Direction=="Random" then RotationTable[i]=random(0,1) end end end

function Update()
	for i=Index,Limit do 
		local Value,Difference=Measure[i]:GetValue(),Measure[i]:GetValue()-OldValue[i]
		OldValue[i]=Value
		
		if Difference<0 then Difference=0 end
			
		if RotationTable[i]==0 or Direction=="Clockwise" then
			StartAngle[i]=(StartAngle[i] + Value^((Limit/i)/Sustain) + Difference^((Limit/i)/Decay) + Constant)%ResetAngle
		elseif RotationTable[i]==1 or Direction=="CounterClockwise" then
			StartAngle[i]=(StartAngle[i] - Value^((Limit/i)/Sustain) - Difference^((Limit/i)/Decay) - Constant)%ResetAngle end
		
		SKIN:Bang("!SetOption",Meter[i],"StartAngle",StartAngle[i])
	end
end