#pragma once

#include "railsParams.hpp"
#include "../engine/engine.hpp"

#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/basic_mesh.hpp"

using namespace glbasimac;

#include "../texture/texture.hpp"

extern RailsParams railParams;

void initCurvedRails();

void initStraightRails();

void initBalast();

void drawStraightRails();

void drawCurvedRails();

