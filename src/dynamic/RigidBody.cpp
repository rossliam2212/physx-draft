/**
 * @file RigidBody.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 23/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/dynamic/RigidBody.hpp"

namespace physx::dynamic {

    /**
     * @brief @c RigidBody constructor.
     * @param mass
     *          The mass of the @c RigidBody.
     */
    RigidBody::RigidBody(float mass)
        : mass{mass} {
    }

    /**
     * @brief @c RigidBody constructor.
     * @param mass
     *          The mass of the @c RigidBody.
     * @param position
     *          The position of the @c RigidBody.
     * @param velocity
     *          The velocity of the @c RigidBody.
     */
    RigidBody::RigidBody(float mass, const math::Vec3f& position, const math::Vec3f& velocity)
        : mass{mass},
          position{position},
          velocity{velocity} {
    }

    void RigidBody::integrateRK4(float dt) {

    }

    void RigidBody::applyForce(const math::Vec3f& force) {
        acceleration = force * (1.0f / mass);
        velocity = velocity + acceleration;
    }

    /**
     * @brief Gets the mass of the @c RigidBody.
     * @return The mass of the @c RigidBody.
     */
    float RigidBody::getMass() const {
        return mass;
    }

    /**
     * @brief Gets the position of the @c RigidBody.
     * @return A reference to the position.
     */
    math::Vec3f& RigidBody::getPosition() {
        return position;
    }

    /**
     * @brief Gets the velocity of the @c RigidBody.
     * @return A reference to the velocity.
     */
    math::Vec3f& RigidBody::getVelocity() {
        return velocity;
    }
} // namespace physx::dynamic