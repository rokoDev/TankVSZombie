//
//  MyCamera.hpp
//  TankVSZombie
//
//  Created by roko on 12/21/16.
//
//

#ifndef MyCamera_hpp
#define MyCamera_hpp

class MyCamera: public cocos2d::Camera {
CC_CONSTRUCTOR_ACCESS:
    MyCamera();
    ~MyCamera();
    
    cocos2d::Rect m_maxZone;
    
    float m_K;
    
    cocos2d::Vec3 m_targetPos;
    
public:
    static MyCamera* createPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane);
    static MyCamera* createOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane);
    
    /** create default camera, the camera type depends on Director::getProjection, the depth of the default camera is 0 */
    static MyCamera* create();
    
    virtual void setPosition3D(const cocos2d::Vec3& position) override;
    
    void setMaxZone(const cocos2d::Rect & maxZone) { m_maxZone = maxZone; }
    
    void setK(const float k) { m_K = k; }
    
    void setTargetPos(const cocos2d::Vec3 & pos) { m_targetPos = pos; }
    cocos2d::Vec3 getTargetPos() const { return m_targetPos; }
    
    cocos2d::Vec2 minPosForZ(const float zVal);
    cocos2d::Vec2 maxPosForZ(const float zVal);
    
    void updateTarZ(float dt);
};

#endif /* MyCamera_hpp */
