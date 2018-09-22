#include "stdafx.h"
#include "NotImplementedException.h"

NotImplementedException::NotImplementedException()
    : runtime_error("Ещё не реализовано.")
{}

NotImplementedException::NotImplementedException(const std::string& message)
    : runtime_error(message)
{}

NotImplementedException::NotImplementedException(const char* message)
    : runtime_error(message)
{}
