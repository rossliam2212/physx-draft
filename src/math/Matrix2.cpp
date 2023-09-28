/**
 * @file Matrix2.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/math/Matrix2.hpp"

namespace physx::math {
    /**
     * @brief @c Matrix2 constructor.
     * @param element00
     *          Element at row 0, column 0.
     * @param element01
     *          Element at row 0, column 1.
     * @param element10
     *          Element at row 1, column 0.
     * @param element11
     *          Element at row 1, column 1.
     */
    Matrix2::Matrix2(math::f32 element00, math::f32 element01, math::f32 element10, math::f32 element11) {
        elements[0][0] = element00;
        elements[0][1] = element01;
        elements[1][0] = element10;
        elements[1][1] = element11;
    }

    /**
     * @brief Overloaded multiplication operator - Matrix multiplication.
     * @param other
     *          The other @x Matrix2 to multiply @c this by.
     * @return The result of the matrix multiplication.
     */
    Matrix2 Matrix2::operator*(const Matrix2& other) const {
        Matrix2 result;
        for (std::size_t i{0}; i < 2; ++i) {
            for (std::size_t j{0}; j < 2; ++j) {
                result.elements[i][j] = 0.f;
                for (std::size_t k{0}; k < 2; ++k) {
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }

    /**
     * @brief Overloaded multiplication operator - Matrix-vector multiplication.
     * @param vector
     *          The vector to multiply @c this with.
     * @return The result of the matrix-vector multiplication.
     */
    Vec2f Matrix2::operator*(const Vec2f& vec) const {
        math::f32 x{elements[0][0] * vec.getX() + elements[0][1] * vec.getY()};
        math::f32 y{elements[1][0] * vec.getX() + elements[1][1] * vec.getY()};
        return {x, y};
    }

    /**
     * @brief Gets the transpose of the @c Matrix2.
     * @return The transposed @c Matrix2.
     */
    Matrix2 Matrix2::transpose() const {
        return {elements[0][0], elements[1][0], elements[0][1], elements[1][1]};
    }

    /**
     * @brief Gets the inverse of the @c Matrix2.
     * @return The inverse of the @c Matrix2.
     * @throws except::InvertibleMatrixException
     *          If the matrix is not invertible.
     */
    Matrix2 Matrix2::inverse() const {
        math::f32 det{determinant()};
        if (std::abs(det) < 1e-6) {
            ///< Matrix is not invertible
            throw except::InvertibleMatrixException("Matrix is not invertible.");
        }
        math::f32 invDet{1.f / det};
        return {elements[1][1] * invDet, -elements[0][1] * invDet, -elements[1][0] * invDet, elements[0][0] * invDet};
    }

    /**
     * @brief Get the determinant of the matrix.
     * @return The determinant value.
     */
    math::f32 Matrix2::determinant() const {
        return elements[0][0] * elements[1][1] - elements[0][1] * elements[1][0];
    }

    /**
     * @brief Gets the element at row 0, column 0.
     * @return The element at row 0, column 0.
     */
    math::f32 Matrix2::get00() const {
        return elements[0][0];
    }

    /**
     * @brief Gets the element at row 0, column 1.
     * @return The element at row 0, column 1.
     */
    math::f32 Matrix2::get01() const {
        return elements[0][1];
    }

    /**
     * @brief Gets the element at row 1, column 0.
     * @return The element at row 1, column 0.
     */
    math::f32 Matrix2::get10() const {
        return elements[1][0];
    }

    /**
     * @brief Gets the element at row 1, column 1.
     * @return The element at row 1, column 1.
     */
    math::f32 Matrix2::get11() const {
        return elements[1][1];
    }
} // namespace physx::math