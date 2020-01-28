
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.hpp"



LCD lcd;

int main(void){

    

    char name[] = "HELLO WORLD!";
    char course[] = "I AM DINODE-AVR";
    lcd.initialize();
    
    lcd.clear();
    lcd.send_string(name);
    lcd.new_line();
    lcd.send_string(course);
   

    while(1){
       
       

          }
}