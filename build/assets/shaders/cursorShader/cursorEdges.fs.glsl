#version 330 core

in vec2 vTexCoords; // Coordonnées de texture du sommet
in vec2 vFragPosition;
in vec3 vNormal_vs;

out vec3 fFragColor;

uniform vec3 uColor;

void main() {
    fFragColor = uColor;
}
