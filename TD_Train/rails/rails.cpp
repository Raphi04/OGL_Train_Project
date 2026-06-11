#include "rails.hpp"

IndexedMesh* test2;
IndexedMesh* test3;

GLBI_Convex_2D_Shape rail{3};
GLBI_Convex_2D_Shape curvedRail{3};

GLBI_Convex_2D_Shape curvedRail1Top{3};
GLBI_Convex_2D_Shape curvedRail1Bot{3};
GLBI_Convex_2D_Shape curvedRail1Left{3};
GLBI_Convex_2D_Shape curvedRail1Right{3};

GLBI_Convex_2D_Shape curvedRail2Top{3};
GLBI_Convex_2D_Shape curvedRail2Bot{3};
GLBI_Convex_2D_Shape curvedRail2Left{3};
GLBI_Convex_2D_Shape curvedRail2Right{3};

IndexedMesh* balast{};

RailsParams railParams{};

void initStraightRails() {
	float const& sr { railParams.rail_size };

	std::vector<float> railShape {
		/* Face Gauche */
		-(sr / 2.f),  0.f, 0.f,
		-(sr / 2.f), 10.f, 0.f,
		-(sr / 2.f),  0.f,  sr,

		-(sr / 2.f),  0.f,  sr,
		-(sr / 2.f), 10.f, 0.f,
		-(sr / 2.f), 10.f,  sr,

		/* Face du Haut */
		-(sr / 2.f),  0.f,  sr,
		-(sr / 2.f), 10.f,  sr,
		 (sr / 2.f),  0.f,  sr,

		 (sr / 2.f),  0.f,  sr,
		-(sr / 2.f), 10.f,  sr,
		 (sr / 2.f), 10.f,  sr,


		/* Face Droite */
		 (sr / 2.f),   0.f, 0.f,
		 (sr / 2.f),  10.f, 0.f,
		 (sr / 2.f),   0.f,  sr,

		 (sr / 2.f),   0.f,  sr,
		 (sr / 2.f),  10.f,  sr,
		 (sr / 2.f),  10.f, 0.f,

		/* Face du Bas */
		-(sr / 2.f),  0.f, 0.f,
		-(sr / 2.f), 10.f, 0.f,
		 (sr / 2.f),  0.f, 0.f,

		 (sr / 2.f),  0.f, 0.f,
		-(sr / 2.f), 10.f, 0.f,
		 (sr / 2.f), 10.f, 0.f,

		/* Face du Fond */
		-(sr / 2.f), 10.f, 0.f,
		 (sr / 2.f), 10.f, 0.f,
		-(sr / 2.f), 10.f,  sr,

		-(sr / 2.f), 10.f,  sr,
		 (sr / 2.f), 10.f,  sr,
		 (sr / 2.f), 10.f, 0.f,

		/* Face Avant */
		-(sr / 2.f), 0.f,  0.f,
		 (sr / 2.f), 0.f,  0.f,
		-(sr / 2.f), 0.f,   sr,

		-(sr / 2.f), 0.f,   sr,
		 (sr / 2.f), 0.f,  0.f,
		 (sr / 2.f), 0.f,   sr,
	};

	std::vector<float> railShapeNormals {
		/* Face de Gauche */
		0.f, -1.f, 0.f,
		0.f, -1.f, 0.f,
		0.f, -1.f, 0.f,
		0.f, -1.f, 0.f,
		0.f, -1.f, 0.f,
		0.f, -1.f, 0.f,

		/* Face du Haut */
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,

		/* Face de Droite */
		0.f, 1.f, 0.f,
		0.f, 1.f, 0.f,
		0.f, 1.f, 0.f,
		0.f, 1.f, 0.f,
		0.f, 1.f, 0.f,
		0.f, 1.f, 0.f,

		/* Face de Bas */
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,

		/* Face du Fond */
		1.f, 0.f, 0.f,
		1.f, 0.f, 0.f,
		1.f, 0.f, 0.f,
		1.f, 0.f, 0.f,
		1.f, 0.f, 0.f,
		1.f, 0.f, 0.f,

		/* Face Avant */
		-1.f, 0.f, 0.f,
		-1.f, 0.f, 0.f,
		-1.f, 0.f, 0.f,
		-1.f, 0.f, 0.f,
		-1.f, 0.f, 0.f,
		-1.f, 0.f, 0.f,
	};

	std::vector<float> railShapeUvs {
		/* Face Gauche */
		0.f, 0.f,
		0.f, 1.f,
		1.f, 0.f,

		1.f, 0.f,
		0.f, 1.f,
		1.f, 1.f,

		/* Face du Haut */
		0.f, 0.f,
		0.f, 1.f,
		1.f, 0.f,

		1.f, 0.f,
		0.f, 1.f,
		1.f, 1.f,

		/* Face Droite */
		0.f, 0.f,
		0.f, 1.f,
		1.f, 0.f,

		1.f, 0.f,
		0.f, 1.f,
		1.f, 1.f,

		/* Face du Bas */
		0.f, 0.f,
		0.f, 1.f,
		1.f, 0.f,

		1.f, 0.f,
		0.f, 1.f,
		1.f, 1.f,

		/* Face du Fond */
		0.f, 0.f,
		1.f, 0.f,
		0.f, 1.f,

		0.f, 1.f,
		1.f, 1.f,
		1.f, 0.f,

		/* Face Avant */
		0.f, 0.f,
		1.f, 0.f,
		0.f, 1.f,

		0.f, 1.f,
		1.f, 0.f,
		1.f, 1.f
	};

	rail.initShape(railShape, railShapeNormals, railShapeUvs);
	rail.changeNature(GL_TRIANGLES);
}

