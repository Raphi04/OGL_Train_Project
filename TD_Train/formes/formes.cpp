#include "formes.hpp"
#include "../draw_scene.hpp"

// pour fermer le cylindre
StandardMesh* createCylinder(float r1, float r2, float h){
    return basicCone(h, r1, r2, 64);
}