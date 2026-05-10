#include "terrain.hpp"
#include "../draw_scene.hpp"
#include "../engine/engine.hpp"
#include "../sceneComposition/sceneComposition.hpp"

GLBI_Convex_2D_Shape terrain{3};
GLBI_Convex_2D_Shape terrainGrid{3};

float& width { sceneComposition.terrainWidth };
float& height { sceneComposition.terrainHeight };

/*

Le terrain et la grille sont dessinés sur [0,0] vers [width, height]
On aurait pu faire sur [-width / 2.f, -height / 2.f] vers [width / 2.f, height / 2.f] pour le centrer directement par rapprot au repère
On a pris la première option pour simplifier l'algorithme et on fait le décallage avec une translation {-width / 2.f, -height / 2.f, 0.f}

*/

/* Toggle de la grille */
bool showTerrainGrid { false };

void initTerrain() {
	std::vector<float> terrainShape{
		   0.0,     0.0, 0.0,
		 width,     0.0, 0.0,
		 width,  height, 0.0,
		   0.0,  height, 0.0,
	};

	terrain.initShape(terrainShape);
	terrain.changeNature(GL_TRIANGLE_FAN);
};

void drawTerrain() {
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({-width / 2.f, -height / 2.f, 0.f});
		myEngine.updateMvMatrix();

		myEngine.setFlatColor(0.f, (113 / 255.f), (49 / 255.f)); // Couleur herbe
		terrain.drawShape();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
};

void initTerrainGrid() {
	std::vector<float> terrainGridShape{};

	/* Hauteur de la grille par rapport au terrain */
	float z {0.5f}; 

	/* Lignes verticales */
	for(int x { 0 }; x < (width / 10) + 1; x++) {
		terrainGridShape.push_back(x * 10);
		terrainGridShape.push_back(height);
		terrainGridShape.push_back(z);

		terrainGridShape.push_back(x * 10);
		terrainGridShape.push_back(0);
		terrainGridShape.push_back(z);
	}

	/* Lignes horizontales */
	for(int y { -1 }; y < (height / 10); y++) {
		terrainGridShape.push_back(0);
		terrainGridShape.push_back(y * 10 + 10);
		terrainGridShape.push_back(z);

		terrainGridShape.push_back(width);
		terrainGridShape.push_back(y * 10 + 10);
		terrainGridShape.push_back(z);
	}

	terrainGrid.initShape(terrainGridShape);
	terrainGrid.changeNature(GL_LINES);
}

void drawTerrainGrid() {

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({-width / 2.f, -height / 2.f, 0.f});
		myEngine.updateMvMatrix();

		myEngine.setFlatColor(255.f, 255.f, 255.f);
		terrainGrid.drawShape();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

}
