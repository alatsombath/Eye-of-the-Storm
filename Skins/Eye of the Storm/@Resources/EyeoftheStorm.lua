-- EyeoftheStorm v2.0
-- LICENSE: Creative Commons Attribution-Non-Commercial-Share Alike 3.0

local measure, meterName, startAngle, measureRotation = {}, {}, {}, {}

function Initialize()
  multiplier, constant = 0.01 * SELF:GetNumberOption("Multiplier"), 0.001 * SELF:GetNumberOption("Constant")
  direction, resetAngle = SELF:GetOption("Direction"), math.rad(360)
  lowerLimit, upperLimit = SELF:GetNumberOption("LowerLimit") + 1, SELF:GetNumberOption("UpperLimit") + 1
  
  local innerMinAngle, outerMinAngle = SELF:GetNumberOption("InnerMinAngle"), SELF:GetNumberOption("OuterMinAngle")
  local innerMaxAngle, outerMaxAngle = SELF:GetNumberOption("InnerMaxAngle"), SELF:GetNumberOption("OuterMaxAngle")
  local minAngleInc, maxAngleInc = math.abs(innerMinAngle - outerMinAngle) * (1 / (upperLimit - lowerLimit)), math.abs(innerMaxAngle - outerMaxAngle) * (1 / (upperLimit - lowerLimit))
  
  for i = lowerLimit, upperLimit do
    startAngle[i], measure[i], meterName[i] = 0, SKIN:GetMeasure(SELF:GetOption("MeasureBaseName") .. i-1), SELF:GetOption("MeterBaseName") .. i-1
	if direction == "Random" then measureRotation[i] = math.random(0, 1) end
	
	local minAngle = innerMinAngle + (minAngleInc * i * (innerMinAngle < outerMinAngle and 1 or -1))
    local maxAngle = outerMaxAngle + (maxAngleInc * i * (outerMaxAngle > innerMaxAngle and -1 or 1))
	
    SKIN:Bang("!SetOption", meterName[i], "RotationAngle", maxAngle)
    SKIN:Bang("!SetOption", SELF:GetOption("MeasureArcBaseName") .. i-1, "Formula", math.rad(minAngle / maxAngle))
  end
  
end

function Update()
  for i = lowerLimit, upperLimit do
  
    if direction == "Clockwise" or measureRotation[i] == 0 then
      startAngle[i] = (startAngle[i] + (measure[i]:GetValue() * multiplier) + constant) % resetAngle
    elseif direction == "CounterClockwise" or measureRotation[i] == 1 then
      startAngle[i] = (startAngle[i] - (measure[i]:GetValue() * multiplier) - constant) % resetAngle
    end
    
    SKIN:Bang("!SetOption", meterName[i], "StartAngle", startAngle[i])
  end
end