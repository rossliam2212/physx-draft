/**
 * @file RigidBody.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 23/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_RIGIDBODY_HPP
#define PHYSX_RIGIDBODY_HPP

#include "../math/Vec3.hpp"

namespace physx::dynamic {
    /**
     * @brief @c RigidBody class.
     * @namespace @c physx::dynamic
     */
    class RigidBody {
    public:
        RigidBody(float mass);
        RigidBody(float mass, const math::Vec3f& position, const math::Vec3f& velocity);
        ~RigidBody() = default;

        // Euler, Verlet, Runge-Kutta
//        void integrateEuler(float dt);
//        void integrateVerlet(float dt);
        void integrateRK4(float dt);
        void applyForce(const math::Vec3f& force);

        float getMass() const;
        math::Vec3f& getPosition();
        math::Vec3f& getVelocity();

    private:
        float mass;
        math::Vec3f position{math::Vec3f::zero()};
        math::Vec3f velocity{math::Vec3f::zero()};
//        math::Vec3f force{math::Vec3f::zero()};
        math::Vec3f acceleration{math::Vec3f::zero()};
    };
} // namespace physx::dynamic


#endif //PHYSX_RIGIDBODY_HPP
