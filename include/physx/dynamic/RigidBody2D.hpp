/**
 * @file RigidBody2D.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_RIGIDBODY2D_HPP
#define PHYSX_RIGIDBODY2D_HPP

#include "../math/Vec2.hpp"

namespace physx::dynamic {
    /**
     * @brief An enumeration of numerical integration methods.
     *
     * This enumeration represents the three different numerical integration methods that can be used to update
     * the positions and velocities of objects in a @c Simulation.
     */
    enum class IntegrationType {
        Euler,      ///< Euler integration.
        Verlet,     ///< Verlet integration.
        RK4         ///< Runge-Kutta Fourth-order integration.
    };


    /**
     * @brief @c RigidBody2D class.
     * @namespace @c physx::dynamic
     */
    class RigidBody2D {
    public:
        RigidBody2D(math::f32 mass);
        RigidBody2D(const math::Vec2f& position);
        RigidBody2D(math::f32 mass, const math::Vec2f& position);
        ~RigidBody2D() = default;

        void updatePosition(math::f32 dt);
        void accelerate(const math::Vec2f& accel);

        float getMass() const;
        math::Vec2f& getPosition();
        math::Vec2f getVelocity();

        void setPosition(const math::Vec2f& newPos);
        void setVelocity(const math::Vec2f& newVel);
        void setIntegrationMethod(IntegrationType integrationType);

    private:
        math::f32 mass{0.f};
        math::Vec2f position{math::Vec2f::zero()};
        math::Vec2f positionOld{math::Vec2f::zero()};
        math::Vec2f velocity{math::Vec2f::zero()};
        math::Vec2f acceleration{math::Vec2f::zero()};

        IntegrationType integration{IntegrationType::Verlet}; ///< Verlet integration by default.

        void integrateVerlet(math::f32 dt);
        void integrateEuler(math::f32 dt);
        void integrateRK4(math::f32 dt);
    };
} // namespace physx::dynamic

#endif //PHYSX_RIGIDBODY2D_HPP
