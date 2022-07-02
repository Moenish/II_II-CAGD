varying vec4 diffuse, ambient;
varying vec3 normal, light_direction, half_vector;

void main()
{
	vec3 n, halfV;
	float nDotL, nDotHV;
	
	vec4 color = ambient;

	n = normalize(normal);
	
        nDotL = max(dot(n,light_direction), 0.0);

        if (nDotL > 0.0)
        {
		color += diffuse * nDotL;
                halfV = normalize(half_vector);
		nDotHV = max(dot(n, halfV), 0.0);
                color += gl_FrontMaterial.specular * gl_LightSource[0].specular *
                         pow(nDotHV, gl_FrontMaterial.shininess);
	}

	gl_FragColor = color;
}
