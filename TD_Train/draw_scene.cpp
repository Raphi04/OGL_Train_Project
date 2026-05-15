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
	initRails();

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


	/* Dessin des éléments de la scène */
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({-sceneComposition.terrainWidth / 2, -sceneComposition.terrainHeight / 2, 0.f});
		myEngine.updateMvMatrix();

		float translationX {};
		float translationY {};
		float rotation {};

		for(SceneElement sceneElement : sceneComposition.sceneElements) {
			translationX = sceneElement.x * 10;
			translationY = sceneElement.y * 10;
			rotation = M_PI * sceneElement.rotation / 180;

			myEngine.mvMatrixStack.pushMatrix();

				myEngine.mvMatrixStack.addTranslation({translationX + 5, translationY + 5, 0.f});
				myEngine.mvMatrixStack.addRotation(rotation, {0.f, 0.f, 1.f});
				myEngine.updateMvMatrix();

				if(sceneElement.elementType == Element::StraightRail) {
					myEngine.setFlatColor(0.75f, 0.75f, 0.75f);
					drawStraightRails();
				}

				if(sceneElement.elementType == Element::CurvedRail) {
					myEngine.setFlatColor(0.f, 1.f, 1.f);
					drawCurvedRails();
				}

			myEngine.mvMatrixStack.popMatrix();
			myEngine.updateMvMatrix();
		}

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}



