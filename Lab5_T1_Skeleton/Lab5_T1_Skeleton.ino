/*Change all the ? in the code and add code in ??? to Control the speed of rotation.*/

#define IN1   27  // Replace the ? with the GPIO pin you selected to connect IN1
#define IN2   32   // Replace the ? with the GPIO pin you selected to connect IN2
#define A  34 // Replace the ? with the GPIO pin you selected to connect encoder A
#define B  35 // Replace the ? with the GPIO pin you selected to connect encoder B
#define PWM 14  // Replace the ? with the GPIO pin you selected to output PWM

int A_data=0;
int B_data=0;

String command;

void setup() {
  /*setup baud and pin mode */
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  pinMode(PWM,OUTPUT);
  Serial.begin(115200);
  /*Set a rotation direction*/
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}

void loop() {
   
    if (Serial.available() > 0) {
        command = Serial.readStringUntil('\n'); // Read the incoming command
        command.trim(); // Remove any leading or trailing whitespace
        if (command == "0") {
        // output PWM signals with 0% duty cycle
        analogWrite(PWM,0.0f/255.f);  
        } 
        else if (command == "25") {
        // output PWM signals with 25% duty cycle
        analogWrite(PWM,0.25f*255.f);   
        }
        else if (command == "50") {
        // output PWM signals with 50% duty cycle
        analogWrite(PWM,0.5f*255);   
        }
        else if (command == "75") {
        // output PWM signals with 75% duty cycle
        analogWrite(PWM,0.75f*255);   
        }
        else if (command == "100") {
        // output PWM signals with 100% duty cycle
        analogWrite(PWM,255);   
        }
        Serial.print("PWM Set successfully");
        delay(200);
        }
    // Read values of A and B
       A_data=digitalRead(A);
       B_data=digitalRead(B);
    // Plot A B in Serial Plotter
       Serial.print("A:");
       Serial.println(A_data);
       Serial.print("B:");
       Serial.println(B_data);
    
}
