//
//  StartScene.cpp
//  ddgame
//
//  Created by mimix on 14-10-10.
//
//

#include "StartScene.h"
#include "SceneSwitch.h"
#include "PigLayer.h"

bool StartScene::init()
{
    PigId=0;
    auto l=LayerColor::create(Color4B(100, 100, 100, 255), 640, 1136);
    auto Normal = LabelTTF::create("简单模式", "", 30);//创建简单模式按钮
    auto Insane = LabelTTF::create("疯狂模式", "", 30);//创建疯狂模式按钮
    auto Flurry = LabelTTF::create("群猪乱舞", "", 30);//创建群猪乱舞按钮
    auto SetButton= LabelTTF::create("设置", "", 30);//创建设置按钮
    Normal->setColor(Color3B(255,0,0));//设置简单模式的前景色
    Insane->setColor(Color3B(255,0,0));//设置疯狂模式的前景色
    Flurry->setColor(Color3B(255,0,0));//设置乱舞模式的前景色
    
    auto itemNormal = MenuItemSprite::create(Normal, Normal,[](Ref* f){//点击触发跳到普通模式场景
        SceneSwitch::Playing(0);
    });
    auto itemInsane = MenuItemSprite::create(Insane, Insane,[](Ref* f){//点击触发跳到疯狂模式场景
        SceneSwitch::Playing(1);
    });
    auto itemFlurry = MenuItemSprite::create(Flurry, Flurry,[](Ref* f){//点击触发跳到乱舞模式场景
        SceneSwitch::Playing(2);
    });
    auto itemSet = MenuItemLabel::create(SetButton,[](Ref* f){//点击触发跳到设置页面
       SceneSwitch::Seting();
    });
    auto SetButtonSize = itemSet->getBoundingBox().size;//获取设置按钮的大小
    itemNormal->setPosition(640/2,600);//设置普通模式的按钮坐标
    itemInsane->setPosition(640/2,500);//设置疯狂模式的按钮坐标
    itemFlurry->setPosition(640/2,400);//设置乱舞模式的按钮坐标
    itemSet->setPosition(0+SetButtonSize.width,0+SetButtonSize.height);//设置 设置按钮 的坐标
    Menu* m=Menu::create(itemInsane,itemNormal,itemFlurry,itemSet, NULL);//创建一个目录加入全部的按钮
    m->setPosition(0,0);//设置目录的坐标为原点
    l->addChild(m);//将目录加入背景层
    addChild(l);//将背景层加入场景
    
    //－－－－－－－－－－－－－－猪的动画－－－－－－－－－－－－－－－－－
    
    return true;
}

void StartScene::PigAnimation(float f)
{
    float PosPercent = 0.8;
    auto WinSize = Director::getInstance()->getWinSize();
    auto Pig = PigLayer::createPigById(PigId);
    Pig->setPosition(Vec2(0, WinSize.height*PosPercent));
    
    PigId = (PigId+1)%8;
}