#pragma once

#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_set_of_points.hpp"
#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/basic_mesh.hpp"

using namespace glbasimac;

/* Paramètres de la caméra */
static const float Z_NEAR { 0.1f };
static const float Z_FAR { 500.f };

    /* Angle entre l'axe des x et la caméra */
    extern float angle_theta;

    /* Angle entre l'axe des Z et la caméra */
    extern float angle_phy;

    /* Distance entre le point d'origine de la scène et la caméra */
    extern float dist_zoom;

/* Moteur OpenGL */
extern GLBI_Engine myEngine;

/* Toggle de la grille */
extern bool showTerrainGrid;

void initScene();

void drawScene();

