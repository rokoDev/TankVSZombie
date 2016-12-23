//
//  MyCamera.cpp
//  TankVSZombie
//
//  Created by roko on 12/21/16.
//
//

#include "MyCamera.hpp"

USING_NS_CC;

MyCamera::~MyCamera()
{
    
}

MyCamera::MyCamera(): m_maxZone(Rect::ZERO), m_K(0), m_targetPos(Vec3::ZERO)
{
    
}

MyCamera* MyCamera::create()
{
    MyCamera* camera = new (std::nothrow) MyCamera();
    camera->initDefault();
    camera->autorelease();
    camera->setDepth(0.f);
    
    return camera;
}

MyCamera* MyCamera::createPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
{
    auto ret = new (std::nothrow) MyCamera();
    if (ret)
    {
        ret->initPerspective(fieldOfView, aspectRatio, nearPlane, farPlane);
        ret->autorelease();
        
        ret->schedule(schedule_selector(MyCamera::updateTarZ));
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

MyCamera* MyCamera::createOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)
{
    auto ret = new (std::nothrow) MyCamera();
    if (ret)
    {
        ret->initOrthographic(zoomX, zoomY, nearPlane, farPlane);
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

void MyCamera::setPosition3D(const cocos2d::Vec3& position)
{
    Vec3 pos = position;
    pos.z = MIN(MAX(_nearPlane, position.z), _farPlane);
    
    const Vec2 minPos = minPosForZ(pos.z);
    const Vec2 maxPos = maxPosForZ(pos.z);
    
    pos.x = MIN(MAX(position.x, minPos.x), maxPos.x);
    pos.y = MIN(MAX(position.y, minPos.y), maxPos.y);
    
    Camera::setPosition3D(pos);
}

Vec2 MyCamera::minPosForZ(const float zVal)
{
    float halfHeight = zVal/m_K/2;
    float halfWidth = halfHeight*_aspectRatio;
    return Vec2(halfWidth, halfHeight);
}

Vec2 MyCamera::maxPosForZ(const float zVal)
{
    float halfHeight = zVal/m_K/2;
    float halfWidth = halfHeight*_aspectRatio;
    return Vec2(m_maxZone.size.width-halfWidth, m_maxZone.size.height-halfHeight);
}

void MyCamera::updateTarZ(float dt)
{
//    Vec3 curPos = getPosition3D();
//    curPos.x = m_targetPos.x;
//    curPos.y = m_targetPos.y;
//    const float curZ = curPos.z;
//    float targetZOffset = m_targetPos.z-curZ;
//    float curZOffset = 100.0f*dt;
//    if (curZOffset < fabsf(targetZOffset)) {
//        curPos.z += curZOffset*sgn(targetZOffset);
//    }
//    else {
//        curPos.z = m_targetPos.z;
//    }
//    //CCLOG("curPosZ:%f, tarZ:%f", curPos.z, m_targetPos.z);
//    setPosition3D(curPos);
}
