/**
 * @file Mouse.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_MOUSE_HPP
#define PHYSX_MOUSE_HPP

#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../utilities/Vec2Utils.hpp"

namespace physx::utils {
    class Mouse {
    public:
        static void init(sf::RenderWindow* t);
        ~Mouse() = default;

        static bool mousePressed(sf::Mouse::Button btn);
        static math::Vec2f getPosition();
        static math::Vec2f getCoords();
        static math::Vec2f getRelativePosition();
        static math::Vec2f getRelativeCoords();

    private:
        const static sf::RenderWindow* window;
    };
} // namespace physx::utils


#endif //PHYSX_MOUSE_HPP
