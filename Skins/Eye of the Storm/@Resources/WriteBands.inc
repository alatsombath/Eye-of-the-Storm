[MeasureAudio1]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=1

[MeasureAudioMin1]
Measure=Calc
Formula=(MeasureAudio1 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio1)

[MeterRoundline1]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin1
LineStart=(#RoundlineLength#*(Abs([Invert]-1)-1)+(#RoundlineGap#*(Abs([Invert]-1)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-1)+(#RoundlineGap#*(Abs([Invert]-1)-1)))

[MeasureAudio2]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=2

[MeasureAudioMin2]
Measure=Calc
Formula=(MeasureAudio2 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio2)

[MeterRoundline2]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin2
LineStart=(#RoundlineLength#*(Abs([Invert]-2)-1)+(#RoundlineGap#*(Abs([Invert]-2)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-2)+(#RoundlineGap#*(Abs([Invert]-2)-1)))

[MeasureAudio3]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=3

[MeasureAudioMin3]
Measure=Calc
Formula=(MeasureAudio3 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio3)

[MeterRoundline3]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin3
LineStart=(#RoundlineLength#*(Abs([Invert]-3)-1)+(#RoundlineGap#*(Abs([Invert]-3)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-3)+(#RoundlineGap#*(Abs([Invert]-3)-1)))

[MeasureAudio4]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=4

[MeasureAudioMin4]
Measure=Calc
Formula=(MeasureAudio4 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio4)

[MeterRoundline4]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin4
LineStart=(#RoundlineLength#*(Abs([Invert]-4)-1)+(#RoundlineGap#*(Abs([Invert]-4)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-4)+(#RoundlineGap#*(Abs([Invert]-4)-1)))

[MeasureAudio5]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=5

[MeasureAudioMin5]
Measure=Calc
Formula=(MeasureAudio5 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio5)

[MeterRoundline5]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin5
LineStart=(#RoundlineLength#*(Abs([Invert]-5)-1)+(#RoundlineGap#*(Abs([Invert]-5)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-5)+(#RoundlineGap#*(Abs([Invert]-5)-1)))

[MeasureAudio6]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=6

[MeasureAudioMin6]
Measure=Calc
Formula=(MeasureAudio6 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio6)

[MeterRoundline6]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin6
LineStart=(#RoundlineLength#*(Abs([Invert]-6)-1)+(#RoundlineGap#*(Abs([Invert]-6)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-6)+(#RoundlineGap#*(Abs([Invert]-6)-1)))

[MeasureAudio7]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=7

[MeasureAudioMin7]
Measure=Calc
Formula=(MeasureAudio7 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio7)

[MeterRoundline7]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin7
LineStart=(#RoundlineLength#*(Abs([Invert]-7)-1)+(#RoundlineGap#*(Abs([Invert]-7)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-7)+(#RoundlineGap#*(Abs([Invert]-7)-1)))

[MeasureAudio8]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=8

[MeasureAudioMin8]
Measure=Calc
Formula=(MeasureAudio8 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio8)

[MeterRoundline8]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin8
LineStart=(#RoundlineLength#*(Abs([Invert]-8)-1)+(#RoundlineGap#*(Abs([Invert]-8)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-8)+(#RoundlineGap#*(Abs([Invert]-8)-1)))

[MeasureAudio9]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=9

[MeasureAudioMin9]
Measure=Calc
Formula=(MeasureAudio9 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio9)

[MeterRoundline9]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin9
LineStart=(#RoundlineLength#*(Abs([Invert]-9)-1)+(#RoundlineGap#*(Abs([Invert]-9)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-9)+(#RoundlineGap#*(Abs([Invert]-9)-1)))

[MeasureAudio10]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=10

[MeasureAudioMin10]
Measure=Calc
Formula=(MeasureAudio10 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio10)

[MeterRoundline10]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin10
LineStart=(#RoundlineLength#*(Abs([Invert]-10)-1)+(#RoundlineGap#*(Abs([Invert]-10)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-10)+(#RoundlineGap#*(Abs([Invert]-10)-1)))

[MeasureAudio11]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=11

[MeasureAudioMin11]
Measure=Calc
Formula=(MeasureAudio11 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio11)

[MeterRoundline11]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin11
LineStart=(#RoundlineLength#*(Abs([Invert]-11)-1)+(#RoundlineGap#*(Abs([Invert]-11)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-11)+(#RoundlineGap#*(Abs([Invert]-11)-1)))

[MeasureAudio12]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=12

[MeasureAudioMin12]
Measure=Calc
Formula=(MeasureAudio12 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio12)

[MeterRoundline12]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin12
LineStart=(#RoundlineLength#*(Abs([Invert]-12)-1)+(#RoundlineGap#*(Abs([Invert]-12)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-12)+(#RoundlineGap#*(Abs([Invert]-12)-1)))

[MeasureAudio13]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=13

[MeasureAudioMin13]
Measure=Calc
Formula=(MeasureAudio13 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio13)

[MeterRoundline13]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin13
LineStart=(#RoundlineLength#*(Abs([Invert]-13)-1)+(#RoundlineGap#*(Abs([Invert]-13)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-13)+(#RoundlineGap#*(Abs([Invert]-13)-1)))

[MeasureAudio14]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=14

[MeasureAudioMin14]
Measure=Calc
Formula=(MeasureAudio14 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio14)

[MeterRoundline14]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin14
LineStart=(#RoundlineLength#*(Abs([Invert]-14)-1)+(#RoundlineGap#*(Abs([Invert]-14)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-14)+(#RoundlineGap#*(Abs([Invert]-14)-1)))

[MeasureAudio15]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=15

[MeasureAudioMin15]
Measure=Calc
Formula=(MeasureAudio15 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio15)

[MeterRoundline15]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin15
LineStart=(#RoundlineLength#*(Abs([Invert]-15)-1)+(#RoundlineGap#*(Abs([Invert]-15)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-15)+(#RoundlineGap#*(Abs([Invert]-15)-1)))

[MeasureAudio16]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=16

[MeasureAudioMin16]
Measure=Calc
Formula=(MeasureAudio16 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio16)

[MeterRoundline16]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin16
LineStart=(#RoundlineLength#*(Abs([Invert]-16)-1)+(#RoundlineGap#*(Abs([Invert]-16)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-16)+(#RoundlineGap#*(Abs([Invert]-16)-1)))

[MeasureAudio17]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=17

[MeasureAudioMin17]
Measure=Calc
Formula=(MeasureAudio17 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio17)

[MeterRoundline17]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin17
LineStart=(#RoundlineLength#*(Abs([Invert]-17)-1)+(#RoundlineGap#*(Abs([Invert]-17)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-17)+(#RoundlineGap#*(Abs([Invert]-17)-1)))

[MeasureAudio18]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=18

[MeasureAudioMin18]
Measure=Calc
Formula=(MeasureAudio18 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio18)

[MeterRoundline18]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin18
LineStart=(#RoundlineLength#*(Abs([Invert]-18)-1)+(#RoundlineGap#*(Abs([Invert]-18)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-18)+(#RoundlineGap#*(Abs([Invert]-18)-1)))

[MeasureAudio19]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=19

[MeasureAudioMin19]
Measure=Calc
Formula=(MeasureAudio19 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio19)

[MeterRoundline19]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin19
LineStart=(#RoundlineLength#*(Abs([Invert]-19)-1)+(#RoundlineGap#*(Abs([Invert]-19)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-19)+(#RoundlineGap#*(Abs([Invert]-19)-1)))

[MeasureAudio20]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=20

[MeasureAudioMin20]
Measure=Calc
Formula=(MeasureAudio20 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio20)

[MeterRoundline20]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin20
LineStart=(#RoundlineLength#*(Abs([Invert]-20)-1)+(#RoundlineGap#*(Abs([Invert]-20)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-20)+(#RoundlineGap#*(Abs([Invert]-20)-1)))

[MeasureAudio21]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=21

[MeasureAudioMin21]
Measure=Calc
Formula=(MeasureAudio21 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio21)

[MeterRoundline21]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin21
LineStart=(#RoundlineLength#*(Abs([Invert]-21)-1)+(#RoundlineGap#*(Abs([Invert]-21)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-21)+(#RoundlineGap#*(Abs([Invert]-21)-1)))

[MeasureAudio22]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=22

[MeasureAudioMin22]
Measure=Calc
Formula=(MeasureAudio22 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio22)

[MeterRoundline22]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin22
LineStart=(#RoundlineLength#*(Abs([Invert]-22)-1)+(#RoundlineGap#*(Abs([Invert]-22)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-22)+(#RoundlineGap#*(Abs([Invert]-22)-1)))

[MeasureAudio23]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=23

[MeasureAudioMin23]
Measure=Calc
Formula=(MeasureAudio23 < (#AngleFillMin#/#AngleFillMax#) ? (#AngleFillMin#/#AngleFillMax#) : MeasureAudio23)

[MeterRoundline23]
Meter=Roundline
MeterStyle=MeterRoundline
MeasureName=MeasureAudioMin23
LineStart=(#RoundlineLength#*(Abs([Invert]-23)-1)+(#RoundlineGap#*(Abs([Invert]-23)-1)))
LineLength=(#RoundlineLength#*Abs([Invert]-23)+(#RoundlineGap#*(Abs([Invert]-23)-1)))