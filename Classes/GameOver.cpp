//
//  GameOver.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "GameOver.h"
#include "SceneSwitch.h"


bool GameOver::init()
{
    Layer::init();
    Size s=Director::getInstance()->getVisibleSize();
    
    
    auto bg=LayerColor::create(Color4B(0, 100, 100, 100), 540, 340);
    bg->ignoreAnchorPointForPosition(false);
    bg->setPosition(s.width*0.5,s.height*0.5);
    
    auto itemRestart=MenuItemLabel::create(LabelTTF::create("重新开始", "", 30), [this](Ref* f){
        SceneSwitch::Playing(gameType);
    });
    auto itemMenu=MenuItemLabel::create(LabelTTF::create("主菜单", "", 30), [this](Ref* f){
        SceneSwitch::Starting();
    });
    itemRestart->setPosition(140,40);
    itemMenu->setPosition(400,40);
    
    
    auto menu=Menu::create(itemRestart,itemMenu,NULL);
    menu->setPosition(0,0);
    bg->addChild(menu);
    addChild(bg);
    return true;
}