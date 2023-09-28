/**
 * @file Vec2Utils.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_VEC2UTILS_HPP
#define PHYSX_VEC2UTILS_HPP

#include <SFML/System/Vector2.hpp>

#include "../math/Vec2.hpp"

namespace physx::utils {
    math::f32 dot(const math::Vec2f& a, const math::Vec2f& b);
    math::f32 cross(const math::Vec2f& a, const math::Vec2f& b);
    math::f32 length(const math::Vec2f& vec);
    math::f32 distance(const math::Vec2f& a, const math::Vec2f& b);
    math::Vec2f normalize(const math::Vec2f& vec);
    math::Vec2f sfVecToVec2(const sf::Vector2f& vec);
} // namespace physx::utils


#endif //PHYSX_VEC2UTILS_HPP
