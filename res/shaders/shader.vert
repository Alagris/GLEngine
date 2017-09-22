#version 330
// Input vertex data, different for all executions of this shader.
in vec3 inVertexPosition_modelspace;
in vec2 inVertexUV;
in vec3 inVertexNormal;
in vec4 inColor;
// Output data ; will be interpolated for each fragment.
out vec2 outVertexUV;
out vec4 outColor;
out vec3 outVertexNormal;
// Values that stay constant for the whole mesh.
uniform mat4 MVP;
uniform float ambientColorStrength;
uniform vec3 ambientColor;
uniform vec3 diffuseColor;
uniform vec3 diffuseLightPosition;
void main(){
    float cosTheta = clamp( dot( inVertexNormal,diffuseLightPosition ), 0,1 );

    // Output position of the vertex, in clip space : MVP * position
    gl_Position =  MVP * vec4(inVertexPosition_modelspace,1);

    // UV of the vertex. No special space for this one.
    outVertexUV = inVertexUV;
    outColor=ambientColorStrength*vec4(ambientColor,1.0)*inColor ;//*vec4(diffuseColor,1.0)*cosTheta
    outVertexNormal=inVertexNormal;
//    outColor=vec4(inVertexNormal,1.0);
}
