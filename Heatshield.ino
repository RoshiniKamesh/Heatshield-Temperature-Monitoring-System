const int tempPin = A0;      // TMP36 sensor connected to A0
const int ledPin = 8;        // LED connected to D8
const int buzzerPin = 9;     // Buzzer connected to D9
void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
void loop() 
{
  // Read temperature sensor value
  int reading = analogRead(tempPin);

  // Convert sensor reading into voltage
  float voltage = reading * (5.0 / 1023.0);

  // Convert voltage into temperature (°C)
  float temperatureC = (voltage - 0.5) * 100.0;

  // Display temperature on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Critical Condition: Heat Stroke Warning
  if (temperatureC >= 40)
 {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
    Serial.println("HEAT STROKE WARNING");
  }

  // High Temperature Warning
  else if (temperatureC >= 35) 
{
    digitalWrite(ledPin, HIGH);
    noTone(buzzerPin);
    Serial.println("HIGH TEMPERATURE WARNING");
  }

  // Safe Condition
  else 
{
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    Serial.println("SAFE CONDITION");
  }
  delay(1000);
}

