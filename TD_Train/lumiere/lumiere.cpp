#include "lumiere.hpp"

#include "../engine/engine.hpp"

bool lightToggle { false };

void initLights() {
    myEngine.switchToPhongShading();

	myEngine.addALight({sceneComposition.terrainWidth / 2, sceneComposition.terrainHeight / 2, 50.f, 0.f}, {0.5f, 0.5f, 0.5f});

	myEngine.setAttenuationFactor({1.f, 1.f, 1.f});

	myEngine.addALight({0.f, 0.f, 0.f, 0.f}, {0.5f, 0.3f, 0.1f});
	myEngine.addALight({0.f, 0.f, 0.f, 0.f}, {0.5f, 0.3f, 0.1f});

	myEngine.setShininess(5.f);

	myEngine.switchToFlatShading();
}