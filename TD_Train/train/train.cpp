#include "train.hpp"

using namespace glbasimac;
using namespace STP3D;


IndexedMesh* sphere;
StandardMesh* body;
GLBI_Convex_2D_Shape disque{3};
IndexedMesh* cylindre;

void initTrain()
{
    body = basicCone(10.0f, 4.0f, 2.50f, 50);
	body->createVAO();
	//DISQUE
 	std::vector<float> pts_disque;
 //remplir tab ac points nécéessaire
 	for (int i=0; i<=50; i++){
		float angle_bis= 2*M_PI*i /50;
		pts_disque.push_back(cos(angle_bis)); //on garde rayon 1 on fera homotéthie pr rayon de 6
		pts_disque.push_back(sin(angle_bis));
		pts_disque.push_back(0.0f);
 }
	disque.initShape(pts_disque);
 	disque.changeNature(GL_TRIANGLE_FAN);

	//CYLINDRE 
	cylindre=basicCylinder(1.f,1.f,32.f,1.f);
	cylindre-> createVAO();


}
void drawTrain()
{
    myEngine.setFlatColor(0.92f, 0.81f, 0.20f);

	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.0f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({1.f,1.f,1.f});
	myEngine.updateMvMatrix();
	body->draw();
	myEngine.mvMatrixStack.popMatrix();

	//CYLINDRE AVANT 
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(-M_PI-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,2.f,4.5f});
	myEngine.updateMvMatrix();
	cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();

	//DISQUE PR FERMER CYL
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
	myEngine.updateMvMatrix();
	disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	//PETIT TRUC SUR LE DEVANT AU DESSUS HORIZONTALE
	 myEngine.setFlatColor(0.f, 0.81f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,-1.f,8.f});
	myEngine.mvMatrixStack.addHomothety({0.4f,0.4f,0.4f});


	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.0f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({1.f,1.f,1.f});
	myEngine.updateMvMatrix();
	body->draw();
	myEngine.mvMatrixStack.popMatrix();

	//CYLINDRE AVANT 
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(-M_PI-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,2.f,4.5f});
	myEngine.updateMvMatrix();
	cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();

	//DISQUE PR FERMER CYL
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
	myEngine.updateMvMatrix();
	disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.popMatrix();

	//PETIT TRUC SUR LE DEVANT AU DESSUS VERTICALE

	myEngine.setFlatColor(1.f, 0.f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,13.f});
	myEngine.mvMatrixStack.addRotation(-M_PI/2,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({0.5f,0.5f,0.5f});


	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.0f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({1.f,1.f,1.f});
	myEngine.updateMvMatrix();
	body->draw();
	myEngine.mvMatrixStack.popMatrix();

	//CYLINDRE AVANT 
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(-M_PI-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,2.f,4.5f});
	myEngine.updateMvMatrix();
	cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();

	//DISQUE PR FERMER CYL
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
	myEngine.updateMvMatrix();
	disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.popMatrix();

}
