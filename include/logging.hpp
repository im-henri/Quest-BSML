#pragma once
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/utils/typedefs.h"
#include "beatsaber-hook/shared/utils/typedefs-string.hpp"
#include <string_view>

#include "typedefs.hpp"
#include "paper/shared/logger.hpp"

namespace BSML
{
    class Logging
    {
    public:
        static Logger& getLogger();
    };
}
template <> struct fmt::formatter<::StringW> : formatter<string_view> {
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(StringW s, FormatContext& ctx) {
        return formatter<string_view>::format(s ? static_cast<std::string>(s) : "NULL", ctx);
    }
};

template <> struct fmt::formatter<::BSML::SStringW> : formatter<string_view> {
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(::BSML::SStringW s, FormatContext& ctx) {
        return formatter<string_view>::format(s ? static_cast<std::string>(s) : "NULL", ctx);
    }
};

#define INFO(str, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::INF>(str, "BSML" __VA_OPT__(, __VA_ARGS__))
#define ERROR(str, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::ERR>(str, "BSML" __VA_OPT__(, __VA_ARGS__))
#define CRITICAL(str, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::ERR>(str, "BSML" __VA_OPT__(, __VA_ARGS__))
#define DEBUG(str, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::DBG>(str, "BSML" __VA_OPT__(, __VA_ARGS__))
#define WARNING(str, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::WRN>(str, "BSML" __VA_OPT__(, __VA_ARGS__))
