varying vec3 interpolated_eye_position;
varying vec3 interpolated_normal;

void main(void)
{
    interpolated_normal       = normalize(vec3(gl_NormalMatrix * gl_Normal));
    vec4 position             = gl_ModelViewMatrix * gl_Vertex;
    interpolated_eye_position = position.xyz;
    gl_Position               = gl_ModelViewProjectionMatrix * gl_Vertex;
}
