#version 330 core

in vec2 vTexCoords; // Coordonnées de texture du sommet
in vec2 vFragPosition;

out vec3 fFragColor;

uniform vec3 uColor;
uniform sampler2D uTexture;

void main() {
  fFragColor = vec3(0.f,1.f,0.f);
};
