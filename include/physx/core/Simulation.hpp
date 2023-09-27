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

namespace physx::core {
    /**
     * @brief @c Simulation class.
     * @namespace @c physx::core
     */
    class Simulation {
    public:
        Simulation();
        ~Simulation();

        void update(float dt);

        void addCircleObject(float radius, const math::Vec2f& position, bool rb, dynamic::IntegrationType integrationType = dynamic::IntegrationType::Verlet);
        void addRectangleObject(float width, float height, const math::Vec2f& position, bool rb, dynamic::IntegrationType integrationType = dynamic::IntegrationType::Verlet);
        void addObject(object::Object2D* obj);
        std::vector<object::Object2D*> getObjects();

    private:
        std::vector<object::Object2D*> objects;

        math::Vec2f gravity{0.f, 1000.f};
        float restitution{0.2f}; ///< Elasticity of a collision
        float friction{0.1f};

        void checkForMouseEvents();
        void updatePositions(float dt);
        void applyGravity();
        void applyConstraints();
        void checkCollisions(float dt);
        bool checkSATCollision(object::Circle2D& a, object::Circle2D& b);
        void handleCollisionResponse(object::Circle2D& a, object::Circle2D& b);
    };
} // namespace physx::core


#endif //PHYSX_SIMULATION_HPP
