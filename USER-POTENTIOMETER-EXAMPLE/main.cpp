#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LCD.hpp"
#include <stdlib.h>


ISR(ADC_vect){
    char adc_value[4];
    itoa(ADCL,adc_value,10);
    lcd.clear();
    lcd.send_string("ADC VALUE: ");
    lcd.send_string(adc_value);

}

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

    //set voltage reference to AVCC
    ADMUX |= (1<<REFS0);
    ADMUX &= ~(1<<REFS1);
    //left adjust the ADC result
    ADMUX |= (1<<ADLAR);
    //set a prescaler division factor of 16
    ADCSRA |= (1<<ADPS2);
    //Enable ADC end of conversion interrupt
    ADCSRA |= (1<<ADIE);
    //Enable the ADC
    ADCSRA |= (1<<ADEN);
    //Start first ADC conversion
    ADCSRA |= (1<<ADSC);


    





    while(1){

    }
}