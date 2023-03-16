//motor direito
#define motor01 4
#define motor02 5

//motor esquerdo
#define motor03 6
#define motor04 7

//sensor direito
#define sensor01 8

//sensor esquerdo
#define sensor02 9

//velocidade
#define velocidade 100

void setup() {
  //motor direito
  pinMode(motor01, OUTPUT);
  pinMode(motor02, OUTPUT);
  
  //motor esquerdo
  pinMode(motor03, OUTPUT);
  pinMode(motor04, OUTPUT);

  //sensor direito
  pinMode(sensor01, INPUT);
  
  //sensor esquerdo
  pinMode(sensor02, INPUT);

  //monitor serial
  Serial.begin(9600);
}

void loop() {
  //leitura do valor dos sensores
  bool estadoSensor01 = digitalRead(sensor01);
  bool estadoSensor02 = digitalRead(sensor02);

  //Nesse if diz que se o sensor esquerdo sentir a linha apenas o motor direito deve ligar 
  if (estadoSensor02 == HIGH){
    digitalWrite(motor03, LOW);  
    analogWrite(motor01, velocidade);  
    delay(100);  
    digitalWrite(motor02, LOW);  
    delay(100);  
  }
  //Nesse if diz que se o sensor direito sentir a linha apenas o motor esquerdo deve ligar 
  else if (estadoSensor01 == HIGH) {
    digitalWrite(motor01, LOW); 
    analogWrite(motor03, velocidade);  
    delay(100);  
    digitalWrite(motor04, LOW);  
    delay(100);  
  }
  //Os dois motores receberão energia enquanto não sentir linha
  else {
    analogWrite(motor03, velocidade);  
    analogWrite(motor01, velocidade);
  }
}

//Codigo de autoria de Júlio Klevérton e Mariana Lisboa
//Desenvolvido no Laboratorio de Inovação e Criatividade
