#pragma once

#include <vector>
#include <array>

enum Element {
    StraightRail,
    CurvedRail,
    Tree,
    Cow
};

struct SceneElement {
    int x;
    int y;

    Element elementType;
    float rotation;
};

struct SceneComposition
{
    float terrainWidth;
    float terrainHeight;

    std::vector<SceneElement> sceneElements;
};

extern SceneComposition sceneComposition;

/* Vérifie que la case est vide */
bool checkIfEmpty(int const& x, int const& y);

/* Récupère les informations des rails */
bool checkIfCurved(std::array<int, 2> precedentRail, std::array<int, 2> nextRail);
float getCurvedDirection(std::array<int, 2> precedentRail, std::array<int, 2> nextRail, std::array<int, 2> currentRail);
float getStraightDirection(std::array<int, 2> precedentRail, std::array<int, 2> currentRail);
void getRails(std::vector<std::array<int, 2>> const& path);

void getTrees();

void getCows();

void getSceneComposition();

