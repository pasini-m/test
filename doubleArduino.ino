#define echoDX 8  
#define trigDX 9 
#define echoSX 10 
#define trigSX 11 
#define rPin  12 // pin a cui sono attaccate le ruote del lato destro

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigDX, OUTPUT); 
  pinMode(echoDX, INPUT);
  pinMode(trigSX, OUTPUT); 
  pinMode(echoSX, INPUT);
  pinMode(rPin, OUTPUT);
  Serial.begin(9600); 
}
void loop() {
  digitalWrite(trigDX, HIGH);
  //digitalWrite(trigSX, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigDX, LOW);
  // Reads the echoDX, returns the sound wave travel time in microseconds
  duration = pulseIn(echoDX, HIGH);
  // Calculating the distance. Tengo conto che la velocità del suono è 332m/s 
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  if (distance < 50){
    digitalWrite(rPin, LOW);
  }else{
    digitalWrite(rPin, HIGH);
  }
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}
