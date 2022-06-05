#include <SoftwareSerial.h>
#include<Servo.h>
#include<NewPing.h>
Servo myservo;
int pos=0;
int item=0;
int k=0;
//void line(int *,int*,int*);
#define TRIGGER_PIN A1  
#define ECHO_PIN A0  
#define MAX_DISTANCE 100 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

#define en1 11
#define en2 12

#define right A2
#define left A3

int m1_speed=128;
int m2_speed=128;

const int in1=5;
const int in2=4;
const int in3=3;
const int in4=2;
//App
int count = 0;
char c;
String id;
int no=1;
int t=0,total=0;
int a=0,b=0;//APP

void setup() {
  myservo.attach(8);
  
  for(pos = 90; pos <= 180; pos += 1)
  {  
     myservo.write(pos);  
     delay(15);  
  } 
  for(pos = 180; pos >= 0; pos-= 1)
  { 
      myservo.write(pos);  
      delay(15);  
  }
   for(pos = 0; pos<=90; pos += 1) 
   {  
      myservo.write(pos);  
      delay(15);  
   } 

   pinMode(en1,OUTPUT);
   pinMode(en2,OUTPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
   
 pinMode(left, INPUT);  
 pinMode(right, INPUT); 

  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial2.println("hii"); 

}

void loop() {
  delay(50);  
  unsigned int distance = sonar.ping_cm(); 
  //Serial1.print("distance");  
  //Serial1.println(distance);
  int right_val = digitalRead(right);  
  int left_val = digitalRead(left);

  //forward
  if((right_val==1) && (distance>=10 && distance<=30)&&(left_val==1))
  {  
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);

    analogWrite(en1,m1_speed);
    analogWrite(en2,m2_speed);
    
  }
  //right
  else if((right_val==0) && (left_val==1))
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);

    analogWrite(en1,m1_speed);
    analogWrite(en2,m2_speed);
    
  }
  else if((right_val==1)&&(left_val==0)) 
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);

    analogWrite(en1,m1_speed);
    analogWrite(en2,m2_speed);
    
  }
  else if((right_val==1)&&(left_val==1)) 
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
     
  }
  else if(distance > 1 && distance < 10) 
  { 
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW); 
    
  }
  App();

}



void App() {
  
  while(Serial1.available()>0)
  {
    c = Serial1.read();
    count++;
    id += c;
    if(count == 12)  
     {
     // Serial2.println(id);
      //break;
     
      if(id=="AB123456789A" )  
      {
        if(++item!=2)
        {
          item=1;
        }
        else
        {
          item=2;  
        }
       
      }
      
      if(id=="AB123456789B")  //Define valid tag id here
      {
        if(++k!=2)
        {
          k=1;
        }
        else
        {
          k=2;
        }
      }
      line(&item,&k,&total);
        
      Serial2.print(total);
      Serial2.print('|');
    }
  
  }

  count = 0;
  total=0;
  id="";
  delay(500);

}

void line(int *item,int *k,int *t)
{
  if(*item==1 && *k==0){

      Serial2.print("hello");
      Serial2.print("|");
      Serial2.print(1);
      Serial2.print("|");
      Serial2.print("Parle-G");
      Serial2.print("|");
      Serial2.print("2");
      Serial2.print("|");
      Serial2.print(20);
      Serial2.print("|");
    
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print(" ");
      Serial2.print("|");
      *t+=20;
    
  }
  if(*item==0 && *k==1)
  {
      Serial2.print("hello");
      Serial2.print("|");
      Serial2.print(1);
      Serial2.print("|");
      Serial2.print("Chocolate");
      Serial2.print("|");
      Serial2.print("1");
      Serial2.print("|");
      Serial2.print(10);
      Serial2.print("|");

      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print(" ");
      Serial2.print("|");
      *t+=10;
    
  }
  if( *item==1 && *k==1){
      Serial2.print("hello");
      Serial2.print("|");
      Serial2.print(1);
      Serial2.print("|");
      Serial2.print("Chocolate");
      Serial2.print("|");
      Serial2.print("1");
      Serial2.print("|");
      Serial2.print(10);
      Serial2.print("|");
      
      Serial2.print(2);
      Serial2.print("|");
      Serial2.print("Parle-G");
      Serial2.print("|");
      Serial2.print("2");
      Serial2.print("|");
      Serial2.print(20);
      Serial2.print("|");
      *t=30;
      
    
    
  }
  if(*item==2 && *k==1)
  {

      Serial2.print("hello");
      Serial2.print("|");
      Serial2.print(1);
      Serial2.print("|");
      Serial2.print("Chocolate");
      Serial2.print("|");
      Serial2.print("1");
      Serial2.print("|");
      Serial2.print(10);
      Serial2.print("|");
      
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print(" ");
      Serial2.print("|");
      *t+=10;
      *item=0;
    
  }
  if(*item==1 && *k==2)
  {
      Serial2.print("hello");
      Serial2.print("|");
      Serial2.print(1);
      Serial2.print("|");
      Serial2.print("Parle-G");
      Serial2.print("|");
      Serial2.print("2");
      Serial2.print("|");
      Serial2.print(20);
      Serial2.print("|");
    
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print(" ");
      Serial2.print("|");
      *t+=20;
      *k=0;
    
  }
  if ((*item==2 && *k==2)|| (*item==2 && *k==0)||(*item==0 && *k==2))
  {
      Serial2.print("Hello");
      Serial2.print("|");
          
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print(" ");
      Serial2.print("|");

      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print("|");
      Serial2.print(" ");
      Serial2.print(" ");
      Serial2.print("|");
      *t=0;
      *item=0;
      *k=0;
  } 
  
}
