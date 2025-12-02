#include "../include/game_system.hpp"
#include "../include/game_gui.hpp"
#include "../include/game_input.hpp"
#include "../include/game_logic.hpp"

void start_ard()
{
    int choice;
    int points = 0;
    while (1)
    {
        start_up_led_show();
        menu_led_on();
        choice = get_input();
        menu_led_off();
        switch (choice)
        {
        case 0:
            points = start_game();
            
            break;
        case 1:
        // show_highscore();

        default:
            break;
        }
        

    }
}
