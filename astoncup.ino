int flag1=1,flag2=1,flag3=1,flag4=1;
int timeout;
void setup() {
  Serial.begin(9600);
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void fail_part(char* partName, int basePin, int* flag) {
  Serial.print(partName);
  Serial.println(" fault!!!!");

  digitalWrite(basePin,LOW);
  digitalWrite(basePin+1,HIGH);
  digitalWrite(basePin+2,LOW);
  int timeout;
  timeout=millis()+10000;
  while((millis()<=timeout)&&*flag==1)
  {
    if(analogRead(A0)>500)
    {
      digitalWrite(basePin,HIGH);
      digitalWrite(basePin+1,LOW);
      digitalWrite(basePin+2,LOW);
      Serial.print(partName);
      Serial.println(" revived!!!!");
      break;
    }
  }
  if(timeout<=millis()&&*flag==1)
  {
    digitalWrite(basePin+2,HIGH);
    digitalWrite(basePin+1,LOW);
    digitalWrite(basePin,LOW);
    *flag=0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int currenttime= millis();
  int fault;
  xy:
  
  fault=random(4);
  Serial.print("Random number: ");
  Serial.println(fault);
  if(flag1==0&&flag2==0&&flag3==0&&flag4==0)
  end();
  if(flag1==0)
  goto xy;
  if(flag2==0)
  goto xy;
  if(flag3==0)
  goto xy;
  if(flag4==0)
  goto xy;

  switch(fault)
  {
    case 0:
      fail_part("Engine", 0, &flag1);
      break;
    case 1:
      fail_part("Shields", 3, &flag2);
      break;
    case 2:
      fail_part("Life Support", 6, &flag3);
      break;
    case 3:
      fail_part("Reactor", 9, &flag4);
      break;
  }
   Serial.print(flag1);
   Serial.print(flag2);
   Serial.print(flag3);
   Serial.println(flag4);
}
void end()
{
   Serial.println("you Died");
}
