#version 150

// these are our textures
uniform sampler2DRect tex0;
uniform sampler2DRect maskTex;

// this comes from the vertex shader
in vec2 texCoordVarying;

// this is the output of the fragment shader
out vec4 outputColor;

void main()
{
    vec3 src = texture(tex0, texCoordVarying).rgb;
    float src_alpha = texture(tex0, texCoordVarying).a;
    float mask = texture(maskTex, texCoordVarying).r;
    outputColor = vec4(src, mask * src_alpha);
}