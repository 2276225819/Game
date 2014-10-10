//
//  Seting.cpp
//  ddgame
//
//  Created by aaa on 14-10-10.
//
//

#include "Seting.h"

Scene * Seting::SceneCreate()
{
    auto s = Seting::create();
    return s;
}

bool Seting::init()
{
    return true;
}