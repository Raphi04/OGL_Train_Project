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
	std::vector<float> terrainShape {
		  0.f,     0.f, 0.f,
		width,     0.f, 0.f,
		width,  height, 0.f,

		  0.f,     0.f, 0.f,
		  0.f,  height, 0.f,
		width,  height, 0.f,
	};

	std::vector<float> terrainShapeNormals {
		  0.f, 0.f, 1.f,
		  0.f, 0.f, 1.f,
		  0.f, 0.f, 1.f,
		  0.f, 0.f, 1.f,
		  0.f, 0.f, 1.f,
		  0.f, 0.f, 1.f,
	};

	std::vector<float> terrainShapeUvs {
		0.f, 0.f,
		1.f, 0.f,
		1.f, 1.f,

		0.f, 0.f,
		0.f, 1.f,
		1.f, 1.f
	};

	terrain.initShape(terrainShape, terrainShapeNormals, terrainShapeUvs);
	terrain.changeNature(GL_TRIANGLE_FAN);

};

void drawTerrain() {
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({-width / 2.f, -height / 2.f, 0.f});
		myEngine.updateMvMatrix();

		myEngine.activateTexturing(true);
		grassTexture.attachTexture();

		terrain.drawShape();

		grassTexture.detachTexture();
		myEngine.activateTexturing(false);

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
};

void initTerrainGrid() {
	std::vector<float> terrainGridShape{};
	std::vector<float> terrainGridShapeNormals{};
	std::vector<float> terrainGridShapeUvs{};

	/* Hauteur de la grille par rapport au terrain */
	float z { 0.1f }; 

	/* Lignes verticales */
	for(int x { 0 }; x < (width / 10) + 1; x++) {
		terrainGridShape.push_back(x * 10);
		terrainGridShape.push_back(height);
		terrainGridShape.push_back(z);

		terrainGridShapeNormals.push_back(0.f);
		terrainGridShapeNormals.push_back(0.f);
		terrainGridShapeNormals.push_back(1.f);

		terrainGridShapeUvs.push_back(0.f);
		terrainGridShapeUvs.push_back(0.f);

		terrainGridShape.push_back(x * 10);
		terrainGridShape.push_back(0);
		terrainGridShape.push_back(z);

		terrainGridShapeNormals.push_back(0.f);
		terrainGridShapeNormals.push_back(0.f);
		terrainGridShapeNormals.push_back(1.f);

		terrainGridShapeUvs.push_back(0.f);
		terrainGridShapeUvs.push_back(0.f);
	}

	/* Lignes horizontales */
	for(int y { 0 }; y < (height / 10) + 1; y++) {
		terrainGridShape.push_back(0);
		terrainGridShape.push_back(y * 10);
		terrainGridShape.push_back(z);

		terrainGridShapeNormals.push_back(0.f);
		terrainGridShapeNormals.push_back(0.f);
		terrainGridShapeNormals.push_back(1.f);
		
		terrainGridShapeUvs.push_back(0.f);
		terrainGridShapeUvs.push_back(0.f);

		terrainGridShape.push_back(width);
		terrainGridShape.push_back(y * 10);
		terrainGridShape.push_back(z);

		terrainGridShapeNormals.push_back(0.f);
		terrainGridShapeNormals.push_back(0.f);
		terrainGridShapeNormals.push_back(1.f);

		terrainGridShapeUvs.push_back(0.f);
		terrainGridShapeUvs.push_back(0.f);
	}

	terrainGrid.initShape(terrainGridShape, terrainGridShapeNormals, terrainGridShapeUvs);
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
