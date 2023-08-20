#define on LOW
#define off HIGH

int R1=8,R2=9,R3=10,R4=11,esp=3;//relay pin
int ls=0,rs=0,toggleleft=4,toggleleftstatus=0,togglerightstatus=0,buzzer=12,i,j=0;

void setup() {
Serial.begin(9600);
pinMode(R1, OUTPUT);digitalWrite(R1, off);  pinMode(R2, OUTPUT);digitalWrite(R2, off);                                                        //setting relays pin as output & intitally turning off the relay
pinMode(R3, OUTPUT);digitalWrite(R3, off);  pinMode(R4, OUTPUT);digitalWrite(R4, off);
pinMode(esp, INPUT);
pinMode(toggleleft, INPUT);
pinMode(buzzer, OUTPUT);  digitalWrite(buzzer, LOW);
}

void loop() {
if(digitalRead(esp)==0){}
else{j=0;
  for(i=0;i<499;i++){if(digitalRead(esp)==0){}else{j++;}delay(2);}
  if(j<200){}else{OPEN();}
}}

void OPEN(){
  digitalWrite(buzzer, HIGH); digitalWrite(R1, on);digitalWrite(R2, on);  Serial.println("gate is opening");
  delay(10000);
  digitalWrite(buzzer, LOW);digitalWrite(R1, off);digitalWrite(R2, off);  Serial.println("gate is opened");
  delay(10000);
  digitalWrite(buzzer, HIGH);digitalWrite(R3, on); digitalWrite(R4, on);  Serial.println("gate is closing");                                                                                          //Wait 10 second  
  delay(10000);
  digitalWrite(buzzer, LOW);digitalWrite(R3, off);digitalWrite(R4, off);  Serial.println("gate is closed");
}
