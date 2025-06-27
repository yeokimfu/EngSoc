![image](https://github.com/user-attachments/assets/69292e0c-9c15-4d2f-a624-2097c3750796)#Simulation of Automatic Gate using Wokwi

Step 1: Open Wokwi
- Go to: https://wokwi.com
- Click “New Project” > Choose ESP32 Project
  
![image](https://github.com/user-attachments/assets/36380c92-2763-4cec-bc4d-db8ecb6011bc)

- Choose the ESP32 Starter Templates

![image](https://github.com/user-attachments/assets/86fe279c-4aac-4165-8e59-5fe369abf9cf)


Step 2: Add the Components
Click the purple “+” button and add these parts:

![image](https://github.com/user-attachments/assets/8802717d-e979-474f-ac85-033000d132ea)

- 1x ESP32 Dev Board
- 1x Ultrasonic Sensor (HC-SR04)
- 1x Servo Motor
- 1x LED
- 1x Resistor (220 ohms) for the LED

Step 3: Wire the Circuit

![image](https://github.com/user-attachments/assets/7f6b1ae5-a1f6-4562-b594-53001a98441d)

Step 4: Copy and Paste the Code
- Paste the code from AutomaticGate.ino into the left side window of Wokwi

![image](https://github.com/user-attachments/assets/b7a7e235-3cbd-4b2e-8402-fb287904b3eb)


Step 5: Run the Simulation
- Press the green ▶️ “Start Simulation” button at the top left corner.
- A virtual car/object will appear in front of the sensor — this mimics a real vehicle.
- If the object is within 10 cm, the servo motor opens the gate, and the LED lights up.
- After 2 seconds of no object detected, the gate automatically closes.

