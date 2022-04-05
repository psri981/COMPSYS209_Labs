<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Answer Sheet - Lab 2

## Part 1: Differential Amplifiers 

Q 1.1: Analyse the OpAmp circuit in the figure above using your theoretical knowledge and sketch the theoretically expected output voltage waveform (Vop(out)). Simulate this circuit on LTspice using the model provided (labelled Part 1A) and verify your theoretically obtained results. Note that the LM324.lib has to be in the same folder as the LTspice simulation file, as we call this  LM324 OpAmp model from within LTspice.

> Transfer function of Vop(out) : Vop(out) = Vsens(pk) x (R2/R1) = 0.1V x (10k/1k) = 1V

> Replace **_Lab2_Images/1Q1Theory.png_** with your theoretical sketch

<img src="Lab2_Images/IMG_445725304FC3-1.jpeg" height="400"> 

> Replace **_Lab2_Images/1Q1Sim.png_** with your simulated waveform

<img src="Lab2_Images/Q1.1Simulated.png" height="400">

Q 1.2: Why is your theory and simulation showing that the output is distorted/clipped (i.e., the output is not an exactly amplified AC waveform)?  

> The waveform is distorted because the amplifier attempts to deliver a voltage that cannot go below 0V. The wave form is pushed to stay above 0V because it is restricted to stay within 0V to 5V.

Q 1.3: Based on the LM324 datasheet provided on Canvas, what is the maximum output voltage an LM324 can produce when it is supplied by a single-rail 5V source? In the datasheet this is usually referred to as the “High-level output voltage” or VOH. This would change with operating temperature and the current supplied through the output pin of the OpAmp (i.e. the load supplied by the OpAmp). Assume 25 degrees C and a 2kOhm load. Can the simulation model mimic this behaviour? To check this, increase the amplitude of the signal labelled Vsens (in the simulation model provided this is set by the AC source V3 found in the section labelled Power/Signal sources) to 0.5V. See if the high-level output voltage of the OpAmp circuit clips close to the level indicated in the datasheet.

> From datasheet VOH when OpAmp supplied by 5V: 3.5V

> VOH observed in simulation: 3.5V

Q 1.4: Based on the plot provided above, what is the minimum output voltage an LM324 can produce when it is supplied by a single-rail 5V source? Assume that the LM324 has to sink 1mA. 

> Minimum VOL from plot: 0.7V

Q 1.5: Analyse the OpAmp circuit in the figure above using your theoretical knowledge and sketch the theoretically expected output voltage waveform (Vop(out)). Simulate this circuit on LTspice using the model provided (labelled Part 1B) and verify your theoretically obtained results.

> Transfer function of Vop(out): V'op(out) + V"op(out) = 2.1 + Vsens x (R2/R1) = 2.1 + 0.1 x (10k/1k) = 3.1V

> Replace **_Lab2_Images/1Q5Theory.png_** with your theoretical sketch

<img src="Lab2_Images/Q1.5CorrectTheoretical.jpg" height="400"> 

> Replace **_Lab2_Images/1Q5Sim.png_** with your simulated waveform

<img src="Lab2_Images/Q1.5Simulated.png" height="400">

## Part 2: Conditioning Current Measurement

Q 2.1: Determine the resistor values R1 and R2 required to produce an output voltage signal (Vio) that has an offset of 2.1V and a peak-peak voltage of 2V when the AC load current is a maximum. Make sure to select resistors from the E12 series. The value of the shunt resistor (Rs) should be what you determined in Q3.4 of Lab 1. Note that you have already calculated and validated the minimum and maximum values of IL as well as Vis in Lab 1. So, refer to lab 1 to extract this information.

> R1: 33k

> R2: 68k

Q 2.2: Modify the simulation model provided (sections of the model labelled ‘Part 2’ and ‘AC Source, Load and Sensors’) to verify that you have calculated the correct resistor values in Q2.1. As you did in Lab 1, you can validate the design by changing load resistance/supply voltage to vary the VA drawn by the AC load, while keeping it within 7.5VA to 2.5VA and observing the sensed voltage (Vis) as well as the output voltage (Vio).

> Summarise key findings (theoretical vs simulated) in the table below. Here we are analysing the circuit under 3 possible scenarios, including the two extreme cases (i.e. minimum and maximum load current). We are assuming that L is exactly 4mH and RL is changed to simulate varying load conditions. You should extract the values you have calculated in Lab 1 (Q3.2) to complete part of this table.

| Source VA  | Vac(rms) | RL       | IL       | Vis,pk Theo | Vis,pk Sim  | Vio,pk Theo | Vio,pk Sim  |
| -----------|----------|----------|----------|-------------|-------------|-------------|-------------|
| 7.5VA      | 12.6V    | 16.26ohms| 0.6A     | 0.475V      | 0.49V       | 3.08V       | 3.01V       |
| 7.5VA      | 15.4V    | 28.46ohms| 0.49A    | 0.39V       | 0.38V       | 2.88V       | 2.81V       |
| 2.5VA      | 15.4V    | 94.87ohms| 0.16A    | 0.13V       | 0.13V       | 2.37V       | 2.33V       |

