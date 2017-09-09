#include <GL/glew.h>
#include <iostream>
#include "base/engine/gl_initializator.h"
#include "base/engine/base_runner.h"
#include "shader_compiler.h"
#include "model_buffer_generators.h"
#include "matrix_computations.h"
#include "matrix_generators.h"
#include "basic_matrix_transformations.h"
#include "display.h"
#include "window_input_handler.h"
#include "camera.h"
#include "model.h"
#include "shader.h"
#include "assimp_loader.h"
#include "assimp/scene.h"
#include "vertex_array_object.h"
#include "assimp_counters.h"
#include "assimp_converters.h"
#include "assimp_copy_data.h"
#include "vertex_buffer_object.h"
#include "vertex_buffer_object_helpers.h"
#include "vertex_attrib_pointer_setup.h"
GLfloat zNear = 2;
GLfloat rest = 2;
GLfloat zFar = -2;
gle::Camera cam(-rest,rest,rest,-rest,zNear,zFar,true);
gle::Model modelMatrix1;
gle::Mat4 mvpMatrix;
gle::Shader shader;
GLint mvp_handle;
gle::VertexArrayObject vao;

void moveLeft(GLFWwindow* window, int key, int scancode, int action, int mods) {
    cam.moveAccordingToRotation(-0.1);
}
void moveRight(GLFWwindow* window, int key, int scancode, int action, int mods) {
    cam.moveAccordingToRotation(0.1);
}
void moveForward(GLFWwindow* window, int key, int scancode, int action, int mods) {
    cam.moveAccordingToRotation(0,0,-0.1);
}
void moveBackward(GLFWwindow* window, int key, int scancode, int action, int mods) {
    cam.moveAccordingToRotation(0,0,0.1);
}
void nearUp(GLFWwindow* window, int key, int scancode, int action, int mods) {
    zNear+=0.1;
    cam.setPerspectiveProjection(-rest,rest,rest,-rest,zNear,zFar);
}
void nearDown(GLFWwindow* window, int key, int scancode, int action, int mods) {
    zNear-=0.1;
    cam.setPerspectiveProjection(-rest,rest,rest,-rest,zNear,zFar);
}
void restUp(GLFWwindow* window, int key, int scancode, int action, int mods) {
    rest+=0.1;
    cam.setPerspectiveProjection(-rest,rest,rest,-rest,zNear,zFar);
}
void restDown(GLFWwindow* window, int key, int scancode, int action, int mods) {
    rest-=0.1;
    cam.setPerspectiveProjection(-rest,rest,rest,-rest,zNear,zFar);
}
void farUp(GLFWwindow* window, int key, int scancode, int action, int mods) {
    zFar+=0.1;
    cam.setPerspectiveProjection(-rest,rest,rest,-rest,zNear,zFar);
}
void farDown(GLFWwindow* window, int key, int scancode, int action, int mods) {
    zFar-=0.1;
    cam.setPerspectiveProjection(-rest,rest,rest,-rest,zNear,zFar);
}
gle::Display * display;
void mouseGrabTrigger(const int button,const int action,const int mods,const double x,const double y) {
    if(action==GLFW_PRESS)
        display->toggleGrabMouse();
}
void mouseCameraMove(const double x,const double y,const double previousX,const double previousY) {
    if(display->isMouseGrabbed()) {
        cam.rotateDegreesAccordingToMouseMovementLockAxes(x-previousX,y-previousY,-0.5);
    }
}


void init(gle::Display & d) {
    gle::init(&d);
    display=&d;
    gle::keyboardAddKey(GLFW_KEY_A,moveLeft);
    gle::keyboardAddKey(GLFW_KEY_D,moveRight);
    gle::keyboardAddKey(GLFW_KEY_W,moveForward);
    gle::keyboardAddKey(GLFW_KEY_S,moveBackward);
    gle::keyboardAddKey(GLFW_KEY_R,nearUp);
    gle::keyboardAddKey(GLFW_KEY_T,nearDown);
    gle::keyboardAddKey(GLFW_KEY_F,restUp);
    gle::keyboardAddKey(GLFW_KEY_G,restDown);
    gle::keyboardAddKey(GLFW_KEY_V,farUp);
    gle::keyboardAddKey(GLFW_KEY_B,farDown);
    gle::mouseAddPerTickMoveCallback(mouseCameraMove);
    gle::mouseAddPressCallback(mouseGrabTrigger);
    glDepthMask(GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    gle::importModel("res/models/model.dae",vao);

    shader.load("res/shaders/shader.vert","res/shaders/shader.frag");
    shader.bind();
    mvp_handle = glGetUniformLocation(shader.getID(), "MVP");
}
void update(gle::Display & d) {
    d.updateInput();
    modelMatrix1.updateModelMatrix();
    cam.updateViewMatrix();
    cam.updateViewProjectionMatrix();
}


void render(gle::Display & d) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    vao.bind();
    vao.bindEBO();
    cam.getModelViewProjectionMatrix(modelMatrix1.getModelMatrix(),mvpMatrix);
    glUniformMatrix4fv(mvp_handle, 1, GL_TRUE, mvpMatrix);
    vao.renderEBO(GL_TRIANGLES,0);



    glfwSwapBuffers(d.getWindow());

}

void destroy(gle::Display & d) {
}

int main()
{
    gle::setInitializationCallback(::init);
    gle::setRenderCallback(::render);
    gle::setUpdateCallback(::update);
    gle::setDestroyCallback(::destroy);
    gle::run(700,700,"test",true);
    return 0;
}



