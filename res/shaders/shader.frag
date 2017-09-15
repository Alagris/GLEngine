#version 130
//
////in vec4 colorV;
//in vec2 textureUV;
//
//out vec3 outputF;
//
//uniform sampler2D textureSampler;
//
//void main()
//{
//    //outputF = colorV;
//    outputF = texture( textureSampler, textureUV ).rgb;
//}
// Interpolated values from the vertex shaders
in vec2 UV;

// Ouput data
out vec3 color;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;

void main(){

    // Output color = color of the texture at the specified UV
    color = texture( myTextureSampler, UV ).rgb;
}
