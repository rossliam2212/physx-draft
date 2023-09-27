/**
 * @file Object2D.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../../include/physx/core/objects/Object2D.hpp"

namespace physx::core::object {
    /**
     * @brief @c Object2D constructor.
     * @param position
     *          The position of the circle.
     * @param rb
     *          Whether the circle has a @c RigidBody2D or not.
     */
    Object2D::Object2D(const math::Vec2f& position, bool rb)
        : position{position} {
        if (rb) {
            addRigidBody();
        }
    }

    /**
     * @brief @c Object2D destructor.
     */
    Object2D::~Object2D() {
        if (rb != nullptr) {
            delete rb;
        }
    }

    /**
     * @brief Adds a @c RigidBody2D to the @c Object2D.
     */
    void Object2D::addRigidBody() {
        rb = new dynamic::RigidBody2D{position};
        rbEnabled = true;
    }

    /**
     * @brief Gets the @c RigidBody2D.
     * @return The @c RigidBody2D.
     */
    dynamic::RigidBody2D* Object2D::getRb() {
        return rb;
    }

    /**
     * @brief Checks if the @c RigidBody is enabled.
     * @return @c true if the @c RigidBody is enabled, @c false otherwise.
     */
    bool Object2D::isRbEnabled() const {
        return rbEnabled;
    }
} // namespace physx::core::object