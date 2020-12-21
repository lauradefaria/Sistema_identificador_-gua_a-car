#define pwm 10
int i;

void setup() {
  //Inicializa as portas
  pinMode(pwm,OUTPUT);

  //Ajusta a frequência do pwm para 31kHz
  TCCR1B = TCCR1B & B11111000 | B00000001;
}

void loop()
{
    // Sinais enviados pelo PWM (Variando de 0V - 2V)
    for(i=0;i<102;i++){
      analogWrite(pwm, i);
      delay(10);
    }
    for(i=102;i>0;i--){
      analogWrite(pwm, i);
      delay(10);
    }
}
