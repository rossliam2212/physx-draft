/**
 * @file RandomNumberGenerator.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_RANDOMNUMBERGENERATOR_HPP
#define PHYSX_RANDOMNUMBERGENERATOR_HPP

#include <random>

namespace physx::utils {
    /**
     * @brief @c RandomNumberGenerator class.
     * @namespace @c physx::utils
     */
    class RandomNumberGenerator {
    public:
        RandomNumberGenerator() = default;
        ~RandomNumberGenerator() = default;

        static float random(float min, float max);
        static int random(int min, int max);
    };

    using RNG = RandomNumberGenerator;
} // namespace physx::utils

#endif //PHYSX_RANDOMNUMBERGENERATOR_HPP
