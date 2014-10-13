#ifndef __ddgame__GameLayer__
#define __ddgame__GameLayer__
#include "cocos2d.h"
#include "PigLayer.h"
#include "ControlLayer.h"
USING_NS_CC;

class GameLayer:public Layer
{
protected:
    Node* root;
    PigLayer* pigs;
    LabelTTF* labScore;
    ControlLayer* ctrl;
    private:
    int score=0;
    void initEvent();
    void gameStop();
public:
    int GameMode=1; 
    void setCombo(int i);
    int Combo=0;
    void addScore(int i);
    bool init();
    CREATE_FUNC(GameLayer);
public: 
    virtual bool onPigDelete(Pig *pig);
};

#endif /* defined(__ddgame__GameLayer__) */
