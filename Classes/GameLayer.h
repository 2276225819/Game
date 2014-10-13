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
    int GameMode=0;
private: 
    int score=0;
    void initEvent();
    void gameStop();
public:
    //void Drag(Vec2 Flag);
    //void Click();
    void setCombo(int i);
    int getCombo();
    void addScore(int i);
    bool init();
    CREATE_FUNC(GameLayer);
    //static Scene* CreateScene(IMode mode) ;
public: 
    bool onPigDelete(Pig *pig);
};






#endif /* defined(__ddgame__GameLayer__) */