> Comments (state if OpAmp output may clip or not): The OpAmp output will not clip because the voltage is within the constraints. This is because the peak voltage does not exceed 3.5V and the amplitude does not exceed 1V.

Q 2.3: What will happen if the corresponding resistor pairs of the differential amplifier are not equal to each other (e.g. R1 in each arm differ slightly from each other)? 

> If the resistors are different in value, they cannot cancel out to give the correct transfer function. Therefore, instead of level shifting by 2.1V we will be amplifying the input which is not what we want.

Q 2.4: What could you do to improve the accuracy of current measurement under light loads? Under light load IL reach the minimum current load current you determined during Lab 1. Since the differential amplifier gain is fixed, Vio can be quite small.

> PCB wires (traces) have imperfections such as inductance and resistance, therefore in order to improve the accuracy of current measurement under light loads we should decrease the length of the PCB wires to minimise imperfections. 

## Part 3: Conditioning Voltage Measurement

Q 3.1: Determine the resistor values R1a, R1b, and R2 required to produce an output voltage signal that has an offset of 2.1V and a peak-peak voltage of about 2Vpk-pk when the AC source voltage is a maximum. Make sure to select resistor values from the E12 series. The values of the voltage divider resistors (Ra and Rb) are what you determined in Q4.3 of Lab 1. Note that you have already calculated and validated the minimum and maximum values of Vvs in Lab 1. So, refer to Lab 1 to extract this information.

> R1a: 47k

> R1b: 56k

> R2: 56k

Q 3.2: Modify the simulation model provided (sections of the model labelled ‘Part 3’ and ‘AC Source, Load and Sensors’) to verify that you have calculated the correct resistor values in Q3.1. As you did in Lab 1, you can validate the design by changing supply voltage (within the specified range) and observing the sensed voltage (Vvs) as well as the output voltage (Vvo). 

> Summarise key findings (theoretical vs simulated) in the table below. Here we are analysing the circuit under 3 possible scenarios including the two extreme cases (i.e. minimum and maximum AC voltage). We are assuming that L is exactly 4mH and RL is changed to simulate varying load conditions. You should extract the values you have calculated in Lab 1 (Q4.2) to complete part of this table.

| Source VA  | Vac(rms) | RL       | IL       | Vvo,pk Theo | Vvo,pk Sim  |
| -----------|----------|----------|----------|-------------|-------------|
| 7.5VA      | 12.6V    | 16.26ohms| 0.6A     | 2.87V       | 2.88V       |
| 7.5VA      | 15.4V    | 28.46ohms| 0.49A    | 3.05V       | 3.05V       |
| 2.5VA      | 15.4V    | 94.87ohms| 0.16A    | 3.05V       | 3.05V       |

> Comments (state if OpAmp output may clip or not): The OpAmp output will not clip because the voltage is within the constraints. This is because the peak voltage does not exceed 3.5V and the amplitude does not exceed 1V.

Q 3.3: State why Vvs has an offset (i.e. it is not a pure AC waveform) once you connect the voltage divider with the differential amplifier? 

> This is because an ideal opamp tries to keep both input voltages equal. When one input voltage is greater than the other, there will be an offset that makes both voltages output to zero. As there is a voltage coming in (V<sub>vs</sub>) through 2 resistors (R<sub>a</sub> and R<sub>b</sub>), this means that the current flowing into the differential amplifier is dependant on the resistors connected to the opamp.

Q 3.4: When selecting the resistors for your differential amplifier circuits, would you pick them to be in the Ohms, Kilo-Ohms, or Mega-Ohms range? State issues relating to using resistor values that are too small (Ohms) or too large (Mega-Ohms).

> Reasons not to use very small resistor values (e.g. Ohms): If the resistor value is too low then there will be a low SNR. There will also be high sensitivity to external factors such as humidity and human touch.

> Reasons not to use very large feedback resistor values (e.g. Mega-Ohms): If the resistor value is too large then there will be high power dissipation and the overall device will be more expensive.

Q 3.5: Assume that LM324 OpAmps become unavailable (products get discontinued very often in real life) and you had to order a different OpAmp. What device parameters would you need to consider? Is there a minimum and/or maximum rating for each of these parameters that need to be observed? Complete the following table – we have given you an example.

| Parameter                     | Max and/or Min Specification    |
| ------------------------------|---------------------------------|
| Single rail supply voltage    | Min rating < 5V < Max rating    |
| Gain bandwidth product (GBP)  | Min rating > 1.3                |
| Slew rate                     | Min rating > 0.5                |
| Total Harmonic distortion     | Min rating > 0.015              |
| Equivalent input noise voltage| Min rating > 40                 |
| Input offset current          | 20V < Max rating                |

