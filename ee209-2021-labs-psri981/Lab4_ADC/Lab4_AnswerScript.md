<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Answer Sheet - Lab 4

## Pre-Lab: Digital I/O3
Q P.1: What is the purpose of a DDRn register?

> Stores memory of recorded data

Q P.2: Which pin is the LED connected to?  

> PIN 17

Q P.3: How much of a delay is there between the ATmega328P producing a logic high (5V) output to drive the LED from the time the push-button is pressed generating a logic low (0V) input (Hint: Change the time scale)? Why is this?

> Around 5ms from observing execution time of code.

## Part 1: What is an ADC?

Q 1.1: Based on the lecture slides, datasheet, COMPSYS201 coursebook, and other online resources, write a description for each of these terms in your own words:

> Channel Selection: In a particular register, we might want to select a particular bit to set or reset its value (left shift by 1 or right shift by 1) in order to activate or deactivate it to achieve a particular task in the project. For example if we want to use ADC1, we write ADMUX = (1 << MUX0).

> Sample and Hold: A process of sample processing to sense the input analogue data. It is done by closing the switch to connect the supply to the capacitor which then starts charging the capacitor. Then the switch opens disconnecting the circuit. The voltage across the capacitor is then recorded for ADC conversion as the input signal. This completes the sample and hold process and everything repeats to collect new sets of data.

> Successive Approximation: An algorithm that converts analogue input to discrete binary output. Measured by taking half the reference voltage and doing a magnitude comparisom with the analogue input signal. If input signal is higher then the binary will left shift by 1. If the input signal is lower then the input signal left shifts by 0. Then half the reference voltage becomes the new voltage of reference. Since the new reference voltage is lower than the input signal we add the original reference voltage creating the final reference voltage. We compare the final reference voltage with the input signal, add a binary bit to the adc binary output then repeat this process until reference voltage = input voltage.

> Reference Voltage: The input voltage is the highest voltage measurable by the ADC converter to convert. This voltage affects the accuracy of the ADC conversion. A higher reference voltage could have more errors than a low reference voltage. But having a high reference voltage allows us to measure a larger variety of voltages as the value of each resolution is bigger as well.

> Sampling Rate: In this project the power supply is a sinusoid and the ADC conversion is discrete. Therefore we need to take measurements at each time interval. Sampling rate is the frequency at which data can be measured. A high sampling rate contributes to higher accuracy as less information is lost due to large time intervals. However this require more computation power, time and more bits of data to be stored.

> Resolution: The discrete step size of the measured voltage calculated using reference voltage/ (2<sup>n bits</sup>)

Q 1.2: How many input channels are connected to the ADC on the ATMega328P? 

> 8 multiplex ADC input channels

Q 1.3: How many channels can this ADC process simultaneously? 

> ADMUX has 8 ADC conversion channels, only 1 can be processed at a time before jumping to another channel.

Q 1.4: How many clock cycles does a standard ADC conversion take? How long is this in real-world time if we have a 125kHz ADC clock? 

> In a normal conversion 13 clock cycles is required. With a frequency of 125kHz, in real-world time it will take 13(clock cycles)/125kHz = 0.000108s.

Q 1.5: Which stage of the sampling process requires the most time? Why?

> The aquisation time requires the most time because it requires the most time to charge the capacitor (5 time constants).

Q 1.6: Write a formula that gives the ADC count you expect to obtain when converting an analogue signal that has an amplitude of Vanalog. Assume Vref of your ATmega328P/PB is set to 5V and Vanalogue < 5V. 

> Assuming all are integers: (Vinput / Vref) x 2^n.

Q 1.7: Based on the project specifications and the characteristics of the ATMega328P ADC, what is the voltage resolution (i.e. how many volts does one ADC count correspond to)?

> 0.00107V

Q 1.8: What is the recommended operating frequency range for the ADC if we want to read 10-bit numbers? 

> 50k to 200k 

Q 1.9: In this lab you will supply a 125kHz to the ADC on the ATmega328P/PB. What is the prescaler value needed to achieve this ADC frequency?

> 200k / x = 125kHz ; x = 16.

## Part 2: Controlling the ADC

Q 2.1: What are our options for setting the reference voltage on this ADC, and which one is most fit-for-purpose for your project?

> The first bit in the ADMUX to get the default reference voltage of 1.1V, or to connect pin 20 and pin 18 to a voltage source to create a reference voltage. 

Q 2.2: For each of the control registers below, fill out the table with the short name for each bit, and the value we need to set it to during initialisation. Your options are 0 or 1, if you don’t care what the value is, set it to 0.

> ADMUX

