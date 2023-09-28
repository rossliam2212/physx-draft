/**
 * @file Vec2.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 22/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_VEC2_HPP
#define PHYSX_VEC2_HPP

#include <llog/llog.hpp>

#include "MathConstants.hpp"
#include "../exceptions/DivisionByZeroException.hpp"

namespace physx::math {
    /**
     * @brief @c Vec2 class.
     *
     * Represents a 2D vector with components of type T.
     * @tparam T
     *          The type of the Vec2 components.
     * @namespace @c physx::math
     */
    template<typename T>
    class Vec2 {
    public:
        /**
         * @brief @c Vec2 default constructor.
         */
        Vec2()
            : x{0}, y{0} {
        }

        /**
         * @brief @c Vec2 constructor.
         * @param x
         *          The x-component value.
         * @param y
         *          The y-component value.
         */
        Vec2(T x, T y)
            : x{x}, y{y} {
        }

        /**
         * @brief @c Vec2 default destructor.
         */
        ~Vec2() = default;

        /**
         * @brief Creates a @c Vec2 with all components set to zero.
         * @return A @c Vec2 with all components set to zero.
         */
        static Vec2<T> zero() { return {0, 0}; }

        /**
         * @brief Creates a unit @c Vec2 along the X-axis.
         * @return A unit @c Vec2 with a value of 1 in the x-component and 0 in the y-component.
         */
        static Vec2<T> unitX() { return {1, 0}; }

        /**
         * @brief Creates a unit @c Vec2 along the Y-axis.
         * @return A unit @c Vec2 with a value of 1 in the y-component and 0 in the x-component.
         */
        static Vec2<T> unitY() { return {0, 1}; }

        /**
         * @brief Overloaded addition operator.
         * @param other
         *          The @c Vec2 to add to @c this.
         * @return The result of adding @c this and another @c Vec2.
         */
        Vec2<T> operator+(const Vec2<T>& other) const {
            return Vec2<T>(x + other.x, y + other.y);
        }

        /**
         * @brief Overloaded addition operator by a scalar.
         * @param scalar
         *          The scalar to add.
         * @return The result of adding a scalar to @c this.
         */
        Vec2<T> operator+(T scalar) const {
            return Vec2<T>(x + scalar, y + scalar);
        }

        /**
         * @brief Overloaded subtraction operator.
         * @param other
         *          The @c Vec2 to subtract from @c this.
         * @return The result of subtracting another @c Vec2 from @c this.
         */
        Vec2<T> operator-(const Vec2<T>& other) const {
            return Vec2<T>(x - other.x, y - other.y);
        }

        /**
         * @brief Overloaded subtraction operator by a scalar.
         * @param scalar
         *          The scalar to subtract by.
         * @return The result of subtraction @c this by a scalar.
         */
        Vec2<T> operator-(T scalar) const {
            return Vec2<T>(x - scalar, y - scalar);
        }

        /**
         * @brief Overloaded multiplication operator.
         * @param scalar
         *          The @c Vec2 to multiply @c this by.
         * @return The result of multiplying @c this by another @c Vec2.
         */
        Vec2<T> operator*(const Vec2<T>& other) const {
            return Vec2<T>(x * other.x, y * other.y);
        }

        /**
         * @brief Overloaded multiplication operator by a scalar.
         * @param scalar
         *          The scalar value to multiply @c this by.
         * @return The result of multiplying @c this by a scalar.
         */
        Vec2<T> operator*(T scalar) const {
            return Vec2<T>(x * scalar, y * scalar);
        }

        /**
         * @brief Overloaded division operator by a scalar.
         * @param scalar
         *          The scalar value to divide @c this by.
         * @return The result of dividing @c this by a scalar.
         * @throws except::DivisionByZeroException
         *          If a division by zero error occurs.
         */
        Vec2<T> operator/(T scalar) const {
            if (scalar == 0) {
                throw except::DivisionByZeroException("Cannot divide Vec2 by zero.");
            }
            return Vec2<T>(x / scalar, y / scalar);
        }

        /**
         * @brief Overloaded addition assignment operator.
         * @param other
         *          The @C Vec2 to add to @c this.
         * @return A reference to @c this after addition.
         */
        Vec2<T>& operator+=(const Vec2<T>& other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        /**
         * @brief Overloaded subtraction assignment operator.
         * @param other
         *          The @c Vec2 to subtract from @c this.
         * @return A reference to @c this after subtraction.
         */
        Vec2<T>& operator-=(const Vec2<T>& other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        /**
         * @brief Overloaded multiplication assignment operator by a scalar.
         * @param scalar
         *          The scalar value to multiply @c this by.
         * @return A reference to @c this after multiplication.
         */
        Vec2<T>& operator*=(T scalar) {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        /**
         * @brief Overloaded division assignment operator by a scalar.
         * @param scalar
         *          The scalar value to divide @c this by.
         * @return A reference to @c this after division.
         * @throws except::DivisionByZeroException
         *          If a division by zero error occurs.
         */
        Vec2<T>& operator/=(T scalar) {
            if (scalar == 0) {
                throw except::DivisionByZeroException("Cannot divide Vec2 by zero.");
            }

            x /= scalar;
            y /= scalar;

            return *this;
        }

        /**
         * @brief Get the x-component of the @c Vec2.
         * @return The x-component value.
         */
        T getX() const { return x; }

        /**
         * @brief Get the y-component of the @c Vec2.
         * @return The y-component value.
         */
        T getY() const { return y; }

        /**
         * @brief Set the x-component of the @c Vec2.
         * @param newX
         *          The new x-component value.
         */
        void setX(T newX) { x = newX; }

        /**
         * @brief Set the y-component of the @c Vec2.
         * @param newY
         *          The new y-component value.
         */
        void setY(T newY) { y = newY; }

        std::string toString() const {
            return "Vec2(" + std::to_string(x) + "," + std::to_string(y) + ")";
        }

    private:
        T x;
        T y;
    };

    using Vec2i = Vec2<i32>;             ///< @c physx::Vec2<i32>
    using Vec2f = Vec2<f32>;             ///< @c physx::Vec2<f32>
} // namespace physx::math


#endif //PHYSX_VEC2_HPP
