/**
 * @file Engine.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_ENGINE_HPP
#define PHYSX_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <llog/llog.hpp>

#include "../utilities/FixedClock.hpp"
#include "Renderer.hpp"
#include "../utilities/Mouse.hpp"

namespace physx::core {
    /**
     * @brief @c Engine class.
     * @namespace @c physx::core
     */
    class Engine {
    public:
        Engine();
        ~Engine();

        void startSimulation();
        void setSimulation(Simulation* simulation);

    private:
        Simulation* simulation;
        Renderer* renderer;
        sf::RenderWindow* window{nullptr};
        sf::Event event;
        utils::FixedClock dtClock;
        float deltaTime;

        void updateEvents();
        void updateDeltaClock();
        void endSimulation();
        void setupWindow();
        void setupRenderer();
        void setupLLOG();
    };
} // namespace physx::core


#endif //PHYSX_ENGINE_HPP
