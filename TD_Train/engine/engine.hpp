#pragma once

#include <fstream>

#include "../draw_scene.hpp"
#include "glbasimac/glbi_engine.hpp"
#include "nlohmann/json.hpp"
#include "../sceneComposition/sceneComposition.hpp"

using namespace glbasimac;

/* Moteur OpenGL */
extern GLBI_Engine myEngine;

struct JSON {
    int grid_width;
    int grid_height;
    int origin;
    std::vector<std::array<int, 2>> path;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JSON, grid_width, grid_height, origin, path)
};

void initJSONConfig(std::string const& json);

void drawRepere();

void initRepere();