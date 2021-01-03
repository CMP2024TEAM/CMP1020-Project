#pragma once
#include "Action.h"
#include "..\Components\Component.h"
class Copy :
    public Action

{
    Output* the_message;
public:
    void Execute();
    void Undo();
    void Redo();
    void ReadActionParameters();
    Copy(ApplicationManager* pApp);
};

