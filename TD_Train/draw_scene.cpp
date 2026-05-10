#include "draw_scene.hpp"
#include "rails/rails.hpp"
#include "terrain/terrain.hpp"

/* Paramètres de la caméra */
	/* Angle entre l'axe des x et la caméra */
	float angle_theta { 45.0 };

	/* Angle entre l'axe des Z et la caméra */
	float angle_phy { 30.0 };

	/* Distance entre le point d'origine de la scène et la caméra */
	float dist_zoom { 30.0 };

/* Moteur OpenGL */
GLBI_Engine myEngine;

/* Toggle de la grille */
bool showTerrainGrid { false };

/* Repère 3D */
StandardMesh* repere;

/* Initialisation des formes de la scèene */
void initScene() {

	/* Initialisation des rails */
	initStraightRails();
	initCurvedRails();

	/* Initialisation du terrain */
	initTerrain();

	/* Initialisation de la grille du terrain */
	initTerrainGrid();

	repere = createRepere();
	repere->createVAO();
}

/* Dessin de la scène */
void drawScene() {
	glPointSize(10.0);
	
	/* Repère 3D */
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety(5);
		myEngine.updateMvMatrix();

		repere->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	/* Dessin de terrain */
	drawTerrain();

	/* Dessin de la grille du terrain*/
	if(showTerrainGrid) {
		drawTerrainGrid();
	}

	// myEngine.setFlatColor((245 / 255.f), (164 / 255.f), (66 / 255.f));
	// drawStraightRails();
}



