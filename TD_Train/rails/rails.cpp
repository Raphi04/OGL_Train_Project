#include "rails.hpp"
#include "../draw_scene.hpp"
#include "../engine/engine.hpp"
#include "../sceneComposition/sceneComposition.hpp"

GLBI_Convex_2D_Shape test{3};

void initStraightRails() {
	std::vector<float> baseCarre{
		-10.0,-10.0, 0.0,
		 10.0,-10.0, 0.0,
		 10.0, 10.0, 0.0,
		-10.0, 10.0, 0.0
	};
	test.initShape(baseCarre);
	test.changeNature(GL_TRIANGLE_FAN);
}

void initCurvedRails() {}

void drawStraightRails() {
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({0.f,0.f,1.f});
		myEngine.updateMvMatrix();

		test.drawShape();

	myEngine.mvMatrixStack.popMatrix ();
}

void drawCurvedRails() {}

void drawCircuit(){
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({-sceneComposition.terrainWidth / 2, -sceneComposition.terrainHeight / 2, 0.f});
		myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}