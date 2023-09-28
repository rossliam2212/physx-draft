/**
 * @file Engine.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/core/Engine.hpp"

namespace physx::core {
    /**
     * @brief @c Engine constructor.
     * @param simulation
     *          The simulation to run.
     */
    Engine::Engine()
        : dtClock{true} {
        utils::configureLLOG();
        LLOG_INFO("physx starting...")
        setupWindow();
        setupRenderer();

        utils::Mouse::init(window);
    }

    /**
     * @brief @c Engine destructor.
     */
    Engine::~Engine() {
        delete window;
        delete renderer;
        delete simulation;
    }

    /**
     * @brief Starts the simulation.
     */
    void Engine::startSimulation() {
        LLOG_INFO("Started simulation...")
        if (window != nullptr) {
            while (window->isOpen()) {
                updateEvents();
                updateDeltaClock();
                simulation->update(deltaTime);

                window->clear();
                renderer->render(*simulation);
                window->display();
            }
        }
    }

    /**
     * @brief Sets the @c Simulation.
     * @param theSimulation
     *          The @c Simulation.
     */
    void Engine::setSimulation(Simulation* theSimulation) {
        simulation = theSimulation;
    }

    /**
     * @brief Checks for an @c sf::Event::Closed polled from the simulation window.
     */
    void Engine::updateEvents() {
        if (window != nullptr) {
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    endSimulation();
                }

//                if (event.type == sf::Event::MouseButtonPressed) {
//                    if (event.mouseButton.button == sf::Mouse::Button::Left) {
//                        simulation->addCircleObject(20.f, utils::Mouse::getRelativePosition(), true);
//                    }
//                }
            }
        }
    }

    /**
     * @brief Updates the delta clock.
     */
    void Engine::updateDeltaClock() {
        dtClock.stop();
        deltaTime = dtClock.GetElapsedTime().asSeconds();
        dtClock.start();
    }

    /**
     * @brief Ends the simulation.
     */
    void Engine::endSimulation() {
        if (window != nullptr) {
            window->close();
            LLOG_INFO("Ended simulation.")
        }
    }

    /**
     * @brief Initializes the simulation window.
     */
    void Engine::setupWindow() {
//        sf::VideoMode desktop{sf::VideoMode::getDesktopMode()};
//        sf::VideoMode vm{desktop.width, desktop.height};
        sf::VideoMode vm{1000, 1000};
        window = new sf::RenderWindow{vm, "physx", sf::Style::Titlebar | sf::Style::Close};
        window->setFramerateLimit(60);
        LLOG_DEBUG("Window initialized.")
    }

    /**
     * @brief Initializes the @c Renderer.
     */
    void Engine::setupRenderer() {
        renderer = new Renderer{window};
        LLOG_DEBUG("Renderer initialized.")
    }
} // namespace physx::core