int danger = 13;  // Define o pino digital 13 para o led vermelho
int alert = 12;   // Define o pino digital 12 para o led amarelo 
int ok = 11;      //  Define o pino digital 8 para o led verde      
int buzzer = 2;  // Define o pino digital 2 para a buzina 

void setup() {
  pinMode(ok, OUTPUT);     // Configura o led verde como sa�da
  pinMode(alert, OUTPUT);  // Configura o led amarelo como sa�da
  pinMode(danger, OUTPUT); // Configura o led vermelho como sa�da
  pinMode(buzzer, OUTPUT); // Configura a buzina como sa�da
  Serial.begin(9600);      // Inicia a comunica��o serial com uma taxa de 9600 bps 
                          // (velocidade em que o computador consegue receber dados pelo USB)
}

void loop() {
	int ldr = analogRead(A0);  // L� o valor do fotoresistor (LDR) conectado ao pino anal�gica A0
                               // e armazena na vari�vel ldr
	int valorldr = map(ldr, 0, 1023, 0, 100);  // Mapeia o valor recebido pelo LDR (de 0 a 1023) 
                                               // para uma faixa de 0 a 100 e armazena na vari�vel valorldr
	Serial.println(valorldr); // Imprime o valor da luminosidade no monitor serial
  
  
if (valorldr <=40) {         // Se a luminosidade for inferior ou igual a 40 est� ideal para os vinhos
  digitalWrite(ok, HIGH);    // Acende a led verde
  digitalWrite(alert, LOW);  // Desliga a led amarela
  digitalWrite(danger, LOW); // Desliga a led vermelha
  noTone(buzzer);            // Desliga o buzzer
} 
  
else if (valorldr > 40 && valorldr < 89){ // Se a luminosidade for maior que 40 e menor que 89, come�a a ficar preocupante
  digitalWrite(ok, LOW);          // Desliga o led verde
  digitalWrite(alert, HIGH);      // Acende o led amarelo, para alertar
  digitalWrite(danger, LOW);       // Desliga o led vermelho
  tone(buzzer,100, 3000);         // Liga o buzzer com uma frequ�ncia que varia entre 100 e 392, 
  delay(3000);                    // repetindo at� que a situa��o seja normalizada
  tone(buzzer,392, 3000);
  delay(3000);
} 
  
else {                    // Se a luminosidade estiver acima de 89, os vinhos podem sofrer altera��o em sua composi��o, 
                          // portanto a situa��o est� critica
  digitalWrite(ok, LOW);     // Desliga o led verde   
  digitalWrite(alert, LOW);  // Desliga o led amarelo
  digitalWrite(danger, HIGH); // Acende o led vermelho
  noTone(buzzer);             // Desliga o buzzer
}
  delay(1000);
}
