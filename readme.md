# Infant Incubator

This code is a basic product for an infant incubator that measures the infant's temperature, heart rate, and color to detect if they have jaundice.

## Components Used
- **DHT11 Sensor**: Measures temperature and humidity.
- **Pulse Sensor**: Measures heart rate.
- **Color Sensor**: Detects color changes.
- **Buzzer**: Provides audible alerts.
- **Relay**: Controls the heating element of the incubator.

## Setup
- **DHT Sensor**: Connected to analog pin A1.
- **Pulse Sensor**: Connected to analog pin 0.
- **Color Sensor**: Connected to pins S0-S3 and sensorOut.
- **Buzzer**: Connected to digital pin 13.
- **Relay**: Connected to digital pin 9.

## How It Works
- The DHT sensor measures temperature and humidity. If the temperature is less than or equal to 37°C, the relay is turned on to activate the heating element, and the buzzer emits a sound.
- The Pulse Sensor detects the heart rate. If the signal exceeds the threshold, LED13 lights up.
- The Color Sensor detects changes in color. It measures if the infant has jaundice or not.
- Sensor readings, including heart rate, temperature, humidity, and color pulse widths, are outputted through the serial monitor.
- If the detected color indicates jaundice (predominantly yellow), an additional alert is triggered through the buzzer.

## Libraries Used
- **DHT**: Library for the DHT sensor.
- **Wire**: Library for I2C communication.
- **DHT.h**: Header file for DHT sensor library.

## Usage
1. Connect the components as per the setup instructions.
2. Upload the code to the microcontroller.
3. Monitor the serial output for real-time readings.
4. Ensure appropriate actions are taken based on the readings, especially if jaundice is detected.

## Note
- This is a basic implementation. For educational medical purposes only.

## Author
- Mohamed Hazem Yahya

Feel free to contribute or modify the code to suit your specific requirements and improve its functionality.
