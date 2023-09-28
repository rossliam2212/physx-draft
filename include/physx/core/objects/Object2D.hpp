/**
 * @file Object2D.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_OBJECT2D_HPP
#define PHYSX_OBJECT2D_HPP

#include "../../dynamic/RigidBody2D.hpp"

namespace physx::core::object {
    /**
     * @brief @c Object2D class.
     * @namespace @c physx::core::object
     */
    class Object2D {
    public:
        Object2D(const math::Vec2f& position, bool rb = false);
        virtual ~Object2D();

        virtual void update(math::f32 dt) = 0;

        void addRigidBody();
        dynamic::RigidBody2D* getRb();
        bool isRbEnabled() const;

    protected:
        math::Vec2f position;
        dynamic::RigidBody2D* rb;
        bool rbEnabled{false};
    };
} // namespace physx::core::object

#endif //PHYSX_OBJECT2D_HPP
