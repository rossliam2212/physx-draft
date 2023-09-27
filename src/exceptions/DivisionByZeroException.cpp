/**
 * @file DivisionByZeroException.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 23/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/exceptions/DivisionByZeroException.hpp"

namespace physx::except {
    /**
     * @brief @c DivisionByZeroException constructor.
     * @param message
     *          The exception message.
     */
    DivisionByZeroException::DivisionByZeroException(const char* message)
        : message{message} {
    }

    /**
     * @brief @c DivisionByZeroException constructor.
     * @param message
     *          The exception message.
     */
    DivisionByZeroException::DivisionByZeroException(const std::string& message)
        : message{message} {
    }

    /**
     * @brief @c Gets the exception message.
     * @return The exception message.
     */
    const char* DivisionByZeroException::what() const noexcept {
        return message.c_str();
    }
}