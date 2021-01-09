This is a floating-point to integer translator written in C used for the emulation of fixed-point arithmetic on 8/16/32-bit target word-length processors.
e.g. 

1.667 x 0.25 = 0.41675 (float value)

1.667000 = 106 (Q2.6)
0.250000 = 32  (Q1.7)
106 x 32 = 13  (Q3.5) --> 0.40625 (float value)
