#include "sceneComposition.hpp"
#include <iostream>

SceneComposition sceneComposition;

bool checkIfEmpty(int const& x, int const& y) {
    for(SceneElement sceneElement : sceneComposition.sceneElements) {
        if(sceneElement.x == x && sceneElement.y == y) {
            return false;
        }
    }

    return true;
}

bool checkIfCurved(std::array<int, 2> precedentRail, std::array<int, 2> nextRail) {
    if(precedentRail[0] != nextRail[0] && precedentRail[1] != nextRail[1]) {
        /* On vérifie que le rail d'avant est bien à côter de l'actuel et pas plus loin*/
        if(abs(precedentRail[0] - nextRail[0]) > 1 || abs(precedentRail[1] - nextRail[1]) > 1) {
            return  false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

float getCurvedDirection(std::array<int, 2> precedentRail, std::array<int, 2> nextRail, std::array<int, 2> currentRail) {
    /*
    Un Rail corubé est modélisé de manière à être de base
    de la Gauche vers le Bas / du Bas vers la Gauche
    */

    int posDepartX { precedentRail[0] - currentRail[0] };
    int posDepartY { precedentRail[1] - currentRail[1] };
    
    int posArriveX { nextRail[0] - currentRail[0] };
    int posArriveY { nextRail[1] - currentRail[1] };

    /* Rotation de 0° | Gauche vers Bas ou Bas vers Gauche */
    if((posDepartX == -1 && posArriveY == -1) || (posDepartY == -1 && posArriveX == -1)) {
        return 0.f;
    }

    /* Rotation de 90° | Droite vers Bas ou Bas vers Droite */
    if((posDepartX == 1 && posArriveY == -1) || (posDepartY == -1 && posArriveX == 1)) {
        return 90.f;
    }

    /* Rotation de 180° | Droite vers Haut ou Haut vers Droite */
    if((posDepartX == 1 && posArriveY == 1) || (posDepartY == 1 && posArriveX == 1)) {
        return 180.f;
    }

    /* Rotation de 270° | Gauche vers Haut ou Haut vers Gauche */
    if((posDepartX == -1 && posArriveY == 1) || (posDepartY == 1 && posArriveX == -1)) {
        return 270.f;
    }

    /* Par défaut sur 0° */
    return 0.f;
}

float getStraightDirection(std::array<int, 2> precedentRail, std::array<int, 2> currentRail, std::array<int, 2> nextRail) {

    if(abs(precedentRail[0] - currentRail[0]) <= 1 && abs(precedentRail[1] - currentRail[1]) <= 1) {
        int posDepartX { precedentRail[0] - currentRail[0] };
        int posDepartY { precedentRail[1] - currentRail[1] };

        /* Rotation de 0° */
        if(posDepartY == 1 || posDepartY == -1) {
            return 0.f;
        }

        /* Rotation de 90° */
        if(posDepartX == 1 || posDepartX == -1) {
            return 90.f;
        }

    } else {
        int posArriveX { nextRail[0] - currentRail[0] };
        int posArriveY { nextRail[1] - currentRail[1] };

        /* Rotation de 90° */
        if(posArriveX == 1 || posArriveX == -1) {
            return 90.f;
        }

        /* Rotation de 0° */
        if(posArriveY == 1 || posArriveY == -1) {
            return 0.f;
        }
    }

    /* Par défaut sur 0° */
    return 0.f;
}

void getRails(std::vector<std::array<int, 2>> const& path ) {
    std::array<int, 2> precedentRail {};
    std::array<int, 2> nextRail {};
    std::array<int, 2> currentRail {};
    SceneElement addedRail {};

    for(std::size_t i { 0 }; i < path.size(); i++) {
        currentRail = path[i];
        
        if(!checkIfEmpty(currentRail[0], currentRail[1])) {
            continue;
        }

        if(i == 0) {
            precedentRail = path[path.size() - 1];
            nextRail = path[i + 1];

        } else if( i == path.size() - 1) {
            precedentRail = path[i - 1];
            nextRail = path[0];
            
        } else {
            precedentRail = path[i - 1];
            nextRail = path[i + 1];
        }

        if(checkIfCurved(precedentRail, nextRail)) {
            addedRail.x = path[i][0];
            addedRail.y = path[i][1];
            addedRail.elementType = Element::CurvedRail;
            addedRail.rotation = getCurvedDirection(precedentRail, nextRail, currentRail);
;
        } else {
            addedRail.x = path[i][0];
            addedRail.y = path[i][1];
            addedRail.elementType = Element::StraightRail;
            addedRail.rotation = getStraightDirection(precedentRail, currentRail, nextRail);
        }

        /* Ajout de l'élément à la composition de la scène */
        sceneComposition.sceneElements.push_back(addedRail);
    }
}

void getTrain(std::array<int, 2> trainPos){

    for(SceneElement sceneElement : sceneComposition.sceneElements) {
        if(sceneElement.x == trainPos[0] && sceneElement.y == trainPos[1]) {
            if(sceneElement.elementType == Element::StraightRail) {
                SceneElement train {};
                train.x = trainPos[0];
                train.y = trainPos[1];
                train.elementType = Element::Train;
                train.rotation = sceneElement.rotation;

                sceneComposition.sceneElements.push_back(train);
            }
        }
    }
}

void getGare(std::array<int, 3> garePos) {
    if(checkIfEmpty(garePos[0], garePos[1])) {
        SceneElement gare {};
        gare.x = garePos[0];
        gare.y = garePos[1];
        gare.elementType = Element::Gare;
        gare.rotation = garePos[2];

        sceneComposition.sceneElements.push_back(gare);
    }
}

void getTrees(){}

void getCows(std::vector<std::array<int, 3>> const& cows){

    for(std::array<int, 3> cowPos : cows) {
        if(checkIfEmpty(cowPos[0], cowPos[1])) {
            SceneElement cow {};
            cow.x = cowPos[0];
            cow.y = cowPos[1];
            cow.elementType = Element::Cow;
            cow.rotation = cowPos[2];
    
            sceneComposition.sceneElements.push_back(cow);
        }
    }
}