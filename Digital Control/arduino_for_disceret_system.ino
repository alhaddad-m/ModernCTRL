int T = 100;  // (in ms) sample time

unsigned long last_t;
unsigned long current_t;

float u;
float u_1;
float u_2;
float y;
float y_1;
float y_2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  u=0;
  u_1=0;
  u_2=0;
  y=0;
  y_1=0;
  y_2=0;
}

void input_signal(){
  if(current_t == 1000){  // set input signal after 1 sec
    u = 1.0;
    }
  }
void loop() {
  // put your main code here, to run repeatedly:

  current_t = millis();
  int delta_t = current_t - last_t;
  if(delta_t>=T){ // when sample time 100 ms is passed read input and comput output

    input_signal();
    y = -3*y_1+ 5*y_2+u+5*u_1-2*u_2;

    Serial.print(u);
    Serial.print("    ");
    Serial.println(y);

    u_2 = u_1;
    y_2 = y_1;
    u_1 = u;
    y_1 = y;


    last_t = current_t;
    }
 

  

}
