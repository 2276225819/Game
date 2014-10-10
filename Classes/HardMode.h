//
//  HardMode.h
//  ddgame
//
//  Created by mimix on 14-10-10.
//
//

#ifndef __ddgame__HardMode__
#define __ddgame__HardMode__


#include "GameLayer.h"

class HardMode :public GameLayer
{
public:
    void start();
    bool init();
    CREATE_FUNC(HardMode);
};
#endif /* defined(__ddgame__HardMode__) */
