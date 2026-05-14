#include "rails.hpp"
#include "../draw_scene.hpp"
#include "../engine/engine.hpp"
#include "../sceneComposition/sceneComposition.hpp"

GLBI_Convex_2D_Shape test{3};
IndexedMesh* test2;
IndexedMesh* test3;

void initStraightRails() {
	std::vector<float> baseCarre{
		-10.0,-10.0, 0.0,
		 10.0,-10.0, 0.0,
		 10.0, 10.0, 0.0,
		-10.0, 10.0, 0.0
	};
	test.initShape(baseCarre);
	test.changeNature(GL_TRIANGLE_FAN);

	test3 = basicCylinder(10, 1);
	test3->createVAO();
}

void initCurvedRails() {
	test2 = basicCylinder(5, 1);
	test2->createVAO();
}

void drawStraightRails() {
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({-5.f, -5.f, 0.f});
		myEngine.mvMatrixStack.addTranslation({5.f, 0.f, 0.f});
		myEngine.updateMvMatrix();
		
		test3->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}

void drawCurvedRails() {
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({-5.f, -5.f, 0.f});
		myEngine.mvMatrixStack.addTranslation({5.f, 0.f, 0.f});
		myEngine.updateMvMatrix();
		
		test2->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({-5.f, -5.f, 0.f});
		myEngine.mvMatrixStack.addTranslation({0.f, 5.f, 0.f});
		myEngine.mvMatrixStack.addRotation(-90*M_PI /180, {0.f, 0.f, 1.f});
		myEngine.updateMvMatrix();
		
		test2->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

}