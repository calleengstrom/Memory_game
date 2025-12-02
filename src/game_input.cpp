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

void flush_all_buttons()
{
    // Clear all pending button events before reading new input
    for (int i = 0; i < (sizeof(buttons) / sizeof(buttons[0])); i++)
    {
        buttons[i].flush();
    }
}

int get_input()
{
    // Wait until a button is pressed
    while (1)
    {
        for (auto i = 0; i < (sizeof(buttons) / sizeof(buttons[0])); i++)
        {
            if (buttons[i].is_pressed())
            {
                return i; // return button index
            }
        }

        // Reduce CPU load
        millis_wait_ms(200);
    }
}