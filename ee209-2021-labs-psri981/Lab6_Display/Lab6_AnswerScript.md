<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Answer Sheet - Lab 6

## Pre-lab: Basics of a 7-segment display

Q P.1) Given the above component, and assuming “dp” is the MSB and “a” is the LSB, complete the table to indicate what segments should light for each digit:

> Segments to be turned on for "0" in binary / hex: 0b00111111 / 0x3F

> Segments to be turned on for "1" in binary / hex: 0b00000110 / 0x6

> Segments to be turned on for "2" in binary / hex: 0b01011011 / 0x5B

> Segments to be turned on for "3" in binary / hex: 0b01001111 / 0x4F

> Segments to be turned on for "4" in binary / hex: 0b01100110 / 0x66

> Segments to be turned on for "5" in binary / hex: 0b01101101 / 0x6D

> Segments to be turned on for "6" in binary / hex: 0b01111101 / 0x7D 

> Segments to be turned on for "7" in binary / hex: 0b00000111 / 0x7

> Segments to be turned on for "8" in binary / hex: 0b01111111 / 0x7F

> Segments to be turned on for "9" in binary / hex: 0b0110011 / 0x67

## Part 1: Multiplexing LEDs

Q 1.2: In the pseudo-code steps given, why do you think that we output the segments before we enable the display (i.e. why is Step 5 before Step 4)?

> This is because the pins for the displays are connected to both Ds1 and Ds2. By setting the pins first and then displaying the correct digit set by the flag, we only need to set the output pins once and the correct digit will be displayed afterwards. If we were to enable the display first and then set the output segments, the previous number would be displayed rather than the next increment of the number.  

Q 1.3: In the pseudo-code steps given, why do you think that we alternate the digit we update every 10ms?

> This is to flash the digits fast enough to give the illusion that both digits are being displayed at the same time. To achieve this illusion, the rate at which the displays  are turned on and off must be higher than the response of the human eye.

## Part 2: Shift registers

Q 2.1: If only using multiplexing, how many I/O pins are needed to drive a display that has N number of 7-segment digits where each digit also has a decimal point?

> Because of multiplexing we only need 8 microcontroller I/O pins (7 segment + decimal point) + N number of digits being displayed. The main reason to multiplex a display is to save I/O pins and this means we can configure the layout of the digits in a line. 
