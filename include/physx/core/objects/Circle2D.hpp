/**
 * @file Circle2D.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_CIRCLE2D_HPP
#define PHYSX_CIRCLE2D_HPP

#include "Object2D.hpp"

namespace physx::core::object {
    /**
     * @brief @c Circle2D class.
     *
     * Inherits from @c Object2D.
     * @namespace @c physx::core::object
     */
    class Circle2D : public Object2D {
    public:
        Circle2D(math::f32 radius, const math::Vec2f& position, bool rb = false);
        ~Circle2D() override = default;

        void update(math::f32 dt) override;
        float getRadius() const;
        float getMass() const;

    private:
        math::f32 mass{500.f};
        math::f32 radius;
    };
} // namespace physx::core::object


#endif //PHYSX_CIRCLE2D_HPP
