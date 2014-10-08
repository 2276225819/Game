//
//  MainScene.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "MainScene.h"

#include "IndexLayer.h"


bool MainScene::init()
{ 
    auto st= IndexLayer::create();
    addChild(st);
    
    
    return true;
}