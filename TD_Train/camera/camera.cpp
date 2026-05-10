#include "camera.hpp"
#include "../engine/engine.hpp"
#include "GLFW/glfw3.h"

/* Selection de la caméra */
int selectedCamera { 0 };

/* Paramètres de la caméra Orbital */
	/* Angle entre l'axe des x et la caméra */
	float angle_theta { 45.0 };

	/* Angle entre l'axe des Z et la caméra */
	float angle_phy { 30.0 };

	/* Distance entre le point d'origine de la scène et la caméra */
	float dist_zoom { 30.0 };

void orbitalCamera() {
	myEngine.mvMatrixStack.loadIdentity();
		
		Vector3D pos_camera =
			Vector3D(dist_zoom*cos(M_PI * angle_theta / 180)*cos(M_PI * angle_phy / 180),
			dist_zoom*sin(M_PI * angle_theta / 180)*cos(M_PI * angle_phy / 180),
			dist_zoom*sin(M_PI * angle_phy / 180));

		Vector3D viewed_point = Vector3D(0.0,0.0,0.0);
		Vector3D up_vector = Vector3D(0.0,0.0,1.0);

		Matrix4D viewMatrix = Matrix4D::lookAt(pos_camera,viewed_point,up_vector);
		myEngine.setViewMatrix(viewMatrix);

	myEngine.updateMvMatrix();
}

/* Paramètres de la caméra du plafond */
int roofCameraX { 0 };
int roofCameraY { 0 };
int roofCameraZ { 75 };

void roofCamera() {
	myEngine.mvMatrixStack.loadIdentity();
		
		Vector3D pos_camera = Vector3D(roofCameraX, roofCameraY, roofCameraZ);
		Vector3D viewed_point = Vector3D(roofCameraX, roofCameraY, 0.0);
		Vector3D up_vector = Vector3D(0.0, 1.0, 0.0);

		Matrix4D viewMatrix = Matrix4D::lookAt(pos_camera, viewed_point, up_vector);
		myEngine.setViewMatrix(viewMatrix);

	myEngine.updateMvMatrix();
}

void cameraSelector() {
	switch (selectedCamera)
	{
	case 0:
		orbitalCamera();
		break;

	case 1: 
		orbitalCamera();
		break;

	case 2:
		roofCamera();
		break;
	
	default:
		orbitalCamera();
		break;
	}
}

void cameraMovement(int const& key, int const& action) {
	switch (key) {
		// Avancer
		case GLFW_KEY_W:
			if(selectedCamera == 0) {
				angle_phy += 1.0;
			}

			if(selectedCamera == 1) {
				angle_phy += 1.0;
			}

			if(selectedCamera == 2) {
				roofCameraY++;
			}
			break;

		// Reculer
		case GLFW_KEY_S:
			if(selectedCamera == 0) {
				angle_phy -= 1.0;
			}

			if(selectedCamera == 1) {
				angle_phy -= 1.0;
			}

			if(selectedCamera == 2) {
				roofCameraY--;
			}
			break;

		// Aller à gauche
		case GLFW_KEY_A:
			if(selectedCamera == 0) {
				angle_theta -= 1.0;
			}

			if(selectedCamera == 1) {
				angle_theta -= 1.0;
			}

			if(selectedCamera == 2) {
				roofCameraX--;
			}
			break;

		// Aller à droite
		case GLFW_KEY_D:
			if(selectedCamera == 0) {
				angle_theta += 1.0;
			}

			if(selectedCamera == 1) {
				angle_theta += 1.0;
			}

			if(selectedCamera == 2) {
				roofCameraX++;
			}
			break;

		// Zoomer
		case GLFW_KEY_R:
			if(selectedCamera == 0 && action == GLFW_PRESS) {
				dist_zoom = dist_zoom * 0.9;
			}

			if(selectedCamera == 1 && action == GLFW_PRESS) {
				dist_zoom = dist_zoom * 0.9;
			}

			if(selectedCamera == 2 && action == GLFW_PRESS) {
				roofCameraZ -= 10;
			}
			break;

		// Dézoomer
		case GLFW_KEY_T:
			if(selectedCamera == 0 && action == GLFW_PRESS) {
				dist_zoom = dist_zoom * 1.1;
			}

			if(selectedCamera == 1 && action == GLFW_PRESS) {
				dist_zoom = dist_zoom * 1.1;
			}

			if(selectedCamera == 2 && action == GLFW_PRESS) {
				roofCameraZ +=10;
			}
			break;
	}
}

