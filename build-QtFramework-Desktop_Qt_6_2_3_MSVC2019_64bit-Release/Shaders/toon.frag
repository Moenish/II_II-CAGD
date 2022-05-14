uniform vec4 default_outline_color;

varying float intensity;
varying vec3  normal, light_direction;

void main()
{
	vec4 color = gl_FrontMaterial.ambient;
        vec3 N = normalize(normal), L = normalize(light_direction);
        float N_dot_L = max(0.0, dot(N, L));
	
	if (intensity > 0.95)
                color += gl_FrontMaterial.diffuse * N_dot_L *  0.95;
	else if (intensity > 0.85)
                color += gl_FrontMaterial.diffuse * N_dot_L *  0.85;
	else if (intensity > 0.75)
                color += gl_FrontMaterial.diffuse * N_dot_L *  0.75;
	else if (intensity > 0.65)
                color += gl_FrontMaterial.diffuse * N_dot_L *  0.65;
	else if (intensity > 0.55)
                color += gl_FrontMaterial.diffuse * N_dot_L *  0.55;
	else if (intensity > 0.45)
                color += gl_FrontMaterial.diffuse * N_dot_L *  0.45;
	else 
	{
            color = default_outline_color;
	}

	gl_FragColor = color;
}
