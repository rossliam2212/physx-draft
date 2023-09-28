/**
 * @file RandomNumberGenerator.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_RANDOMNUMBERGENERATOR_HPP
#define PHYSX_RANDOMNUMBERGENERATOR_HPP

#include <random>

#include "../math/MathConstants.hpp"

namespace physx::utils {
    /**
     * @brief @c RandomNumberGenerator class.
     * @namespace @c physx::utils
     */
    class RandomNumberGenerator {
    public:
        RandomNumberGenerator() = default;
        ~RandomNumberGenerator() = default;

        static math::f32 random(math::f32 min, math::f32 max);
        static math::i32 random(math::i32 min, math::i32 max);
    };

    using RNG = RandomNumberGenerator;
} // namespace physx::utils

#endif //PHYSX_RANDOMNUMBERGENERATOR_HPP
