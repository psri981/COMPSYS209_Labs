<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Answer Sheet - Lab 1

## Part 1: Revising Basics 

Q 1.1: Determine the load current (IL), load voltage (VL), and power delivered to the load (PL).

> IL: 0.5A
> VL: 7V
> PL: 3.5W

Q 1.2: After predicting how the circuit should behave theoretically, you should now simulate the circuit in LTspice and validate your theoretical analysis. Use the LTspice model provided to you (labelled Part 1A).

| Parameter             | Theoretical Value    | Simulated Value      | 
| ----------------------|----------------------|----------------------|
| IL                    | 0.5A                 | 0.5A                 |
| VL                    | 7V                   | 7V                   |
| PL                    | 3.5W                 | 3.5W                 |

> Comments (state if results match/differ): 
  Theoretical and simulated values match.
  
Q 1.3: What would be an appropriate “Maximum Timestep” and “Stop Time” to be used for this simulation?	

> Time Step (assuming 1/20th of the period of 500 Hz):
  0.0001s
  
> Stop Time (assuming we’d like to capture 200 cycles):
  0.4s

Q 1.4: Calculate the theoretical load current (IL(RMS)), load voltage (VL(RMS)), peak instantaneous power (PL(t)), and average power delivered by the source (Pin) for the circuits shown above. Simulate these circuits in LTspice using the models provided (labelled Part 1B-1D) and compare with the theoretical results.

> Circuit with Resistor

| Parameter             | Theoretical Value    | Simulated Value      | 
| ----------------------|----------------------|----------------------|
| IL(rms)               | 1.12A                | 1.10A                |
| VL(rms)               | 14V                  | 13.936V              |
| Peak PL(t)            | 31.36W               | 31.36W               |
| Pin                   | 15.68                | 15.354mW             |

> Circuit with Inductor

| Parameter             | Theoretical Value    | Simulated Value      | 
| ----------------------|----------------------|----------------------|
| IL(rms)               | 1.11A                | 1.53A                |
| VL(rms)               | 14V                  | 13.935V              |
| Peak PL(t)            | 15.48W               | 39.53W               |
| Pin                   | 0W                   | 15.115mW             |

> Circuit with Capacitor

| Parameter             | Theoretical Value    | Simulated Value      | 
| ----------------------|----------------------|----------------------|
| IL(rms)               | 1.11A                | 1.1A                 |
| VL(rms)               | 14V                  | 17.794V              |
| Peak PL(t)            | 15.5W                | 32.67W               |
| Pin                   | 0W                   | 18.632W              |

Q 1.5: How can we minimise the granularity of simulation points and improve the accuracy? What would be a drawback of doing so?

> To minimise the granularity and improve accuracy we can decrease the time step from 1/20th of the period with the highest frequency to a much smaller percentage e.g. 1/50th.
  The drawback of a very small time step is a longer processing time making the simulation loading time longer.
  
Q 1.6: Lets add a 0.2 Ohm resistor in series with the inductor and a 790 Ohm resistor in parallel with the capacitor to help the two circuits reach steady-state conditions faster. What is the time-constant of each circuit? Will your simulation reach steady-state well before the “Stop Time” you have defined? (i.e. is the “Stop Time” larger than 5 times the time constant?)

> Time constant of circuit with 4mH inductor:
  0.02s
  
> Time constant of circuit with 25.3uF capacitor:
  0.02s
  
> Would simulation reach steady-state:
  Yes, because the time constants are very small therefore the simulate should read steady-state. 
  
Q 1.7: Modify the simulation as per Q1.6 and run it. Compare the simulation results you obtained from the modified circuits to show that they somewhat agree with the theoretical predictions. You can further improve the accuracy of your simulations by reducing the “Maximum Timestep” and/or reducing the impact on the circuit due to the resistive element you added. However, this will be at the expense of simulation time.

> Circuit with Inductor

| Parameter             | Simulated Value      | 
| ----------------------|----------------------|
| IL(rms)               | 1.14A                |
| VL(rms)               | 13.993V              |
| Peak PL(t)            | 15.5W                |
| Pin                   | -275.2mW             |

> Circuit with Capacitor

| Parameter             | Simulated Value      | 
| ----------------------|----------------------|
| IL(rms)               | 1.11A                |
| VL(rms)               | 14.302V              |
| Peak PL(t)            | 15.41W               |
| Pin                   | -272.52mW            |

