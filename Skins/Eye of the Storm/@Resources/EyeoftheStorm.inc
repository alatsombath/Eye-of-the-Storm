[Rainmeter]
Update=16
DefaultUpdateDivider=-1
Group=#SkinGroup#
OnCloseAction=[!RefreshGroup #SkinGroup#]

ContextTitle="Open settings window"
ContextAction=#OpenSettingsWindow#
ContextTitle2="Edit variables"
ContextAction2=["#@#Variables.inc"]

[Variables]

; Since each skin file has some specific settings, they should be written to the global Variables file for access
EnvDirection=[!WriteKeyValue Variables Direction #Direction# "#@#Variables.inc"]
EnvInvert=[!WriteKeyValue Variables Invert #Invert# "#@#Variables.inc"]
EnvChannel=[!WriteKeyValue Variables Channel #Channel# "#@#Variables.inc"]
EnvPort=[!WriteKeyValue Variables Port #Port# "#@#Variables.inc"]
EnvID=[!WriteKeyValue Variables ID "#ID#" "#@#Variables.inc"]
EnvConfig=[!WriteKeyValue Variables Config "#CURRENTCONFIG#" "#@#Variables.inc"]
EnvConfigPath=[!WriteKeyValue Variables ConfigPath "#CURRENTPATH##CURRENTFILE#" "#@#Variables.inc"]
EnvSettingsWindow=#EnvDirection##EnvInvert#EnvChannel##EnvPort##EnvID##EnvConfig##EnvConfigPath#
OpenSettingsWindow=#EnvSettingsWindow#[!ActivateConfig "#ROOTCONFIG#\SettingsWindow"][!Refresh "#ROOTCONFIG#\SettingsWindow"]

[MeasureAudio]
Measure=Plugin
Plugin=AudioLevel
Port=#Port#
ID=#ID#
RMSAttack=0
RMSDecay=0
RMSGain=1
PeakAttack=0
PeakDecay=0
PeakGain=1
FFTSize=#FFTSize#
FFTOverlap=#FFTOverlap#
FFTAttack=#FFTAttack#
FFTDecay=#FFTDecay#
Bands=#Bands#
FreqMin=#FreqMin#
FreqMax=#FreqMax#
Sensitivity=#Sensitivity#
UpdateDivider=1

[DisableProcessCheck]
Measure=String
String=#MusicPlayer#
IfMatch="None"
IfMatchAction=[!SetOption DisableProcessCheck String 1][!UpdateMeasure DisableProcessCheck]
IfNotMatchAction=[!SetOption MeasureProcess UpdateDivider 62.5]

[MeasureProcess]
Measure=Plugin
Plugin=Process
ProcessName=#MusicPlayer#.exe

[Standby]
Measure=Plugin
Plugin=AudioLevel
Port=#Port#
ID=#ID#
RMSAttack=0
RMSDecay=0
RMSGain=1
PeakAttack=0
PeakDecay=0
PeakGain=1
UpdateDivider=1

; Toggle measures/meters based on idle audio, music player running status, and constant rotation
IfCondition=((Standby > 0.00001) && ((DisableProcessCheck = 1) || (MeasureProcess = 1)))
IfTrueAction=[!EnableMeasureGroup Audio][!EnableMeasure MeasureAudio][!EnableMeasure DynamicSensitivity][!EnableMeasure DynamicFFTDecay]
IfFalseAction=[!DisableMeasureGroup Audio][!DisableMeasure MeasureAudio][!DisableMeasure DynamicSensitivity][!DisableMeasure DynamicFFTDecay]
IfCondition2=((Standby > 0.00001) && ((DisableProcessCheck = 1) || (MeasureProcess = 1)) && (#Constant# = 0))
IfTrueAction2=[!EnableMeasure ScriptEyeoftheStorm][!ShowFade]
IfFalseAction2=[!DisableMeasure ScriptEyeoftheStorm][!HideFade]
IfCondition3=(#Constant# <> 0)
IfTrueAction3=[!EnableMeasure ScriptEyeoftheStorm][!ShowFade]

[DynamicSensitivity]
Measure=Calc
Formula=(#Sensitivity# - (MeasureAudio * 100 - #Sensitivity#))
IfCondition=((DynamicSensitivity > #Sensitivity#) && (#LoudnessEqualization# = 1))
IfTrueAction=[!SetOption MeasureAudio Sensitivity [DynamicSensitivity]]
IfConditionMode=1
UpdateDivider=1
; Average over the past 0.9 seconds to prevent stuttering
AverageSize=56

[DynamicFFTDecay]
Measure=Calc
Formula=(#FFTDecay# + (MeasureAudio * 100 - #Sensitivity#) * 10)
IfCondition=((DynamicSensitivity > #Sensitivity#) && (#LoudnessEqualization# = 1))
IfTrueAction=[!SetOption MeasureAudio FFTDecay [DynamicFFTDecay]]
IfConditionMode=1
UpdateDivider=1
AverageSize=56

@Include=#@#Bands.inc

[SetMeasureOptions]
Measure=Calc
OnUpdateAction=[!SetOptionGroup Audio Channel #Channel#][!SetOptionGroup Audio AverageSize #AverageSize#][!SetOptionGroup Audio UpdateDivider 1][!UpdateMeasureGroup Audio]

[SetMeterOptions]
Measure=Script
ScriptFile=#@#SetMeterOptions.lua

[ScriptEyeoftheStorm]
Measure=Script
ScriptFile=#@#EyeoftheStorm.lua
MeasureBaseName=MeasureAudio
MeasureArcBaseName=MeasureArc
MeterBaseName=MeterRoundline
LowerLimit=#FirstBandIndex#
UpperLimit=(#Bands#-1)
Multiplier=#Multiplier#
Constant=#Constant#
Direction=#Direction#
InnerMinAngle=#InnerMinAngle#
OuterMinAngle=#OuterMinAngle#
InnerMaxAngle=#InnerMaxAngle#
OuterMaxAngle=#OuterMaxAngle#
UpdateDivider=1