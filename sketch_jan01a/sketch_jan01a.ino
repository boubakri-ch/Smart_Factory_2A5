#define 12
#define 13
#define 8
char data;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    data=Serial.read();
    if(data=='1')
    {
      digitalWrite(13,HIGH);
      Serial.write('1');
    }
    else if(data=='0')
    {
      digitalWrite(13,LOW);
      Serial.write('0');
    }
    else if(data=='2')
    {
      digitalWrite(12,HIGH);
      Serial.write('2');
    }
    else if(data=='3')
    {
      digitalWrite(12,LOW);
      Serial.write('3');
    }
    else if(data=='4')
    {
      digitalWrite(8,HIGH);
      Serial.write('4');
    }
    else if(data=='5')
    {
      digitalWrite(8,LOW);
      Serial.write('5');
    }   
  }
}
