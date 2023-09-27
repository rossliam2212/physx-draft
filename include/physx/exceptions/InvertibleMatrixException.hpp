/**
 * @file InvertibleMatrixException.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 25/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_INVERTIBLEMATRIXEXCEPTION_HPP
#define PHYSX_INVERTIBLEMATRIXEXCEPTION_HPP

#include <exception>
#include <string>

namespace physx::except {
    /**
     * @brief @c InvertibleMatrixException class.
     *
     * Inherits from std::exception.
     * @namespace @c physx::except
     */
class InvertibleMatrixException : public std::exception {
    public:
        InvertibleMatrixException(const char* message);
        InvertibleMatrixException(const std::string& message);
        ~InvertibleMatrixException() _NOEXCEPT override = default;

        const char* what() const _NOEXCEPT override;

    private:
        std::string message;
    };
} // physx::except


#endif //PHYSX_INVERTIBLEMATRIXEXCEPTION_HPP
