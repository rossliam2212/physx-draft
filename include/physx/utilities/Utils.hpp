/**
 * @file Utils.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 28/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef PHYSX_UTILS_HPP
#define PHYSX_UTILS_HPP

#include <llog/llog.hpp>

namespace physx::utils {
    static bool LLOG_CONFIGURED{false}; ///< To ensure setup only happens once.

    void configureLLOG();
} // namespace physx::utils

#endif //PHYSX_UTILS_HPP
