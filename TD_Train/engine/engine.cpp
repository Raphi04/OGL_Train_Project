#include "engine.hpp"

/* Moteur OpenGL */
GLBI_Engine myEngine;

/* Repère 3D */
StandardMesh* repere;

void initJSONConfig(std::string const& json) {
	std::ifstream file("../" + json);

	if(!file) {
		std::cout << "Fichier non trouve" << std::endl << "../" +json << std::endl;
		return;
	}

	nlohmann::json inputJson = nlohmann::json::parse(file);

	sceneComposition.terrainWidth = inputJson.at("size_grid").get<float>();
	sceneComposition.terrainHeight = inputJson.at("size_grid").get<float>();
}

void initRepere() {
    repere = createRepere();
	repere->createVAO();
}

void drawRepere() {
    myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety(5);
		myEngine.updateMvMatrix();

		repere->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}