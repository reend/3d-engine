// Camera.h
#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);

    glm::mat4 getViewMatrix() const;
    void processKeyboardInput(int direction, float deltaTime);

    enum CameraMovement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    float yaw;
    float pitch;
    float movementSpeed;

    void updateCameraVectors();
};

#endif // CAMERA_H