void initCurvedRails() {
	float const& sr { railParams.rail_size };

	/* CurvedRail1Top */
	std::vector<float> curvedRail1TopShape {};
	std::vector<float> curvedRail1TopNormals {};
	std::vector<float> curvedRail1TopUvs {};
	
	/* CurvedRail1Left */
	std::vector<float> curvedRail1LeftShape {};
	std::vector<float> curvedRail1LeftNormals {};
	std::vector<float> curvedRail1LeftUvs {};

	/* CurvedRail1Right */
	std::vector<float> curvedRail1RightShape {};
	std::vector<float> curvedRail1RightNormals {};
	std::vector<float> curvedRail1RightUvs {};

	/* CurvedRail1Bot */
	std::vector<float> curvedRail1BotShape {};
	std::vector<float> curvedRail1BotNormals {};
	std::vector<float> curvedRail1BotUvs {};

	/* CurvedRail2Top */
	std::vector<float> curvedRail2TopShape {};
	std::vector<float> curvedRail2TopNormals {};
	std::vector<float> curvedRail2TopUvs {};

	/* CurvedRail2Left */
	std::vector<float> curvedRail2LeftShape {};
	std::vector<float> curvedRail2LeftNormals {};
	std::vector<float> curvedRail2LeftUvs {};

	/* CurvedRail2Right */
	std::vector<float> curvedRail2RightShape {};
	std::vector<float> curvedRail2RightNormals {};
	std::vector<float> curvedRail2RightUvs {};

	/* CurvedRail2Bot */
	std::vector<float> curvedRail2BotShape {};
	std::vector<float> curvedRail2BotNormals {};
	std::vector<float> curvedRail2BotUvs {};

	for(int i { 0 }; i <= 50; i++) {
		float angle = i * (M_PI /2.0f) / 50.0f;

		float posX = cos(angle) * (railParams.posRailOne - sr / 2);
		float posY = sin(angle) * (railParams.posRailOne - sr / 2);

		float posXE = cos(angle) * (railParams.posRailOne + sr / 2);
		float posYE = sin(angle) * (railParams.posRailOne + sr / 2);

		/* CurvedRail1Top */
		curvedRail1TopShape.push_back(posX);
		curvedRail1TopShape.push_back(posY);
		curvedRail1TopShape.push_back(sr);

		curvedRail1TopNormals.push_back(0.f);	
		curvedRail1TopNormals.push_back(0.f);	
		curvedRail1TopNormals.push_back(1.f);
		
		curvedRail1TopUvs.push_back(0.4 + cos(angle) / 2 );	
		curvedRail1TopUvs.push_back(0.4 + sin(angle) / 2 );

		curvedRail1TopShape.push_back(posXE);
		curvedRail1TopShape.push_back(posYE);
		curvedRail1TopShape.push_back(sr);
		
		curvedRail1TopNormals.push_back(0.f);	
		curvedRail1TopNormals.push_back(0.f);	
		curvedRail1TopNormals.push_back(1.f);

		curvedRail1TopUvs.push_back(0.5 + cos(angle)  / 2);	
		curvedRail1TopUvs.push_back(0.5 + sin(angle)  / 2);

		/* CurvedRail1Left */
		curvedRail1LeftShape.push_back(posX);
		curvedRail1LeftShape.push_back(posY);
		curvedRail1LeftShape.push_back(0.f);

		curvedRail1LeftNormals.push_back(-cos(angle));	
		curvedRail1LeftNormals.push_back(-sin(angle));	
		curvedRail1LeftNormals.push_back(0.f);
		
		curvedRail1LeftUvs.push_back(0.4 + cos(angle) / 2 );	
		curvedRail1LeftUvs.push_back(0.4 + sin(angle) / 2 );

		curvedRail1LeftShape.push_back(posX);
		curvedRail1LeftShape.push_back(posY);
		curvedRail1LeftShape.push_back(sr);
		
		curvedRail1LeftNormals.push_back(-cos(angle));	
		curvedRail1LeftNormals.push_back(-sin(angle));	
		curvedRail1LeftNormals.push_back(0.f);

		curvedRail1LeftUvs.push_back(0.5 + cos(angle)  / 2);	
		curvedRail1LeftUvs.push_back(0.5 + sin(angle)  / 2);

		/* CurvedRail1Right */
		curvedRail1RightShape.push_back(posXE);
		curvedRail1RightShape.push_back(posYE);
		curvedRail1RightShape.push_back(0.f);

		curvedRail1RightNormals.push_back(cos(angle));	
		curvedRail1RightNormals.push_back(sin(angle));	
		curvedRail1RightNormals.push_back(0.f);
		
		curvedRail1RightUvs.push_back(0.4 + cos(angle) / 2 );	
		curvedRail1RightUvs.push_back(0.4 + sin(angle) / 2 );

		curvedRail1RightShape.push_back(posXE);
		curvedRail1RightShape.push_back(posYE);
		curvedRail1RightShape.push_back(sr);
		
		curvedRail1RightNormals.push_back(cos(angle));	
		curvedRail1RightNormals.push_back(sin(angle));	
		curvedRail1RightNormals.push_back(0.f);

		curvedRail1RightUvs.push_back(0.5 + cos(angle)  / 2);	
		curvedRail1RightUvs.push_back(0.5 + sin(angle)  / 2);

		/* CurvedRail1Bot */
		curvedRail1BotShape.push_back(posX);
		curvedRail1BotShape.push_back(posY);
		curvedRail1BotShape.push_back(0.f);

		curvedRail1BotNormals.push_back(0.f);	
		curvedRail1BotNormals.push_back(0.f);	
		curvedRail1BotNormals.push_back(1.f);
		
		curvedRail1BotUvs.push_back(0.4 + cos(angle) / 2 );	
		curvedRail1BotUvs.push_back(0.4 + sin(angle) / 2 );

		curvedRail1BotShape.push_back(posXE);
		curvedRail1BotShape.push_back(posYE);
		curvedRail1BotShape.push_back(0.f);
		
		curvedRail1BotNormals.push_back(0.f);	
		curvedRail1BotNormals.push_back(0.f);	
		curvedRail1BotNormals.push_back(1.f);

		curvedRail1BotUvs.push_back(0.5 + cos(angle)  / 2);	
		curvedRail1BotUvs.push_back(0.5 + sin(angle)  / 2);

		float posX2 = cos(angle) * (railParams.posRailTwo - sr / 2);
		float posY2 = sin(angle) * (railParams.posRailTwo - sr / 2);

		float posX2E = cos(angle) * (railParams.posRailTwo + sr / 2);
		float posY2E = sin(angle) * (railParams.posRailTwo + sr / 2);

		/* CurvedRail2Top */
		curvedRail2TopShape.push_back(posX2);
		curvedRail2TopShape.push_back(posY2);
		curvedRail2TopShape.push_back(sr);

		curvedRail2TopNormals.push_back(0.f);	
		curvedRail2TopNormals.push_back(0.f);	
		curvedRail2TopNormals.push_back(1.f);
		
		curvedRail2TopUvs.push_back(0.4 + cos(angle) / 2 );	
		curvedRail2TopUvs.push_back(0.4 + sin(angle) / 2 );

		curvedRail2TopShape.push_back(posX2E);
		curvedRail2TopShape.push_back(posY2E);
		curvedRail2TopShape.push_back(sr);
		
		curvedRail2TopNormals.push_back(0.f);	
		curvedRail2TopNormals.push_back(0.f);	
		curvedRail2TopNormals.push_back(1.f);

		curvedRail2TopUvs.push_back(0.5 + cos(angle)  / 2);	
		curvedRail2TopUvs.push_back(0.5 + sin(angle)  / 2);

		/* CurvedRail2Left */
		curvedRail2LeftShape.push_back(posX2);
		curvedRail2LeftShape.push_back(posY2);
		curvedRail2LeftShape.push_back(0.f);

		curvedRail2LeftNormals.push_back(-cos(angle));	
		curvedRail2LeftNormals.push_back(-sin(angle));	
		curvedRail2LeftNormals.push_back(0.f);
		
		curvedRail2LeftUvs.push_back(0.4 + cos(angle) / 2 );	
		curvedRail2LeftUvs.push_back(0.4 + sin(angle) / 2 );

		curvedRail2LeftShape.push_back(posX2);
		curvedRail2LeftShape.push_back(posY2);
		curvedRail2LeftShape.push_back(sr);
		
		curvedRail2LeftNormals.push_back(-cos(angle));	
		curvedRail2LeftNormals.push_back(-sin(angle));	
		curvedRail2LeftNormals.push_back(0.f);

		curvedRail2LeftUvs.push_back(0.5 + cos(angle)  / 2);	
		curvedRail2LeftUvs.push_back(0.5 + sin(angle)  / 2);

		/* CurvedRail2Right */
		curvedRail2RightShape.push_back(posX2E);
		curvedRail2RightShape.push_back(posY2E);
		curvedRail2RightShape.push_back(0.f);

		curvedRail2RightNormals.push_back(cos(angle));	
		curvedRail2RightNormals.push_back(sin(angle));	
		curvedRail2RightNormals.push_back(0.f);
		
		curvedRail2RightUvs.push_back(0.4 + cos(angle) / 2 );	
		curvedRail2RightUvs.push_back(0.4 + sin(angle) / 2 );

		curvedRail2RightShape.push_back(posX2E);
		curvedRail2RightShape.push_back(posY2E);
		curvedRail2RightShape.push_back(sr);
		
		curvedRail2RightNormals.push_back(cos(angle));	
		curvedRail2RightNormals.push_back(sin(angle));	
		curvedRail2RightNormals.push_back(0.f);

		curvedRail2RightUvs.push_back(0.5 + cos(angle)  / 2);	
		curvedRail2RightUvs.push_back(0.5 + sin(angle)  / 2);

		/* CurvedRail2Bot */
		curvedRail2BotShape.push_back(posX2);
		curvedRail2BotShape.push_back(posY2);
		curvedRail2BotShape.push_back(0.f);

		curvedRail2BotNormals.push_back(0.f);	
		curvedRail2BotNormals.push_back(0.f);	
		curvedRail2BotNormals.push_back(1.f);
		
		curvedRail2BotUvs.push_back(0.4 + cos(angle) / 2 );	
		curvedRail2BotUvs.push_back(0.4 + sin(angle) / 2 );

		curvedRail2BotShape.push_back(posX2E);
		curvedRail2BotShape.push_back(posY2E);
		curvedRail2BotShape.push_back(0.f);
		
		curvedRail2BotNormals.push_back(0.f);	
		curvedRail2BotNormals.push_back(0.f);	
		curvedRail2BotNormals.push_back(1.f);

		curvedRail2BotUvs.push_back(0.5 + cos(angle) / 2);	
		curvedRail2BotUvs.push_back(0.5 + sin(angle) / 2);

	}

	curvedRail1Top.initShape(curvedRail1TopShape, curvedRail1TopNormals, curvedRail1TopUvs);
	curvedRail1Top.changeNature(GL_TRIANGLE_STRIP);
	curvedRail1Bot.initShape(curvedRail1BotShape, curvedRail1BotNormals, curvedRail1BotUvs);
	curvedRail1Bot.changeNature(GL_TRIANGLE_STRIP);
	curvedRail1Left.initShape(curvedRail1LeftShape, curvedRail1LeftNormals, curvedRail1LeftUvs);
	curvedRail1Left.changeNature(GL_TRIANGLE_STRIP);
	curvedRail1Right.initShape(curvedRail1RightShape, curvedRail1RightNormals, curvedRail1RightUvs);
	curvedRail1Right.changeNature(GL_TRIANGLE_STRIP);

	curvedRail2Top.initShape(curvedRail2TopShape, curvedRail2TopNormals, curvedRail2TopUvs);
	curvedRail2Top.changeNature(GL_TRIANGLE_STRIP);
	curvedRail2Left.initShape(curvedRail2LeftShape, curvedRail2LeftNormals, curvedRail2LeftUvs);
	curvedRail2Left.changeNature(GL_TRIANGLE_STRIP);
	curvedRail2Right.initShape(curvedRail2RightShape, curvedRail2RightNormals, curvedRail2RightUvs);
	curvedRail2Right.changeNature(GL_TRIANGLE_STRIP);
	curvedRail2Bot.initShape(curvedRail2BotShape, curvedRail2BotNormals, curvedRail2BotUvs);
	curvedRail2Bot.changeNature(GL_TRIANGLE_STRIP);
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

			myEngine.activateTexturing(true);
			
				metalTexture.attachTexture();

				rail.drawShape();

				metalTexture.detachTexture();

			myEngine.activateTexturing(false);

		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	/* Draw Second Rail*/
		myEngine.mvMatrixStack.pushMatrix();

			myEngine.mvMatrixStack.addTranslation({railParams.posRailTwo, 0.f, 2 * railParams.balastRayons});
			myEngine.updateMvMatrix();

			myEngine.activateTexturing(true);
			
				metalTexture.attachTexture();
				
				rail.drawShape();
			
				metalTexture.detachTexture();

			myEngine.activateTexturing(false);

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

			// myEngine.switchToPhongShading();

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

					myEngine.activateTexturing(true);					

						woodTexture.attachTexture();
					
						balast->draw();
						
						woodTexture.detachTexture();

					myEngine.activateTexturing(false);

				myEngine.mvMatrixStack.popMatrix();
				myEngine.updateMvMatrix();
			}

			// myEngine.switchToFlatShading();
		
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
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.f, 0.f, 2 * railParams.balastRayons});
			myEngine.updateMvMatrix();

			myEngine.activateTexturing(true);
			
				metalTexture.attachTexture();

				curvedRail1Top.drawShape();
				curvedRail1Left.drawShape();
				curvedRail1Right.drawShape();
				curvedRail1Bot.drawShape();

				metalTexture.detachTexture();

			myEngine.activateTexturing(false);

		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		/* Dessin du deuxième Rail */
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.f, 0.f, 2 * railParams.balastRayons});
			myEngine.updateMvMatrix();

			myEngine.activateTexturing(true);
			
				metalTexture.attachTexture();

				curvedRail2Top.drawShape();
				curvedRail2Left.drawShape();
				curvedRail2Right.drawShape();
				curvedRail2Bot.drawShape();

				metalTexture.detachTexture();

			myEngine.activateTexturing(false);

		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

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
								
					myEngine.activateTexturing(true);

						woodTexture.attachTexture();

						balast->draw();

						woodTexture.detachTexture();

					myEngine.activateTexturing(false);


				myEngine.mvMatrixStack.popMatrix();
				myEngine.updateMvMatrix();
			}

		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}