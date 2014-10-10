//
//  MainScene.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "MainScene.h"

#include "StartScene.h"

bool MainScene::init()
{ 
    auto st=StartScene::create();
    addChild(st);
    return true;
}