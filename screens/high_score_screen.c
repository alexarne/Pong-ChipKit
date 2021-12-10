#include "../include/timer.h"
#include "../include/screens.h"
#include "../include/display.h"
#include "../include/buttons.h"
#include "../include/eeprom.h"
#include "../include/tools.h"

/**
 * Written by: Marcus Nilszén
 * 
 * @brief The leaderboard for different difficulty
 * levels. Shows top 4 players (names and scores).
 * 
 */
void high_score_screen() {
    char *screens[DIFFICULTYLEVELS] = {
        "HIGHSCORE: EASY",
        "HIGHSCORE: NORMAL",
        "HIGHSCORE: HARD"
    };

    char current_screen = 0;

    short name_addrs[DIFFICULTYLEVELS][TOPNPLAYERS] = {
        {ADDR_EASY1_NAME, ADDR_EASY2_NAME, ADDR_EASY3_NAME, ADDR_EASY4_NAME},
        {ADDR_NORMAL1_NAME, ADDR_NORMAL2_NAME, ADDR_NORMAL3_NAME, ADDR_NORMAL4_NAME},
        {ADDR_HARD1_NAME, ADDR_HARD2_NAME, ADDR_HARD3_NAME, ADDR_HARD4_NAME}
    };
    short score_addrs[DIFFICULTYLEVELS][TOPNPLAYERS] = {
        {ADDR_EASY1_SCORE, ADDR_EASY2_SCORE, ADDR_EASY3_SCORE, ADDR_EASY4_SCORE},
        {ADDR_NORMAL1_SCORE, ADDR_NORMAL2_SCORE, ADDR_NORMAL3_SCORE, ADDR_NORMAL4_SCORE},
        {ADDR_HARD1_SCORE, ADDR_HARD2_SCORE, ADDR_HARD3_SCORE, ADDR_HARD4_SCORE}
    };

    // [mode (normal/easy)][position (1-4)][len of string]
    char names[DIFFICULTYLEVELS][TOPNPLAYERS][7];
    char scores[DIFFICULTYLEVELS][TOPNPLAYERS][10];
    char name_scores[DIFFICULTYLEVELS][TOPNPLAYERS][30];
    
    char mode, place;
    for (mode = 0; mode < DIFFICULTYLEVELS; mode++) {
        for (place = 0; place < TOPNPLAYERS; place++) {
            eeprom_read_str(name_addrs[mode][place], names[mode][place]);
            if (names[mode][place][0] == '0') {
                name_scores[mode][place][0] = '\0';
                continue;
            }
            int temp = eeprom_read_int(score_addrs[mode][place]);
            itos(temp, scores[mode][place]);

            // add name and score into name_scores
            char entry_pos = 0, name_score_pos = 0;
            // name
            while (names[mode][place][name_score_pos])
                name_scores[mode][place][entry_pos++] = names[mode][place][name_score_pos++];
            name_scores[mode][place][entry_pos++] = ':';
            name_score_pos = 0;
            // score
            while (scores[mode][place][name_score_pos])
                name_scores[mode][place][entry_pos++] = scores[mode][place][name_score_pos++];
            name_scores[mode][place][entry_pos] = '\0';
        }
    }

    while (1) {
        draw_clear();

        draw_string_grid(screens[current_screen], 0, CENTER);

        // displays top 4 players
        draw_string_grid(name_scores[current_screen][0], 15, LEFT);
        draw_string_grid(name_scores[current_screen][1], 15, RIGHT);
        draw_string_grid(name_scores[current_screen][2], 25, LEFT);
        draw_string_grid(name_scores[current_screen][3], 25, RIGHT);

        // go left
        if (btn4_ispressed() && current_screen != 0) {
            while (btn4_ispressed());
            current_screen--;
        }

        // go right
        if (btn3_ispressed() && current_screen != DIFFICULTYLEVELS - 1) {
            while (btn3_ispressed());
            current_screen++;
        }

        // go back
        if (btn2_ispressed()) {
            while (btn2_ispressed());
            return;
        }

        draw_canvas();
        delay(10);
    }
}
