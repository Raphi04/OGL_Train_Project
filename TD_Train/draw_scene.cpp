#include "draw_scene.hpp"

#include "engine/engine.hpp"

#include "rails/rails.hpp"
#include "terrain/terrain.hpp"

/* Initialisation des formes de la scèene */
void initScene() {

	/* Initialisation du repère*/
	initRepere();

	/* Initialisation des rails */
	initStraightRails();
	initCurvedRails();

	/* Initialisation du terrain */
	initTerrain();

	/* Initialisation de la grille du terrain */
	initTerrainGrid();
}

/* Dessin de la scène */
void drawScene() {
	glPointSize(10.0);
	
	/* Dessin du repère 3D */
	drawRepere();

	/* Dessin de terrain */
	drawTerrain();

	/* Dessin de la grille du terrain*/
	if(showTerrainGrid) {
		drawTerrainGrid();
	}

	// myEngine.setFlatColor((245 / 255.f), (164 / 255.f), (66 / 255.f));
	// drawStraightRails();
}



