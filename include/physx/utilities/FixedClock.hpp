/**
 * @file FixedClock.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_FIXEDCLOCK_HPP
#define PHYSX_FIXEDCLOCK_HPP

#include <SFML/System/Clock.hpp>

namespace physx::utils {
    /**
     * @brief @c FixedClock class.
     * @namespace physx::utils
     */
    class FixedClock {
    public:
        FixedClock(bool startClock);
        ~FixedClock() = default;

        void start();
        void stop();
        void restart();
        sf::Time GetElapsedTime() const;

    private:
        sf::Clock clock{};
        sf::Time stoppedTime{sf::Time::Zero};
        bool running{false};
    };
} // namespace physx::utils

#endif //PHYSX_FIXEDCLOCK_HPP
