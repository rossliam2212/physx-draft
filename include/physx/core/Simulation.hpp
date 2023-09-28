/**
 * @file Simulation.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_SIMULATION_HPP
#define PHYSX_SIMULATION_HPP

#include <vector>

#include "../core/objects/Circle2D.hpp"
#include "../core/objects/Rectangle2D.hpp"
#include "../utilities/Vec2Utils.hpp"
#include "../utilities/Mouse.hpp"
#include "../utilities/Utils.hpp"

namespace physx::core {
    /**
     * @brief @c Simulation class.
     * @namespace @c physx::core
     */
    class Simulation {
    public:
        Simulation();
        ~Simulation();

        void update(math::f32 dt);

        void addCircleObject(math::f32 radius, const math::Vec2f& position, bool rb, dynamic::IntegrationType integrationType = dynamic::IntegrationType::Verlet);
        void addRectangleObject(math::f32 width, math::f32 height, const math::Vec2f& position, bool rb, dynamic::IntegrationType integrationType = dynamic::IntegrationType::Verlet);
        void addObject(object::Object2D* obj);
        std::vector<object::Object2D*> getObjects();

    private:
        std::vector<object::Object2D*> objects;

        math::Vec2f gravity{0.f, 1000.f};     ///< Gravity
        math::f32 restitution{0.2f};          ///< Elasticity of a collision
        math::f32 friction{0.1f};             ///< Friction coefficient

        void checkForMouseEvents();
        void updatePositions(math::f32 dt);
        void applyGravity();
        void applyConstraints();
        void checkCollisions(math::f32 dt);
        bool checkSATCollision(object::Circle2D& a, object::Circle2D& b);
        void handleCollisionResponse(object::Circle2D& a, object::Circle2D& b);
    };
} // namespace physx::core


#endif //PHYSX_SIMULATION_HPP
