//
//  GameLayer.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "GameLayer.h" 

Vec2 offPosition(Vec2 p, Node* by)
{
    return p-by->getPosition();
}

const Vec2 Flag[8] = {Vec2(0,0),Vec2(0,0.5),Vec2(0,1),Vec2(0.5,1),Vec2(1,1),Vec2(1,0.5),Vec2(1,0),Vec2(0.5,0)};

/*
Scene* GameLayer::CreateScene(IMode mode)
{
    auto s=Scene::create();
    auto g=GameLayer::create(); 
    s->addChild(g);
    return s;
}*/

bool GameLayer::init()
{
    Size s=Director::getInstance()->getVisibleSize();
    root=LayerColor::create(Color4B(100, 100, 100, 255), 640, 640);
    root->ignoreAnchorPointForPosition(false);
    root->setAnchorPoint(Vec2(0,0));
    root->setPosition(0,300);
    root->addChild(pigs=PigLayer::create());
    root->addChild(labScore=LabelTTF::create("Score:0", "yahei", 30));
    root->addChild(ctrl=ControlLayer::CreateAt(0));
    addChild(root);
    
    labScore->setPosition(0,s.height/2);
    labScore->setAnchorPoint(Vec2(0,0)); 
    
    ctrl->onClick=[&](Vec2 np){
        Vec2 o1=np;
        pigs->each([&](Pig* pig){ 
            if (pig->getBoundingBox().containsPoint(offPosition(np, root)))
            {
                pig->Click();
                onPigDelete(pig);
            }
        });
    };
    ctrl->onDrag=[this](int tg){
        pigs->each([&](Pig* pig){
            pig->Drag(tg);
            onPigDelete(pig);
        });
    };
    return true;
}
void GameLayer::onPigDelete(Pig* pig)
{
    if (pig->isDie())
    {
        pig->Remove();
        this->addScore(1);
    }
}



int score=0;
void GameLayer::addScore(int i)
{
    score+=i;
    labScore->setString(String::createWithFormat("Score:%d",score)->getCString());

}
