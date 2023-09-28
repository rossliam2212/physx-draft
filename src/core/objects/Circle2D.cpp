/**
 * @file Circle2D.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../../include/physx/core/objects/Circle2D.hpp"

namespace physx::core::object {

    /**
     * @brief @c Circle2D constructor.
     * @param radius
     *          The radius of the circle.
     * @param position
     *          The position of the circle.
     * @param rb
     *          Whether the circle has a @c RigidBody2D or not.
     */
    Circle2D::Circle2D(math::f32 radius, const math::Vec2f& position, bool rb)
        : Object2D{position, rb},
          radius{radius} {
    }

    void Circle2D::update(math::f32 dt) {
        if (rb != nullptr) {
            rb->updatePosition(dt);
        }
    }

    /**
     * @brief Gets the radius of the @c Circle2D.
     * @return The radius.
     */
    math::f32 Circle2D::getRadius() const {
        return radius;
    }

    /**
     * @brief Gets the mass of the @c Circle2D.
     * @return The masss.
     */
    math::f32 Circle2D::getMass() const {
        return mass;
    }
} // namespace physx::core::object