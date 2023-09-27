/**
 * @file RandomNumberGenerator.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/utilities/RandomNumberGenerator.hpp"

namespace physx::utils {
    /**
     * @brief Generates a random integer between two values.
     * @param min
     *          The minimum value.
     * @param max
     *          The maximum value.
     * @return A random integer.
     */
    int RandomNumberGenerator::random(int min, int max) {
        std::random_device rd;
        std::mt19937 mt{rd()};
        std::uniform_int_distribution<int> dist(min, max);
        return dist(mt);
    }

    /**
     * @brief Generates a random floating-point number between two values.
     * @param min
     *          The minimum value.
     * @param max
     *          The maximum value.
     * @return A random floating-point number.
     */
    float RandomNumberGenerator::random(float min, float max) {
        std::random_device rd;
        std::mt19937 mt{rd()};
        std::uniform_real_distribution<float> dist(min, max);
        return dist(mt);
    }
} // namespace physx::utils