#include "formes.hpp"
#include "../draw_scene.hpp"

//INUTILE DCP je ne l'utilise pas pr le moment
StandardMesh* createCylinder(float r1, float r2, float h){
    return basicCone(h, r1, r2, 64);
}