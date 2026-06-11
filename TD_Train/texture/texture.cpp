#include "texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "tools/stb_image.h"

GLBI_Texture woodTexture;
GLBI_Texture metalTexture;
GLBI_Texture grassTexture;

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

	// Grass Texture
    int grassWidth {};
	int grassHeight {};
	int grassChannel {};

    unsigned char* grass { stbi_load("../assets/textures/grass.png", &grassWidth, &grassHeight, &grassChannel, 0) };

	if(grass == NULL) {
		std::cout << "Le charchement de la texture grass à échoué" << std::endl;
	}

    grassTexture.createTexture();
	grassTexture.attachTexture();
	grassTexture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	grassTexture.loadImage(grassWidth, grassHeight, grassChannel, grass);

	stbi_image_free(grass);
}