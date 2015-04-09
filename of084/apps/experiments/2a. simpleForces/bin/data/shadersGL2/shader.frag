#version 120

uniform sampler2DRect tex0;
uniform sampler2DRect maskTex;

varying vec2 texCoordVarying;

void main()
{
    vec3 src = texture2DRect(tex0, texCoordVarying).rgb;
    float src_alpha = texture2DRect(tex0, texCoordVarying).a;
    float mask = texture2DRect(maskTex, texCoordVarying).r;
    gl_FragColor = vec4(src, mask * src_alpha);
}