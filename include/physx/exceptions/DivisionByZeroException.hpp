/**
 * @file DivisionByZeroException.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 23/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_DIVISIONBYZEROEXCEPTION_HPP
#define PHYSX_DIVISIONBYZEROEXCEPTION_HPP

#include <exception>
#include <string>

namespace physx::except {
    /**
     * @brief @c DivisionByZeroException class.
     *
     * Inherits from @c std::exception.
     * @namespace @c physx::except
     */
    class DivisionByZeroException : public std::exception {
    public:
        DivisionByZeroException(const char* message);
        DivisionByZeroException(const std::string& message);
        ~DivisionByZeroException() _NOEXCEPT override = default;

        const char* what() const _NOEXCEPT override;

    private:
        std::string message;
    };
} // physx::except


#endif //PHYSX_DIVISIONBYZEROEXCEPTION_HPP
