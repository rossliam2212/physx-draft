/**
 * @file Vec3.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 22/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_VEC3_HPP
#define PHYSX_VEC3_HPP

#include <llog/llog.hpp>

#include "../exceptions/DivisionByZeroException.hpp"

namespace physx::math {
    /**
     * @brief @c Vec3 class.
     *
     * Represents a 3D vector with components of type T.
     * @tparam T
     *          The type of the @c Vec3 components.
     * @namespace @c physx::math
     */
    template <typename T>
    class Vec3 {
    public:
        /**
         * @brief @c Vec3 default constructor.
         */
        Vec3()
            : x{0}, y{0}, z{0} {
        }

        /**
         * @brief @c Vec3 constructor.
         * @param x
         *          The x-component value.
         * @param y
         *          The y-component value.
         * @param z
         *          The x-component value.
         */
        Vec3(T x, T y, T z)
            : x{x}, y{y}, z{z} {
        }

        /**
         * @brief @c Vec3 default destructor.
         */
        ~Vec3() = default;

        /**
         * @brief Creates a @c Vec3 with all components set to zero.
         * @return A @c Vec3 with all components set to zero.
         */
        static Vec3<T> zero() { return {0, 0, 0}; }

        /**
         * @brief Returns a unit @c Vec3 along the X-axis.
         * @return A unit @c Vec3 with a value of 1 in the x-component and 0 in the y and z components.
         */
        static Vec3<T> unitX() { return {1, 0, 0}; }

        /**
         * @brief Returns a unit @c Vec3 along the Y-axis.
         * @return A unit @c Vec3 with a value of 1 in the y-component and 0 in the x and z components.
         */
        static Vec3<T> unitY() { return {0, 1, 0}; }

        /**
         * @brief Returns a unit @c Vec3 along the Y-axis.
         * @return A unit @c Vec3 with a value of 1 in the z-component and 0 in the x and y components.
         */
        static Vec3<T> unitZ() { return {0, 0, 1}; }

        /**
         * @brief Overloaded addition operator.
         * @param other
         *          The @c Vec3 to add to @c this.
         * @return The result of adding @c this and another @c Vec3.
         */
        Vec3<T> operator+(const Vec3<T>& other) const {
            return Vec3<T>(x + other.x, y + other.y, z + other.z);
        }

        /**
         * @brief Overloaded subtraction operator.
         * @param other
         *          The @c Vec3 to subtract from @c this.
         * @return The result of subtracting another @c Vec3 from @c this.
         */
        Vec3<T> operator-(const Vec3<T>& other) const {
            return Vec3<T>(x - other.x, y - other.y, z - other.z);
        }

        /**
         * @brief Overloaded multiplication operator by a scalar.
         * @param scalar
         *          The scalar value to multiply @c this by.
         * @return The result of multiplying @c this by a scalar.
         */
        Vec3<T> operator*(T scalar) const {
            return Vec3<T>(x * scalar, y * scalar, z * scalar);
        }

        /**
         * @brief Overloaded division operator by a scalar.
         * @param scalar
         *          The scalar value to divide @c this by.
         * @return The result of dividing @c this by a scalar.
         * @throws except::DivisionByZeroException
         *          If a division by zero error occurs.
         */
        Vec3<T> operator/(T scalar) const {
            if (scalar == 0) {
                throw except::DivisionByZeroException("Cannot divide Vec3 by zero.");
            }
            return Vec3<T>(x / scalar, y / scalar, z / scalar);
        }

        /**
         * @brief Overloaded addition assignment operator.
         * @param other
         *          The @C Vec3 to add to @c this.
         * @return A reference to @c this after addition.
         */
        Vec3<T>& operator+=(const Vec3<T>& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        /**
         * @brief Overloaded subtraction assignment operator.
         * @param other
         *          The @c Vec3 to subtract from @c this.
         * @return A reference to @c this after subtraction.
         */
        Vec3<T>& operator-=(const Vec3<T>& other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        /**
         * @brief Overloaded multiplication assignment operator by a scalar.
         * @param scalar
         *          The scalar value to multiply @c this by.
         * @return A reference to @c this after multiplication.
         */
        Vec3<T>& operator*=(T scalar) {
            x *= scalar;
            y *= scalar;
            z *= scalar;
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
        Vec3<T>& operator/=(T scalar) {
            if (scalar == 0) {
                throw except::DivisionByZeroException("Cannot divide Vec2 by zero.");
            }

            x /= scalar;
            y /= scalar;
            z /= scalar;

            return *this;
        }

        /**
         * @brief Get the x-component of the @c Vec3.
         * @return The x-component value.
         */
        T getX() const { return x; }

        /**
         * @brief Get the y-component of the @c Vec3.
         * @return The y-component value.
         */
        T getY() const { return y; }

        /**
         * @brief Get the z-component of the @c Vec3.
         * @return The z-component value.
         */
        T getZ() const { return z; }

        /**
         * @brief Set the x-component of the @c Vec3.
         * @param newY
         *          The new x-component value.
         */
        void setX(T newX) { x = newX; }

        /**
         * @brief Set the y-component of the @c Vec3.
         * @param newY
         *          The new y-component value.
         */
        void setY(T newY) { y = newY; }

        /**
         * @brief Set the z-component of the @c Vec3.
         * @param newY
         *          The new z-component value.
         */
        void setZ(T newZ) { z = newZ; }

    private:
        T x;
        T y;
        T z;
    };

    using Vec3i = Vec3<int>;            // physx::Vec3<int>
    using Vec3u = Vec3<unsigned int>;   // physx::Vec3<unsigned int>
    using Vec3f = Vec3<float>;          // physx::Vec3<float>
} // namespace physx::math


#endif //PHYSX_VEC3_HPP
