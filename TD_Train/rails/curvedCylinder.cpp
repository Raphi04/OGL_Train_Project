#include "curvedCylinder.hpp"

GLBI_Convex_2D_Shape curvedCylinder{3};

void initCurvedCylinder(
	float const& rayonAngle,
    float const& repetition,
    float const& rayonCylindre,
    float const& nombrePoints
) {
	std::vector<float> curvedCylinderPoints {};

	
	for(int i { 0 }; i <= nombrePoints; i++) {
		float angleCercle { float(i * (2 * M_PI) / nombrePoints) };

		for(int j { 0 }; j <= repetition; j++) {
			float angleRepetition { float(j * (M_PI / 2) / repetition) };

			if(i % 2 == 1) {
				curvedCylinderPoints.push_back(rayonAngle * sin(angleRepetition) + rayonCylindre * cos(angleCercle) * sin(angleRepetition));
				curvedCylinderPoints.push_back(rayonAngle * cos(angleRepetition) + rayonCylindre * cos(angleCercle) * cos(angleRepetition));
				curvedCylinderPoints.push_back(rayonCylindre + rayonCylindre * sin(angleCercle));
			} else {
				curvedCylinderPoints.push_back(rayonAngle * cos(angleRepetition) + rayonCylindre * cos(angleCercle) * cos(angleRepetition));
				curvedCylinderPoints.push_back(rayonAngle * sin(angleRepetition) + rayonCylindre * cos(angleCercle) * sin(angleRepetition));
				curvedCylinderPoints.push_back(rayonCylindre + rayonCylindre * sin(angleCercle));
			}
		}
	}

	curvedCylinder.initShape(curvedCylinderPoints);
	curvedCylinder.changeNature(GL_POINTS);
}

void drawCurvedCylinder() {
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({-5.f, -5.f, 0.f});
		myEngine.updateMvMatrix();

		curvedCylinder.drawShape();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}