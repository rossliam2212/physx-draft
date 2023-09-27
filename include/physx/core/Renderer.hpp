/**
 * @file Renderer.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_RENDERER_HPP
#define PHYSX_RENDERER_HPP

#include <SFML/Graphics.hpp>

#include "Simulation.hpp"

namespace physx::core {
    /**
     * @brief @c Renderer class.
     * @namespace physx::core
     */
    class Renderer {
    public:
        Renderer(sf::RenderTarget* target);
        ~Renderer() = default;

        void render(Simulation simulation);

    private:
        sf::RenderTarget* target;
    };
} // namespace physx::core


#endif //PHYSX_RENDERER_HPP
