[Variables]

; Refresh the skin after updating these settings!


; DISPLAY
; =======

Bands=24
; Number of roundlines

RoundlineLength=8
; Technically the "width" of the line

RoundlineGap=4

CenterOffset=0
; Distance from the center of the eye

Color=161,186,220,255


; MECHANICS
; =========

Direction=Random
; Direction=Clockwise
; Direction=CounterClockwise

InvertSpectrum=0
; 0 = Bass inside, treble outside
; 1 = Treble inside, bass outside

Constant=0.005
; Band rotation speed when no sound is playing
Sustain=0.3
; Band rotation speed when sound level is the same
Attack=0.6
; Band angle change intensity when sound level jumps

AverageSustain=0.1
; Spectrum rotation speed when treble sound level is the same
AverageAttack=0.2
; Spectrum angle change intensity when bass sound level jumps

AngleFillMinLowFreq=(Rad(0))
; Minimum angle size on no sound for lowest frequency
AngleFillMinHighFreq=(Rad(180))
; Minimum angle size on no sound for highest frequency

AngleFillMaxLowFreq=(Rad(360))
; Maximum angle size on loudest sound for lowest frequency
AngleFillMaxHighFreq=(Rad(180))
; Maximum angle size on loudest sound for highest frequency


; AUDIO
; =====

Sensitivity=42
; Increase this if the spectrum is not visible enough

FFTAttack=350
FFTDecay=350
; Decrease for faster response, increase for slower response
; http://docs.rainmeter.net/manual-beta/plugins/audiolevel#FFTAttack

FFTSize=2048
FFTOverlap=(#FFTSize#/2)
FreqMin=40
FreqMax=16000
Port=Output
; Additional audio settings
; http://docs.rainmeter.net/manual-beta/plugins/audiolevel#FFTOptions
