#pragma once
#include "Action.h"
#include "..\Components\Component.h"
class Past :
    public Action
{
    int x, y;
  
public:
    
    void Execute();
    void Undo();
    void Redo();
    void ReadActionParameters();
    Past(ApplicationManager* pApp);
};

