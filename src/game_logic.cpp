#include <stdlib.h>
#include "../include/game_logic.hpp"
#include "../include/random_seed.hpp"
#include "../include/game_input.hpp"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <util/atomic.h>

int lights_sequence[MAX_SIZE_ARRAY];
int user_pressed[MAX_SIZE_ARRAY];
int start_game()
{
    radnom_lights_sequence();
    int i = 0;
    int game_lights = 2;
    int life = 3;
    int userinput;
    int points = 0;

    do
    {
        int index_tries = 0;
        for (int j = 0; j < game_lights; j++)
        {
            // light up bulb [j]
        }
        for (int i = 0; i < game_lights; i++)
        {
            user_pressed[i] = get_input();
            if (user_pressed[i] != lights_sequence[i])
            {
                index_tries++;
                life--;
                break;
            }
        }
        if (index_tries < 1)
        {
            points++;
            game_lights = game_lights + 2;
        }

    } while (((life > 0)) || (game_lights == MAX_SIZE_ARRAY));
    return points;
}

void radnom_lights_sequence()
{
    for (int i = 0; i < MAX_SIZE_ARRAY; i++)
    {
        int random_num = rand() % 4;
        lights_sequence[i] = random_num;
    }
}
