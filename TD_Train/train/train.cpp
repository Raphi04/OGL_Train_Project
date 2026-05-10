#include "train.hpp"
#include "../draw_scene.hpp"
#include "../formes/formes.hpp"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "tools/shaders.hpp"
#include <iostream>
using namespace glbasimac;
using namespace STP3D;


IndexedMesh* sphere;
StandardMesh* body;
void initTrain()
{
    body = basicCone(1.0f, 5.0f, 0.0f, 50);
	body->createVAO();


}
void drawTrain()
{
    myEngine.setFlatColor(0.92f, 0.81f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addHomothety({2.0f,2.f,10.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{1,0,0});
	myEngine.updateMvMatrix();
	body->draw();
	myEngine.mvMatrixStack.popMatrix();

}
