//
//  GameLayer.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "GameLayer.h" 
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
    root->setAnchorPoint(Vec2(0.5,0.5));
    root->setPosition(s.width/2,s.height/2);
    root->addChild(pigs=PigLayer::create());
    root->addChild(labScore=LabelTTF::create("Score:0", "yahei", 30));
    root->addChild(ctrl=ControlLayer::CreateAt(0));
    addChild(root);
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
    pigs->onRemove=[this](Pig* pig){
        if (!pig->isDie())
        {
            //int life
            SceneSwitch::Starting();
            ::shake(root);
        }
    };
    return true;
}
bool GameLayer::onPigDelete(Pig* pig)
{
    if (pig->isDie())
    {
        pig->Kill();
        this->addScore(1);
        return false;
    }
    return true;
}




void GameLayer::addScore(int i)
{
    score+=i;
    labScore->setString(String::createWithFormat("Score:%d",score)->getCString());

}
