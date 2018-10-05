#include "stdafx.h"
#include "EntityNotFoundException.h"

namespace Core
{
    EntityNotFoundException::EntityNotFoundException()
        : std::runtime_error("Сущность с таким именем не найдена.")
    {}

    EntityNotFoundException::EntityNotFoundException(
        const std::string& message
    ) : std::runtime_error(message)
    {}

    EntityNotFoundException::EntityNotFoundException(const char* message)
        : std::runtime_error(message)
    {
    }
}
