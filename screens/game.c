#include <stdbool.h>
#include "../include/timer.h"
#include "../include/screens.h"
#include "../include/buttons.h"
#include "../include/display.h"

typedef enum {
    EASY,
    NORMAL,
    HARD,
    IMPOSSIBLE
} game_difficulty;

game_difficulty difficulty_selection() {
    game_difficulty current_selection = EASY;
    int y_pos = 8;

    while (1) {
        delay(100); // this causes som issues
        draw_clear();

        draw_string_align("DIFFICULTY!", 0, CENTER);
        draw_string_align("EASY", 15, LEFT);
        draw_string_align("NORMAL", 25, LEFT);
        draw_string_align("HARD", 15, RIGHT);
        draw_string_align("IMPOSSIBLE", 25, RIGHT);

        // selection indicator
        draw_pixel(0, y_pos);

        // up
        if (btn4_ispressed() && current_selection != EASY) {
            y_pos -= 8;
            current_selection--;
        }

        // down
        if (btn3_ispressed() && current_selection != IMPOSSIBLE) {
            y_pos += 8;
            current_selection++;
        }

        // select
        if (btn1_ispressed()) {
            return current_selection;
        }

        draw_canvas();
    }
}

/**
 * Written by: Alex Gunnarsson & Marcus Nilszén
 * 
 * @brief Run game routine for singleplayer and multiplayer gamemode.
 * 
 * @param mode Enum value for playing singleplayer or multiplayer.
 * Determines if other paddle is player- or AI-controlled, respectively.
 * @param difficulty Enum value deciding difficult level
 * in singleplayer vs AI. Has no effect when mode is set to multiplayer.
 */
void game_screen(game_mode mode) {
    game_difficulty difficulty;

    if (mode == SINGLEPLAYER) {
        difficulty = difficulty_selection();
    }

    while (1) {
        draw_clear();
        
        // player1 movement
        if (btn4_ispressed()) draw_pixel(1, 1);       // implement BTN4 as player 1 move up
        if (btn3_ispressed()) draw_pixel(10, 1);      // implement BTN3 as player 1 move down
        
        // player2 movement
        if (mode == MULTIPLAYER) {
            // player-controlled through buttons
            if (btn1_ispressed()) draw_pixel(20, 1);      // implement BTN1 as player 2 move up
            if (btn2_ispressed()) draw_pixel(30, 1);      // implement BTN2 as player 2 move down
        } else {
            // AI-controlled via calculations based on difficulty
            // temp as buttons on other pos
            if (btn1_ispressed()) draw_pixel(20, 20);      // implement BTN1 as player 2 move up
            if (btn2_ispressed()) draw_pixel(30, 20);      // implement BTN2 as player 2 move down
        }

        static int x = 0;
        static int y = 0;
        static bool x_forward = true;
        static bool y_up = true;

        if (x > 125) x_forward = false;
        if (x < 1) x_forward = true;
        if (y > 30) y_up = false;
        if (y < 1) y_up = true;

        x_forward ? x++ : x--;
        y_up ? y++ : y--;

        draw_pixel(x, y);
        draw_pixel(x+1, y);
        draw_pixel(x, y+1);
        draw_pixel(x+1, y+1);

        draw_canvas();

        delay(10);
    }
}
