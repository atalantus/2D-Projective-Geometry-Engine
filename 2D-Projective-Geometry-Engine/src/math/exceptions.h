#pragma once
#include <stdexcept>

namespace math
{
    class DimensionMismatch final : public std::runtime_error
    {
    public:
        explicit DimensionMismatch(const std::string& message)
            : std::runtime_error(message)
        {
        }
    };
}
