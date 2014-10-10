//
//  GameLayer.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "GameLayer.h" 



const Vec2 Flag[8] = {Vec2(0,0),Vec2(0,0.5),Vec2(0,1),Vec2(0.5,1),Vec2(1,1),Vec2(1,0.5),Vec2(1,0),Vec2(0.5,0)};


Scene* GameLayer::CreateScene(IMode mode)
{
    auto s=Scene::create();
    auto g=GameLayer::create();
    g->mode=mode;
    s->addChild(g);
    return s;
}

bool GameLayer::init()
{
    Size s=Director::getInstance()->getVisibleSize();
    auto root=LayerColor::create(Color4B(100, 100, 100, 255), 640, 640);
    root->ignoreAnchorPointForPosition(false);
    root->setAnchorPoint(Vec2(0.5,0));
    root->setPosition(630/2,300);
    root->addChild(pigs=PigLayer::create());
    root->addChild(labScore=LabelTTF::create("TEXT", "yahei", 30));
    root->addChild(ctrl=ControlLayer::CreateAt(0));
    addChild(root);
    
    labScore->setPosition(0,s.height/2);
    labScore->setAnchorPoint(Vec2(0,0));
    
    ModeA();
    
    ctrl->onClick=[this](Vec2 np){
        pigs->each([&](Pig* pig){
            if (pig->getBoundingBox().containsPoint(np))
            {
                log("%f %f",np.x,np.y);
                (pig)->Click();
                if (pig->isDie()) {
                    this->addScore(1);
                }
            }
        });
    };
    ctrl->onDrag=[this](int tg){
        pigs->each([&](Pig* pig){
            pig->Drag(tg);
            if (pig->isDie()) {
                this->addScore(1);
            }
        });
    };
    return true;
}




int score=0;
void GameLayer::addScore(int i)
{
    score+=i;
    labScore->setString(String::createWithFormat("%d",score)->getCString());

}


void GameLayer::ModeA()//游戏模式一：随机创建
{
    ActionInterval* ac;
    ac=Sequence::create(CallFunc::create([&]{
        pigs->addRndPig();
    }),DelayTime::create(4), NULL);
    ac=RepeatForever::create(ac);
    runAction(ac);
}