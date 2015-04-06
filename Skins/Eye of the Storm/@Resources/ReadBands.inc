[MeasureAudioRepeat]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=Repeat

[MeasureAudioMinRepeat]
Measure=Calc
Formula=(MeasureAudioRepeat < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudioRepeat)

[MeterRoundlineRepeat]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMinRepeat
LineStart=(#RoundlineLength#*(Abs([Invert]-Repeat)-1)+(#RoundlineGap#*(Abs([Invert]-Repeat)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-Repeat)+(#RoundlineGap#*(Abs([Invert]-Repeat)-1)))