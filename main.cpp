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
#include "vertex_array_object_helpers.h"
#include "assimp_counters.h"
#include "assimp_converters.h"
#include "assimp_copy_data.h"
#include "vertex_buffer_object.h"
#include "vertex_buffer_object_helpers.h"
#include "vertex_attrib_pointer_setup.h"
#include <FreeImage.h>
#include "texture_context.h"
#include "texture_loader.h"
#include "vao_vbo_ebo_package.h"
#include "vao_vbo_ebo_package_helpers.h"
#include "model_buffer_binders.h"
#include "render_ready_package.h"
#include "render_ready_package_helpers.h"
#include "render_ready_package_renderer.h"
#include "shader_lighting_data.h"
#include "ambient_light_data.h"
#include "vector_helpers.h"
#include "ambient_light_helpers.h"
#include "diffuse_light_helpers.h"
#include "render_ready_root_node.h"
#include "model_node_helpers.h"
#include "shader_lighting_uniforms.h"
GLfloat zNear = 2;
GLfloat rest = 2;
GLfloat zFar = -2;
gle::Camera cam(-rest,rest,rest,-rest,zNear,zFar,true);
gle::Model modelMatrix1;
gle::Mat4 mvpMatrix;
gle::Shader shader;
//GLint mvp_handle;
gle::RenderReadyPackage rr;

void moveLeft(GLFWwindow* window, int key, int scancode, int action, int mods) {
    cam.moveAccordingToRotation(-0.5);
}
void moveRight(GLFWwindow* window, int key, int scancode, int action, int mods) {
    cam.moveAccordingToRotation(0.5);
}
void moveForward(GLFWwindow* window, int key, int scancode, int action, int mods) {
    cam.moveAccordingToRotation(0,0,-0.5);
}
void moveBackward(GLFWwindow* window, int key, int scancode, int action, int mods) {
    cam.moveAccordingToRotation(0,0,0.5);
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
void scaleUp(GLFWwindow* window, int key, int scancode, int action, int mods) {
    GLfloat n=rr.getRootNode(0).getLightingData().ambient.m_ambientLightStrength+0.02;
    if(n<=1)rr.getRootNode(0).getLightingData().ambient.m_ambientLightStrength=n;
    std::cout<<rr.getRootNode(0).getLightingData().ambient.m_ambientLightStrength<<"\n";
}
void scaleDown(GLFWwindow* window, int key, int scancode, int action, int mods) {
    GLfloat n=rr.getRootNode(0).getLightingData().ambient.m_ambientLightStrength-0.02;
    if(n>=0)rr.getRootNode(0).getLightingData().ambient.m_ambientLightStrength=n;
    std::cout<<rr.getRootNode(0).getLightingData().ambient.m_ambientLightStrength<<"\n";
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
    gle::keyboardAddKey(GLFW_KEY_Q,scaleUp);
    gle::keyboardAddKey(GLFW_KEY_E,scaleDown);
    gle::mouseAddPerTickMoveCallback(mouseCameraMove);
    gle::mouseAddPressCallback(mouseGrabTrigger);
    glDepthMask(GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
//    gle::importModel("res/models/bicyclekeycollada.dae",rr,GL_STATIC_DRAW,0,-1,2,0,1,1,1);
//    rr=gle::importModel("res/models/model.dae",GL_STATIC_DRAW);
//    rr=gle::importModel("res/models/dummy_obj.obj",GL_STATIC_DRAW);
    const char * arr[]={"res/models/dummy_obj.obj","res/models/model.dae","res/models/Militia-Adventurer-RIGGED.dae"};//,
    rr=gle::importModels(arr ,3,GL_STATIC_DRAW);
    gle::unbindVAO();
    gle::unbindEBO();
    shader.load("res/shaders/shader.vert","res/shaders/shader.frag");
    shader.bind();


    gle::setShaderVertexInputLocation(rr,shader.getID(),"inVertexPosition_modelspace");
    gle::setShaderColorInputLocation(rr,shader.getID(),"inColor");
    gle::setShaderTextureInputLocation(rr,shader.getID(),"inVertexUV");
    gle::setShaderNormalInputLocation(rr,shader.getID(),"inVertexNormal");
    gle::setShaderModelViewProjectionMatrixLocation(rr,shader.getID(),"MVP");
    gle::setAmbientLightShaderInputLocation(rr.getLighting().ambient,shader.getID(),"ambientColor","ambientColorStrength");
    gle::setDiffuseLightShaderInputLocation(rr.getLighting().diffuse,shader.getID(),"diffuseColor","diffuseLightPosition");
    rr.getRootNode(0).getLightingData().ambient.m_ambientLightStrength=0.5;
    rr.getRootNode(0).setDefaultColor(1,1,1,1);

    rr.getRootNode(1).getLightingData().ambient.m_ambientLightStrength=0.5;
    rr.getRootNode(1).setDefaultColor(1,0,0,1);
//    gle::debugModelNodes(*rr.getRootNode(0).get().get());
//    std::cout<<rr.getShaderColorInputLocation()<<"\n";
}

void update(gle::Display & d) {
    d.updateInput();
    modelMatrix1.updateModelMatrix();
    cam.updateViewMatrix();
    cam.updateViewProjectionMatrix();
}


void render(gle::Display & d) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(shader.getID()!=0 && gle::hasVAO_ID(rr.getData()) ) {
//        cam.getModelViewProjectionMatrix(modelMatrix1.getModelMatrix(),mvpMatrix);
//        glUniformMatrix4fv(mvp_handle, 1, GL_TRUE, mvpMatrix);
//        gle::renderEBO(rr,GL_TRIANGLES,0);
//        gle::renderAllEBO(rr,GL_TRIANGLES);
        gle::renderAllNodes(rr,GL_TRIANGLES,cam.getViewProjectionMatrix(),0);

        gle::renderAllNodes(rr,GL_TRIANGLES,cam.getViewProjectionMatrix(),1);

        gle::renderAllNodes(rr,GL_TRIANGLES,cam.getViewProjectionMatrix(),2);
    }


    glfwSwapBuffers(d.getWindow());

}

void destroy(gle::Display & d) {
}

int main()
{
    gle::TextureContext texContext(true);
    gle::setInitializationCallback(::init);
    gle::setRenderCallback(::render);
    gle::setUpdateCallback(::update);
    gle::setDestroyCallback(::destroy);
    gle::run(700,700,"test",true);
    return 0;
}



