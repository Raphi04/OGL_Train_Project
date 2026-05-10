#include "engine.hpp"
#include "../draw_scene.hpp"

/* Moteur OpenGL */
GLBI_Engine myEngine;

/* Repère 3D */
StandardMesh* repere;

void initRepere() {
    repere = createRepere();
	repere->createVAO();
}

void drawRepere() {
    myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety(5);
		myEngine.updateMvMatrix();

		repere->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}