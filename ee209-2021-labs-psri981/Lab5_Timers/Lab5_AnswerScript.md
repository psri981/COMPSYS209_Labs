<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Answer Sheet - Lab 5

## Part 1: What is a Timer Peripheral?

Q 1.1: Based on the diagram above and the information provided in the datasheet, are the two OCRnX registers (i.e. ORCnA and OCRnB) needed for all timer configurations?

> Yes because the timer is constantly compared with OCRnA and OCRnB (No change answer)

Q 1.2: Based on the lecture slides, datasheet, COMPSYS201 notes, and other online resources, find and then state in your own words the difference between the **range** and **resolution** of a given timer: 

> Range: The range is the max time interval that the timer can measure.

> Resolution: Bit resolution is the min time interval that the timer can measure.

Q 1.3: What is the purpose of the prescaler used with the clock source? 

> The prescaler works as a clock divider that divides the system clock in order to create a timer clock.

Q 1.4: If the clock rate of the ATmega328P is 2MHz, and the clock selection bits in TCCR0B are set to “100”, 

> The prescaler is: 256

> Resolution of TIMER0 is: 128 microseconds (f<sub>timer</sup> = f<sub>system clk</sub> / prescaler) (resultion = 1 / f<sub>timer</sub>) 

> Maximum range of TIMER0 is: range = resolution x (2<sup>bits</sup>-1) = 32640 microseconds

Q 1.5: We want TIMER0 to use CTC mode to set the “output compare A match” flag every 10 milliseconds. What should the following registers be set to (some bits have already been filled in for you)?

> TCCR0A

| COM0An  |         |COM0Bn   |         |    -    |     -   |WGM0n    |         |
|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
| 0       |0        |0        |0        |0        |  0      |1        |   0     |

> TCCR0B

|FOC0A    |FOC0B    |   -     |    -    |WGM02    | CS02    | CS01    | CS00    |
|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
|   0     | 0       |0        |  0      |   0     | 1       | 0       | 0       |

> OCR0A

|OCR0A[7] |OCR0A[6 ]|OCR0A[5] |OCR0A[4] |OCR0A[3] |OCR0A[2] |OCR0A[1] |OCR0A[0] |
|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
| 0       |   1     |  0      |     0   |    1    |   1     |    0    |  1      |

Q 1.6: In which bit of which register is the “output compare match A” flag?

> OCF0A in TIFR0 reg

## Part 2: Controlling the TIMER0

Q 2.1: Using your answers thus far, create an Atmel Studio Project to toggle the LED that is connected to the ATmega328P in the proteus project “Lab5_Proteus_All.pdsprj”. It should toggle every 10ms, and you should be using Timer0. Use polling to check the compare match flag. Provide the completed skeleton code below (see word document for header file examples):

main.c
![image](https://user-images.githubusercontent.com/79814779/135510769-06106978-d0d5-4813-9658-fb18c0c73cb4.png) 

timer0.c
![image](https://user-images.githubusercontent.com/79814779/135511011-bca59044-4c57-4991-abdb-2e9dedfb3fa4.png)

led.h
![image](https://user-images.githubusercontent.com/79814779/135511095-3f635cec-0d84-437d-a2c4-1380dcdbf907.png)

led.c
![image](https://user-images.githubusercontent.com/79814779/135511136-3f1dab1f-c2bd-4cbc-b47e-bde0abfe1810.png)

Q 2.2: 

![image](https://user-images.githubusercontent.com/79814779/135511395-9d467f9b-024d-4a5a-955f-6f6353b71545.png)
 Each grid is 1ms. Every rising or falling edge there is 10 grids distance (channel A). 

## Part 3: Timer Interrupts

Q 3.1: Change the embedded program you developed previously to toggle the LED using an Output Compare A match interrupt. To do this, firstly, enable the timer0 interrupt in your timer0_init(), add the ISR function to your timer0.c, and in here toggle the LED. Finally, enable global interrupts. Provide the completed skeleton code below:

![image](https://user-images.githubusercontent.com/79814779/135511632-371c6dba-959e-40d1-82e9-24fad96c1ba3.png)

Q 3.3: ![image](https://user-images.githubusercontent.com/79814779/135511939-7101ae7f-1f1f-4026-a722-bcb062a900cb.png)

timer0.c (code above)

![image](https://user-images.githubusercontent.com/79814779/135512047-797e555c-ceca-466b-83aa-ca548663572b.png)

Each grid is 10ms. As there are 10 grids this means the LED flashes every 100ms/

Q 3.4: What is the maximum range of Timer1? Assume the system clock frequency is 2MHz

> range = resolution x (2<sup>bits</sup>-1)
> range = 128 x (2<sup>16</sup>-1) 
> range = 8388480

## Part 4: Measuring Time

Q 4.1: Modify your code so that the timer is started on the rising edge of INT0, and stopped on the falling edge of INT0. You can poll the input at INT0, or you can use interrupts. Calculate the frequency of the waveform and send the result over the UART to be displayed on a terminal window. Compile the Atmel Studio project and simulate your program in Proteus. What frequency is the waveform on INT0?

> 500Hz

Q 4.2: What is the lowest frequency waveform the timer could measure? Why?

> To measure the lowest we do biggest period / time interval. Our resolution is 128us and timer0 has 8bit counter. Therefore the range of timer counter is 128us * 2<sup>8</sup> -1 = 32640us = biggest time interval. Therefore frequency is 1/32460 = 15.32Hz. (need to multiply by 2 to get full wave) 30.64Hz.

Q 4.3: Change the processor to an ATmega328PB, recompile your code and load on to the Xplained Mini. Make sure the Xplained Mini is plugged on to the Emulator Board. On PuTTY or other terminal program observe the messages printed. What frequency is the waveform on INT0?

> Add answer here 
