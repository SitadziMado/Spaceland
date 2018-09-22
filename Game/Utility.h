#pragma once

#include <string>

#include <cinttypes>

namespace Core
{
    template<typename T>
    using Ptr = std::shared_ptr<T>;

    using Float = double;
    using Int = int64_t;
    using Float = double;
    using String = std::string;

    template<typename T, typename... TArgs>
    std::shared_ptr<T> alloc(TArgs&&... args)
    {
        return std::make_shared<T>(std::forward<TArgs>(args)...);
    }
}