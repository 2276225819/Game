//
//  IndexLayer.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "IndexLayer.h"

bool IndexLayer::init()
{
    selectMode();
    
    return true;
}
void IndexLayer::selectMap()
{
    removeAllChildren();
    auto l1=LayerColor::create(Color4B(255, 255, 255, 255), 80, 25);
    auto sb1=MenuItemSprite::create(l1, l1, [&](Ref* r) {
        MessageBox("1", "selectMap");
        this->selectMode();
    });
    sb1->setPosition(80,25);
    auto l2=LayerColor::create(Color4B(255, 255, 255, 255), 80, 80);
    
    auto sb2=MenuItemSprite::create(l2, l2, [&](Ref* r)  {
        MessageBox("2", "selectMap");
        this->selectMode();
    });
    sb2->setPosition(80,25);
    auto menu=Menu::create(sb1, sb2 , NULL);
    addChild(menu);
}

void IndexLayer::selectMode()
{
    removeAllChildren();
    auto l1=LayerColor::create(Color4B(255, 20, 255, 255), 80, 25);
    auto sb1=MenuItemSprite::create(l1, l1, [&](Ref* r) {
        MessageBox("1", "selectMode");
        this->selectMap();
    });
    sb1->setPosition(80,25);
    auto l2=LayerColor::create(Color4B(255, 20, 255, 255), 80, 80);
    
    auto sb2=MenuItemSprite::create(l2, l2, [&](Ref* r)  {
        MessageBox("2", "selectMode");
        this->selectMap();
    });
    sb2->setPosition(80,25);
    auto menu=Menu::create(sb1, sb2 , NULL);
    addChild(menu);
}