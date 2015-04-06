[MeasureAudioRepeat]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=Repeat

[MeasureAudioMinRepeat]
Measure=Calc

[MeterRoundlineRepeat]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMinRepeat
LineStart=(#CenterOffset#+(#RoundlineLength#*(Abs([Invert]-Repeat)-1))+(#RoundlineGap#*(Abs([Invert]-Repeat)-1)))
LineLength=(#CenterOffset#+(#RoundlineLength#*Abs([Invert]-Repeat))+(#RoundlineGap#*(Abs([Invert]-Repeat)-1)))