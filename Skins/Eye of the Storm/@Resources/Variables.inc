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

RoundlineLength=8
RoundlineGap=4
CenterOffset=0
Color=161,186,220,255

Direction=Random
; Direction=Clockwise
; Direction=CounterClockwise

InvertSpectrum=0
; 0 = Bass inside, treble outside
; 1 = Treble inside, bass outside

Constant=0.005
; Rotation speed when no sound is playing
Sustain=0.35
; Rotation speed when sound level is the same
Attack=0.7
; Angle change intensity when sound level jumps

AngleFillMinLowFreq=(Rad(0))
; Minimum angle size on no sound for lowest frequency
AngleFillMinHighFreq=(Rad(180))
; Minimum angle size on no sound for highest frequency

AngleFillMaxLowFreq=(Rad(360))
; Maximum angle size on loudest sound for lowest frequency
AngleFillMaxHighFreq=(Rad(180))
; Maximum angle size on loudest sound for highest frequency