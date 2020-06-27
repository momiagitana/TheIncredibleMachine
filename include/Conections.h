#pragma once
#include "GameObj.h"


class Conections
{
private:
    std::vector<std::pair<GameObj*, GameObj*>> m_conections;

    GameObj* m_first = nullptr;
    GameObj* m_second = nullptr;


public:
    Conections();
    ~Conections();

    


    bool tryConecting (std::shared_ptr<GameObj>);
};
