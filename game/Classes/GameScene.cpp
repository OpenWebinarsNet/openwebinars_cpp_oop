//
// Created by netwave on 8/26/18.
//

#include "GameScene.hpp"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::createScene();
}

bool GameScene::init()
{
    if(!Scene::initWithPhysics()) return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin      = Director::getInstance()->getVisibleOrigin();

    this->addChild(Flappy::create());
}