| REFS1  |  REFS0 |  ADLAR |       |  MUX3  |  MUX2  |  MUX1  |  MUX0  |        
|:------:|:------:|:------:|:-----:|:------:|:------:|:------:|:------:|
|   0    |   1    |    0   |       |   0    |   0    |   1    |   0    |        

> ADCSRA

|  ADEN  |  ADSC  | ADATE  |   ADIF | ADIE   | ADPS2  | ADPS1  | ADPS0  |
|:------:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|
|   1    |   0    |   0    |   0    |    0   |    1   |    0   |   0    |

> ADCSRB

|        | ACME   |        |        |        | ADTS2  | ADTS1  | ADTS0  |
|:------:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|
|    0   |    0   |    0   |   0    |   0    |    0   |    0   |   0    |

Q 2.3: Create a new Atmel Studio project and using your answers thus far, write a function called adc_init(), which initializes the ADC component. Provide the completed skeleton code below.

> adc.c

```c
#include "adc.h"
#include <avr/io.h> //necessary for definitions of ADMUX etc
void adc_init() {
    
    ADMUX = 0b01000010; //set reference voltage as AVCC (5V reference)
    ADCSRA = 0b10101100; //set ADC enable, interrupt enabled, prescale enabled
    ADCSRB = 0b00000100; //autotrigger source as timer/counter0 overflow
}
```

## Part 3: Reading from the ADC

Q 3.1: Write C code to change ADMUX to read from ADC1, without affecting the other bits in ADMUX that do not control channel selection:

```c
ADMUX = (1 << MUX0);
```

Q 3.2: Which bit do we set to start an ADC conversion?

> Bit 6, ADSC the analogue digital converter encoder. ADCSRA = (1 << ADSC)

Q 3.3: Which bit do we check to know if the conversion is complete?

> Bit 4, ADCSRA = (ADIF) 

Q 3.4: When we read the ADC result, we use ADCL and ADCH. Why are there two data registers for storing the ADC result?

> The ADC result is greated than the bits availible in 1 register, therefore 2 registers are used for storing the result.

## Part 4: Processing the Data

Q 4.1: Using your answers thus far, add a function called **_adc_convert(value)_** to your program, which takes a raw ADC count and converts it back to the original voltage value. Write out the pseudocode steps (like the ones shown in Q 3.5) here:

> Add answer here 

Q 4.2: What do you observe in the simulation when

> RV1 is set to 100%, what does the ADC read? 1023
> 
> RV1 is set to 50%, what does the ADC read? 512
> 
> RV1 is set to 0%, what does the ADC read? 0

Q 4.5: Run your compiled code using the Lab4_Proteus.pdsprj which has two 500Hz sine wave inputs on ADC0 and ADC1 (remember to change the device back to an ATmega328P ). The signal on ADC0 has an amplitude of 2V and an offset of 2.5V. The signal on ADC1, which is delayed with respect to the signal on ADC0 by a 300 phase-lag, has an amplitude of 1V and an offset of 2.5V. Observe the printed voltages on Proteus’s virtual terminal. Plot these waveforms on Excel to verify the functionality of your code.

> Replace **_Lab4_Images/plot.png_** with image of your plot (adjust width as needed)

<img width="829" alt="Screen Shot 2021-09-24 at 1 30 35 PM" src="https://user-images.githubusercontent.com/79814779/134615854-8a6d4673-2c79-40b8-86f3-5f6293c4c0c1.png">


## Part 5: Calculating Power

Q 5.1: Let us assume that both the voltage and current are sinusoidal signals with the same time period. If the ADC is supplied with a 125kHz clock, how much of a time-delay would there be between two consecutive ADC0 and ADC1 samples?

> Time delay = 1/125kHz x 13.5. (1/frequency x clock cycle times)

## Optional Task: Implementing Power Calculation

Q O.1: Modify your C program to implement your chosen method for calculating power, and print the results through to the terminal. Compare these results to your theoretical result obtained in Q5.2 – how much difference is there? Where does this difference come from?

> Add answer here 

Q O.2: Note that the design specifications limit the rate at which you can take ADC readings to a maximum of 10kHz (i.e., ADC conversion rate). This means we can’t take as many ADC readings as we would like to. In the code you have developed so far, you are using a 125kHz ADC clock and operating it in the single conversion mode. At what rate are currently taking ADC readings? How can you verify that you are taking an ADC reading at this theoretical rate you calculated? How would you increase the rate at which you take ADC samples?

> Add answer here 

Q O.3: What could be an advantage of operating the microcontroller at a lower clock frequency and taking fever ADC samples?

> Add answer here 

Q O.4: In Q4.4 why did we first store the ADC values in to two arrays and only sent them over UART once all 100 samples were collected? Can we not send the ADC values over UART as we read them from the ADC?

> Add answer here 

