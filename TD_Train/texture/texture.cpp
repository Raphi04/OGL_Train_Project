#include "texture.hpp"
///////////////////////////
// CHANGER LES CHEMINS POUR LES TEXTURE.PNG
////////////////////////////////////////
#define STB_IMAGE_IMPLEMENTATION
#include "tools/stb_image.h"

GLBI_Texture woodTexture;
GLBI_Texture metalTexture;
GLBI_Texture bois_gareTexture;
GLBI_Texture acier_gareTexture;

void createTexture() {
    stbi_set_flip_vertically_on_load(true);

    // Wood Texture
    int woodWidth {};
	int woodHeight {};
	int woodChannel {};

    unsigned char* wood { stbi_load("../assets/textures/wood.jpg", &woodWidth, &woodHeight, &woodChannel, 0) };

	if(wood == NULL) {
		std::cout << "Le charchement de la texture wood à échoué" << std::endl;
	}

    woodTexture.createTexture();
	woodTexture.attachTexture();
	woodTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	woodTexture.loadImage(woodWidth, woodHeight, woodChannel, wood);

	stbi_image_free(wood);

    // Metal Texture
    int metalWidth {};
	int metalHeight {};
	int metalChannel {};

    unsigned char* metal { stbi_load("../assets/textures/metal.jpg", &metalWidth, &metalHeight, &metalChannel, 0) };

	if(metal == NULL) {
		std::cout << "Le charchement de la texture metal à échoué" << std::endl;
	}

    metalTexture.createTexture();
	metalTexture.attachTexture();
	metalTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	metalTexture.loadImage(metalWidth, metalHeight, metalChannel, metal);

	stbi_image_free(metal);

	////////////////////////////////////////////////////BOIS TRAIN

    // Wood Texture
    int boisWidth {};
	int boisHeight {};
	int boisChannel {};

    unsigned char* bois_gare { stbi_load("../TD_Train/texture/bois_gare.png", &boisWidth, &boisHeight, &boisChannel, 0) };

	if(bois_gare == NULL) {
		std::cout << "Le charchement de la texture pour la gare à échoué" << std::endl;
	}

    bois_gareTexture.createTexture();
	bois_gareTexture.attachTexture();
	bois_gareTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	bois_gareTexture.loadImage(boisWidth, boisHeight, boisChannel, bois_gare);

	stbi_image_free(bois_gare);

	///////////////////////ACIER TRAIN

	////////////////////////////////////////////////////BOIS TRAIN
	
    // Wood Texture
    int acierWidth {};
	int acierHeight {};
	int acierChannel {};

    unsigned char* acier_gare { stbi_load("../TD_Train/texture/acier_gare.png", &acierWidth, &acierHeight, &acierChannel, 0) };

	if(bois_gare == NULL) {
		std::cout << "Le charchement de la texture pour l'acier gare à échoué" << std::endl;
	}

    acier_gareTexture.createTexture();
	acier_gareTexture.attachTexture();
	acier_gareTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	acier_gareTexture.loadImage(acierWidth, acierHeight, acierChannel, acier_gare);

	stbi_image_free(acier_gare);


}