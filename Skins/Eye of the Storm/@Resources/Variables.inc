[Variables]
FFTAttack=350
FFTDecay=350
FFTSize=2048
FreqMin=40
FreqMax=16000
; Audio settings
; http://docs.rainmeter.net/manual-beta/plugins/audiolevel#FFTOptions

MeasureName=MeasureAudioRepeat
MeterName=MeterRoundlineRepeat

Bands=24
Sensitivity=42
InvertSpectrum=0

RoundlineLength=6
RoundlineGap=2

AngleFillMin=(Rad(90))
AngleFillMax=(Rad(360))

Constant=0.0125
; Rotation speed when no sound is playing
SustainSensitivity=0.1
; Rotation speed when sound level is the same
ChangeSensitivity=5
; Angle change when sound level jumps

Regression=0
; Rotate backwards when sound decreases

Direction=Random
; Direction=Clockwise
; Direction=CounterClockwise

Color=161,186,220,255
