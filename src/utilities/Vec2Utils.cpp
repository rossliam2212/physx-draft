/**
 * @file Vec2Utils.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/utilities/Vec2Utils.hpp"

namespace physx::utils {
    /**
     * @brief Calculates the dot product of two @c Vec2f's.
     * @param a
     *          The first @c Vec2f.
     * @param b
     *          The second @c Vec2f.
     * @return The dot product.
     */
    math::f32 dot(const math::Vec2f& a, const math::Vec2f& b) {
        return (a.getX() * b.getX()) + (a.getY() + b.getY());
    }

    /**
     * @brief Calculates the cross product of two @c Vec2f's
     * @param a
     *          The first @c Vec2f.
     * @param b
     *          The second @c Vec2f.
     * @return The cross product.
     */
    math::f32 cross(const math::Vec2f& a, const math::Vec2f& b) {
        return a.getX() * b.getY() - a.getY() * b.getX();
    }

    /**
     * @brief Calculates the length (magnitude) of a @c Vec2.f
     * @param vec
     *          The @c Vec2f to calculate the length of.
     * @return The length of the @c Vec2f.
     */
    math::f32 length(const math::Vec2f& vec) {
        return std::sqrt(vec.getX() * vec.getX() + vec.getY() * vec.getY());
    }

    /**
     * @brief Calculates the distance between two @c Vec2f's.
     * @param a
     *          The first @c Vec2f.
     * @param b
     *          The second @c Vec2f.
     * @return The distance.
     */
    math::f32 distance(const math::Vec2f& a, const math::Vec2f& b) {
        float num1{a.getX() - b.getX()};
        float num2{a.getY() - b.getY()};
        return std::sqrt((num1 * num1) + (num2 * num2));
    }

    /**
     * @brief Normalizes a @c Vec2f to make it a unit vector.
     * @param vec
     *          The @c Vec2f to normalize.
     * @return The normalized vector.
     */
    math::Vec2f normalize(const math::Vec2f& vec) {
        math::f32 len{length(vec)};
        if (len != 0) {
            math::f32 x{vec.getX() / len};
            math::f32 y{vec.getY() / len};

            return {x, y};
        } else {
            return math::Vec2f::zero();
        }
    }

    /**
     * @brief Converts an @c sf::Vector2f to a @c Vec2f.
     * @param vec
     *          The @c sf::Vector2f.
     * @return The converted @c Vec2.
     */
    math::Vec2f sfVecToVec2(const sf::Vector2f& vec) {
        return {vec.x, vec.y};
    }
} // namespace physx::utils