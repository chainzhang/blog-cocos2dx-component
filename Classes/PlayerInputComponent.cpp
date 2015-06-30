//
//  PlayerInputComponent.cpp
//  cocos2dx-components
//
//  Created by 張程 on 2015/06/30.
//
//

#include "PlayerInputComponent.h"

USING_NS_CC;

PlayerInputComponent::PlayerInputComponent():
touch_listener_(nullptr),
move_to_(Vec2::ZERO),
cur_pos_(Vec2::ZERO),
speed_(0)
{
    
}

PlayerInputComponent::~PlayerInputComponent()
{
    
}

bool PlayerInputComponent::init()
{
    if (! Component::init()) return false;
    
    this->setName("PlayerInput");
    
    touch_listener_ = EventListenerTouchOneByOne::create();
    touch_listener_->setSwallowTouches(true);
    touch_listener_->retain();
    
    touch_listener_->onTouchBegan = CC_CALLBACK_2(PlayerInputComponent::onTouchBegan, this);
    touch_listener_->onTouchMoved = CC_CALLBACK_2(PlayerInputComponent::onTouchMoved, this);
    touch_listener_->onTouchEnded = CC_CALLBACK_2(PlayerInputComponent::onTouchEnded, this);
    touch_listener_->onTouchCancelled = CC_CALLBACK_2(PlayerInputComponent::onTouchCanceled, this);
    
    return true;
}

void PlayerInputComponent::onEnter()
{
    Component::onEnter();
    
    speed_ = 400;
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch_listener_, this->getOwner());
}

void PlayerInputComponent::update(float delta)
{
    if (! this->getOwner()->getPosition().equals(move_to_)) {
        Vec2 v = move_to_ - cur_pos_;
        float d = move_to_.distance(cur_pos_);
        Vec2 to = this->getOwner()->getPosition();
        
        Vec2 s = Vec2(v.x * speed_/d, v.y * speed_/d);
        
        
        to += s * delta;
        
        if (v.x < 0) {
            if (to.x < move_to_.x) to.x = move_to_.x;
        } else {
            if (to.x > move_to_.x) to.x = move_to_.x;
        }
        if (v.y < 0) {
            if (to.y < move_to_.y) to.y = move_to_.y;
        } else {
            if (to.y > move_to_.y) to.y = move_to_.y;
        }
        this->getOwner()->setPosition(to);
    }
}

bool PlayerInputComponent::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event)
{
    CCLOG("On touch began");
    return true;
}

void PlayerInputComponent::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event)
{
    CCLOG("On touch moved");
}

void PlayerInputComponent::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event)
{
    cur_pos_ = this->getOwner()->getPosition();
    move_to_ = touch->getLocation();
    CCLOG("On touch ended");
}

void PlayerInputComponent::onTouchCanceled(cocos2d::Touch* touch, cocos2d::Event *event)
{
    CCLOG("On touch canceled");
}