## Part 4: Filters

Q 4.1: Derive the transfer function (Vfilter/VOpAmp) of the RC filter shown above to show that it functions as a 1st order low-pass filter. Determine the values of Cf and Rf required to ensure a -3dB cut-off frequency of 10kHz. Note that, the AC sources is expected to generate a significantly strong noise components at frequencies 100kHz and beyond. As such, it is a good decision to place the filter cut-off frequency at 10kHz, which is significantly lower than noise frequency but still considerably higher than the 500Hz signal frequency.

> Transfer function Vfilter/VOpAmp: |H(w)| = 1/(sqrt(1+(w<sup>2</sup>R<sup>2</sup>C<sup>2</sup>)))

> Cf and Rf: Cf = 0.0159uF R = 1k

Q 4.2: Sketch the theoretically expected output voltage waveform (Vfilter) of the RC filter if the input is a 2Vpk-pk AC signal that has an offset of 2.1V. Modify the simulation model provided by editing Cf and Rf values as per Q4.1 (section of the model labelled ‘Part 4’) and verify your theoretically obtained results. 

> Replace **_Lab2_Images/4Q2Theory.png_** with your theoretical sketch

<img src="Lab2_Images/Q1.5CorrectTheoretical.jpg" height="400"> 

> Replace **_Lab2_Images/4Q2Sim.png_** with your simulated waveform

<img src="Lab2_Images/Q4.2Simulated.png" height="400">

Q 4.3: Sketch the theoretically expected bode magnitude and phase plots of the filter transfer function (Vfilter/VOpAmp). Using AC analysis option provided in LTspice, simulate the frequency response of the RC filter circuit (section of the provided model labelled ‘Part 4’) and verify your theoretically obtained results. To assist, the simulation command required is provided in the comments under ‘Simulation Commands’.

> Replace **_Lab2_Images/4Q3Theory.png_** with your theoretical sketch

<img src="Lab2_Images/Q4.3CorrectTheoretical.jpg" height="400"> 

> Replace **_Lab2_Images/4Q2Sim.png_** with your simulated waveform

<img src="Lab2_Images/Q4.3Simulated.png" height="400">

Q 4.4: What will be the impact of shifting the filter cut-off frequency closer to 500Hz or 100kHz? Validate your answer using LTspice.

> A cut-off frequency closer to 500Hz results in: A higher cut off frequency allows higher ranged noise frequencies to pass through.

> A cut-off frequency closer to 100kHz results in: A lower cut off frequency allow low frequencies below 0 to pass through.

## Part 5: DC Regulator Circuit

Q 5.1: The smoothing capacitor Cs in the regulator circuit above is selected in order to make sure the voltage ripple at the input (dVin) to the regulator is acceptable. Note that the worst case line regulation of the LT1085 regulator IC according to the datasheet is 0.5%. Thus, a certain dVin will result in an output ripple of dVin x 0.5%. If Cs is chosen to be 47uF, stating your assumptions, determine the approximate value of dVin. Simulate the operation of regulator circuit using the LTspice model provided (labelled ‘Part 5’) and verify your answer.

> Assumptions:  τ<sub>2</sub> << τ<sub>2</sub> and τ<sub>1</sub> approximates to τ<sub>g</sub>

> Theoretical dVin: 2.128s

> Simulated dVin: 2.38s

Q 5.2: On LTspice, observe Vac and Ireg waveforms, and sketch them here. State why the current waveform looks like short-duration bursts.

> Replace **_Lab2_Images/5Q2Sim.png_** with your simulated waveform

<img width="400" alt="Screen Shot 2021-08-10 at 6 45 07 PM" src="https://user-images.githubusercontent.com/79814779/128820697-df60b687-e990-4553-a912-5e8de4c7f398.png">


> Ireg looks like short-duration bursts because: Ireg looks like it has short-duration bursts because of the diode switching between conducting and blocking states when Vac is as low as 0.7V. 

Q 5.4: What are the benefits and disadvantages of using a half-wave rectifier opposed to a full-wave rectifier in your design?

> Advantages of a half-wave rectifier: Low cost, simpler circuit and easy to construct.

> Disadvantages of a half-wave rectifier: Lower output voltage, harder to provide smoothing as a result of using the ripple frequency and lower efficiency.

Q 5.5: How can you derive the 2.1V offset required for the differential amplifiers from the 5V DC supply that you just designed? Sketch a suitable circuit, simulate and verify the answer. Hint: Using just a simple voltage divider is not the best solution. You need extra circuitry in addition to the voltage divider to derive a stable and clean 2.1V signal.

> Replace **_Lab2_Images/5Q4Circuit.png_** with your circuit diagram

![IMG_5322](https://user-images.githubusercontent.com/79814779/128965891-88a42117-5463-4c20-adbc-d206d6115f4f.jpg)

