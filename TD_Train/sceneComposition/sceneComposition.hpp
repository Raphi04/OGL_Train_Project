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
    float terrainWidth { 100 };
    float terrainHeight { 100 };

    std::vector<sceneElement> sceneElements;
};

extern SceneComposition sceneComposition;

void getRails();

void getTrees();

void getCows();

void getSceneComposition();

