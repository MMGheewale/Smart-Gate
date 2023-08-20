  #define on LOW
#define off HIGH

int R1=8,R2=9,R3=10,R4=11,esp=3;//relay pin
int ls=0,rs=0,toggleleft=4,toggleleftstatus=0,togglerightstatus=0,buzzer=12,i,j=0;
const int trigPin = 7,echoPin = 6;
long duration;
int distance;

void setup() {
Serial.begin(9600);
pinMode(R1, OUTPUT);digitalWrite(R1, off);  pinMode(R2, OUTPUT);digitalWrite(R2, off);                                                        //setting relays pin as output & intitally turning off the relay
pinMode(R3, OUTPUT);digitalWrite(R3, off);  pinMode(R4, OUTPUT);digitalWrite(R4, off);
pinMode(esp, INPUT);
pinMode(toggleleft, INPUT);
pinMode(buzzer, OUTPUT);  digitalWrite(buzzer, LOW);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
} 

void loop() {
OPEN();
CLOSE();  
}

void OPEN(){
  Serial.println("open signal recived");
  digitalWrite(buzzer, HIGH); digitalWrite(R1, on);digitalWrite(R2, on);
  ls=0;rs=0;  
  while(ls==0){Serial.println("opening");
    toggleleftstatus=digitalRead(toggleleft);
    if(toggleleftstatus==0){}else{ls=1;}
    }
  digitalWrite(buzzer, LOW);digitalWrite(R1, off);digitalWrite(R2, off);
  Serial.println("Stop opening signal recived");
}
void CLOSE(){
  Serial.println("Close signal recived");
  digitalWrite(buzzer, HIGH);digitalWrite(R3, on); digitalWrite(R4, on);                                                                                            //Wait 10 second  
  while(rs==0){Serial.println("closing");
  togglerightstatus=digitalRead(toggleleft);
  if(togglerightstatus==1){}else{rs=1;}
  }
  digitalWrite(buzzer, LOW);digitalWrite(R3, off);digitalWrite(R4, off);
  Serial.println("Stop closing signal recived");
}
int ultrasonic() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration/74/2;
return distance;
}
