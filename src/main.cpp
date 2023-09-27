#include <iostream>
#include <llog/llog.hpp>
#include <llog/Config.hpp>
#include <SFML/Graphics.hpp>
#include "../include/physx/math/Vec3.hpp"
#include "../include/physx/dynamic/RigidBody.hpp"
#include "../include/physx/core/Simulation.hpp"
#include "../include/physx/core/Engine.hpp"
#include "../include/physx/utilities/RandomNumberGenerator.hpp"

int main() {
//    llog::Config cfg;
//    cfg.useLowercaseLogLevels();
//    llog::setLoggerConfig(cfg);
//
//    LLOG_INFO("Hello World")
//    physx::math::Vec3<float> test{2, 2, 2,};
//    physx::math::Vec3<float> test2{2, 2, 2};
//
//    physx::math::Vec3<float> test3 = test + test2;
//    LLOG_DEBUG("Vec3({}, {}, {})", test3.getX(), test3.getY(), test3.getZ())
//
//    physx::math::Vec3<float>::zero();
//
//    auto t = physx::math::Vec3i {1, 2, 3} / 0;
//    LLOG_DEBUG("Vec3({}, {}, {})", t.getX(), t.getY(), t.getZ())

    // auto engine = physx::engine::getInstance();
    // physx::engine::Simulation simulation{};

    // physx::engine::Circle2D circle;
    // circle.addRigidBody(<params>);

    // simulation.addObjects(<objects>);

    // engine.startSimulation(simulation);

    physx::core::Engine engine;
    auto* simulation{new physx::core::Simulation};

//    for (int i = 0; i < 10; i++) {
//            simulation->addCircleObject(20.f, {(300.f + i * 50), (200.f + i * 25)}, true);
//        if (i < 5)

//        if (i > 5)
//            simulation->addRectangleObject(20.f, 40.f, {(300.f + i * 50), (200.f + i * 25)}, true);
//    }

//    simulation->addCircleObject(20.f, {300.f, 200.f}, true);
//    simulation->addCircleObject(20.f, {400.f, 200.f}, true);

    engine.setSimulation(std::move(simulation)); ///< Moving ownership of the pointer
    engine.startSimulation();


    return 0;
}
