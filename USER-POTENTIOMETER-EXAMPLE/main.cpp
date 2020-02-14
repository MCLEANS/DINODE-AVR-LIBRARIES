#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LCD.hpp"


int main(void){

    LCD lcd;
    lcd.initialize();
    
    char line_1[] = "   USER POT";
    char line_2[] = "    EXAMPLE";
    lcd.clear();
    lcd.send_string(line_1);
    lcd.new_line();
    lcd.send_string(line_2);
    _delay_ms(1000);




    while(1){

    }
}