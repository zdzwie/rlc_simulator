/**
 * @file trigonometric.h
 * @author Jakub Brzezowski
 * @copyright Copyright (c) 2022
 *
 * @brief Declaration of useful trigonometric functions.
 * @version 0.1
 * @date 2022-06-16
 *
 */

#include <stdint.h>
#include <iostream>
#pragma once

namespace maths {

constexpr uint8_t SIN_ARRAY_LEN = 126;
constexpr int8_t sin_array[SIN_ARRAY_LEN] = { 0, 4, 9, 14, 19, 24, 29, 34, 38, 43, 47, 52, 56, 60, 64, 68, 71, 75, 78, 81, 84, 86, 89, 91, 93, 94, 96, 97, 98, 99, 99, 99, 99, 99, 99, 98, 97, 96, 94, 92, 90, 88, 86, 83, 80, 77, 74, 71, 67, 63, 59, 55, 51, 47, 42, 38, 33, 28, 23, 19, 14, 9, 4, 0, -5, -10, -15, -20, -25, -30, -35, -39, -44, -48, -52, -57, -61, -65, -68, -72, -75, -78, -81, -84, -87, -89, -91, -93, -95, -96, -97, -98, -99, -99, -99, -99, -99, -99, -98, -97, -95, -94, -92, -90, -88, -85, -83, -80, -77, -74, -70, -66, -63, -59, -55, -50, -46, -41, -37, -32, -27, -23, -18, -13, -8, -3};


constexpr int64_t SIN_ONE_PERIOD_RAD_VALUE = 63; /**< 2*pi radians multiplied by 10, to adjust all given angle in trigonometric calculation. */
constexpr int8_t CALCULATION_ERR = 0x7F;         /**< Value returning by trigonometric function in case of error. */

/**
 * @brief Calculate sinus from given angle.
 * @note Function return value multiplied by 100 to avoid float calculation, which is very useful in embedded system,
 *       especially without hardware floating point accelerator.
 *
 * @param[in] angle Angle (in radians multiplied by 10 to avoid floats), from which sinus will be calculated.
 *
 * @return Value of sinus multiplied by 100.
 * @retval 127 When some calculation error detected.
 */
constexpr int8_t trigonometric_calculate_sinus(int64_t angle)
{
    int64_t adjust = angle / SIN_ONE_PERIOD_RAD_VALUE;
    adjust = ((10 * angle) - (10 * adjust * SIN_ONE_PERIOD_RAD_VALUE)) / 5 ;

    if (adjust >= SIN_ARRAY_LEN) {
        return 0x7F;
    }

    return sin_array[adjust];
}
}