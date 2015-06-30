//
//  PlayerInputComponent.h
//  cocos2dx-components
//
//  Created by 張程 on 2015/06/30.
//
//

#ifndef __cocos2dx_components__PlayerInputComponent__
#define __cocos2dx_components__PlayerInputComponent__

#include "cocos2d.h"

class PlayerInputComponent : public cocos2d::Component
{
public:
    PlayerInputComponent();
    virtual ~PlayerInputComponent();
    
    virtual bool init();
    virtual void onEnter();
    virtual void update(float delta);
    
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchCanceled(cocos2d::Touch* touch, cocos2d::Event* event);
    
    CREATE_FUNC(PlayerInputComponent);
    
protected:
    cocos2d::EventListenerTouchOneByOne *touch_listener_;
    cocos2d::Vec2 move_to_;
    cocos2d::Vec2 cur_pos_;
    int speed_;
};

#endif /* defined(__cocos2dx_components__PlayerInputComponent__) */
