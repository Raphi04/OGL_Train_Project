#include "rails.hpp"

GLBI_Convex_2D_Shape test{3};
IndexedMesh* test2;
IndexedMesh* test3;

GLBI_Convex_2D_Shape rail{3};
IndexedMesh* balast;

StraightRailParams straightRailParams {};
CurvedRailParams curvedRailsParams {};

void initRails() {
	float const& sr { straightRailParams.rail_size };

	std::vector<float> railShape {
		/* Face Gauche */
		-(sr / 2.f),  0.f, 0.f,
		-(sr / 2.f), 10.f, 0.f,
		-(sr / 2.f),  0.f,  sr,
		-(sr / 2.f), 10.f,  sr,

		/* Face du Haut */
		 (sr / 2.f),  0.f,  sr,
		 (sr / 2.f), 10.f,  sr,

		/* Face Droite */
		 (sr / 2.f),   0.f, 0.f,
		 (sr / 2.f),  10.f, 0.f,

		/* Face du Bas */
		-(sr / 2.f),  0.f, 0.f,
		-(sr / 2.f), 10.f, 0.f,
		 (sr / 2.f), 10.f, 0.f,

		/* Face du Fond */
		 (sr / 2.f), 10.f,  sr,
		-(sr / 2.f), 10.f, 0.f,
		-(sr / 2.f), 10.f,  sr,

		/* Face Avant */
		-(sr / 2.f), 0.f,  sr,
		-(sr / 2.f), 0.f, 0.f,
		 (sr / 2.f), 0.f,  sr,
		 (sr / 2.f), 0.f, 0.f,
	};

	rail.initShape(railShape);
	rail.changeNature(GL_TRIANGLE_STRIP);
}

void initBalast(){
	float const& rayon { straightRailParams.balastRayons };
	float const hauteur { straightRailParams.balastX2 - straightRailParams.balastX1 };
	balast = basicCylinder(hauteur, rayon);
}

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
		myEngine.updateMvMatrix();

		/* Draw First Rail*/
		myEngine.mvMatrixStack.pushMatrix();

			myEngine.mvMatrixStack.addTranslation({straightRailParams.posRailOne, 0.f, straightRailParams.balastRayons});
			myEngine.updateMvMatrix();

			rail.drawShape();

		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	/* Draw Second Rail*/
		myEngine.mvMatrixStack.pushMatrix();

			myEngine.mvMatrixStack.addTranslation({straightRailParams.posRailTwo, 0.f, straightRailParams.balastRayons});
			myEngine.updateMvMatrix();

			rail.drawShape();

		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

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