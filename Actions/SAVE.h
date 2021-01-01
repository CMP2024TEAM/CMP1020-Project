#pragma once
#include "Action.h"
#include"../Components/Component.h"
#include "..\Components\Connection.h"
class Save :
    public Action
{public:
    void save_gates(Component** y,int t);
};

