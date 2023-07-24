# Fan-Controller
-a fan controller system is a temperature-controlled fan using ATmega32 microcontroller, in which the fan is automatically turned ON or OFF according to the 
temperature. 
-System frequency is 1Mhz
Used Drivers:
1.ADC (internal reference voltage 2.56 voltage and Prescaler F_CPU/8).
2.LM35 Temperature Sensor (ADC channel 2).
3.LCD (8-Bits Data Mode).
4.L293D Motor Driver.
5.Timer0 (PWM Mode ).

-How it works:
1-the LM35 temperature sensor will give continuous analog output corresponding to the temperature sensed by it. This analog signal is given to the ADC, which converts the analog values to digital values.
2-then perform some calculations in the programming for the microcontroller to get the temperature from the sensed analog voltage.
3-The microcontroller will continuously monitor the temperature and based on the temperature value, the microcontroller will drive the fan like that:

 a. If the temperature is less than 30C turn off the fan.

 b. If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed. 

c. If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed. 

d. If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed.

e. If the temperature is greater than or equal 120C turn on the fan with 100% of its maximum speed.
*The LCD displays the temperature value and the fan state continuously*
4-The DC-Motor rotates in clock-wise direction or stopped based on 
the fan state.
