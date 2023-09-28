/**
 * @file Matrix2.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_MATRIX2_HPP
#define PHYSX_MATRIX2_HPP

#include <array>
#include <cmath>

#include "Vec2.hpp"
#include "../exceptions/InvertibleMatrixException.hpp"

namespace physx::math {
    /**
     * @brief @c Matrix2 class.
     * @namespace @c physx::math
     */
    class Matrix2 {
    public:
        Matrix2() = default;
        Matrix2(math::f32 element00, math::f32 element01, math::f32 element10, math::f32 element11);
        ~Matrix2() = default;

        Matrix2 operator*(const Matrix2& other) const;
        Vec2f operator*(const Vec2f& vec) const;

        Matrix2 transpose() const;
        Matrix2 inverse() const;
        float determinant() const;

        math::f32 get00() const;
        math::f32 get01() const;
        math::f32 get10() const;
        math::f32 get11() const;

    private:
        std::array<std::array<math::f32, 2>, 2> elements;
    };
} // namespace physx::math


#endif //PHYSX_MATRIX2_HPP
