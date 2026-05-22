#include "camera.hpp"
#include "../engine/engine.hpp"
#include "GLFW/glfw3.h"

/* Selection de la caméra */
int selectedCamera { 0 };

/* Paramètres de la caméra Orbital */
	/* Angle entre l'axe des X et la caméra */
	float angle_theta { 270.0 };

	/* Angle entre l'axe des Z et la caméra */
	float angle_phy { 30.0 };

	/* Distance entre le point d'origine de la scène et la caméra */
	float dist_zoom { 15.0 };

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

/* Paramètres de la caméra fps */

/* Pour la position */
	Vector3D fps_camera_pos = Vector3D(0.f, -10.f, 5.f);
	Vector3D fps_camera_movement = Vector3D(0.f, 1.f, 0.0);
	Vector3D fps_up_vector = Vector3D(0.f, 0.f, 1.f);

	float fps_camera_movement_speed = 0.3f;

	/* Pour les mouvements de souris */
	bool firstMouseMovement { true };

	int fps_mouse_lastX { 0 };
	int fps_mouse_lastY { 0 };

	float fps_mouse_offsetX { 0.f };
	float fps_mouse_offsetY { 0.f };

	float fps_angle_horizontal { 90.f };
	float fps_angle_vertical { 0.f};

	float fps_mouse_sensitivity { 0.1f };

void fpsCamera() {
	myEngine.mvMatrixStack.loadIdentity();
		Matrix4D viewMatrix = Matrix4D::lookAt(fps_camera_pos, fps_camera_pos + fps_camera_movement, fps_up_vector);
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
		fpsCamera();
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
				fps_camera_pos += fps_camera_movement * fps_camera_movement_speed;
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
				fps_camera_pos -= fps_camera_movement * fps_camera_movement_speed;
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
				Vector3D produitVectoriel = Vector3D (
					fps_camera_movement.y * fps_up_vector.z - fps_camera_movement.z * fps_up_vector.y,
					fps_camera_movement.z * fps_up_vector.x - fps_camera_movement.x * fps_up_vector.z,
					fps_camera_movement.x * fps_up_vector.y - fps_camera_movement.y * fps_up_vector.x
				);

				fps_camera_pos -= produitVectoriel * fps_camera_movement_speed;
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
				Vector3D produitVectoriel = Vector3D (
					fps_camera_movement.y * fps_up_vector.z - fps_camera_movement.z * fps_up_vector.y,
					fps_camera_movement.z * fps_up_vector.x - fps_camera_movement.x * fps_up_vector.z,
					fps_camera_movement.x * fps_up_vector.y - fps_camera_movement.y * fps_up_vector.x
				);

				fps_camera_pos += produitVectoriel * fps_camera_movement_speed;
			}

			if(selectedCamera == 2) {
				roofCameraX++;
			}
			break;

		// [FPS] Monter
		case GLFW_KEY_E:
			if(selectedCamera == 1) {
				fps_camera_pos.z += 1 * fps_camera_movement_speed;
			}
			break;

		// [FPS] Descendre
		case GLFW_KEY_Q:
			if(selectedCamera == 1) {
				fps_camera_pos.z -= 1 * fps_camera_movement_speed;
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

void cameraAim(double x, double y) {
	if(firstMouseMovement) {
		fps_mouse_lastX = x;
		fps_mouse_lastY = y;
		firstMouseMovement = false;
	}

	/* On calcult l'écart entre l'actuelle et l'ancienne position */
	fps_mouse_offsetX = fps_mouse_lastX - x;
	fps_mouse_offsetY = fps_mouse_lastY - y;

	/* On attribue la nouvelle position au variable des anciennes*/
	fps_mouse_lastX = x;
	fps_mouse_lastY = y;

	/* On réduit le mouvement pour pas qu'il soit trop important */
	fps_mouse_offsetX *= fps_mouse_sensitivity;
	fps_mouse_offsetY *= fps_mouse_sensitivity;

	/* On met à jour les angles de vues */
	fps_angle_horizontal += fps_mouse_offsetX;
	fps_angle_vertical += fps_mouse_offsetY;

	/* On bloque à 90° en haut et en bas */
	if(fps_angle_vertical > 89.f) {
		fps_angle_vertical = 89.f;
	} else if( fps_angle_vertical < -89.f) {
		fps_angle_vertical = -89.f;
	}

	Vector3D viewed_point = Vector3D(
		cos(M_PI * fps_angle_horizontal / 180) * cos(M_PI * fps_angle_vertical / 180),
		sin(M_PI * fps_angle_horizontal / 180) * cos(M_PI * fps_angle_vertical / 180),
		sin(M_PI * fps_angle_vertical / 180)
	);

	fps_camera_movement = viewed_point;
	fps_camera_movement.normalize();
}
