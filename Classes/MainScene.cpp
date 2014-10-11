//
//  MainScene.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "MainScene.h"

#include "StartScene.h"

//#include "jointlayer.h"

bool MainScene::init()
{
    //addChild(JointLayer::create());
    auto st=StartScene::create();
    addChild(st);
    return true;
}