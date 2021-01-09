#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
class load :
    public Action
{
public:
    load(ApplicationManager* pApp);
    void ReadActionParameters();
    void Execute();
    void Undo();
    void Redo();
};

