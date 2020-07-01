#include "BowlingBall.h"

BowlingBall::BowlingBall(ObjInfo info, bool movable, b2World& world)
    :Ball(info._loc, movable, world, bowlingBall)
{
}

bool BowlingBall::m_registerit = ObjFactory::registerit(bowlingBall, [](ObjInfo info, bool movable, b2World& world) -> std::shared_ptr<GameObj> { return std::make_shared<BowlingBall>(info, movable, world); });