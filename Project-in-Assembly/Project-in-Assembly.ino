
   int motorA1;  
   int motorA2;  
   int motorB1; 
   int motorB2;  
   int BTState;
   int state;     // for checking conditions
   int vspeed;     // Default speed, from 0 to 255
   int aportnum;
   int aportnum1;
   int fullspeed;

void assign()
{
   asm volatile ( "" : "=a" (motorA1)   : "a" (7));
   asm volatile ( "" : "=a" (motorA2)   : "a" (8));
   asm volatile ( "" : "=a" (motorB1)   : "a" (13));
   asm volatile ( "" : "=a" (motorB2)   : "a" (12));
   asm volatile ( "" : "=a" (aportnum)  : "a" (9));
   asm volatile ( "" : "=a" (aportnum1) : "a" (10));
   asm volatile ( "" : "=a" (BTState)   : "a" (2));
   asm volatile ( "" : "=a" (vspeed)    : "a" (150));
   asm volatile ( "" : "=a" (fullspeed) : "a" (250));
}



void setup() {
    // Set pins as outputs:

    assign();
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    pinMode(aportnum,OUTPUT);
    pinMode(aportnum1,OUTPUT);
    pinMode(BTState, INPUT);
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);


}


 
void loop() {
 //Stop car when connection lost or bluetooth disconnected
     if(digitalRead(BTState)==LOW) { state='S'; }

  //Save income data to variable 'state'
    if(Serial.available() > 0)
    {
      state = Serial.read();   
    }
  
  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') 
    {
        asm volatile ("lds r24, (aportnum)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (aportnum1)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22");                 
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (motorB1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
    }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', car will go forward left
    else if (state == 'G') 
    {
      asm volatile ("lds r24, (aportnum)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (vspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (aportnum1)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (motorA2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");
        asm volatile ("call digitalWrite");         
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
    else if (state == 'I') 
    {
      asm volatile ("lds r24, (aportnum)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (vspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (aportnum1)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (motorB1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");        
        asm volatile ("call digitalWrite");   
    }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
    else if (state == 'B') 
    {
       asm volatile ("lds r24, (aportnum)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (aportnum1)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (motorB1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
    }
  /**********************Backward Left************************/
  //If state is equal with letter 'H', car will go backward left
    else if (state == 'H') 
    {
      asm volatile ("lds r24, (aportnum)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (vspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (aportnum1)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (motorB2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
             
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'J', car will go backward right
    else if (state == 'J') 
    {
         asm volatile ("lds r24, (aportnum)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (vspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (aportnum1)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (motorA1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
    }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
    else if (state == 'L') 
    {
   asm volatile ("lds r24, (aportnum)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22"); 
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (aportnum1)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (motorA1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");
        asm volatile ("call digitalWrite");     
    }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
    else if (state == 'R') 
    {
        asm volatile ("lds r24, (aportnum)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22"); 
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (aportnum1)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("lds r22, (fullspeed) \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (motorA1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 1 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
    }
  /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
    else if (state == 'S')
    {
       asm volatile ("lds r24, (aportnum)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (aportnum1)  \n\t"::: "r24");
        asm volatile ("ldi r23, 0 \n\t":::"r23");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call analogWrite");   
        asm volatile ("lds r24, (motorA1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorA2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB1)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
        asm volatile ("lds r24, (motorB2)  \n\t"::: "r24");
        asm volatile ("ldi r22, 0 \n\t":::"r22");
        asm volatile ("call digitalWrite");   
    }
}

