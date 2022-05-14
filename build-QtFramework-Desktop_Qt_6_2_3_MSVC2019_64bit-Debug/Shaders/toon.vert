varying float intensity;
varying vec3  normal, light_direction;

void main()
{
        normal = normalize(gl_NormalMatrix * gl_Normal);

        light_direction = normalize(vec3(gl_LightSource[0].position));

        intensity = dot(light_direction, normal);

        gl_Position = ftransform();
}
