#include "train.hpp"
using namespace glbasimac;
using namespace STP3D;


IndexedMesh* sphere;
StandardMesh* body;
GLBI_Convex_2D_Shape disque{3};
IndexedMesh* cylindre;
IndexedMesh* cube;



void drawCurvedCylinder2() {
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({-5.f, -5.f, 0.f});
		myEngine.updateMvMatrix();

	

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}

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
	cylindre = basicCylinder(1.0f, 1.0f, 32, 1);
	cylindre-> createVAO();

	//CUBE
	cube=basicCube(1);
	cube-> createVAO();




}
void drawTrain()
{
myEngine.setFlatColor(0.92f, 0.81f, 0.20f);
//BASE DU TRAIN

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0f,0.f,6.f});
		myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({1.f,1.f,1.f});
		myEngine.updateMvMatrix();
		body->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	//CYLINDRE AVANT 
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
		myEngine.mvMatrixStack.addRotation(-M_PI-M_PI/16,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({4.5f,2.f,4.5f});
		myEngine.updateMvMatrix();
		cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	//DISQUE PR FERMER CYL
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
		myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
		myEngine.updateMvMatrix();
		disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

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
		myEngine.updateMvMatrix();

		//Ccylidnre avant 
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
			myEngine.mvMatrixStack.addRotation(-M_PI-M_PI/16,{1,0,0});
			myEngine.mvMatrixStack.addHomothety({4.5f,2.f,4.5f});
			myEngine.updateMvMatrix();
			cylindre->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//Disque pr fermer cylindre
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
			myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
			myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
			myEngine.updateMvMatrix();
			disque.drawShape();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

// //PETIT TRUC SUR LE DEVANT AU DESSUS VERTICALE

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
	myEngine.updateMvMatrix();

	//CYLINDRE AVANT 
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
		myEngine.mvMatrixStack.addRotation(-M_PI-M_PI/16,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({4.5f,2.f,4.5f});
		myEngine.updateMvMatrix();
		cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	//DISQUE PR FERMER CYL
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
		myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
		myEngine.updateMvMatrix();
		disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();

// //2EME ELEMENT VERTICAL AU DESSUS DU TRAIN 

myEngine.setFlatColor(1.f, 0.f, 0.20f);
myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,7.f,8.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({0.2f,0.2f,0.2f});


	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0f,0.f,6.f});
		myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({1.f,1.f,1.f});
		myEngine.updateMvMatrix();
		body->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	//cylindre avant
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
		myEngine.mvMatrixStack.addRotation(-M_PI-M_PI/16,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({4.5f,2.f,4.5f});
		myEngine.updateMvMatrix();
		cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	//disque pr fermer cylindre
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
		myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
		myEngine.updateMvMatrix();
		disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();

// //anneau
myEngine.setFlatColor(0.6f, 0.6f, 0.8f);
myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,6.f,9.f});
	myEngine.mvMatrixStack.addRotation(-M_PI/2,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({0.8f,0.8f,0.8f});
		

		//cylindre
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addRotation(-M_PI-M_PI/16,{1,0,0});
		myEngine.updateMvMatrix();
		cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

		//disque pr fermer cylindre
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
		myEngine.updateMvMatrix();
		disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	// 	//petit cone 1
	myEngine.setFlatColor(0.6f, 0.6f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addRotation(-M_PI/16+M_PI,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({0.2f,0.1f,0.2f});
		myEngine.updateMvMatrix();
		body->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
	//petit cone 2 inversé
	myEngine.setFlatColor(0.6f, 0.6f, 0.6f);
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0f,-1.8f,0.2f});
		myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({0.1f,0.1f,0.1f});
		myEngine.updateMvMatrix();
		body->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DROIT
// ROUES GAUCHE

myEngine.setFlatColor(1.f, 0.f, 0.20f);
myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addHomothety({1.f,1.5f,1.5f});
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({3.f,3.f,1.f});
		myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
		myEngine.updateMvMatrix();
		cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();


	//DISQUE PR FERMER CYL
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({3.f,3.f,1.f});
		myEngine.mvMatrixStack.addRotation(M_PI/2,{0,1,0});
		myEngine.updateMvMatrix();
		disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	//2 ème disque pr fermer
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({2.f,3.f,1.f});
		myEngine.mvMatrixStack.addRotation(M_PI/2,{0,1,0});
		myEngine.updateMvMatrix();
		disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();


//ROUES DROITE 

myEngine.setFlatColor(1.f, 0.f, 0.20f);
myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0,3,0});
	myEngine.setFlatColor(1.f, 0.f, 0.20f);
	myEngine.mvMatrixStack.addHomothety({1.f,1.5f,1.5f});

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({3.f,3.f,1.f});
		myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
		myEngine.updateMvMatrix();
		cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();


	//DISQUE PR FERMER CYL
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({3.f,3.f,1.f});
		myEngine.mvMatrixStack.addRotation(M_PI/2,{0,1,0});
		myEngine.updateMvMatrix();
		disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	//2 ème disque pr fermer
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({2.f,3.f,1.f});
		myEngine.mvMatrixStack.addRotation(M_PI/2,{0,1,0});
		myEngine.updateMvMatrix();
		disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//GAUCHE
