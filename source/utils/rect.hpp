#pragma once

/**
* @brief Structure for rect, 4 values
* @param x X coordinate for rect
* @param y Y coordinate for rect
* @param w width size for rect
* @param h height size for rect
* @code
* // Example:
* s_rect my_rect;
* my_rect.x = 8;
* my_rect.y = 8;
* my_rect.w = 16;
* my_rect.h = 16;
*
* Draw::draw_rectangle(my_rect.x, my_rect.y, my_rect.w, my_rect.h, blue);
* @endcode
*/
struct s_rect {
    /**
    * @brief X coordinate
    */
    int x;

    /**
    * @brief Y coordinate
    */
    int y;

    /**
    * @brief Width
    */
    int w;

    /**
    * @brief Height
    */
    int h;
};