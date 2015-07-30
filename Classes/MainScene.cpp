//
//  MainScene.cpp
//  myBooks
//
//  Created by kongbaguni on 2015. 7. 29..
//
//

#include "MainScene.h"
#include "DirectHangleMaker.h"
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
    auto label = Label::createWithBMFont("fonts/direct50.fnt", DH(L"가 갸 거 겨 고 교 구 규 그기"));
    label->setPosition(Vec2(100, 100));
    addChild(label);
    
    
    
    return true;
}



