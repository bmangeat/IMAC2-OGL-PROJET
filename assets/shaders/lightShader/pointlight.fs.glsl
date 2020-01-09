#version 330 core

in vec2 vTexCoords; // Coordonnées de texture du sommet
in vec3 vPosition_vs;
in vec3 vNormal_vs;

out vec3 fFragColor;

//Light management
uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

//Working in the view space = product(vec3, ViewMatrix)
uniform vec3 uLightPos_vs; //wi =  normalize (uLightPos_vs)
uniform vec3 uLightIntensity;
uniform vec3 uColor;

vec3 blinnPhong(vec3 Kd, vec3 Ks, float Shininess, vec3 LightPos_vs, vec3 LightIntensity) {
    vec3 wi = normalize(LightPos_vs - vPosition_vs);
    vec3 w0 = normalize(-vPosition_vs);
    vec3 halfVector = (wi + w0)/2;
    vec3 Li = uLightIntensity / (distance(LightPos_vs, vPosition_vs)*distance(LightPos_vs,vPosition_vs));
    return Li * ( Kd * dot(wi, vNormal_vs) + Ks * pow(dot(halfVector, vNormal_vs), Shininess));
}

void main() {
  fFragColor = uColor + blinnPhong(uKd, uKs, uShininess, uLightPos_vs, uLightIntensity);
}
