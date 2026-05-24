#include "train.hpp"
using namespace glbasimac;
using namespace STP3D;


IndexedMesh* sphere;
StandardMesh* body;
GLBI_Convex_2D_Shape disque{3};
IndexedMesh* cylindre;
IndexedMesh* cube;



void drawCurvedCylinder() {
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

//2EME ELEMENT VERTICAL AU DESSUS DU TRAIN 
	
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

	//cylindre avant
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(-M_PI-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,2.f,4.5f});
	myEngine.updateMvMatrix();
	cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();

	//disque pr fermer cylindre
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
	myEngine.updateMvMatrix();
	disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();

//anneau
myEngine.setFlatColor(0.6f, 0.6f, 0.8f);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,8.f,8.5f});
	myEngine.mvMatrixStack.addRotation(-M_PI,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({0.7f,0.7f,0.7f});

	//cylindre
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(-M_PI-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,2.f,4.5f});
	myEngine.updateMvMatrix();
	cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();

	//disque pr fermer cylindre
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
	myEngine.updateMvMatrix();
	disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	//petit cone 1

	myEngine.setFlatColor(0.6f, 0.6f, 0.20f);


	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.0f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(-M_PI/16+M_PI,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({0.5f,0.5f,1.f});
	myEngine.updateMvMatrix();
	body->draw();
	myEngine.mvMatrixStack.popMatrix();

	//petit cone 2 inversé
	myEngine.setFlatColor(0.6f, 0.6f, 0.6f);

	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.0f,-7.f,8.f});
	myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({1.f,1.f,1.f});
	myEngine.updateMvMatrix();
	body->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.popMatrix();



// ROUES GAUCHE COTE DROIT (quand face au train)

	myEngine.setFlatColor(1.f, 0.f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({15.f,-25.f,-6.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
	myEngine.mvMatrixStack.addHomothety({2.f,2.f,2.f});

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

	//2 ème disque pr fermer
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,-2.f,6.5f});
	myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
	myEngine.updateMvMatrix();
	disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.popMatrix();


	// ROUES DROITE COTE DROIT (quand face au train)

	myEngine.setFlatColor(1.f, 0.f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({15.f,-25.f,-25.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
	myEngine.mvMatrixStack.addHomothety({2.f,2.f,2.f});

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

	//2 ème disque pr fermer
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,-2.f,6.5f});
	myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
	myEngine.updateMvMatrix();
	disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.popMatrix();

	
//ROUES COTE GAUCHE (face au train)


// ROUES GAUCHE COTE DROIT (quand face au train)

	myEngine.setFlatColor(1.f, 0.f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({-17.f,-25.f,-6.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
	myEngine.mvMatrixStack.addHomothety({2.f,2.f,2.f});

	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(-M_PI,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,2.f,4.5f});
	myEngine.updateMvMatrix();
	cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();

	//DISQUE PR FERMER CYL
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
	myEngine.updateMvMatrix();
	disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	//2 ème disque pr fermer
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,-2.f,6.5f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
	myEngine.updateMvMatrix();
	disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.popMatrix();


	// ROUES DROITE COTE DROIT (quand face au train)

	myEngine.setFlatColor(1.f, 0.f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({-17.f,-25.f,-25.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
	myEngine.mvMatrixStack.addHomothety({2.f,2.f,2.f});

	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(-M_PI,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,2.f,4.5f});
	myEngine.updateMvMatrix();
	cylindre->draw();
	myEngine.mvMatrixStack.popMatrix();

	//DISQUE PR FERMER CYL
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
	myEngine.updateMvMatrix();
	disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	//2 ème disque pr fermer
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,-2.f,6.5f});
	myEngine.mvMatrixStack.addRotation(M_PI/2,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
	myEngine.updateMvMatrix();
	disque.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.popMatrix();

	//PAVE DROIT 
	myEngine.setFlatColor(1.f, 1.f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,-8.f,-15.f});
	myEngine.mvMatrixStack.addRotation(-M_PI/2-M_PI/16,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({30.f,10.f,50.f});
	myEngine.updateMvMatrix();
	cube->draw();
	myEngine.mvMatrixStack.popMatrix();
	
	//SOL DU WAGON
	myEngine.setFlatColor(1.f, 1.f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,-25.f,-17.f});
	myEngine.mvMatrixStack.addRotation(-M_PI,{1,0,0});
	myEngine.mvMatrixStack.addHomothety({30.f,5.f,30.f});
	myEngine.updateMvMatrix();
	cube->draw();
	myEngine.mvMatrixStack.popMatrix();


	drawCurvedCylinder();

	

}
