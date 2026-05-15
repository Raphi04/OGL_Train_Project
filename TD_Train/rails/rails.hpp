#pragma once

#include "railsParams.hpp"
#include "../engine/engine.hpp"

#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/basic_mesh.hpp"

using namespace glbasimac;

extern StraightRailParams straightRailParams;
extern CurvedRailParams curvedRailsParams;

void initStraightRails();

void initCurvedRails();

void initRails();

void initBalast();

void drawStraightRails();

void drawCurvedRails();

