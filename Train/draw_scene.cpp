#include "draw_scene.hpp"

/* Paramètres de la caméra */
	/* Angle entre l'axe des x et la caméra */
	float angle_theta { 45.0 };

	/* Angle entre l'axe des Z et la caméra */
	float angle_phy { 30.0 };

	/* Distance entre le point d'origine de la scène et la caméra */
	float dist_zoom { 30.0 };

/* Moteur OpenGL */
GLBI_Engine myEngine;

GLBI_Convex_2D_Shape ground{3};

/* Initialisation des formes */
void initScene() {
	std::vector<float> baseCarre{
		-10.0,-10.0, 0.0,
		 10.0,-10.0, 0.0,
		 10.0, 10.0, 0.0,
		-10.0, 10.0, 0.0
	};
	ground.initShape(baseCarre);
	ground.changeNature(GL_TRIANGLE_FAN);
}

/* Dessin de la scène */
void drawScene() {
	glPointSize(10.0);

	myEngine.setFlatColor((245 / 255.f), (164 / 255.f), (66 / 255.f));
	ground.drawShape();
}