> Comments (state observation when experimenting with “Maximum Timestep”):
  At first I changed the time step to 0.0000001s but when simulating the simulation took a long time to load. I then changed the time step to 0.000001s which was much faster and shows slightly less groves on the waves than the initial time step of 0.0001s giving more accurate answers similar to the theoretical numbers.
  
## Part 2: Modelling Your AC Load

Q 2.1: As stated in your design specifications, the AC voltage supplied by the power supply across the AC load is going to be between 12.6Vrms and 15.4Vrms. The AC load is going to be set to draw 2.5VA-7.5VA regardless of the AC voltage supplied to it. What is the maximum and minimum current you expect to measure? What is the maximum and minimum AC voltage you expect to measure?

> Maximum RMS load voltage:
  15.4V
> Minimum RMS load voltage:
  12.6V
> Maximum RMS load current:
  0.6A
> Minimum RMS load current:
  0.16A

Q 2.2: Assume that the viper on the variable resistor is set somewhat closer to the lowest resistance position, and therefore RL is 25 Ohm. We are also assuming that L is 4mH and Vac is 14Vrms in this specific example. Note that these numbers are chosen as an example load setting we may test your circuit at. Using circuit theory, determine the RMS load current as well as the real, reactive, and apparent power consumed by the load. Verify answers using the LTspice model provided (labelled Part 2).

| Parameter             | Theoretical Value    | Simulated Value      | 
| ----------------------|----------------------|----------------------|
| Load current IL(rms)  | 0.5A                 | 0.5A                 |
| Real power (W)        | 6.26W                | 6.26W                |
| Reactive power (VAR)  | 3.14VAR              | 3.13VAR              |
| Apparent power (VA)   | 7VA                  | 6.8VA                |

> Comment (state if results match/differ and why):
  Results of the theoretical and simulated values are very similar.

Q 2.3: Similarly, calculate and simulate the RMS load current, real, reactive, and apparent power if the viper position is changed to increase RL to 75 Ohm (i.e. closer to the highest resistance position)? Again, these numbers are chosen as an example setting we may test your circuit at (note that L is 4mH and Vac is 14Vrms).

| Parameter             | Theoretical Value    | Simulated Value      | 
| ----------------------|----------------------|----------------------|
| Load current IL(rms)  | 0.18A                | 0.18A                |
| Real power (W)        | 2.43W                | 2.54W                |
| Reactive power (VAR)  | 0.41VAR              | 0.42VAR              |
| Apparent power (VA)   | 2.4VA                | 2.6VA                |

> Comment (state if results match/differ and why):
  Theoretical and Simulated results are very similar, possibly due to increased accuracy from smaller stop time.

## Part 3: Sensing AC Load Current

Q 3.1: Determine the value of the shunt resistor suitable to measure the current flowing through the AC load used in your project. Note that you have already calculated the minimum and maximum currents to be measured in Q2.1. Limit the maximum power dissipation in the shunt resistor to 200mW. 

> Shunt Resistor (Rs):
  0.56ohms

Q 3.2: Using the simulation model given (labelled Part 3 & 4), verify that you have calculated the correct shunt resistor value in Q3.1. You can validate the design by changing load resistance/supply voltage to vary the VA drawn by the AC load, while keeping it within 7.5VA to 2.5VA and observing peak amplitude of sensed voltage (Vis(pk)) as well as the power dissipated in the shunt resistor (Pis).

> Summarise key findings (theoretical vs simulated) in table below. Here we are analysing circuit under 3 possible scenarios including the two extreme cases (i.e. minimum and maximum load current). We are assuming that L is exactly 4mH and RL is changed to simulate varying load conditions.

| Source VA  | Vac(rms) | RL       | IL(rms)  | Vis(pk) Theo | Vis(pk) Sim  | Pis Theo | Pis Sim  |
| -----------|----------|----------|----------|--------------|--------------|----------|----------|
| 7.5VA      | 12.6V    | 16.26ohms| 0.6A     | 0.475V       | 0.49V        | 0.29W    | 0.201W   |
| 7.5VA      | 15.4V    | 28.46ohms| 0.49A    | 0.39V        | 0.38V        | 0.19W    | 0.13W    |
| 2.5VA      | 15.4V    | 94.87ohms| 0.16A    | 0.13V        | 0.13V        | 0.02W    | 0.01W    |

> Comments (state if Pis is kept below 200mW under all conditions):
  Pis Theo for the first source in the table was calculated to be greater than 200mW though this may be due to rounding too early in my calculations as the simulated value is extremely close to 200mW. All other conditions Pis is kept below 200mW. It is interesting that Pis Simulated values is lower than all Pis Theoretical, which once again may be down to rounding too early in theoretical calculations.

