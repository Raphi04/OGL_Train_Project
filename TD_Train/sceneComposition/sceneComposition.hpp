#pragma once

#include <vector>

enum Element{
    StraightRail,
    CurvedRail,
    Tree,
    Cow
};

struct sceneElement {
    int x;
    int y;

    Element elementType;
};

struct SceneComposition
{
    float terrainWidth;
    float terrainHeight;

    std::vector<sceneElement> sceneElements;
};

extern SceneComposition sceneComposition;

void getRails();

void getTrees();

void getCows();

void getSceneComposition();

