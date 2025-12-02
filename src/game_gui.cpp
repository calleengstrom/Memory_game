#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <util/atomic.h>

#include "../include/millis.h"
#include "../include/led_driver.hpp"
#include "../include/button_driver.hpp"
#include "../include/random_seed.hpp"

led_handle blue_led = led_handle(&DDRB, &PORTB, &PINB, PB0);
led_handle yellow_led = led_handle(&DDRD, &PORTD, &PIND, PB7);
led_handle red_led = led_handle(&DDRD, &PORTD, &PIND, PB6);
led_handle green_led = led_handle(&DDRD, &PORTD, &PIND, PB5);

// Start game led sequence
void init_lights()
{
    millis_wait_ms(100);
    blue_led.turn_on();
    millis_wait_ms(100);
    blue_led.turn_off();

    millis_wait_ms(100);    
    yellow_led.turn_on();
    millis_wait_ms(100);
    yellow_led.turn_off();

    millis_wait_ms(100);
    red_led.turn_on();
    millis_wait_ms(100);
    red_led.turn_off();

    millis_wait_ms(100);
    green_led.turn_on();
    millis_wait_ms(100);
    green_led.turn_off();
}