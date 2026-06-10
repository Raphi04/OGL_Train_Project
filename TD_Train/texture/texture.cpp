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
GLBI_Texture logo_trainTexture;
GLBI_Texture pipeLogoTexture;
GLBI_Texture goldTexture;
GLBI_Texture wood2Texture;
GLBI_Texture glassTexture;

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

//LOGO TRAIN
  // Wood Texture
    int logoWidth {};
	int logoHeight {};
	int logoChannel {};

    unsigned char* logo_train { stbi_load("../TD_Train/texture/logo_train.png", &logoWidth, &logoHeight, &logoChannel, 0) };

	if(logo_train == NULL) {
		std::cout << "Le charchement de la texture pour logo train a échoué" << std::endl;
	}

    logo_trainTexture.createTexture();
	logo_trainTexture.attachTexture();
	logo_trainTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	logo_trainTexture.loadImage(logoWidth, logoHeight, acierChannel, logo_train);

	stbi_image_free(logo_train);

//TUYAU
int pipeLogoWidth {};
int pipeLogoHeight {};
int pipeLogoChannel {};

unsigned char* pipe_logo {
    stbi_load("../TD_Train/texture/pip2.jpg",
              &pipeLogoWidth,
              &pipeLogoHeight,
              &pipeLogoChannel,
              0)
};

if(pipe_logo == NULL) {
    std::cout << "Le chargement de la texture pour le logo tuyau a échoué" << std::endl;
}

pipeLogoTexture.createTexture();
pipeLogoTexture.attachTexture();
pipeLogoTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);


pipeLogoTexture.loadImage(pipeLogoWidth, pipeLogoHeight, pipeLogoChannel, pipe_logo);

stbi_image_free(pipe_logo);

//OR
// GOLD TEXTURE
int goldWidth {};
int goldHeight {};
int goldChannel {};

unsigned char* gold_texture {
    stbi_load("../TD_Train/texture/gold.jpg",
              &goldWidth,
              &goldHeight,
              &goldChannel,
              0)
};

if(gold_texture == NULL) {
    std::cout << "Le chargement de la texture gold a échoué" << std::endl;
}

goldTexture.createTexture();
goldTexture.attachTexture();
goldTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

goldTexture.loadImage(goldWidth, goldHeight, goldChannel, gold_texture);

stbi_image_free(gold_texture);

//BOIS TRAIN
int wood2Width {};
int wood2Height {};
int wood2Channel {};

unsigned char* wood2_texture {
    stbi_load("../TD_Train/texture/wood2.png",
              &wood2Width,
              &wood2Height,
              &wood2Channel,
              0)
};

if(wood2_texture == NULL) {
    std::cout << "Le chargement de la texture wood2 a échoué" << std::endl;
}

wood2Texture.createTexture();
wood2Texture.attachTexture();
wood2Texture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

wood2Texture.loadImage(wood2Width, wood2Height, wood2Channel, wood2_texture);

stbi_image_free(wood2_texture);

//GLASS

int glassWidth {};
int glassHeight {};
int glassChannel {};

unsigned char* glass_texture {
    stbi_load("../TD_Train/texture/glass.jpg",
              &glassWidth,
              &glassHeight,
              &glassChannel,
              0)
};

if(glass_texture == NULL) {
    std::cout << "Le chargement de la texture glass a échoué" << std::endl;
}

glassTexture.createTexture();
glassTexture.attachTexture();
glassTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

glassTexture.loadImage(glassWidth, glassHeight, glassChannel, glass_texture);

stbi_image_free(glass_texture);


}