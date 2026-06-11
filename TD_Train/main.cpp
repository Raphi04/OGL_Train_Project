#include <iostream>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "tools/shaders.hpp"

#include "engine/engine.hpp"
#include "terrain/terrain.hpp"
#include "camera/camera.hpp"
#include "draw_scene.hpp"

#include "lumiere/lumiere.hpp"

using namespace glbasimac;
using namespace STP3D;

/* Propriétés de la fenêtre */
static const unsigned int WINDOW_WIDTH = 1200;
static const unsigned int WINDOW_HEIGHT = 800;
static const char WINDOW_TITLE[] = "Train Project";
static float aspectRatio = 1.0f;

/* Intervale de temps entre deux images */
static const double FRAMERATE_IN_SECONDS = 1. / 30.;

/* Variable d'état du mode filaire */
bool isLineMode { false };

/* Fonction de gestion des erreurs */
void onError(int error, const char* description) {
	std::cout << "GLFW Error ("<<error<<") : " << description << std::endl;
}

/* Gestion du changement de la taille de la fenêtre */
void onWindowResized(GLFWwindow* /*window*/, int width, int height) {
	aspectRatio = width / (float) height;

	glViewport(0, 0, width, height);
	std::cerr << "Setting 3D projection" << std::endl;

	myEngine.set3DProjection(90.0, aspectRatio, Z_NEAR, Z_FAR);
}

/* Gestion des touches de clavier */
void onKey(GLFWwindow* window, int key, int /*scancode*/, int action, int /*mods*/) {
	/* Ferme la fenêtre à l'appuie de la touche échap */
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	/* Passer au mode de lumière réaliste */
	if(key == GLFW_KEY_L && action == GLFW_PRESS) {
		lightToggle = !lightToggle;
	}

	/* Changer de caméra */
	if(key == GLFW_KEY_C && action == GLFW_PRESS) {
		selectedCamera = (selectedCamera + 1) % 3;
	}

	/* Afficher / Retirer la grille du terrain */
	if(key == GLFW_KEY_G && action == GLFW_PRESS) {
		showTerrainGrid = !showTerrainGrid;
	}

	/* Gestion des mouvements de la caméra */
	cameraMovement(key, action);
}

/* Fonction de callback du mouvement de la souris */
void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	if(selectedCamera == 1) {
		cameraAim(xpos, ypos);
	}
}

int main(int argc, char* argv[]) {

	if(argc < 2 ){
		std::cout << "Veuillez inclure un json en argument de la commande";

		return 0;
		
	} else {
		initJSONConfig(argv[1]);
	}


	/* Initialisation de GLFW */
	GLFWwindow* window;
	if (!glfwInit()) return -1;

	/* Renvoie une erreur si GLFW en relève une */
	glfwSetErrorCallback(onError);

	/* Ouvre une fenêtre OpenGL */
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Faire de la fenêtre le contexte actuel */
	glfwMakeContextCurrent(window);

	std::cout<<"Loading GL extension"<<std::endl;
	// Initialisation de glad (charge les fonctions OpenGL)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return -1;
	}

	/* Mise en place des fonctions de callback */
	glfwSetWindowSizeCallback(window, onWindowResized);
	glfwSetKeyCallback(window, onKey);

	/* Mise en place de la détéction du mouvement de la souris */
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); 
	glfwSetCursorPosCallback(window, mouse_callback);   

	/* Lancement du moteur 3D */
	myEngine.mode2D = false;
	myEngine.initGL();

	onWindowResized(window,WINDOW_WIDTH,WINDOW_HEIGHT);

	initScene();

	/* Variable du temps passer depuis le début de la boucle */
	double elapsedTime { 0.0 };

	/* Boucle tant que la fenêtre n'est pas fermé */
	while (!glfwWindowShouldClose(window)) {

		/* Temps en seconde au début de la boucle*/
		double startTime = glfwGetTime();
		
		/* Fond de la scène */
		glClearColor(0.f,0.0f,0.2f,0.0f);

		// Gestion de l'axe Z
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		/* Gestion de la caméra */
		cameraSelector();

		/* Dessine notre scene */
		drawScene();
		
		/* Échange les buffers front et back */
		glfwSwapBuffers(window);

		/* Gestion des evenements et du poll */
		glfwPollEvents();

		/* Calcul du temps passer depuis le début de la boucle */
		elapsedTime = glfwGetTime() - startTime;
		/* If to few time is spend vs our wanted FPS, we wait */
		while(elapsedTime < FRAMERATE_IN_SECONDS)
		{
			glfwWaitEventsTimeout(FRAMERATE_IN_SECONDS-elapsedTime);
			elapsedTime = glfwGetTime() - startTime;
		}
	}

	glfwTerminate();
	return 0;
}
