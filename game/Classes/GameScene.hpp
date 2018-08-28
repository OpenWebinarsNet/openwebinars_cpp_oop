

#ifndef OPENWEBINARS_OOP_GAME_GAMESCENE_HPP
#define OPENWEBINARS_OOP_GAME_GAMESCENE_HPP


class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(GameScene);
};



#endif //OPENWEBINARS_OOP_GAME_GAMESCENE_HPP
