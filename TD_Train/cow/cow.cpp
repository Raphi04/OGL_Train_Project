#include "cow.hpp"

IndexedMesh* cube4;

void initCow() {
    cube4 = basicCube();
    cube4->createVAO();
}

void drawCow() {
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addHomothety({2.f, 1.f, 1.f});
        myEngine.updateMvMatrix();

        cube4->draw();

    myEngine.mvMatrixStack.popMatrix();
    myEngine.updateMvMatrix();
}