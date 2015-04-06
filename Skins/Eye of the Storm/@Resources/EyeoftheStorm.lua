-- EyeoftheStorm v1.0
-- LICENSE: Creative Commons Attribution-Non-Commercial-Share Alike 3.0

local Measure,Meter,OldValue,StartAngle,RotationTable,rad={},{},{},{},{},math.rad
function Initialize()
	Constant,SustainSensitivity,ChangeSensitivity=SKIN:ReplaceVariables("#Constant#"),SKIN:ReplaceVariables("#SustainSensitivity#"),SKIN:ReplaceVariables("#ChangeSensitivity#")
	Regression,Direction=SKIN:ParseFormula(SKIN:ReplaceVariables("#Regression#")),SKIN:ReplaceVariables("#Direction#")
	Sub,Index,Limit=SELF:GetOption("Sub"),SKIN:ParseFormula(SELF:GetOption("Index")),SKIN:ParseFormula(SELF:GetOption("Limit"))
	local MeasureName,MeterName,gsub,random=SKIN:ReplaceVariables("#MeasureName#"),SKIN:ReplaceVariables("#MeterName#"),string.gsub,math.random
	for i=Index,Limit do OldValue[i],StartAngle[i],Measure[i],Meter[i]=0,0,SKIN:GetMeasure((gsub(MeasureName,Sub,i))),(gsub(MeterName,Sub,i))
		if Direction=="Random" then RotationTable[i]=random(0,1) end end end

function Update()
	for i=Index,Limit do 
		local Difference=Measure[i]:GetValue()-OldValue[i]
		OldValue[i]=Measure[i]:GetValue()
		
		if Regression==0 then if Difference<0 then Difference=0 end end
		
		if RotationTable[i]==0 or Direction=="Clockwise" then
			StartAngle[i]=(StartAngle[i] + SustainSensitivity*Measure[i]:GetValue() + ChangeSensitivity*Difference + Constant)%rad(360)
		elseif RotationTable[i]==1 or Direction=="CounterClockwise" then
			StartAngle[i]=(StartAngle[i] - SustainSensitivity*Measure[i]:GetValue() - ChangeSensitivity*Difference - Constant)%rad(360) end
		
		SKIN:Bang("!SetOption",Meter[i],"StartAngle",StartAngle[i])
	end
end