#include "../include/timer.h"
#include "../include/screens.h"
#include "../include/display.h"
#include "../include/timer.h"
#include "../include/eeprom.h"

/**
 * Written by: Marcus Nilszén
 * 
 * @brief Adds name and score to leaderboard
 * if score is top 4.
 * 
 * @param name Name to add to leaderboard.
 * @param score Score to add to leaderboard.
 * @param difficulty The difficulty used to achieve this score.
 */
void add_to_eeprom(char *name, int score, game_difficulty difficulty) {
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

    char temp_names[DIFFICULTYLEVELS][TOPNPLAYERS][7];
    int temp_scores[DIFFICULTYLEVELS][TOPNPLAYERS];

    char i, pos = -1, saved = 0;

    for (i = 0; i < TOPNPLAYERS; i++) {
        int eeprom_score = eeprom_read_int(score_addrs[difficulty][i]);
        eeprom_read_str(name_addrs[difficulty][i], temp_names[difficulty][i]);
        temp_scores[difficulty][i] = eeprom_score;

        // change >= to > to avoid duplicate scores.
        if (score >= eeprom_score && !saved) {
            pos = i;
            saved = 1;
        }
    }
    
    if (pos != -1) {
        // push other scores down
        for (i = pos; i < TOPNPLAYERS - 1; i++) {
            eeprom_write_str(name_addrs[difficulty][i + 1], temp_names[difficulty][i]);
            eeprom_write_int(score_addrs[difficulty][i + 1], temp_scores[difficulty][i]);
        }

        // add new score to leaderboard
        eeprom_write_str(name_addrs[difficulty][pos], name);
        eeprom_write_int(score_addrs[difficulty][pos], score);
    }

}

/**
 * Written by: Marcus Nilszén
 * 
 * @brief A screen were a player can enter a name.
 * 
 * @param score Score the player got.
 * @param difficulty The difficulty used to achieve this score.
 */
void input_name_screen(int score, game_difficulty difficulty) {
    int current_selection = 0;
    char name[] = {'A'-1, 'A'-1, 'A'-1, 'A'-1, 'A'-1, 'A'-1, '\0'};
    char i, spacing = 3, len = 5, x = 43, y = 20;
    
    while (1) {
        draw_clear();
        
        draw_string_grid("ENTER YOUR NAME", 0, CENTER);
        for (i = 0; i < 6; i++) {
            char temp[] = {name[i], '\0'};
            draw_string_spacing(&temp, x+i*(len+spacing), y - 6, spacing);
            draw_line(x+i*(len+spacing), y, len, 1);
        }

        // draw extra line under selected char.
        draw_line(x + current_selection*(len+spacing), y, len, 2);

        // left
        if (btn4_ispressed() && current_selection != 0) {
            while (btn4_ispressed());
            current_selection--;
        }

        // right
        if (btn3_ispressed()) {
            while (btn3_ispressed());
            current_selection++;
        }

        // char up
        if (btn2_ispressed() && name[current_selection] != 'Z') {
            while (btn2_ispressed());
            name[current_selection]++;
        }

        // char down
        if (btn1_ispressed() && name[current_selection] != 'A' - 1) {
            while (btn1_ispressed());
            name[current_selection]--;
        }

        if (current_selection == 6) {
            // add name and score to highscore list
            add_to_eeprom(name, score, difficulty);
            break;
        }

        draw_canvas();
        delay(10);
    }
}
