const int TCK_PIN = 8;   // Asigna el pin 8 a TCK
const int TMS_PIN = 9;   // Asigna el pin 9 a TMS
const int TDI_PIN = 10;  // Asigna el pin 10 a TDI
const int TDO_PIN = 11;  // Asigna el pin 11 a TDO
const int VREF_PIN = 12; // Asigna el pin 12 a VREF

// Función para generar un pulso de clock (TCK)
void toggleClock(int clk) {
  Serial.println("Glitching ON");
  digitalWrite(TCK_PIN, HIGH);
  delayMicroseconds(clk);  // Ajusta este valor según tus necesidades
  digitalWrite(TCK_PIN, LOW);
  delayMicroseconds(clk);  // Ajusta este valor según tus necesidades
  Serial.println("Glitching OFF");
}

// Función para cambiar el estado de TMS
void setTMS(int state) {
  digitalWrite(TMS_PIN, state);
}

// Función para cambiar el estado de TDI
void setTDI(int state) {
  digitalWrite(TDI_PIN, state);
}

void setup() {
  Serial.begin(115200);
  pinMode(TCK_PIN, OUTPUT);
  pinMode(TMS_PIN, OUTPUT);
  pinMode(TDI_PIN, OUTPUT);
  pinMode(TDO_PIN, INPUT);
  pinMode(VREF_PIN, OUTPUT);
}

void loop() {
  // Ejemplo de secuencia de JTAG (personaliza según tus necesidades)
  setTMS(1);  // Entra en estado Test-Logic-Reset (TLR)
  
  //Glitch 1 Microseconds
  toggleClock(1);
  delay(100);
  
  // Aquí puedes agregar tu secuencia de operaciones JTAG personalizada antes del glitch  
  // Vuelve al estado TLR
  setTMS(0);

  // Liberación de recursos
  pinMode(TCK_PIN, INPUT);
  pinMode(TMS_PIN, INPUT);
  pinMode(TDI_PIN, INPUT);
  pinMode(TDO_PIN, INPUT);
  pinMode(VREF_PIN, INPUT);
}
