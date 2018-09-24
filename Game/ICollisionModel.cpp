#include "stdafx.h"
#include "ICollisionModel.h"

namespace Core
{
    ICollisionModel::Bounds::Bounds(Float left, Float top, Float width, Float height)
        : l(left), t(top), r(left + width), b(top + height)
    {}
}
