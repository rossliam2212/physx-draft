/**
 * @file RigidBody2D.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/dynamic/RigidBody2D.hpp"

namespace physx::dynamic {
    /**
     * @brief @c RigidBody2D constructor.
     * @param mass
     *          The mass of the @c RigidBody2D.
     */
    RigidBody2D::RigidBody2D(float mass)
        : mass{mass} {
    }

    /**
     * @brief @c RigidBody2D constructor.
     * @param position
     *          The position of the @c RigidBody2D.
     */
    RigidBody2D::RigidBody2D(const math::Vec2f& position)
        : position{position},
          positionOld{position} {
    }

    /**
     * @brief @c RigidBody2D constructor.
     * @param mass
     *          The mass of the @c RigidBody2D.
     * @param position
     *          The position of the @c RigidBody2D.
     */
    RigidBody2D::RigidBody2D(float mass, const math::Vec2f& position)
        : mass{mass},
          position{position} {
    }


    void RigidBody2D::updatePosition(float dt) {
        switch (integration) {
            case IntegrationType::Euler:
                integrateEuler(dt);
                break;
            case IntegrationType::Verlet:
                integrateVerlet(dt);
                break;
            case IntegrationType::RK4:
                integrateRK4(dt);
                break;
        }
    }

    void RigidBody2D::accelerate(const math::Vec2f& accel) {
        acceleration += accel;
    }

    void RigidBody2D::integrateVerlet(float dt) {
        velocity = position - positionOld;
        positionOld = position;

        position = position + velocity + acceleration * dt * dt;
        acceleration = math::Vec2f::zero();
    }

    void RigidBody2D::integrateEuler(float dt) {

    }

    void RigidBody2D::integrateRK4(float dt) {

    }

    /**
     * @brief Gets the mass of the @c RigidBody2D.
     * @return The mass of the @c RigidBody2D.
     */
    float RigidBody2D::getMass() const {
        return mass;
    }

    /**
     * @brief Gets the position of the @c RigidBody2D.
     * @return A reference to the position.
     */
    math::Vec2f& RigidBody2D::getPosition() {
        return position;
    }

    /**
     * @brief Gets the velocity of the @c RigidBody2D.
     * @return The velocity.
     */
    math::Vec2f RigidBody2D::getVelocity() {
        return velocity;
    }

    /**
     * @brief Sets the position of the @c RigidBody2D.
     * @param newPos
     *          The new position.
     */
    void RigidBody2D::setPosition(const math::Vec2f& newPos) {
        position = newPos;
    }

    /**
     * @brief Sets the velocity of the @c RigidBody2D.
     * @param newVel
     *          The new velocity.
     */
    void RigidBody2D::setVelocity(const math::Vec2f& newVel) {
        velocity = newVel;
    }

    /**
     * @brief Sets the type of numerical integration to use - Euler, Verlet or RK4.
     * @param integrationType
     *          The new numerical integration to use.
     */
    void RigidBody2D::setIntegrationMethod(physx::dynamic::IntegrationType integrationType) {
        integration = integrationType;
    }
} // namespace physx::dynamic