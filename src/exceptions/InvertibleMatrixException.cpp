/**
 * @file InvertibleMatrixException.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/exceptions/InvertibleMatrixException.hpp"

namespace physx::except {
    /**
     * @brief @c InvertibleMatrixException constructor.
     * @param message
     *          The exception message.
     */
    InvertibleMatrixException::InvertibleMatrixException(const char* message)
        : message{message} {
    }

    /**
     * @brief @c InvertibleMatrixException constructor.
     * @param message
     *          The exception message.
     */
    InvertibleMatrixException::InvertibleMatrixException(const std::string& message)
        : message{message} {
    }

    /**
     * @brief @c Gets the exception message.
     * @return The exception message.
     */
    const char* InvertibleMatrixException::what() const _NOEXCEPT {
        return message.c_str();
    }
}