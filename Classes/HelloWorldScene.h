#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public Layer
{
private:
    bool isUp;
    bool isColliding;
    Point currentPoint;                 // 현재 좌표
    Size winsize;                       // window Size
    Sequence* playerAction;
    
    CCArray* arPlayer;                  // 플레이어 배열
    CCArray* arBridge;                  // 구름 배열
    
    Sprite* m_pBall;
    
    
    

    
public:
    
    static Scene* createScene();
    
    virtual bool init();
    CREATE_FUNC(HelloWorld);
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void keyPressed(EventKeyboard::KeyCode keyCode, Event *event);
    virtual void keyReleased(EventKeyboard::KeyCode keyCode, Event *event);
    
    //virtual void onEnter();
    //virtual void didAccelerate(Acceleration* pAccelerationValue);
    virtual void onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* unused_event);
    void onAcceleration();
    
    void update();                      // 레이어 업데이트
    void checkCollision(float time);    // 충돌 체크
    void checkPosition(float time);
    void checkBridge(float time);
    
    void moveBridge();                  // 구름 이동
    void createNewBridge();             // 구름 생성
    
    void setCallFunc_0();               // isStop
    void setCallFunc_1(Ref *sender);
    void setCallFunc_2(Ref *sender, void *d);
    void setCallFunc_3(Ref *sender, Ref *object);

};

#endif
