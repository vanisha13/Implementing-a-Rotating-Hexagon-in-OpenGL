#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:
    Camera();
    const float* GetViewMatrix() const; // Change return type to const float*
    const float* GetProjectionMatrix() const; // Change return type to const float*
private:
    float viewMatrix[16];
    float projectionMatrix[16];
};

#endif // CAMERA_H
