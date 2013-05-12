#include "readings.h"


Readings::Readings()
{
    clear();
}

void Readings::clear()
{
    worldWidth = 0;
    worldHeight = 0;
    worldFill = 0.f;

    objectSizeAbs = 0;
    objectSizeRel = 0.f;

    state = Readings::showPast;
    leapFrom = 0;
    leapTo = 0;
    leapDistance = 0;

    leapDifMax = 0.f;
    leapDifRoot = 0.f;
    leapDifK = 0.f;
    leapRootInvar = 0.f;
    leapType = 0;
}

