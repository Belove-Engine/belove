#include <cstdlib>

static int seed;

/**
* @brief Get the current seed
* @return Integer of the current seed
*/
int get_seed();

/**
* @brief Sets a seed
* @param new_seed New seed to be set
* @code
* set_seed(time(NULL))
* @endcode
*/
void set_seed(long new_seed);

/**
 * @brief Generates a random float in a range.
 * @param min Lowest number in the range.
 * @param max Highest number in the range.
 * @return Random float.
 * @par Example
 * @code
 * float value = rand_frange(1.0f, 5.0f); // e.g. 4.7
 * @endcode
 */
int rand_range(int min, int max);

/**
* @brief Generates a random number from the range
* @param min Lowest number in the range
* @param max Highest number in the range
* @return Random float from the range 
* @code
* rand_frange(1, 5) = 4.7
* @endcode
*/
float rand_frange(float min, float max);

/**
* @brief Generates a boolean value
* @return Random boolean
* @code
* rand_range() = true
* @endcode
*/
bool rand_bool();