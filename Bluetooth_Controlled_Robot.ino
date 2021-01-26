#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
#define ENA 6 //left motor
#define ENB 11 //right motor

char junk;
String inputString="";

void setup()                    // run once, when the sketch starts
{
 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 125); //left motor
  analogWrite(ENB, 100); //right motor
}

void loop()
{

  // a => forward  b=> reverse  c=> FR   d=> FL

  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear the serial buffer
    analogWrite(ENA, 125); //left motor
    analogWrite(ENB, 100); //right motor
    
    if(inputString == "a"){         // Moving Robot Forward
      digitalWrite(IN1, HIGH); //left motor
      digitalWrite(IN2, LOW); //left motor
    
      digitalWrite(IN3, HIGH); // right motor
      digitalWrite(IN4, LOW); // right motor  
      delay(500);
    }
    else if(inputString == "b"){   //Moving Robot reverse
      digitalWrite(IN1, LOW); //left motor
      digitalWrite(IN2, HIGH); //left motor
    
      digitalWrite(IN3, LOW); // right motor
      digitalWrite(IN4, HIGH); // right motor
      delay(500);
    }
    else if(inputString == "c"){   //Move forward then turn left
      digitalWrite(IN1, HIGH); //left motor
      digitalWrite(IN2, LOW); //left motor
    
      digitalWrite(IN3, HIGH); // right motor
      digitalWrite(IN4, LOW); // right motor  
      delay(500);
      
      digitalWrite(IN1, LOW); //left motor
      digitalWrite(IN2, LOW); //left motor
      delay(400);

      digitalWrite(IN1, HIGH); //left motor
      digitalWrite(IN2, LOW); //left motor
    
      digitalWrite(IN3, HIGH); // right motor
      digitalWrite(IN4, LOW); // right motor  
      delay(500);
    }
    else if(inputString == "d"){   //move forward then turn right
       digitalWrite(IN1, HIGH); //left motor
      digitalWrite(IN2, LOW); //left motor
    
      digitalWrite(IN3, HIGH); // right motor
      digitalWrite(IN4, LOW); // right motor  
      delay(500);
       
       digitalWrite(IN3, LOW); // right motor
       digitalWrite(IN4, LOW); // right motor
       delay(400);

       digitalWrite(IN1, HIGH); //left motor
      digitalWrite(IN2, LOW); //left motor
    
      digitalWrite(IN3, HIGH); // right motor
      digitalWrite(IN4, LOW); // right motor  
      delay(500);
    }

      digitalWrite(IN1, LOW); //left motor
      digitalWrite(IN2, LOW); //left motor
    
      digitalWrite(IN3, LOW); // right motor
      digitalWrite(IN4, LOW); // right motor
    inputString = "";
  }
}
