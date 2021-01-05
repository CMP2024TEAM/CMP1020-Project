#pragma once
#include "Action.h"
#include "Past.h"
#include "..\Components\Component.h"
class Copy :
    public Action

{protected:
    Component* the_object;
    int x, y;
    bool Cancel;
public:
    void Execute();
    void Undo();
    void Redo();
    void ReadActionParameters();
    Copy(ApplicationManager* pApp,Component*);
};

