#ifndef GAME_INPUT_HPP_
#define GAME_INPUT_HPP_
#include "../include/button_driver.hpp"

typedef enum LED_PRESSED{
    BLUE_LED_PRESSED,
    YELLOW_LED_PRESSED,
    RED_LED_PRESSED,
    GREEN_LED_PRESSED,
};
int main_meny();
int get_input();

class input_source {
private:
button_handle buttons[4];

public:
input_source();
int get_input();
};

#endif