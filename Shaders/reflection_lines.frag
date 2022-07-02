varying vec3 interpolated_eye_position;
varying vec3 interpolated_normal;

uniform float scale_factor;
uniform float smoothing;
uniform float shading;

float arcSinus(float x)
{
    return x * (1.0 + x*x * ((1.0/6.0) + x*x * ((3.0/40.0) + (15.0/336.0)*x*x)));
}

void main (void)
{
    vec4 color;
    vec3 reflection_vector;

    vec3 n           = normalize(interpolated_normal);
    vec3 view_vector = normalize(interpolated_eye_position);

    reflection_vector     = view_vector.xyz - 2.0 * n * dot(n, view_vector.xyz);
    reflection_vector.z  += 1.0;
    reflection_vector.z   = 0.5/sqrt(dot(reflection_vector, reflection_vector));
    reflection_vector.xy  = (reflection_vector.xy * reflection_vector.z) + 0.5;
    reflection_vector     *= 2.0;

    float sharpness = 1.0/arcSinus(smoothing * fwidth(reflection_vector.x) * 2.0 * scale_factor);

    color = vec4(clamp(0.5 + sharpness * sin(2.0 * 3.1428 * reflection_vector.x*scale_factor), 0.0, 1.0));

    gl_FragColor = (clamp(dot(gl_LightSource[0].position.xyz, n)*shading + (1.0-shading), 0.0, 1.0) * min(color, vec4(1.0,1.0,1.0,1.0)));
}
