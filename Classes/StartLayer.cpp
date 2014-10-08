//
//  StartLayer.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "StartLayer.h"

bool StartLayer::init()
{
    auto l1= LayerColor::create(Color4B(255, 255, 255, 255), 80, 25);
    auto sb1=  MenuItemSprite::create(l1, l1, [](Ref* r) {
        MessageBox("1", "3");
    });
    sb1->setPosition(130,25);
    auto l2=LayerColor::create(Color4B(255, 255, 255, 255), 80, 25);
    auto sb2=MenuItemSprite::create(l2, l2, [](Ref* r)  {
        MessageBox("2", "3");
    }) ;
    sb2->setPosition(10,25);
    auto menu=Menu:: create(sb1,sb2 , NULL);
    addChild(menu);
    
    
    return true;
}