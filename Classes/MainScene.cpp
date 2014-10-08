//
//  MainScene.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "MainScene.h"

#include "StartLayer.h"


bool MainScene::init()
{ 
    auto st= StartLayer::create();
    addChild(st);
    
    
    return true;
}