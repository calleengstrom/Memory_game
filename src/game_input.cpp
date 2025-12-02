#include "../include/game_input.hpp"
#include "../include/game_gui.hpp"

static button_handle buttons[] = {
        button_handle(&DDRB, &PORTB, &PINB, PB5),
        button_handle(&DDRB, &PORTB, &PINB, PB4),
        button_handle(&DDRB, &PORTB, &PINB, PB3),
        button_handle(&DDRB, &PORTB, &PINB, PB2)
    };

input_source::input_source() {
    
}

int input_source::get_input()
{
    while (1)
    {
        if (buttons[0].is_pressed())
        {
            return BLUE_LED_PRESSED;
        }
        else if (buttons[1].is_pressed())
        {
            return YELLOW_LED_PRESSED;
        }
        else if (buttons[2].is_pressed())
        {
            return RED_LED_PRESSED;
        }
        else if (buttons[3].is_pressed())
        {
            return GREEN_LED_PRESSED;
        }
    }
}