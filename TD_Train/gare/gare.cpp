#include "gare.hpp"
using namespace glbasimac;
using namespace STP3D;


IndexedMesh* sphere2;
StandardMesh* body2;
GLBI_Convex_2D_Shape disque2{3};
IndexedMesh* cylindre2;
IndexedMesh* cube2;

 void initGare(){
    body2 = basicCone(10.0f, 4.0f, 2.50f, 50);
	body2->createVAO();
	//DISQUE
 	std::vector<float> pts_disque;
 //remplir tab ac points nécéessaire
 	for (int i=0; i<=50; i++){
		float angle_bis= 2*M_PI*i /50;
		pts_disque.push_back(cos(angle_bis)); //on garde rayon 1 on fera homotéthie pr rayon de 6
		pts_disque.push_back(sin(angle_bis));
		pts_disque.push_back(0.0f);
 }
	disque2.initShape(pts_disque);
 	disque2.changeNature(GL_TRIANGLE_FAN);

	//CYLINDRE 
	cylindre2 = basicCylinder(1.0f, 1.0f, 32, 1);
	cylindre2-> createVAO();

	//CUBE
	cube2=basicCube(1);
	cube2-> createVAO();

    

 }

 void drawGare(){
	myEngine.setFlatColor(0.118, 0.118, 0.118);
//BASE GARE

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0f,0.f,6.f});
		myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({1.f,0.8f,1.f});
		myEngine.updateMvMatrix();
		body2->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
 }