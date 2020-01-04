#version 330 core

in vec2 vTexCoords; // Coordonnées de texture du sommet
in vec2 vFragPosition;
in vec3 vNormal_vs;

out vec3 fFragColor;

uniform bool uSelect;

void main() {
  if (!uSelect)
    fFragColor = vec3(1.0,0.5,0.5);
  else fFragColor = vec3(0.5,0.5,1.0);
}
