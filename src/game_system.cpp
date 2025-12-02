#include "../include/game_system.hpp"
#include "../include/game_gui.hpp"
#include "../include/game_input.hpp"

void start_ard()
{
    int choice;

    while (1)
    {
        init_lights();

        choice = main_meny();
        
        switch (choice)
        {
        case 0:
            // start_game();
            break;
        case 1:
        // show_highscore();

        default:
            break;
        }
        

    }
}
