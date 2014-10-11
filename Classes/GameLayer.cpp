//
//  GameLayer.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "GameLayer.h" 
#include "GameOver.h";
#include "SceneSwitch.h"

void shake(Node* n)
{
    n->runAction(
              Repeat::
              create(
                     Sequence::
                     create(
                            RotateBy::
                            create(0.01, -1),
                            RotateBy::
                            create(0.01, 2),
                            RotateBy::
                            create(0.01, -1), NULL), 3));
}


Vec2 offPosition(Vec2 p, Node* by)
{
    return p-by->getPosition() +by->getAnchorPointInPoints();
}

bool GameLayer::init()
{ 
    
    Size s=Director::getInstance()->getVisibleSize();
    root=LayerColor::create(Color4B(100, 100, 100, 255), 640, 640);
    root->ignoreAnchorPointForPosition(false);
    root->setAnchorPoint(Vec2(0.5,1));
    root->setPosition(s.width/2,s.height);
    root->addChild(pigs=PigLayer::create());
    root->addChild(labScore=LabelTTF::create("Score:0", "yahei", 30));
    addChild(root);
    addChild(ctrl=ControlLayer::CreateAt(0));
    labScore->setPosition(0,s.height/2);
    labScore->setAnchorPoint(Vec2(0,0)); 
 
    ctrl->onClick=[&](Vec2 np){
        pigs->each([&](Pig* pig){
            Vec2 tt=offPosition(np, root);
            if (pig->getBoundingBox().containsPoint(offPosition(np, root)))
            {
                pig->Click();
                return onPigDelete(pig);
            }
            return true;
        });
    };
    ctrl->onDrag=[this](int tg){
        pigs->each([&](Pig* pig){
            pig->Drag(tg);
            return onPigDelete(pig);
        });
    };
    pigs->onFlee=[this](Pig* pig){
        this->gameStop();
        this->addChild(GameOver::Create(GameMode));
        ::shake(root);
    };
    return true;
}
bool GameLayer::onPigDelete(Pig* pig)
{
    if (pig->isDie())
    {
        pig->Die();
        this->addScore(1);
        return false;
    }
    return true;
}
void GameLayer::gameStop()
{
    stopAllActions();
    pigs->each([](Pig* p){
        p->stopAllActions();
        return true;
    });
    pigs->stopAllActions();
    removeChild(ctrl);
}

int zScore=1;
void GameLayer::addScore(int i)
{
    score+=i;
    labScore->stopAllActions();
    labScore->runAction(Sequence::create(ScaleBy::create(0.3, 1.1),ScaleTo::create(1, 1),CallFunc::create([]{
 
    
    }), NULL));
    labScore->setString(String::createWithFormat("Score:%d",score)->getCString());

}
