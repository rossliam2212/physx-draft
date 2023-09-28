cmake_minimum_required(VERSION 3.26)
project(physx)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)
include_directories(${SFML_INCLUDE_DIRS})

# LLOG
find_package(llog REQUIRED)

# SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

set(HEADER_FILES
        include/physx/math/Vec3.hpp
        include/physx/math/Vec2.hpp
        include/physx/exceptions/DivisionByZeroException.hpp
        include/physx/dynamic/RigidBody.hpp
        include/physx/dynamic/RigidBody2D.hpp
        include/physx/math/Matrix2.hpp
        include/physx/exceptions/InvertibleMatrixException.hpp
        include/physx/core/Simulation.hpp
        include/physx/utilities/Vec2Utils.hpp
        include/physx/core/Engine.hpp
        include/physx/core/Renderer.hpp
        include/physx/core/objects/Circle2D.hpp
        include/physx/utilities/RandomNumberGenerator.hpp
        include/physx/core/objects/Rectangle2D.hpp
        include/physx/utilities/Mouse.hpp
        include/physx/utilities/Utils.hpp
        include/physx/math/MathConstants.hpp
)

set(SOURCE_FILES
        src/exceptions/DivisionByZeroException.cpp
        src/dynamic/RigidBody.cpp
        src/dynamic/RigidBody2D.cpp
        src/math/Matrix2.cpp
        src/exceptions/InvertibleMatrixException.cpp
        src/core/Simulation.cpp
        src/utilities/Vec2Utils.cpp
        src/core/Engine.cpp
        src/core/Renderer.cpp
        src/utilities/FixedClock.cpp
        include/physx/utilities/FixedClock.hpp
        src/core/objects/Circle2D.cpp
        src/core/objects/Object2D.cpp
        include/physx/core/objects/Object2D.hpp
        src/utilities/RandomNumberGenerator.cpp
        src/core/objects/Rectangle2D.cpp
        src/utilities/Mouse.cpp
        src/utilities/Utils.cpp
)

add_executable(physx src/main.cpp ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(physx PRIVATE ${LLOG_LIBRARIES} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)


# Google Test
include(FetchContent)
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG v1.13.0)
FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif ()

# Test files
set(TEST_FILES
        test/unit-tests/Vec3_TEST.cpp
        test/unit-tests/Vec2_TEST.cpp
)
add_executable(tests ${TEST_FILES} ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(tests PRIVATE ${LLOG_LIBRARIES} gtest_main gmock_main sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

