#pragma once

#include <functional>
#include <map>
#include <string>
#include <vector>

#if !defined(HAS_STD_FORMAT)
#include <fmt/format.h>
#else
#include <format>
#endif

namespace faker
{
class FormatHelper
{
public:
#if !defined(HAS_STD_FORMAT)
    template <typename... Args>
    static std::string format(fmt::format_string<Args...> fmt, Args&&... args)
    {
        return fmt::format(fmt, std::forward<Args>(args)...);
    }
#else
    template <typename... Args>
    static std::string format(std::format_string<Args...> fmt, Args&&... args)
    {
        return std::format(fmt, std::forward<Args>(args)...);
    }
#endif

    static std::string fillTokenValues(const std::string& format,
                                       std::map<std::string, std::function<std::string()>> tokenValueGenerators);
};
}
