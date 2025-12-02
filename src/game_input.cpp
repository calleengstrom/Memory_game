#include "../include/game_input.hpp"
#include "../include/game_gui.hpp"
#include "../include/button_driver.hpp"
#include "../include/millis.h"
static button_handle buttons[] = {
        button_handle(&DDRB, &PORTB, &PINB, PB5),
        button_handle(&DDRB, &PORTB, &PINB, PB4),
        button_handle(&DDRB, &PORTB, &PINB, PB3),
        button_handle(&DDRB, &PORTB, &PINB, PB2)
    };


int get_input()
{
    while (1)
    {
        for (int i = 0; i < (sizeof(buttons)/sizeof(buttons[0])); i++) {
            if (buttons[i].is_pressed()) return i;
        }

        millis_wait_ms(10);
    }
}