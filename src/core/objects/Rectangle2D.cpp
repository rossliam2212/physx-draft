/**
 * @file Rectangle2D.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../../include/physx/core/objects/Rectangle2D.hpp"

namespace physx::core::object {
    /**
     * @brief @c Rectangle2D constructor.
     * @param width
     *          The width of the rectangle.
     * @param height
     *          The height of the rectangle.
     * @param position
     *          The position of the rectangle.
     * @param rb
     *          Whether the rectangle has a @c RigidBody2D or not.
     */
    Rectangle2D::Rectangle2D(float width, float height, const math::Vec2f& position, bool rb)
        : Object2D{position, rb},
          width{width},
          height{height} {
    }

    void Rectangle2D::update(float dt) {
        if (rb != nullptr) {
            rb->updatePosition(dt);
        }
    }

    /**
     * @brief Gets the width of the @c Rectangle2D.
     * @return The width.
     */
    float Rectangle2D::getWidth() const {
        return width;
    }

    /**
     * @brief Gets the height of the @c Rectangle2D.
     * @return The height.
     */
    float Rectangle2D::getHeight() const {
        return height;
    }
} // namespace physx::core::object