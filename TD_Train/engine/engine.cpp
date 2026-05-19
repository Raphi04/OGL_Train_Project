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

	sceneComposition.terrainWidth = inputJson.at("grid_width").get<float>();
	sceneComposition.terrainHeight = inputJson.at("grid_height").get<float>();

	getRails(inputJson.at("path").get<std::vector<std::array<int, 2>>>());

	railParams = inputJson.at("railsParams").get<RailsParams>();
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