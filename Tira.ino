#include <Adafruit_NeoPixel.h>

int pulzador_izquierdo = 5, pulzador_derecho = 4;

long time_relative;
int wait_time = 500; 
bool active_led_red = true;
int conexion = 6, count_leds = 8;  
int apuntador = 0, contador = 0, intentos = 1, espera = 0;

Adafruit_NeoPixel tira = Adafruit_NeoPixel(count_leds, conexion , NEO_GRB + NEO_KHZ800);

void paint_led_red(int led);
void paint_led_green(int led);
void paint_led_blue(int led);
void paint_led_black(int led);

void setup(){
  tira.begin();
  tira.show();
}
void loop(){
  do{
    if((apuntador==0) && (contador==0)){
      for(int led = 0 ; led < 8 ; led++){
        paint_led_blue(led,150);
        paint_led_black(led,150);
      }
      for(int led = 8 ; led >= 0 ; led--){
        paint_led_blue(led,150);
        paint_led_black(led,150);
      }
      espera = 1;
    }
    if(espera == 1){
      if(contador < intentos){
        for(int led = 0 ; led < 8 ; led++) {
          if(digitalRead(pulzador_derecho) == 1){
            for(int recorrido = 0 ; recorrido < 3 ; recorrido++){
              paint_led_red(7,200);
              paint_led_black(7,200);
            }
            contador++;
          }
          if(contador < intentos){
            paint_led_green(led,200);
            paint_led_black(led,200);
          }
        }
        if(contador<intentos){
          paint_led_green(7,0);
 
          active_led_red = true;
          wait_time = 500;
          time_relative = millis();
      
          while((millis() - time_relative) < wait_time){
            if(digitalRead(pulzador_derecho) == 1){
              active_led_red = false;
            }
          }
          paint_led_black(7,0);

          if(active_led_red){
            for(int recorrdio = 0 ; recorrdio < 4 ; recorrdio++){
              paint_led_red(7,200);
              paint_led_black(7,200);
            }
            contador++;
          }
        }
      }
      if(contador < intentos){
        for(int led = 8 ; led >= 1 ; led--){
          if(digitalRead(pulzador_izquierdo) == 1){
            for(int recorrido = 0 ; recorrido < 3 ; recorrido++){
              paint_led_red(0,200);
              paint_led_black(0,200);
            }
            contador++;
          }
          if(contador < intentos){
            paint_led_green(led,200);
            paint_led_black(led,200);
          }
        } 
        if(contador < intentos){
          paint_led_green(0,0);
          active_led_red = true;
        
          wait_time = 260;
          time_relative = millis();
          while((millis() - time_relative) < wait_time){
            if(digitalRead(pulzador_izquierdo) == 1){
              active_led_red = false;
            }
          }
          paint_led_black(0,0);
        }
        if(active_led_red){
          for(int recorrido = 0 ; recorrido < 4 ; recorrido++){
            paint_led_red(0,200);
            paint_led_black(0,200);
          }
          contador++;
        }
        if(active_led_red == false){
          apuntador = 1;
        }
      }
    }
  }while(contador < intentos);
  apuntador = 0;
  contador = 0;
  wait_time += 400;
}
void paint_led_red(int led, int time){
  tira.setPixelColor(led,tira.Color(150,0,0));
  tira.show();
  delay(time);
}
void paint_led_green(int led, int time){
  tira.setPixelColor(led,tira.Color(0,150,0));
  tira.show();
  delay(time);
}
void paint_led_blue(int led, int time){
  tira.setPixelColor(led,tira.Color(0,0,150));
  tira.show();
  delay(time);
}
void paint_led_black(int led, int time){
  tira.setPixelColor(led,tira.Color(0,0,0));
  tira.show();
  delay(time);
}