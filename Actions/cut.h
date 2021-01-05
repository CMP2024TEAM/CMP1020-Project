#pragma once
#include "Action.h"
#include "..\Components\Component.h"
class cut :
    public Action
{
protected:
    Component* the_object;
    int x, y;
public:
    void Execute();
    void Undo();
    void Redo();
    void ReadActionParameters();
    cut(ApplicationManager* pApp,Component*);
};

