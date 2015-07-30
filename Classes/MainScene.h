//
//  MainScene.h
//  myBooks
//
//  Created by kongbaguni on 2015. 7. 29..
//
//

#ifndef __myBooks__MainScene__
#define __myBooks__MainScene__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class MainScene : public Layer
{
public:
    CREATE_FUNC(MainScene);
    static Scene* createScene();
    
protected:
    virtual bool init() override;
    
};
#endif /* defined(__myBooks__MainScene__) */
