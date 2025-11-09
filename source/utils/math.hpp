#pragma once
#include <cmath>

#define PI = 3.141592653
#define PI_2 = 1.5707963265
#define PI_3 = 1.047197551

/**
* @brief 2D Vector2 class
*/
struct vector2 {
    float x, y;

    /**
    * @brief Construct a new vector2 object
    * @param x float X coordinate
    * @param y float y coordinate
    */
    vector2(float x = 0, float y = 0) : x(x), y(y) {}

    /**
    * @brief Add two vectors
    * @param v Vector to add
    * @return vector2 Result of addition
    */
    vector2 operator+(const vector2& v) const { return vector2(x + v.x, y + v.y); }

    /**
    * @brief Subtract two vectors
    * @param v Vector to subtract
    * @return vector2 Result of subtraction
    */
    vector2 operator-(const vector2& v) const { return vector2(x - v.x, y - v.y); }

    /**
    * @brief Multiply two vectors
    * @param f Value to multiply in all axis
    * @return vector2 Result of multiply
    */
    vector2 operator*(float f) const { return vector2(x * f, y * f); }

    /**
    * @brief Multiply two vectors
    * @param v Vector to multiply
    * @return vector2 Result of multiplication
    */
    vector2 operator*(const vector2& v) const { return vector2(x * v.x, y * v.y); }

    /**
    * @brief Gets the length of the vector
    * @return float Length of vector
    */
    float length() const { return sqrt(x * x + y * y); }

    /**
    * @brief Normalizes the vector
    * @return vector2 Normalized vector
    */
    vector2 normalize() const { 
        float l = length(); 
        return l > 0 ? vector2(x/l, y/l) : vector2(0,0); 
    }
};

struct vector3 {
    float x, y, z;

    /**
    * @brief Construct a new vector3 object
    * @param x float X coordinate
    * @param y float y coordinate
    */
    vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    /**
    * @brief Add two vectors
    * @param v Vector to add
    * @return vector2 Result of addition
    */
    vector3 operator+(const vector3& v) const { return vector3(x + v.x, y + v.y, z + v.z); }

    /**
    * @brief Subtract two vectors
    * @param v Vector to subtract
    * @return vector2 Result of subtraction
    */
    vector3 operator-(const vector3& v) const { return vector3(x - v.x, y - v.y, z - v.z); }

    /**
    * @brief Multiply two vectors
    * @param f Value to multiply in all axis
    * @return vector2 Result of multiply
    */
    vector3 operator*(float f) const { return vector3(x * f, y * f, z * f); }

    /**
    * @brief Multiply two vectors
    * @param v Vector to multiply
    * @return vector2 Result of multiplication
    */
    vector3 operator*(const vector3& v) const { return vector3(x * v.x, y * v.y, z * v.z); }

    /**
    * @brief Gets the length of the vector
    * @return float Length of vector
    */
    float length() const { return sqrt(x * x + y * y + z * z); }

    /**
    * @brief Normalizes the vector
    * @return vector2 Normalized vector
    */
    vector3 normalize() const { 
        float l = length(); 
        return l > 0 ? vector3(x/l, y/l, z/l) : vector3(0,0,0); 
    }
};