#include "../include/game_input.hpp"
#include "../include/game_gui.hpp"

int get_input()
{
    while (1)
    {
        if ("press blue")
        {
            return BLUE_LED_PRESSED;
        }

        else if ("press yellow")
        {
            return YELLOW_LED_PRESSED;
        }
        else if ("press red")
        {
            return RED_LED_PRESSED;
        }
        else if ("press green")
        {
            return GREEN_LED_PRESSED;
        }
    }
}