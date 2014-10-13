//
//  StartScene.cpp
//  ddgame
//
//  Created by mimix on 14-10-10.
//
//

#include "StartScene.h"
#include "SceneSwitch.h"

bool StartScene::init()
{
    auto l=LayerColor::create(Color4B(100, 100, 100, 255), 640, 1136);
    //Size s=Director::getInstance()->getVisibleSize();
    auto aBtn= LabelTTF::create("疯狂模式", "", 30);
    aBtn->setColor(Color3B(255,0,0));
    auto bBtn= LabelTTF::create("简单模式", "", 30);
    
    bBtn->setColor(Color3B(255,0,0));
    auto cBtn= LabelTTF::create("Set", "", 30);
    
    auto itemA=MenuItemSprite::create(aBtn, aBtn,[](Ref* f){
        SceneSwitch::Playing(1);
    });
    auto itemB=MenuItemSprite::create(bBtn, bBtn,[](Ref* f){
        SceneSwitch::Playing(0);
    });
    
    auto itemSet=MenuItemSprite::create(cBtn, cBtn,[](Ref* f){
       SceneSwitch::Seting();
    });
    
<<<<<<< HEAD
    //－－－－－－－－－－－－－－猪的动画－－－－－－－－－－－－－－－－－
    PigAnimation(NULL);
    return true;
}

void StartScene::PigAnimation(Node * n)
{
    const float PosPercent = 0.8;//小猪出现的位置会在屏幕高度的百分比
    
    auto WinSize = Director::getInstance()->getWinSize();//获取窗口大小
    if(n!=NULL)//如果这只猪不是空，则表示他跑完，就将它从场景中删除
        this->removeChild(n);
    auto Pig = PigLayer::createPigById(PigId+1);//创建一只新猪
    Pig->setPosition(Vec2(0, WinSize.height*PosPercent));//设置他的坐标
    auto Move = MoveBy::create(3, Vec2(WinSize.width, 0));//创建一个移动动作
    auto Seq = Sequence::create(Move,CallFuncN::create(CC_CALLBACK_1(StartScene::PigAnimation, this)), NULL);//让动作顺序执行，跑完删除，并且从新创建一只继续跑
    this->addChild(Pig);
    Pig->runAction(Seq);
    PigId = (PigId+1)%8;
}

=======
    //itemB->setPosition(0,40);
    //itemB->setPosition(0,0);
    itemA->setPosition(640/2+80 , 300);
    itemB->setPosition(640/2-80,300);
    itemSet->setPosition(640/2,250);
    Menu* m=Menu::create(itemA,itemB, itemSet, NULL);
    m->setPosition(0,0);
    //m->ignoreAnchorPointForPosition(false);
    l->addChild(m);
    addChild(l);
    return true;
}
>>>>>>> FETCH_HEAD
