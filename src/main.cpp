// Copyright 2025 FEFU Best Team
#include "../include/Core/Engine.h"
#include <Core/Ai.h>
#include <iostream>
int main()
{
    // ��� ��������� �����
    srand(time(0));
    
    Engine engine;
    engine.init();
    engine.run();
    engine.end();
    
    return 0;
}
