#pragma once

/**
* @brief Color structure
* @param r integer for red value
* @param g integer for green value
* @param b integer for blue value
* @param a integer for alpha value
* @code
* // Example
* s_color blue = {0, 0, 255, 255};
* @endcode
*/
struct s_color {
    /**
    * @brief Red
    */
    unsigned int r = 0;

    /**
    * @brief Green
    */
    unsigned int g = 0;

    /**
    * @brief Blue
    */
    unsigned int b = 0;

    /**
    * @brief Alpha (transparency)
    */
    unsigned int a = 0;
};
