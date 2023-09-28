/**
 * @file Simulation.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/core/Simulation.hpp"

namespace physx::core {

    /**
     * @brief @c Simulation constructor.
     */
    Simulation::Simulation() {
        utils::configureLLOG();
        LLOG_DEBUG("Simulation created.")
    }

    /**
     * @brief @c Simulation destructor.
     */
    Simulation::~Simulation() {
        // BREAKING SIMULATION

//        if (!objects.empty()) {
//            for (auto* obj : objects) {
//                delete obj;
//            }
//        }
    }

    void Simulation::update(math::f32 dt) {
        checkForMouseEvents();
        updatePositions(dt);
        applyConstraints();
        applyGravity();
        checkCollisions(dt);
    }

    /**
     * @brief Adds a @c Circle2D object to the simulation.
     * @param radius
     *          The radius of the circle.
     * @param position
     *          The position of the circle.
     * @param rb
     *          Whether the circle has a @c RigidBody2D or not.
     * @param integrationType
     *          The numerical integration the @c RigidBody2D should use.
     */
    void Simulation::addCircleObject(math::f32 radius, const math::Vec2f& position, bool rb,
                                     dynamic::IntegrationType integrationType) {
        objects.emplace_back(new object::Circle2D{radius, position, rb});
        LLOG_DEBUG("Added Circle2D object to simulation @ pos {}.", position.toString())
    }

    /**
     * @brief Adds a @c Rectangle2D object to the simulation.
     * @param width
     *          The width of the rectangle.
     * @param height
     *          The height of the rectangle.
     * @param position
     *          The position of the rectangle.
     * @param rb
     *          Whether the rectangle has a @c RigidBody2D or not.
     * @param integrationType
     *          The numerical integration the @c RigidBody2D should use.
     */
    void Simulation::addRectangleObject(float width, float height, const math::Vec2f& position, bool rb,
                                        dynamic::IntegrationType integrationType) {
        objects.emplace_back(new object::Rectangle2D{width, height, position, rb});
        LLOG_DEBUG("Added Rectangle2D object to simulation @ pos {}.", position.toString())
    }

    /**
     * @brief Adds an object to the simulation.
     * @param obj
     *          The object to add.
     */
    void Simulation::addObject(object::Object2D* obj) {
        objects.emplace_back(obj);
    }

    /**
     * @brief Gets all the objects in the simulation.
     * @return All the objects in the simulation.
     */
    std::vector<object::Object2D*> Simulation::getObjects() {
        return objects;
    }

    void Simulation::checkForMouseEvents() {
        static bool pressed{false};

        ///< Adding a Circle2D at the position of the mouse when the left button is pressed.
        if (utils::Mouse::mousePressed(sf::Mouse::Left) && !pressed) {
            pressed = true;
            addCircleObject(20.f, utils::Mouse::getRelativePosition(), true);
        }

        if (!utils::Mouse::mousePressed(sf::Mouse::Left)) {
            pressed = false;
        }
    }

    void Simulation::updatePositions(math::f32 dt) {
        for (auto& obj : objects) {
            if (obj->isRbEnabled()) {
                obj->update(dt);
            }
        }
    }

    void Simulation::applyGravity() {
        // For each object in the simulation -> accelerate
        for (auto& obj : objects) {
            if (obj->isRbEnabled()) {
                obj->getRb()->accelerate(gravity);
            }
        }
    }

    void Simulation::applyConstraints() {
        for (auto& obj : objects) {
            auto cast{dynamic_cast<object::Circle2D*>(obj)};
            if (cast) {
                math::Vec2f v{math::Vec2f{500.f, 500.f} - obj->getRb()->getPosition()};
                math::f32 distance{utils::length(v)};

                if (distance > (450.f - cast->getRadius())) {
                    math::Vec2f n{v / distance};
                    obj->getRb()->setPosition(math::Vec2f{500.f, 500.f} - n * (450.f - cast->getRadius()));
                }
            } else {
                auto cast1 = dynamic_cast<object::Rectangle2D*>(obj);
                math::Vec2f v{math::Vec2f{500.f, 500.f} - obj->getRb()->getPosition()};
                float distance{utils::length(v)};

                if (distance > (450.f - cast1->getWidth())) {
                    math::Vec2f n{v / distance};
                    obj->getRb()->setPosition(math::Vec2f{500.f, 500.f} - n * (450.f - cast1->getWidth()));
                }
            }
        }
    }

    void Simulation::checkCollisions(math::f32 dt) {
//        float responseCEOF{0.75f};
//        uint64_t numObjects{objects.size()};
//
//        for (uint64_t i{0}; i < numObjects; ++i) {
//            auto& object1{objects[i]};
//            auto cast1{dynamic_cast<object::Circle2D*>(object1)};
//
//            for (uint64_t k{i + 1}; k < numObjects; ++k) {
//                auto& object2{objects[k]};
//                auto cast2{dynamic_cast<object::Circle2D*>(object2)};
//
//                math::Vec2f v{object1->getRb()->getPosition() - object2->getRb()->getPosition()};
//                float distance{utils::length(v)};
//                float minDistance{cast1->getRadius() + cast2->getRadius()};
//
//                if (distance < (minDistance * minDistance)) {
//                    float distance2{std::sqrt(distance)};
//                    math::Vec2f n{v / distance2};
//                    float massRatio1 = cast1->getRadius() / (cast1->getRadius() + cast2->getRadius());
//                    float massRatio2 = cast2->getRadius() / (cast1->getRadius() + cast2->getRadius());
//                    float delta = 0.5f * responseCEOF * (distance2 - minDistance);
//
//                    auto pos1 = cast1->getRb()->getPosition();
//                    auto pos2 = cast2->getRb()->getPosition();
//
//                    pos1 -= n * (massRatio2 * delta);
//                    pos2 += n * (massRatio1 * delta);
//                    cast1->getRb()->setPosition(pos1);
//                    cast2->getRb()->setPosition(pos2);
//                }
//            }
//        }

        for (std::size_t i{0}; i < objects.size(); ++i) {
            auto* obj1{dynamic_cast<object::Circle2D*>(objects[i])};

            for (std::size_t k{i + 1}; k < objects.size(); ++k) {
                auto* obj2{dynamic_cast<object::Circle2D*>(objects[k])};

                if (checkSATCollision(*obj1, *obj2)) {
                    LLOG_DEBUG("COLLISION")
                    handleCollisionResponse(*obj1, *obj2);
//                    obj1->getRb()->setVelocity({10, 0});
//                    obj2->getRb()->setVelocity({-10, 0});
                }
            }
        }
    }

    bool Simulation::checkSATCollision(object::Circle2D& a, object::Circle2D& b) {
        // Calculate the vector from circleA center to circleB center.
        math::f32 dx{b.getRb()->getPosition().getX() - a.getRb()->getPosition().getX()};
        math::f32 dy{b.getRb()->getPosition().getY() - a.getRb()->getPosition().getY()};

        // Calculate the distance between the two circle centers.
        math::f32 distance{std::sqrt(dx * dx + dy * dy)};

        // If the distance is less than the sum of the radii, they are colliding.
        return distance < (a.getRadius() + b.getRadius());
    }

    void Simulation::handleCollisionResponse(object::Circle2D& a, object::Circle2D& b) {
        // Calculate collision normal
        math::Vec2f collisionNormal{utils::normalize(b.getRb()->getPosition() - a.getRb()->getPosition())};

        // Calculate relative velocity
        math::Vec2f relativeVelocity{b.getRb()->getVelocity() - a.getRb()->getVelocity()};
        math::f32 relativeSpeed{utils::dot(relativeVelocity, collisionNormal)};

        // Check if objects are moving toward each other
        if (relativeSpeed > 0) {
            // Calculate impulse
            math::f32 impulse{-(1 + restitution) * relativeSpeed / (1 / a.getMass() + 1 / b.getMass())};

            // Calculate friction impulse
            math::Vec2f frictionImpulse{relativeVelocity - (collisionNormal * relativeSpeed)};
            frictionImpulse = utils::normalize(frictionImpulse) * impulse * friction;

            // Update velocities
            math::Vec2f tempA{a.getRb()->getVelocity() - impulse - frictionImpulse};
            tempA /= a.getMass();
            tempA = tempA * collisionNormal;
            a.getRb()->setVelocity(tempA / 25.f);

            math::Vec2f tempB{b.getRb()->getVelocity() + impulse + frictionImpulse};
            tempB /= b.getMass();
            tempB = tempB * collisionNormal;
            b.getRb()->setVelocity(tempB / 25.f);

            // Perform position correction to resolve overlap
            math::f32 overlap{a.getRadius() + b.getRadius() - utils::distance(a.getRb()->getPosition(), b.getRb()->getPosition())};
            math::Vec2f correction{collisionNormal * 0.5f * overlap};
            a.getRb()->setPosition(a.getRb()->getPosition() - correction);
            b.getRb()->setPosition(b.getRb()->getPosition() + correction);
        }
    }
} // namespace physx::core