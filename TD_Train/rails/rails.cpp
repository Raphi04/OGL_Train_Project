#include "rails.hpp"

IndexedMesh* test2;
IndexedMesh* test3;

GLBI_Convex_2D_Shape rail{3};
GLBI_Convex_2D_Shape curvedRail{3};
IndexedMesh* balast;

RailsParams railParams {};

void initStraightRails() {
	float const& sr { railParams.rail_size };

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

void initCurvedRails() {
	float const& sr { railParams.rail_size };

	std::vector<float> curvedRailShape {
		/* Face du Bas */
		-(sr / 2.f), 0.f, 0.f,
		-(sr / 2.f),  sr, 0.f,
		 (sr / 2.f), 0.f, 0.f,
		 (sr / 2.f),  sr, 0.f,

		/* Face du Fond */
		-(sr / 2.f),  sr, 0.f,
		-(sr / 2.f),  sr,  sr,
		 (sr / 2.f),  sr, 0.f,
		 (sr / 2.f),  sr,  sr,

		/* Face de Gauche*/
		-(sr / 2.f),  sr,  sr,
		-(sr / 2.f), 0.f,  sr,
		-(sr / 2.f),  sr, 0.f,
		-(sr / 2.f), 0.f, 0.f,

		/* Face Avant */
		-(sr / 2.f), 0.f,  sr,
		 (sr / 2.f), 0.f, 0.f,
		 (sr / 2.f), 0.f,  sr,
		-(sr / 2.f), 0.f,  sr,
	
		/* Face du Dessus */
		-(sr / 2.f),  sr,  sr,
		 (sr / 2.f),  sr,  sr,
		-(sr / 2.f),  sr,  sr,
		 (sr / 2.f), 0.f,  sr,

		/* Face de Droit */
		 (sr / 2.f), 0.f, 0.f,
		 (sr / 2.f),  sr, 0.f,
		 (sr / 2.f), 0.f,  sr,
		 (sr / 2.f),  sr,  sr
	};

	curvedRail.initShape(curvedRailShape);
	curvedRail.changeNature(GL_TRIANGLE_STRIP);
}

void initBalast(){
	float rayon { railParams.balastRayons };
	std::cout << "test : " << railParams.balastRayons <<std::endl;
	float hauteur { railParams.balastX2 - railParams.balastX1 };

	balast = basicCylinder(hauteur, rayon);
	balast->createVAO();
}

void drawStraightRails() {
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({-5.f, -5.f, 0.f});
		myEngine.updateMvMatrix();

		/* Draw First Rail*/
		myEngine.mvMatrixStack.pushMatrix();

			myEngine.mvMatrixStack.addTranslation({railParams.posRailOne, 0.f, 2 * railParams.balastRayons});
			myEngine.updateMvMatrix();

			myEngine.setFlatColor(0.75f, 0.75f, 0.75f);
			rail.drawShape();

		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	/* Draw Second Rail*/
		myEngine.mvMatrixStack.pushMatrix();

			myEngine.mvMatrixStack.addTranslation({railParams.posRailTwo, 0.f, 2 * railParams.balastRayons});
			myEngine.updateMvMatrix();

			myEngine.setFlatColor(0.75f, 0.75f, 0.75f);
			rail.drawShape();

		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		/* Draw Balasts */
		/*
			10u = 5 * r * 2 + 10sx
			=> 10u = 10r + 10sx
			=> 1u = r + sx
			=> sx = 1 - r
		*/

		float balastEcart = 1 - railParams.balastRayons;

		myEngine.mvMatrixStack.pushMatrix();

			myEngine.mvMatrixStack.addTranslation({railParams.balastX1, 0.f, railParams.balastRayons});
			myEngine.updateMvMatrix();

			for(int i { 0 }; i < 5; i++) {

				/* Déplacement en Y */
				if(i == 0) {
					myEngine.mvMatrixStack.addTranslation({0.f, balastEcart + railParams.balastRayons, 0.f});
				} else {
					myEngine.mvMatrixStack.addTranslation({0.f, 2 * balastEcart + 2 * railParams.balastRayons, 0.f});
				}
				myEngine.updateMvMatrix();

				/* Rotation à 90° */
				myEngine.mvMatrixStack.pushMatrix();

					myEngine.mvMatrixStack.addRotation(-M_PI * 90 / 180, {0.f, 0.f, 1.f});
					myEngine.updateMvMatrix();

					myEngine.setFlatColor(157 / 255.f, 101 / 255.f, 61 / 255.f);
					balast->draw();
				
				myEngine.mvMatrixStack.popMatrix();
				myEngine.updateMvMatrix();
			}
		
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}

void drawCurvedRails() {
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({-5.f, -5.f, 0.f});
		myEngine.updateMvMatrix();
		
		/* Dessin du premier Rail */
		for(int i { 1 }; i <= 50; i++) {
			float angle = i * (M_PI /2) / 50;
			float posX = cos(angle) * railParams.posRailOne;
			float posY = sin(angle) * railParams.posRailOne;

			myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({0.f, -railParams.rail_size / 2, 2 * railParams.balastRayons});
				myEngine.mvMatrixStack.addTranslation({posX, posY, 0.f});
				myEngine.updateMvMatrix();
			
				myEngine.setFlatColor(0.75f, 0.75f, 0.75f);
				curvedRail.drawShape();

			myEngine.mvMatrixStack.popMatrix();
			myEngine.updateMvMatrix();
		}

		/* Dessin du deuxième Rail */
		for(int i { 1 }; i <= 50; i++) {
			float angle = i * (M_PI /2) / 50;
			float posX = cos(angle) * railParams.posRailTwo;
			float posY = sin(angle) * railParams.posRailTwo;

			myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({0.f, -railParams.rail_size / 2, 2 * railParams.balastRayons});
				myEngine.mvMatrixStack.addTranslation({posX, posY, 0.f});
				myEngine.updateMvMatrix();
			
				myEngine.setFlatColor(0.75f, 0.75f, 0.75f);
				curvedRail.drawShape();

			myEngine.mvMatrixStack.popMatrix();
			myEngine.updateMvMatrix();
		}

		/* Dessin des trois Balasts */
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.f, 0.f, railParams.balastRayons});
			myEngine.updateMvMatrix();

			for(int i { 0 }; i < 3; i++) {
				float angle = ((i * 2 * M_PI) + 1) / 12.f + railParams.balastRayons / 2;
				myEngine.mvMatrixStack.pushMatrix();

					myEngine.mvMatrixStack.addTranslation({float(cos(angle)) * railParams.balastX1, float(sin(angle)) * railParams.balastX1, 0.f});
					myEngine.mvMatrixStack.addRotation(-M_PI * 90 / 180, {0.f, 0.f, 1.f});
					myEngine.mvMatrixStack.addRotation(angle, {0.f, 0.f, 1.f});
					myEngine.updateMvMatrix();
			
					myEngine.setFlatColor(157 / 255.f, 101 / 255.f, 61 / 255.f);
					balast->draw();

				myEngine.mvMatrixStack.popMatrix();
				myEngine.updateMvMatrix();
			}

		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}