Q 3.3: Using table below, compare the advantages and disadvantages of using a bigger vs a smaller shunt resistor than the one in Q3.1? Based on this comparison, what specific value will you use as the shunt resistor in your project? Will you use the value calculated in Q3.1 or a different value? Justify your selection.

| Parameter             | Bigger Rs Value      | Smaller Rs Value     | 
| ----------------------|----------------------|----------------------|
| SNR                   | High                 | Low                  |
| Dissipation (Pis)     | High                 | Low                  |
| Size                  | High                 | Low                  |
| Cost                  | High                 | Low                  |

> Shunt resistor (Rs) to be used in your design:
  0.5ohms.  
> Justification:
  Use a resistor that is 0.5ohms to keep the Power dissipation below 200mW and because 0.56ohms resistor does not exist in the E12 series. 

## Part 4: Sensing AC Source Voltage

Q 4.1: Determine the values of the voltage divider resistors suitable for measuring the input voltage supplied by the AC source. Note that you have already calculated the minimum and maximum input voltages to be measured in Q2.1. The voltage divider should step down the maximum load voltage to about 2Vpk-pk so that it can be processed by the signal conditioning circuit and fed to an ADC channel of the microcontroller. Make sure to pick E12 resistor values from the ROYALOHM MF006JJ metal film resistor series.

> Voltage divider resistors (Ra and Rb):
  Ra = 220kohms Rb = 10kohms

Q 4.2: Using the simulation model given (labelled Part 3 & 4), verify that you have calculated the correct voltage divider resistor values in Q4.1. You can validate the design by changing the load resistance/supply voltage to vary the VA drawn by the AC load, while keeping it within 7.5VA to 2.5VA and observing peak amplitude of sensed voltage (Vvs). It is also good to check the total power dissipated in the resistors (Pvs).

> Summarise the key findings (theoretical vs simulated) in table below. Here we are analysing the circuit under 3 possible scenarios including the two extreme cases (i.e. minimum and maximum input voltage). We are assuming that L is exactly 4mH and RL is changed to simulate varying load conditions.

| Source VA  | Vac(rms) | RL       | IL(rms)  | Vvs(pk) Theo | Vvs(pk) Sim  | Pvs Theo | Pvs Sim  |
| -----------|----------|----------|----------|--------------|--------------|----------|----------|
| 7.5VA      | 12.6V    | 16.26ohms| 0.6A     | 0.78V        | 0.774V       | 30uW     | 30uW     |
| 7.5VA      | 15.4V    | 28.46ohms| 0.49A    | 0.96V        | 0.946V       | 45uW     | 45uW     |
| 2.5VA      | 15.4V    | 94.87ohms| 0.16A    | 0.96V        | 0.946V       | 45uW     | 45uW     |

> Comments (state if 2Vpk-pk is met and Pvs is acceptably low):
  Pvs is acceptably low and 2Vpk  - pk is met.

Q 4.3: Using table below, compare the advantages and disadvantages of using resistors for your voltage divider in the Ohms vs Kilo-Ohms vs Mega-Ohms range. Based on this comparison, what specific values will you use in the voltage divider? Will you use the values calculated in Q4.1 or different values? Justify your selection.

| Parameter             | Ohms        | Kilo-Ohms   | Mega-Ohms   |
| ----------------------|-------------|-------------|-------------|
| SNR                   | low         | high        | high        |
| Dissipation (Pis)     | low         | high        | high        |
| Sensitivity           | high        | low         | low         |

> Voltage divider resistors (Ra and Rb) to be used in your design:
  Ra = 220k Rb = 10k
  
> Justification:
  Because the specifications are met with using kilo-ohm resistor values from the E12 series we will use kilo-ohm resistors in our design.

## Optional Task: Practical Thoughts

Q O.1: Assume that you have decided to use two 1 Ohm ROYALOHM MF006JJ series metal film resistors in parallel as the shunt resistor (Rs). As shown in the datasheet, the resistors have a tolerance of +/-5% and a temperature coefficient of +/-200ppm/°C (measured from 20°C). What are the worst-case minimum and maximum values of your current shunt? Note that your energy monitor will be designed to operate in a 10°C to 40°C ambient temperature. State all assumptions you made. Also, comment on the expected measurement accuracy based on the minimum and maximum shunt resistance values calculated.

> Minimum Rs:                   (observed when 					)

> Maximum Rs:                   (observed when 					)

> Assumptions: 

> Expected Accuracy:
