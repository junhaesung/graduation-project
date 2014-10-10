#include "HelloWorldScene.h"
#include <cstdlib>
#include <ctime>

#define TAG_BRIDGE_1  0
#define TAG_BRIDGE_2  1
#define TAG_BRIDGE_3  2
#define TAG_BRIDGE_4  3
#define TAG_BRIDGE_5  4

#define TAG_SPRITE_PLAYER    10


Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    isUp = true;
    isColliding = false;
    currentPoint = Point(0,0);
    
    winsize = Director::getInstance()->getWinSize();
    setAccelerometerEnabled(true);
    
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
    
    //keyboardListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event *event){
    //    CCLOG("%d press", keyCode);
    //};
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(keyboardListener, 2);
    
    // init 함수에서 배열을 생성하여
    // 미사일과 적비행기 배열을 초기화합니다
    // 배열을 초기화한 후 retain() 함수를 호출해야
    // 배열이 정상적으로 작동.
    
    // 배열 초기화
    arPlayer = CCArray::create();
    arPlayer->retain();
    arBridge = CCArray::create();
    arBridge->retain();
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
    
    float winWidth = winsize.width;
    float winHeight = winsize.height;
    
    srand((unsigned)time(NULL));
    // int result = 범위의 하한 + (int) ( 범위 * rand()/ (RAND_MAX + 1.0) );
    // float result = winWidth * ( rand()%20 ) / 20 ;
    // float randWidth = result;
    
    float randWidth = winWidth * ( rand()%20 ) / 20 ;
    
    auto spr_1 = Sprite::create("cloud01_550x400.jpg", Rect(20,100,530,200));
	spr_1->setScale(0.25);
    spr_1->setAnchorPoint(Point(0.5, 0));
	spr_1->setPosition(Point(winWidth/2, winHeight/7*0));
    spr_1->setTag(0);
	this->addChild(spr_1);
    arBridge->addObject(spr_1);
    
    randWidth = winWidth * ( rand()%20 ) / 20 ;
    
    auto spr_2 = Sprite::create("cloud01_550x400.jpg", Rect(20,100,530,200));
	spr_2->setScale(0.25);
	spr_2->setAnchorPoint(Point(0.5, 0.5));
	spr_2->setPosition(Point(randWidth, winHeight/7*2));
    spr_2->setTag(1);
	this->addChild(spr_2);
    arBridge->addObject(spr_2);
    
    randWidth = winWidth * ( rand()%20 ) / 20 ;
    
    auto spr_3 = Sprite::create("cloud01_550x400.jpg", Rect(20,100,530,200));
	spr_3->setScale(0.25);
	spr_3->setAnchorPoint(Point(0.5, 0.5));
	spr_3->setPosition(Point(randWidth, winHeight/7*4));
    spr_3->setTag(2);
	this->addChild(spr_3);
    arBridge->addObject(spr_3);
    
    randWidth = winWidth * ( rand()%20 ) / 20 ;
    
    auto spr_4 = Sprite::create("cloud01_550x400.jpg", Rect(20,100,530,200));
	spr_4->setScale(0.25);
	spr_4->setAnchorPoint(Point(0.5, 0.5));
	spr_4->setPosition(Point(randWidth, winHeight/7*6));
    spr_4->setTag(3);
	this->addChild(spr_4);
    arBridge->addObject(spr_4);
    
    randWidth = winWidth * ( rand()%20 ) / 20 ;
    
    
    auto player = Sprite::create("ball_green_200x200.png");
    player->setScale(0.5);
    player->setAnchorPoint(Point(0.5,0.5));
    player->setPosition(winWidth/2+15, winHeight*0/7);
    player->setTag(TAG_SPRITE_PLAYER);
    this->addChild(player);
    arPlayer->addObject(player);
    /*
    auto moveUpAction = MoveBy::create(1.0, Point(0,winsize.height*2/9));
    auto easeAction = EaseOut::create(moveUpAction, 3.0);
    auto moveDownAction = MoveBy::create(5.0, Point(0, -winsize.height));
    auto easeAction2 = EaseIn::create(moveDownAction, 3.0);
    auto sequenceAction = Sequence::create(easeAction, easeAction2, NULL);
     */
    
    auto jumpAction = JumpBy::create(2.0, Point(0,0), winsize.height*3/7, 1);
    auto moveAction = MoveBy::create(1.5 ,Point(0, -winsize.height));
    auto sequenceAction = Sequence::create(jumpAction,
                                           moveAction, NULL);
    player->runAction(sequenceAction);
    
    
    update();
    

    return true;
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
    /*
    Point location = touch->getLocation();
    
    Sprite* player = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
    player->stopAllActions();
    
    if(player->getPositionY() > winsize.height/2 ) {
        // bridge들이 움직인다
        moveBridge();
        
        auto jumpAction = JumpBy::create(0.86, Point(0,0), winsize.height*1/7, 1);
        auto moveAction = MoveBy::create(1.5 ,Point(0, -winsize.height));
        auto sequenceAction = Sequence::create(jumpAction,
                                               moveAction,
                                               NULL);
        player->runAction(sequenceAction);
    }
    else {
        auto jumpAction = JumpBy::create(1.5, Point(0,0), winsize.height*3/7, 1);
        auto moveAction = MoveBy::create(1.5 ,Point(0, -winsize.height));
        auto sequenceAction = Sequence::create(jumpAction,
                                               moveAction, NULL);
        player->runAction(sequenceAction);
    }
     */

    return true;
}

