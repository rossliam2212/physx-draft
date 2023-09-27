/**
 * @file Rectangle2D.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_RECTANGLE2D_HPP
#define PHYSX_RECTANGLE2D_HPP

#include "Object2D.hpp"

namespace physx::core::object {
    class Rectangle2D : public Object2D {
    public:
        Rectangle2D(float width, float height, const math::Vec2f& position, bool rb = false);
        ~Rectangle2D() override = default;

        void update(float dt) override;
        float getWidth() const;
        float getHeight() const;

    private:
        float width;
        float height;
    };
} // namespace physx::core::object


#endif //PHYSX_RECTANGLE2D_HPP
