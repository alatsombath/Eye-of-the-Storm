[Variables]

Bands=9
; Number of arcs - Activate Eye of the Storm\GenerateBands.ini skin after changing this value

Color=128,128,128

RoundlineLength=12
RoundlineGap=4

CenterOffset=0
; Distance from the center of the eye

Multiplier=35
; Arc rotation speed

Constant=5
; Arc rotation speed when no sound is playing

InnerMinAngle=0
; Determines minimum inner arc length
OuterMinAngle=180
; Determines minimum outer arc length

InnerMaxAngle=360
; Determines maximum inner arc length
OuterMaxAngle=0
; Determines maximum outer arc length

AverageSize=0
; Average sound levels over time to provide continuity

LoudnessEqualization=1
; Increases visibility for quiet audio sources when applicable

FFTSize=10240
FFTOverlap="(#FFTSize#-512)"
FFTAttack=0
FFTDecay=0
FreqMin=20
FreqMax=20000
Sensitivity=18
; http://docs.rainmeter.net/manual-beta/plugins/audiolevel

MusicPlayer=None
; Music player process name

FirstBandIndex=1

; Environment variables for settings window
SkinGroup=EyeoftheStorm
Config=Eye of the Storm
ConfigPath=#ROOTCONFIGPATH##Config#.ini
WriteVariable=Color
Direction=Random
Invert=0
Channel=Avg
Port=Output
ID=
