#pragma once
#include"BaseObject.h"

class GameObj :public BaseObject
{
public:
	GameObj();


private:
	sf::Vector2f m_startLoc;
	bool m_movable;
	bool m_dynamic;
};
