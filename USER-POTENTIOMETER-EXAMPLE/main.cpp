#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LCD.hpp"
#include <stdlib.h>

LCD lcd;

ISR(ADC_vect){
    char adc_result[4];
    uint16_t adc_value = ADCL>>6;
    adc_value |= (ADCH<<2);
    itoa(adc_value,adc_result,10);
    lcd.clear();
    lcd.send_string("ADC VALUE: ");
    lcd.send_string(adc_result);
    _delay_ms(100);
    ADCSRA |= (1<<ADSC);

}

int main(void){

    
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
    //enable global interrupt
    sei();
    //Enable the ADC
    ADCSRA |= (1<<ADEN);
    //Start first ADC conversion
    ADCSRA |= (1<<ADSC);


    





    while(1){

    }
}