int danger = 13;  // Define o pino digital 13 para o led vermelho
int alert = 12;   // Define o pino digital 12 para o led amarelo 
int ok = 11;      //  Define o pino digital 8 para o led verde      
int buzzer = 2;  // Define o pino digital 2 para a buzina 

void setup() {
  pinMode(ok, OUTPUT);     // Configura o led verde como saída
  pinMode(alert, OUTPUT);  // Configura o led amarelo como saída
  pinMode(danger, OUTPUT); // Configura o led vermelho como saída
  pinMode(buzzer, OUTPUT); // Configura a buzina como saída
  Serial.begin(9600);      // Inicia a comunicação serial com uma taxa de 9600 bps 
                          // (velocidade em que o computador consegue receber dados pelo USB)
}

void loop() {
	int ldr = analogRead(A0);  // Lê o valor do fotoresistor (LDR) conectado ao pino analógica A0
                               // e armazena na variável ldr
	int valorldr = map(ldr, 0, 1023, 0, 100);  // Mapeia o valor recebido pelo LDR (de 0 a 1023) 
                                               // para uma faixa de 0 a 100 e armazena na variável valorldr
	Serial.println(valorldr); // Imprime o valor da luminosidade no monitor serial
  
  
if (valorldr <=40) {         // Se a luminosidade for inferior ou igual a 40 está ideal para os vinhos
  digitalWrite(ok, HIGH);    // Acende a led verde
  digitalWrite(alert, LOW);  // Desliga a led amarela
  digitalWrite(danger, LOW); // Desliga a led vermelha
  noTone(buzzer);            // Desliga o buzzer
} 
  
else if (valorldr > 40 && valorldr < 89){ // Se a luminosidade for maior que 40 e menor que 89, começa a ficar preocupante
  digitalWrite(ok, LOW);          // Desliga o led verde
  digitalWrite(alert, HIGH);      // Acende o led amarelo, para alertar
  digitalWrite(danger, LOW);       // Desliga o led vermelho
  tone(buzzer,100, 3000);         // Liga o buzzer com uma frequência que varia entre 100 e 392, 
  delay(3000);                    // repetindo até que a situação seja normalizada
  tone(buzzer,392, 3000);
  delay(3000);
} 
  
else {                    // Se a luminosidade estiver acima de 89, os vinhos podem sofrer alteração em sua composição, 
                          // portanto a situação está critica
  digitalWrite(ok, LOW);     // Desliga o led verde   
  digitalWrite(alert, LOW);  // Desliga o led amarelo
  digitalWrite(danger, HIGH); // Acende o led vermelho
  noTone(buzzer);             // Desliga o buzzer
}
  delay(1000);
}
