#include <iostream>
#include "base/engine/gl_initializator.h"
#include "base/engine/base_runner.h"
#include <GL/glew.h>
#include "shader_compiler.h"
#include "model_buffer_generators.h"
#include "matrix_computations.h"
#include "matrix_generators.h"
#include "basic_matrix_transformations.h"
#include "base/engine/display.h"
#include "window_input_handler.h"
#include "camera.h"
#include "matrix_helpers.h"
#include "compound_matrix_transformations.h"
#include "quaternion_computations.h"
#include "vector_helpers.h"
#include "model.h"
#include "shader.h"
GLfloat vertices[] = {
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};


GLfloat color[] = {
    0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,
    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,
    0.676f,  0.977f,  0.133f,
    0.971f,  0.572f,  0.833f,
    0.140f,  0.616f,  0.489f,
    0.997f,  0.513f,  0.064f,
    0.945f,  0.719f,  0.592f,
    0.543f,  0.021f,  0.978f,
    0.279f,  0.317f,  0.505f,
    0.167f,  0.620f,  0.077f,
    0.347f,  0.857f,  0.137f,
    0.055f,  0.953f,  0.042f,
    0.714f,  0.505f,  0.345f,
    0.783f,  0.290f,  0.734f,
    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,
    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,
    0.673f,  0.211f,  0.457f,
    0.820f,  0.883f,  0.371f,
    0.982f,  0.099f,  0.879f
};

GLfloat zNear = 2;
GLfloat rest = 2;
GLfloat zFar = -2;
gle::Camera cam(-rest,rest,rest,-rest,zNear,zFar,true);
gle::Model modelMatrix;
gle::Model modelMatrix1;
gle::Mat4 mvpMatrix;
gle::Shader shader;
GLuint colorbuffer;
GLuint vertexbuffer;
GLint mvp_handle;

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
gle::Vec3 rotateLeft;
void lookLeft(GLFWwindow* window, int key, int scancode, int action, int mods) {
    cam.rotateByQuaternion(rotateLeft);
}
void lookRight(GLFWwindow* window, int key, int scancode, int action, int mods) {
    gle::reverseQuaternion(rotateLeft);
    cam.rotateByQuaternion(rotateLeft);
    gle::reverseQuaternion(rotateLeft);
}
void turnLeft(GLFWwindow* window, int key, int scancode, int action, int mods) {
    modelMatrix.rotateByQuaternion(rotateLeft);
}
void turnRight(GLFWwindow* window, int key, int scancode, int action, int mods) {
    gle::reverseQuaternion(rotateLeft);
    modelMatrix.rotateByQuaternion(rotateLeft);
    gle::reverseQuaternion(rotateLeft);
}
void scaleUp(GLFWwindow* window, int key, int scancode, int action, int mods) {
    modelMatrix1.setScale(modelMatrix1.getScaleDepth()+0.1);
}
void scaleDown(GLFWwindow* window, int key, int scancode, int action, int mods) {
    modelMatrix1.setScale(modelMatrix1.getScaleDepth()-0.1);
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
void init(gle::Display & d) {
    gle::init(&d);
    gle::keyboardAddKey(GLFW_KEY_A,moveLeft);
    gle::keyboardAddKey(GLFW_KEY_D,moveRight);
    gle::keyboardAddKey(GLFW_KEY_W,moveForward);
    gle::keyboardAddKey(GLFW_KEY_S,moveBackward);
    gle::keyboardAddKey(GLFW_KEY_Q,lookLeft);
    gle::keyboardAddKey(GLFW_KEY_E,lookRight);
    gle::keyboardAddKey(GLFW_KEY_Z,turnLeft);
    gle::keyboardAddKey(GLFW_KEY_C,turnRight);
    gle::keyboardAddKey(GLFW_KEY_X,scaleUp);
    gle::keyboardAddKey(GLFW_KEY_Y,scaleDown);
    gle::keyboardAddKey(GLFW_KEY_R,nearUp);
    gle::keyboardAddKey(GLFW_KEY_T,nearDown);
    gle::keyboardAddKey(GLFW_KEY_F,restUp);
    gle::keyboardAddKey(GLFW_KEY_G,restDown);
    gle::keyboardAddKey(GLFW_KEY_V,farUp);
    gle::keyboardAddKey(GLFW_KEY_B,farDown);
    glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

    vertexbuffer=gle::generateVBO(sizeof(vertices),vertices,GL_STATIC_DRAW);
    colorbuffer=gle::generateVBO(sizeof(color),color,GL_STATIC_DRAW);
    modelMatrix.setScale(1);
    modelMatrix1.setScale(0.8);
    modelMatrix1.setLocation(3,0.2,3);
    gle::generateDegreesQuaternion(0,1,0,2,rotateLeft);
    shader.load("res/shaders/shader.vert","res/shaders/shader.frag");
    shader.bind();
    mvp_handle = glGetUniformLocation(shader.getID(), "MVP");


    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        nullptr            // array buffer offset
    );
    glDisableVertexAttribArray(1);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        nullptr            // array buffer offset
    );
    // Draw the triangle !

    glDisableVertexAttribArray(0);
//    glUseProgram(0);

}
void update(gle::Display & d) {
    glfwPollEvents();
    gle::keyboardUpdateKeys();
    modelMatrix.updateModelMatrix();
    modelMatrix1.updateModelMatrix();
    cam.updateViewMatrix();
    cam.updateViewProjectionMatrix();

}


void render(gle::Display & d) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



//    glUseProgram(shaderProgram);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(0);
    cam.getModelViewProjectionMatrix(modelMatrix.getModelMatrix(),mvpMatrix);
    glUniformMatrix4fv(mvp_handle, 1, GL_TRUE, mvpMatrix);
    glDrawArrays(GL_TRIANGLES, 0, 12*3); // Starting from vertex 0; 3 vertices total -> 1 triangle

    cam.getModelViewProjectionMatrix(modelMatrix1.getModelMatrix(),mvpMatrix);
    glUniformMatrix4fv(mvp_handle, 1, GL_TRUE, mvpMatrix);
    glDrawArrays(GL_TRIANGLES, 0, 12*3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
//    glUseProgram(0);

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
    gle::run(300,300,"test",true);
    return 0;
}