void HelloWorld::update()
{
    schedule(schedule_selector(HelloWorld::checkCollision));    // 충돌 검사
    schedule(schedule_selector(HelloWorld::checkPosition));     // 공이 어느 방향인지 검사
    schedule(schedule_selector(HelloWorld::checkBridge));       // 구름이 화면아래면 삭제
}

void HelloWorld::checkCollision(float time) {
    Object* obj = NULL;
    
    CCARRAY_FOREACH(arBridge, obj) {
        Sprite* bridge = (Sprite*) obj;
        auto player = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
        
        if(bridge->getBoundingBox().intersectsRect(player->getBoundingBox()) && isUp == false) {
            if(player->getPosition().y >= winsize.height*4/7 && isColliding == false) {
                isColliding = true;
                player->stopAllActions();
                player->setPositionY(currentPoint.y+2);
                
                // 3층이면, 구름 모두 아래로 이동하고 공은 낮게 튕김
                moveBridge();
                auto jumpAction = JumpBy::create(0.86, Point(0,0), winsize.height*1/7, 1);
                auto moveAction = MoveBy::create(1.5 ,Point(0, -winsize.height));
                auto sequenceAction = Sequence::create(jumpAction,
                                                       moveAction, NULL);
                player->runAction(sequenceAction);
            }
            else {
                // 공만 튕김
                player->stopAllActions();
                auto jumpAction = JumpBy::create(1.5, Point(0,0), winsize.height*3/7, 1);
                auto moveAction = MoveBy::create(1.5 ,Point(0, -winsize.height));
                auto sequenceAction = Sequence::create(jumpAction,
                                                       moveAction, NULL);
                player->runAction(sequenceAction);
            }
            isColliding = false;
        }
    }
}

void HelloWorld::moveBridge()
{
    log("moveBridge is called.");
    Object* obj = NULL;
    // 블록 생성
    createNewBridge();
    
    CCARRAY_FOREACH(arBridge, obj) {
        Sprite* bridge = (Sprite*)obj;
        auto action  = MoveBy::create(0.5, Point(0, -winsize.height*2/7));
        //auto action2 = EaseOut::create(action, 1.5);
        bridge->runAction(action);
    }
}

void HelloWorld::createNewBridge()
{
    // 화면 위에 구름 새로 하나 만듦
    auto spr = Sprite::create("cloud01_550x400.jpg", Rect(20,100,530,200));
    spr->setScale(0.25);
    spr->setAnchorPoint(Point(0.5, 0.5));
    spr->setPosition(Point(rand()%(int)winsize.width, winsize.height/7*8));
    this->addChild(spr);
    arBridge->addObject(spr);
}


void HelloWorld::checkPosition(float time)
{
    auto player = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
    Point playerPoint = player->getPosition();
    
    if(currentPoint.y > playerPoint.y) {
        isUp = false;
    }
    else {
        isUp = true;
    }
    
    currentPoint = playerPoint;
}

void HelloWorld::checkBridge(float time)
{
    Object* obj = NULL;
    
    CCARRAY_FOREACH(arBridge, obj)
    {
        auto bridge = (Sprite*)obj;
        // 아래로 내려간 구름 지우기
        if(bridge->getPositionY() < 0 ) {
            removeChild(bridge, false);
            arBridge->removeObject(bridge);
        }
    }
}

void HelloWorld::setCallFunc_0()
{
    
}
void HelloWorld::setCallFunc_1(Ref *sender)
{
    
}
void HelloWorld::setCallFunc_2(Ref *sender, void *d)
{
    CCLOG("CallFunc_2");
}
void HelloWorld::setCallFunc_3(Ref *sender, Ref *object)
{
    
}


void HelloWorld::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    CCLOG("Key with keycode %d pressed", keyCode);
}
void HelloWorld::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    CCLOG("Key with keycode %d released", keyCode);
}

void HelloWorld::onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *unused_event)
{
    //log("accelerometer %lf", acc->y);
    
    auto sprPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
    Point changePosition = Point(acc->y*50, 0);
    
    if(currentPoint.x-50 >= 0 && currentPoint.x <= winsize.width-50)
        sprPlayer->setPosition(currentPoint+changePosition);
    else if(currentPoint.x < 50)
        sprPlayer->setPosition(50, currentPoint.y);
    else if(currentPoint.x > winsize.width-50)
        sprPlayer->setPosition(winsize.width-50, currentPoint.y);
    else
        sprPlayer->setPosition(currentPoint);

}
