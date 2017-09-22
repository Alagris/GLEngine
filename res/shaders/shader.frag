#version 130
// Interpolated values from the vertex shaders
in vec2 outVertexUV;
in vec4 outColor;
in vec3 outVertexNormal;
// Ouput data
out vec4 color;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;

void main(){

    // Output color = color of the texture at the specified UV
    color = outColor*vec4(texture( myTextureSampler, outVertexUV ).rgb,1.0);
}
