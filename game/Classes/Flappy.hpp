//
// Created by netwave on 8/26/18.
//

#ifndef OPENWEBINARS_OOP_GAME_FLAPPY_HPP
#define OPENWEBINARS_OOP_GAME_FLAPPY_HPP

#include "cocos2d.h"

class Flappy
{
private:
    cocos2d::Sprite*                     m_sprite;
    cocos2d::EventListenerKeyboard*      m_listener;

    Flappy(const std::string& sprite_image) :
        m_sprite(cocos2d::Sprite::create(sprite_image)),
        m_listener(cocos2d::EventListenerKeyboard::create())
    {
        //add physics to sprite
        m_sprite->setPhysicsBody(
                cocos2d::PhysicsBody::createCircle(m_sprite->getScaleX()/2)
        );
        m_sprite->getPhysicsBody()->setMass(100.f);
        m_sprite->getPhysicsBody()->setRotationEnable(false);
        m_sprite->getPhysicsBody()->setVelocityLimit(300);
        //add to react to touch
        m_listener->onKeyReleased = [this](cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
                                    {
                                        if(key == cocos2d::EventKeyboard::KeyCode::KEY_SPACE)
                                            this->jump();
                                    };
        cocos2d::Director::getInstance()
        ->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(m_listener, m_sprite);

    }

    void jump()
    {
        auto body = m_sprite->getPhysicsBody();
        float impulse_amount = body->getMass() * 300 - body->getVelocity().y;
        body->applyImpulse(cocos2d::Vec2(0, impulse_amount), body->getPosition());
    }

public:
    ~Flappy()
    {
        delete m_sprite;
        delete m_listener;
    }
    cocos2d::Sprite* getSprite() {return m_sprite;}
    static Flappy* create(cocos2d::Vec2 pos = cocos2d::Vec2(0,0))
    {
        Flappy* flappy = new Flappy("flappy.png");
        flappy->m_sprite->setPosition(pos);
        return flappy;
    }

};
#endif //OPENWEBINARS_OOP_GAME_FLAPPY_HPP
