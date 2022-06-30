/**
 * @file rlc.h
 * @author Jakub Brzezowski
 * @copyright Copyright (c) 2022
 *
 * @brief Simulator of RLC circuit.
 * @version 0.1
 * @date 2022-06-16
 *
 */

#include <cstdint>
#include <stddef.h>
#include <chrono>
#include <complex>

#pragma once

using cmpl = std::complex<float>;
namespace rlc {

/**
 * @class RLC
 * @brief Class using to deliver method to simulate behaviour of RLC circuit.
 */
class RLC {
    private:

        float R;  /**< Value of resistance inc RLC circuit. */
        float L;  /**< Value of inductance inc RLC circuit. */
        float C;  /**< Value of capacity inc RLC circuit. */

        float V0;  /**< Start voltage in circuit. */
        float f;    /**< Alternative voltage frequency. */
        float omega;/**< Alternative voltage angular velocity. */

        cmpl Z_R;  /**< Value represents impedance of resistor in RLC circuit. */
        cmpl Z_L;  /**< Value represents impedance of inductor in RLC circuit. */
        cmpl Z_C;  /**< Value represents impedance of capacitor in RLC circuit. */

        cmpl Z;    /**< Total impedance of circuit. */

        cmpl I;   /**< Current in circuit. */
        cmpl V_R; /**< Voltage on resistor. */
        cmpl V_L; /**< Voltage on inductor. */
        cmpl V_C; /**< Voltage on capacitor. */

        /**
         * @brief Calculate second derivate of current.
         *
         * @param[in] omega Angular velocity.
         * @param[in] time Current time.
         * @param[in] current Given current value.
         * @param[in] der_current First derivate of current.
         *
         * @return Value of second derivate of RLC circuit current.
         */
        float second_derivate_of_current(float omega, uint64_t time, float current, float der_current);

        /**
         * @brief Calculate impedance values for every elements.
         */
        void calculate_impedances(void);

        /**
         * @brief Calculate phase of complex number.
         *
         * @param[in] number Number which phase, will be calculated.
         * @return Calculated phase.
         */
        static float calculate_phase(cmpl number);

    public:
        /**
         * @brief Construct a new RLC object
         *
         * @param[in] res Resistance of new created circuit.
         * @param[in] ind Inductance of new created circuit.
         * @param[in] cap Capacity of new created circuit.
         */
        RLC(float res, float ind, float cap);

        /**
         * @brief Construct a new RLC object
         *
         * @param[in] ind Inductance of new created circuit.
         * @param[in] cap Capacity of new created circuit.
         */
        RLC(float ind, float cap);

        /**
         * @brief Construct a new RLC object
         *
         * @param[in] res Resistance of new created circuit.
         * @param[in] ind Inductance of new created circuit.
         * @param[in] cap Capacity of new created circuit.
         * @param[in] V Initial voltage in circuit.
         * @param[in] f Frequency of given voltage
         */
        RLC(float res, float ind, float cap, float V, float f);

        /**
         * @brief Change RLC circuit parameters and recalculate all values.
         *
         * @param[in] res Resistance of new created circuit.
         * @param[in] ind Inductance of new created circuit.
         * @param[in] cap Capacity of new created circuit.
         * @param[in] V Initial voltage in circuit.
         * @param[in] f Frequency of given voltage
         */
        void change_params(float res, float ind, float cap, float V, float f);

        /**
         * @brief Print all parameters calculated during working of RLC simulator.
         */
        void print_parameters(void);

        /**
         * @brief Destroy the RLC object
         */
        virtual ~RLC(void);
};
}
