/**
 * @file FixedClock.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 26/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/utilities/FixedClock.hpp"

namespace physx::utils {
    /**
     * @brief @c FixedClock constructor.
     * @param startClock
     *          Whether the clock should start or not.
     */
    FixedClock::FixedClock(bool startClock) {
        if (startClock) {
            start();
        }
    }

    /**
     * @brief Starts the clock.
     */
    void FixedClock::start() {
        if (!running) {
            running = true;
            clock.restart();
        }
    }

    /**
     * @brief Stops the clock.
     */
    void FixedClock::stop() {
        if (running) {
            running = false;
            stoppedTime = clock.getElapsedTime();
        }
    }

    /**
     * @brief Restarts the clock.
     */
    void FixedClock::restart() {
        stoppedTime = sf::Time::Zero;
        running = false;
        start();
    }

    /**
     * @brief Gets the elapsed time since the last frame.
     * @return The elapsed time since the last frame.
     */
    sf::Time FixedClock::GetElapsedTime() const {
        if (running) {
            return stoppedTime + clock.getElapsedTime();
        }
        return stoppedTime;
    }
} // namespace physx::utils