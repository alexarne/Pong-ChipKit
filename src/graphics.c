#include <stdint.h>
#include "../include/graphics.h"

/**
 * @brief The font used for text
 * throughout the program.
 * 
 */
const unsigned int const font[] = {
    0x00000000, // ' '
    0x00100421, // '!'
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x00208422, // '('
    0x00110841, // ')'
    0x0,
    0x0,
    0x0,
    0x00007C00, // '-'
    0x00100000, // '.'
    0x0,
    0x0064A526, // '0'
    0x00710862, // '1'
    0x00F09907, // '2'
    0x00741907, // '3'
    0x00843D29, // '4'
    0x00741C2F, // '5'
    0x00649C26, // '6'
    0x0021110F, // '7'
    0x00649926, // '8'
    0x00643926, // '9'
    0x00008020, // ':'
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0094BD26, // 'A'
    0x00749D27, // 'B'
    0x00E0842E, // 'C'
    0x0074A527, // 'D'
    0x00F09C2F, // 'E'
    0x00109C2F, // 'F'
    0x00E4B42E, // 'G'
    0x0094BD29, // 'H'
    0x00710847, // 'I'
    0x0064A10F, // 'J'
    0x00928CA9, // 'K'
    0x00F08421, // 'L'
    0x0118D771, // 'M'
    0x0094B569, // 'N'
    0x0064A526, // 'O'
    0x00109D27, // 'P'
    0x00F6A52F, // 'Q'
    0x00929D27, // 'R'
    0x0074182E, // 'S'
    0x00210847, // 'T'
    0x0064A529, // 'U'
    0x002294A5, // 'V'
    0x00AAD6B1, // 'W'
    0x00949929, // 'X'
    0x002108A5, // 'Y'
    0x00F0990F, // 'Z'
};

/**
 * @brief The width of all font chars.
 * 
 */
const unsigned char const font_width[] = {
    4, // ' '
    1, // '!'
    0,
    0,
    0,
    0,
    0,
    0,
    2, // '('
    2, // ')'
    0,
    0,
    0,
    5,
    1, // '.'
    0,
    4, // '0'
    3, // '1'
    4, // '2'
    4, // '3'
    4, // '4'
    4, // '5'
    4, // '6'
    4, // '7'
    4, // '8'
    4, // '9'
    1, // ':'
    0,
    0,
    0,
    0,
    0,
    0,
    4, // 'A'
    4, // 'B'
    4, // 'C'
    4, // 'D'
    4, // 'E'
    4, // 'F'
    4, // 'G'
    4, // 'H'
    3, // 'I'
    4, // 'J'
    4, // 'K'
    4, // 'L'
    5, // 'M'
    4, // 'N'
    4, // 'O'
    4, // 'P'
    4, // 'Q'
    4, // 'R'
    4, // 'S'
    3, // 'T'
    4, // 'U'
    3, // 'V'
    5, // 'W'
    4, // 'X'
    3, // 'Y'
    4, // 'Z'
};

/**
 * @brief The image used in loading()
 * to display a loading image.
 * How to create: create a 128x32 image with
 * a white background. Go to http://www.majer.ch/lcd/adf_bitmap.php
 * to convert image into array of size 512. Paste here and replace
 * signature with `const uint8_t const name_here[]`.
 */
const uint8_t const pong_image[] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
    0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x3F, 0x3F, 0x3F,
    0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F,
    0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xEF, 0xCF, 0x07, 0x03, 0x03, 0x03, 0x03, 0x7B, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
    0x1F, 0x01, 0x00, 0x00, 0xB0, 0xF0, 0xF8, 0x78, 0x3C, 0x3C,
    0x10, 0x00, 0x00, 0x81, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
    0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0xFF, 0xCF, 0xC7,
    0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xE0, 0x80,
    0x01, 0x01, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x01,
    0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0xFF, 0x1F, 0x03, 0x03,
    0x00, 0x00, 0x00, 0x00, 0xE0, 0xF0, 0x30, 0x30, 0x10, 0x10,
    0x30, 0x30, 0x30, 0x30, 0x30, 0x18, 0x18, 0x18, 0x18, 0x1C,
    0x1E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBC,
    0x14, 0x00, 0x00, 0x00, 0x20, 0x70, 0xF8, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x1F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x80,
    0xC0, 0xC0, 0xC0, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC, 0xFE, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
    0xC0, 0xC1, 0xC1, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC1,
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xE0, 0xC0, 0xC0, 0xC0,
    0xC0, 0xC0, 0xC3, 0xE3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC,
    0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0,
    0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0, 0xE0, 0xE0, 0xE0,
    0xC0, 0xC0, 0xC1, 0xC1, 0xC3, 0xC2, 0xC2, 0xC2, 0xC3, 0xC3,
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0, 0xF0, 0xF3,
    0xFB, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x3F, 0x39, 0x38, 0x30,
    0x30, 0x38, 0x1C, 0x1E, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB,
    0xFB, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
    0xC0, 0xC0, 0xE0, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF
};
