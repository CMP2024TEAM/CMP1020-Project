#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
class Save : public Action
{
public:
    Save(ApplicationManager* pApp);
    void ReadActionParameters();
    void Execute();
    void Undo();
    void Redo();
};

