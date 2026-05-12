#include "train.hpp"

using namespace glbasimac;
using namespace STP3D;


IndexedMesh* sphere;
StandardMesh* body;
void initTrain()
{
    body = basicCone(15.0f, 2.0f, 2.50f, 50);
	body->createVAO();


}
void drawTrain()
{
    myEngine.setFlatColor(0.92f, 0.81f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.0f,0.f,3.f});
	myEngine.updateMvMatrix();
	body->draw();
	myEngine.mvMatrixStack.popMatrix();

}
