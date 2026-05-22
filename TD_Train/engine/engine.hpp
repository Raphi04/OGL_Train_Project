#pragma once

#include <fstream>

#include "glbasimac/glbi_set_of_points.hpp"
#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/basic_mesh.hpp"
#include "glbasimac/glbi_engine.hpp"

using namespace glbasimac;

#include "./jsonParams.hpp"

#include "../sceneComposition/sceneComposition.hpp"
#include "../rails/rails.hpp"

/* Moteur OpenGL */
extern GLBI_Engine myEngine;

void initJSONConfig(std::string const& json);

void drawRepere();

void initRepere();