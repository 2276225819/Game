//
//  IMode.h
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#ifndef __ddgame__IMode__
#define __ddgame__IMode__

class IMode
{
public:
    int size;
    void update(); 
public:
    static IMode getEasyMode(int size);
    static IMode getHardMode(int size);
};

#endif /* defined(__ddgame__IMode__) */
