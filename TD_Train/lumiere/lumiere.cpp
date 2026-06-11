#include "lumiere.hpp"

#include "../engine/engine.hpp"

bool lightToggle { false };

void initLights() {
    myEngine.switchToPhongShading();

	myEngine.addALight({0.f, sceneComposition.terrainHeight / 2, 15.f, 0.f}, {0.9f, 0.9f, 0.9f});
	myEngine.addALight({sceneComposition.terrainWidth / 2, 0.f, 15.f, 0.f}, {0.9f, 0.9f, 0.9f});
	myEngine.addALight({0.f, -sceneComposition.terrainHeight / 2, 15.f, 0.f}, {0.5f, 0.5f, 0.5f});
	myEngine.addALight({-sceneComposition.terrainWidth / 2, 0.f, 15.f, 0.f}, {0.5f, 0.5f, 0.5f});
	myEngine.addALight({0.f, 0.f, 15.f, 0.f}, {0.5f, 0.5f, 0.5f});
	myEngine.addALight({0.f, 0.f, -15.f, 0.f}, {0.5f, 0.5f, 0.5f});

	myEngine.setShininess(5.f);

	myEngine.switchToFlatShading();
}