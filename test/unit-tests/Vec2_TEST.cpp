/**
 * @file Vec2_TEST.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 23/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include <gtest/gtest.h>

#include "../../include/physx/math/Vec2.hpp"

/**
 * @brief @c Vec2 test 1.
 */
TEST(Vec2, GIVEN_multipleVectors_WHEN_initialized_THEN_correctValuesSet) {
    physx::math::Vec2<float> vec1{1.f, 1.f};
    ASSERT_EQ(1.f, vec1.getX());
    ASSERT_EQ(1.f, vec1.getY());

    physx::math::Vec2<float> vec2{physx::math::Vec2<float>::zero()};
    ASSERT_EQ(0.f, vec2.getX());
    ASSERT_EQ(0.f, vec2.getY());

    physx::math::Vec2f vec3;
    ASSERT_EQ(0.f, vec3.getX());
    ASSERT_EQ(0.f, vec3.getY());

    physx::math::Vec2i vec4{1, 2};
    ASSERT_EQ(1, vec4.getX());
    ASSERT_EQ(2, vec4.getY());

    physx::math::Vec2<float> vec5{physx::math::Vec2<float>::unitX()};
    ASSERT_EQ(1.f, vec5.getX());
    ASSERT_EQ(0.f, vec5.getY());

    physx::math::Vec2<float> vec6{physx::math::Vec2<float>::unitY()};
    ASSERT_EQ(0.f, vec6.getX());
    ASSERT_EQ(1.f, vec6.getY());
}

/**
 * @brief @c Vec2 test 2.
 */
TEST(Vec2, GIVEN_twoVectors_WHEN_addedTogether_THEN_correctlyAddedTogether) {
    physx::math::Vec2f vec1{1.f, 1.f};
    physx::math::Vec2f vec2{1.f, 1.f};

    physx::math::Vec2f vec3{vec1 + vec2};
    ASSERT_EQ(2.f, vec3.getX());
    ASSERT_EQ(2.f, vec3.getY());


    vec1 += vec2;
    ASSERT_EQ(2.f, vec1.getX());
    ASSERT_EQ(2.f, vec1.getY());
}

/**
 * @brief @c Vec2 test 3.
 */
TEST(Vec2, GIVEN_twoVectors_WHEN_subtracted_THEN_correctlySubracted) {
    physx::math::Vec2f vec1{3.f, 3.f};
    physx::math::Vec2f vec2{1.f, 1.f};

    physx::math::Vec2f vec3{vec1 - vec2};
    ASSERT_EQ(2.f, vec3.getX());
    ASSERT_EQ(2.f, vec3.getY());

    vec1 -= vec2;
    ASSERT_EQ(2.f, vec1.getX());
    ASSERT_EQ(2.f, vec1.getY());
}

/**
 * @brief @c Vec3 test 4.
 */
TEST(Vec2, GIVEN_vector_WHEN_multipliedByScalar_THEN_correctlyMultiplied) {
    const int scalar{5};
    physx::math::Vec2f vec1{3.f, 3.f};

    physx::math::Vec2f vec2{vec1 * scalar};
    ASSERT_EQ(15.f, vec2.getX());
    ASSERT_EQ(15.f, vec2.getY());

    vec1 *= scalar;
    ASSERT_EQ(15.f, vec1.getX());
    ASSERT_EQ(15.f, vec1.getY());
}

/**
 * @brief @c Vec3 test 5.
 */
TEST(Vec2, GIVEN_vector_WHEN_dividedByScalar_THEN_correctlyDivided) {
    const int scalar{5};
    physx::math::Vec2f vec1{15.f, 15.f};

    physx::math::Vec2f vec2{vec1 / scalar};
    ASSERT_EQ(3.f, vec2.getX());
    ASSERT_EQ(3.f, vec2.getY());

    vec1 /= scalar;
    ASSERT_EQ(3.f, vec1.getX());
    ASSERT_EQ(3.f, vec1.getY());

    ASSERT_THROW(physx::math::Vec2f vec3{vec1 / 0}, physx::except::DivisionByZeroException);
}