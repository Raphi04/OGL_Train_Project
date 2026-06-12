#pragma once 

#include <vector>

enum Element {
    StraightRail,
    CurvedRail,
    Tree,
    Cow,
    Train,
    Gare
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