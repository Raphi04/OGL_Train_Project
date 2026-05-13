#pragma once

/* Selection de la caméra */
extern int selectedCamera;

/* Paramètres de la caméra orbital */
static const float Z_NEAR { 0.1f };
static const float Z_FAR { 500.f };

void orbitalCamera();

void fpsCamera();

void roofCamera();

void cameraSelector();

void cameraMovement(int const& key, int const& action);

void cameraAim(double x, double y);
