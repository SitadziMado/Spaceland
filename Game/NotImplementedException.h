#pragma once

#include <stdexcept>

class NotImplementedException : std::runtime_error
{
public:
    NotImplementedException();
    explicit NotImplementedException(const std::string& message);
    explicit NotImplementedException(const char* message);
};
