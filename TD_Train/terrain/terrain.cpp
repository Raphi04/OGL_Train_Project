#include "terrain.hpp"
#include "../draw_scene.hpp"

GLBI_Convex_2D_Shape terrain{3};

void initTerrain() {
	std::vector<float> terrainShape{
		-10.0,-10.0, 0.0,
		 10.0,-10.0, 0.0,
		 10.0, 10.0, 0.0,
		-10.0, 10.0, 0.0
	};

	terrain.initShape(terrainShape);
	terrain.changeNature(GL_TRIANGLE_FAN);
};

void drawTerrain() {
    terrain.drawShape();
};
