#pragma once

#include <stdexcept>

namespace Core
{
    class EntityNotFoundException : public std::runtime_error
    {
    public:
        EntityNotFoundException();
        explicit EntityNotFoundException(const std::string& message);
        explicit EntityNotFoundException(const char* message);
    };
}
