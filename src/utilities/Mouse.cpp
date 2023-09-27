/**
 * @file Mouse.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/utilities/Mouse.hpp"

namespace physx::utils {
    const sf::RenderWindow* Mouse::window;

    void Mouse::init(sf::RenderWindow* w) {
        window = w;
    }

    bool Mouse::mousePressed(sf::Mouse::Button btn) {
        return sf::Mouse::isButtonPressed(btn);
    }

    math::Vec2f Mouse::getPosition() {
        if (!window->getSystemHandle()) {
            return math::Vec2f::zero();
        }
        return {(float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y};
    }

    math::Vec2f Mouse::getCoords() {
        if (!window->getSystemHandle()) {
            return math::Vec2f::zero();
        }
        return utils::sfVecToVec2(window->mapPixelToCoords(sf::Mouse::getPosition()));
    }

    math::Vec2f Mouse::getRelativePosition() {
        if (!window->getSystemHandle()) {
            return math::Vec2f::zero();
        }
        return utils::sfVecToVec2((sf::Vector2f)sf::Mouse::getPosition(*window));
    }

    math::Vec2f Mouse::getRelativeCoords() {
        if (!window->getSystemHandle()) {
            return math::Vec2f::zero();
        }
        return utils::sfVecToVec2(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
    }
} // namespace physx::utils