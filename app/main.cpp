/**
 * @file main.cpp
 * @author Jakub Brzezowski
 * @copyright Copyright (c) 2022
 *
 * @brief Test of RLC simulator.
 * @version 0.1
 * @date 2022-06-16
 *
 */

#include <iostream>
#include "rlc.hpp"

int main(void)
{
    rlc::RLC first = rlc::RLC(0.05f, 10e-6f);
    rlc::RLC second = rlc::RLC(10000.0f, 0.0041f, 20e-9f);
    rlc::RLC third = rlc::RLC(2200.0f, 0.001f, 67e-9f, 25.0f, 65000.0f);

    first.print_parameters();
    second.print_parameters();
    third.print_parameters();

    return 0;
}