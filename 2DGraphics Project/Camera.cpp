#include "Camera.h"

// Constructor initializes matrices to identity matrices
Camera::Camera() {
    // Initialize viewMatrix and projectionMatrix to identity matrices
    for (int i = 0; i < 16; ++i) {
        viewMatrix[i] = (i % 5 == 0) ? 1.0f : 0.0f;
        projectionMatrix[i] = (i % 5 == 0) ? 1.0f : 0.0f;
    }
}

const float* Camera::GetViewMatrix() const {
    return viewMatrix;
}

const float* Camera::GetProjectionMatrix() const {
    return projectionMatrix;
}
