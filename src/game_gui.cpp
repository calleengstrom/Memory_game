#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <util/atomic.h>

#include "../include/millis.h"
#include "../include/led_driver.hpp"
#include "../include/button_driver.hpp"
#include "../include/random_seed.hpp"
#include "../include/led_driver.hpp"

led_handle blue_led = led_handle(&DDRB, &PORTB, &PINB, PB0);
led_handle yellow_led = led_handle(&DDRD, &PORTD, &PIND, PB7);
led_handle red_led = led_handle(&DDRD, &PORTD, &PIND, PB6);
led_handle green_led = led_handle(&DDRD, &PORTD, &PIND, PB5);

// Start game led sequence
void start_up_led_show()
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

void menu_led_on()
{
    blue_led.turn_on();
    yellow_led.turn_on();
}

void menu_led_off()
{
    blue_led.turn_off();
    yellow_led.turn_off();
}

void life_lost_led_show()
{
    int ms_wait = 100;
    for (size_t i = 0; i < 3; i++)
    {
        millis_wait_ms(ms_wait);

        blue_led.turn_on();
        yellow_led.turn_on();
        red_led.turn_on();
        green_led.turn_on();

        millis_wait_ms(ms_wait);

        red_led.turn_off();
        green_led.turn_off();
        yellow_led.turn_off();
        blue_led.turn_off();
    }
}

void game_over_led_show()
{
    int ms_wait = 300;
    for (size_t i = 0; i < 6; i++)
    {
        millis_wait_ms(ms_wait);

        blue_led.turn_on();
        yellow_led.turn_on();
        red_led.turn_on();
        green_led.turn_on();

        millis_wait_ms(ms_wait);

        red_led.turn_off();
        green_led.turn_off();
        yellow_led.turn_off();
        blue_led.turn_off();
    }
}

void game_ligth_sequence(int led_num)
{
    int ms_wait = 1500;
    switch (led_num)
    {
    case BLUE_LED_ON:
        blue_led.turn_on();
        millis_wait_ms(ms_wait);
        blue_led.turn_off();
        break;

    case YELLOW_LED_ON:
        yellow_led.turn_on();
        millis_wait_ms(ms_wait);
        yellow_led.turn_off();
        break;

    case RED_LED_ON:
        red_led.turn_on();
        millis_wait_ms(ms_wait);
        red_led.turn_off();
        break;

    case GREEN_LED_ON:
        green_led.turn_on();
        millis_wait_ms(ms_wait);
        green_led.turn_off();
        break;

    default:
        break;
    }
}

// void game_led_sequence(int level)
// {
//     for (size_t i = 0; i < level; i++)
//     {
//     }
// }