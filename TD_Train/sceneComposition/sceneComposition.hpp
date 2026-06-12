#pragma once

#include <array>

#include "./sceneCompositionType.hpp"

extern SceneComposition sceneComposition;

/* Vérifie que la case est vide */
bool checkIfEmpty(int const& x, int const& y);

/* Récupère les informations des rails */
bool checkIfCurved(std::array<int, 2> precedentRail, std::array<int, 2> nextRail);
float getCurvedDirection(std::array<int, 2> precedentRail, std::array<int, 2> nextRail, std::array<int, 2> currentRail);
float getStraightDirection(std::array<int, 2> precedentRail, std::array<int, 2> currentRail, std::array<int, 2> nextRail);
void getRails(std::vector<std::array<int, 2>> const& path);

void getTrain(std::array<int, 2> trainPos);
void getGare(std::array<int, 3> gare);
void getTrees();

void getCows(std::vector<std::array<int, 3>> const& cows);
