#define trigPin 12
#define echoPin 11


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 }

void loop() {
  int i;
  long suma;
  float promedio;
  for(i=0,promedio=0;i<7;i++){
    long duration, distance;
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
  
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    suma=suma+distance;
  }
  promedio=suma/7;
  if (promedio >= 400 || promedio <= 0){
    Serial.println("400");
  }
  else {
    Serial.print(promedio);
    //Serial.println(" cm");
  }
  delay(50);
} 
