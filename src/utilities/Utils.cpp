/**
 * @file Utils.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 28/09/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/physx/utilities/Utils.hpp"

namespace physx::utils {
    /**
     * @brief Sets up @c llog logger config.
     */
    void configureLLOG() {
        if (!LLOG_CONFIGURED) {
            llog::Config cfg;
            cfg.enableConsoleColors();
            cfg.useLowercaseLogLevels();
            cfg.displayOnlyLogLevelInColor();
//        cfg.disableDebugLogLevel();
            llog::setLoggerConfig(cfg);

            LLOG_DEBUG("llog configured.")
            LLOG_CONFIGURED = true;
        }
    }
} // namespace physx::utils