myEngine.mvMatrixStack.pushMatrix();
myEngine.mvMatrixStack.addTranslation({-5.f,0.f,0.f});

	myEngine.setFlatColor(1.f, 0.f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({1.f,1.5f,1.5f});
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({3.f,3.f,1.f});
			myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
			myEngine.updateMvMatrix();
			cylindre->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();


		//DISQUE PR FERMER CYL
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({3.f,3.f,1.f});
			myEngine.mvMatrixStack.addRotation(M_PI/2,{0,1,0});
			myEngine.updateMvMatrix();
			disque.drawShape();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//2 ème disque pr fermer
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({2.f,3.f,1.f});
			myEngine.mvMatrixStack.addRotation(M_PI/2,{0,1,0});
			myEngine.updateMvMatrix();
			disque.drawShape();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();


	//ROUES DROITE 

	myEngine.setFlatColor(1.f, 0.f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0,3,0});
		myEngine.setFlatColor(1.f, 0.f, 0.20f);
		myEngine.mvMatrixStack.addHomothety({1.f,1.5f,1.5f});

		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({3.f,3.f,1.f});
			myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
			myEngine.updateMvMatrix();
			cylindre->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();


		//DISQUE PR FERMER CYL
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({3.f,3.f,1.f});
			myEngine.mvMatrixStack.addRotation(M_PI/2,{0,1,0});
			myEngine.updateMvMatrix();
			disque.drawShape();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//2 ème disque pr fermer
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({2.f,3.f,1.f});
			myEngine.mvMatrixStack.addRotation(M_PI/2,{0,1,0});
			myEngine.updateMvMatrix();
			disque.drawShape();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();

 //REGLER LES TAILLES

//PAVE DROIT 
myEngine.setFlatColor(1.f, 1.f, 0.20f);
myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,10.5f,5.5f});
	myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,0.5f,8.f});
	myEngine.updateMvMatrix();
	cube->draw();
myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();
	
//SOL DU WAGON
myEngine.setFlatColor(1.f, 0.9f, 0.20f);
myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,11.f,4.f});
	myEngine.mvMatrixStack.addRotation(-M_PI,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,3.f,0.5f});
	myEngine.updateMvMatrix();
	cube->draw();
myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();

//BARRIERE GAUCHE
myEngine.setFlatColor(1.f, 0.67f, 0.20f);
myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({-3.5f,11.5f,6.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
	myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({2.f,0.5f,4.f});
	myEngine.updateMvMatrix();
	cube->draw();
myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();

//BARRIERE DROITE
myEngine.setFlatColor(1.f, 0.67f, 0.20f);
myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({3.5f,11.5f,6.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
	myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({2.f,0.5f,4.f});
	myEngine.updateMvMatrix();
	cube->draw();
myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();
	

}
