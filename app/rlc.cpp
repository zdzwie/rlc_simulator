/**
 * @file rlc.cpp
 * @author Jakub Brzezowski
 * @copyright Copyright (c) 2022
 *
 * @brief Simulator of RLC circuit.
 * @version 0.1
 * @date 2022-06-16
 *
 */

#include "rlc.hpp"

#include <iostream>
#include <iomanip>

#include <cmath>


namespace rlc {

/**
 * @brief Define cout input to better view of code.
 */
#define TAB() << std::setw( 15 ) <<

constexpr float MY_PI = 3.14159265f;

constexpr float RAD_TO_DEG_VALUE = (180.0f / MY_PI);

float RLC::calculate_phase(cmpl number)
{
    return RAD_TO_DEG_VALUE * std::arg(number);
}

void RLC::calculate_impedances(void)
{
    this->Z_R = cmpl(this->R, 0.0f);
    this->Z_L = cmpl(0.0f, this->omega * this->L);
    this->Z_C = cmpl(0.0f, -1.0f /(this->omega * this->C));

    this->Z = this->Z_R + this->Z_L + this->Z_C;
    this->I = this->V0 / this->Z;

    this->V_R = this->I * this->Z_R;
    this->V_C = this->I * this->Z_C;
    this->V_L = this->I * this->Z_L;
}

RLC::RLC(float res, float ind, float cap) : R(res), L(ind), C(cap),
                V0(DEFAULT_VOLTAGE), f(DEFAULT_FREQUENCY),
                omega(2 * MY_PI * this->f)
{
    this->calculate_impedances();
}

RLC::RLC(float ind, float cap) : R(0.0), L(ind), C(cap),
                V0(DEFAULT_VOLTAGE), f(DEFAULT_FREQUENCY),
                omega(2 * MY_PI * this->f)
{
    this->calculate_impedances();
}

RLC::RLC(float res, float ind, float cap, float V, float f) : R(res), L(ind), C(cap),
                V0(V), f(f), omega(2 * MY_PI * this->f)
{
    this->calculate_impedances();
}

RLC::~RLC()
{

}

void RLC::change_params(float res, float ind, float cap, float V, float f)
{
    this->R = res;
    this->L = ind;
    this->C = cap;
    this->V0 = V;
    this->f = f;

    this->omega = 2 * MY_PI * this->f;
}

void RLC::print_parameters(void)
{
   std::cout << "RLC circuit parameters:" << std::endl;
   std::cout << "Input voltage: " << this->V0 << "V" << std::endl;
   std::cout << "Input frequency: " << this->f << "H" << std::endl;
   std::cout << "Input angular velocity: " << this->omega << std::endl << std::endl;

   std::cout TAB() "Component" TAB() "Impedance(Ohm)" TAB() "Voltage(V)"       TAB() "Voltage mag" TAB() "Phase (deg)" << std::endl;
   std::cout TAB() "Resistor"  TAB()  std::abs(this->Z_R)  TAB()  std::abs(this->V_R) TAB()  std::abs(this->V_R)  TAB()  this->calculate_phase(this->V_R)  << std::endl;
   std::cout TAB() "Inductor"  TAB()  std::abs(this->Z_L)  TAB()  std::abs(this->V_L) TAB()  std::abs(this->V_L)  TAB()  this->calculate_phase(this->V_L)  << std::endl;
   std::cout TAB() "Capacitor" TAB()  std::abs(this->Z_C)  TAB()  std::abs(this->V_C) TAB()  std::abs(this->V_C)  TAB()  this->calculate_phase(this->V_C)  << std::endl << std::endl;

   std::cout TAB() "Component" TAB() "Impedance(Ohm)" TAB() "Current(A)"       TAB() "Current mag" TAB() "Phase (deg)" << std::endl;
   std::cout TAB() "Overall"   TAB()  std::abs(this->Z)    TAB()  std::abs( this->I)   TAB()  std::abs(this->I)    TAB()  this->calculate_phase(this->I)    << std::endl << std::endl << std::endl;
}

float RLC::second_derivate_of_current(float omega, uint64_t time, float current, float der_current)
{
    float di = (this->V0 * omega * ((float) cos(omega * time)) / this->L) + (-1.0f) * (((this->R * der_current) / this->L) + (current / (this->L * this->C)));
    return di;
}

}