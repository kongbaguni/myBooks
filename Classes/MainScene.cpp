//
//  MainScene.cpp
//  myBooks
//
//  Created by kongbaguni on 2015. 7. 29..
//
//

#include "MainScene.h"
#include "DirectHangleMaker.h"
MainScene::MainScene():
_pLabel(nullptr)
{
    
}
MainScene::~MainScene()
{
    CC_SAFE_RELEASE_NULL(_pLabel);
    
}

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    if (scene && layer)
    {
        scene->addChild(layer);
        return scene;
    }
    return nullptr;
}

bool MainScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    auto label = Label::createWithBMFont("fonts/direct50.fnt", DH(L"1+2=105"));
    label->setAnchorPoint(Vec2::ZERO);
    label->setPosition(Vec2(100, 100));
    addChild(label);
    label->runAction
    (RepeatForever::create
     (Sequence::create
      (DelayTime::create(2.0f),
       JumpBy::create(0.5f, Vec2::ZERO, 50, 1),
       CallFunc::create(CC_CALLBACK_0(MainScene::changeString, this))
       , NULL)
      ));
    
    setLabel(label);
    
    return true;
}

void MainScene::changeString()
{
    
    std::string stringList[] =
    {
        DH(L"우리집 강아지는 복슬강아지"),
        DH(L"학교갔다 돌아오면 멍멍멍"),
        DH(L"반갑다고 꼬리치며 멍멍멍"),
        DH(L"<철수>는 <순이>보다 똘똘하냐?"),
        DH(L"1+1=3"),
    };
    
    static int iCnt = 0;
    _pLabel->setString(stringList[iCnt]);
    
    iCnt++;
    if (iCnt==sizeof(stringList)/sizeof(std::string))
    {
        iCnt=0;
    }
    
}



