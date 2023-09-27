/**
 * @file Renderer.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/core/Renderer.hpp"

namespace physx::core {
    Renderer::Renderer(sf::RenderTarget* target)
        : target{target} {
    }

    void Renderer::render(Simulation simulation) {
        // Constraints
        sf::CircleShape bg{450.f};
        bg.setOrigin(450.f, 450.f);
        bg.setFillColor(sf::Color::White);
        bg.setPosition(500.f, 500.f);
        bg.setPointCount(128);
        target->draw(bg);


        ///< Objects
        auto objects{simulation.getObjects()};

//        sf::CircleShape circle;
//        circle.setPointCount(32);
//        circle.setOrigin(1.f, 1.f);
//
//        for (auto& obj : objects) {
//            // Circle2D
////            if (dynamic_cast<object::Circle2D*>(obj) != nullptr) {
//                // Circle2D Obj
//                auto* cast{dynamic_cast<object::Circle2D*>(obj)};
//                circle.setPosition(obj->getRb()->getPosition().getX(), obj->getRb()->getPosition().getY());
//                circle.setScale(cast->getRadius(), cast->getRadius());
//                circle.setFillColor(sf::Color::Red);
//                target->draw(circle);
////            }
//        }

        sf::CircleShape circle{1.f};
        circle.setPointCount(32);
        circle.setOrigin(1.f, 1.f);

        sf::RectangleShape rect{{1.f, 1.f}};
        rect.setOrigin(1.f, 1.f);

        for (auto& obj : objects) {
            object::Circle2D* cast{dynamic_cast<object::Circle2D*>(obj)};

//            circle.setPosition(obj->getRb()->getPosition().getX(), obj->getRb()->getPosition().getY());
//            circle.setScale(cast->getRadius(), cast->getRadius());
//            circle.setFillColor(sf::Color::Red);
//            target->draw(circle);

            if (cast) {
                circle.setPosition(obj->getRb()->getPosition().getX(), obj->getRb()->getPosition().getY());
                circle.setScale(cast->getRadius(), cast->getRadius());
                circle.setFillColor(sf::Color::Red);
                target->draw(circle);
            } else {
                auto cast1 = dynamic_cast<object::Rectangle2D*>(obj);
                rect.setPosition(obj->getRb()->getPosition().getX(), obj->getRb()->getPosition().getY());
                rect.setScale(cast1->getWidth(), cast1->getHeight());
                rect.setFillColor(sf::Color::Blue);
                target->draw(rect);
            }
        }
    }
} // namespace physx::core