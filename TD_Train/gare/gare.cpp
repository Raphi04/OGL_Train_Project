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
	myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.0f,0.f,0.5f});
			// myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
			// myEngine.mvMatrixStack.addHomothety({1.f,0.8f,1.f});
		//BASE GARE

		myEngine.mvMatrixStack.pushMatrix();
			//couche 1
			myEngine.mvMatrixStack.addHomothety({10.f,20.f,0.3f});
			myEngine.updateMvMatrix();
			cube2->draw();
		
			//couche 2
			myEngine.setFlatColor(1, 0, 0.118);
			myEngine.mvMatrixStack.addTranslation({0.f,0.f,1.2f});
			myEngine.mvMatrixStack.addHomothety({1.f,1,1.5f});
			myEngine.updateMvMatrix();
			cube2->draw();

		 	//couche 3
			myEngine.setFlatColor(0, 1, 0.118);
			myEngine.mvMatrixStack.addTranslation({0.f,0.f,0.7f});
			myEngine.mvMatrixStack.addHomothety({1.f,1,0.3f});
			myEngine.updateMvMatrix();
			cube2->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//poteaux bois fond

		myEngine.setFlatColor(0.431, 0.404, 0.38);
			for (int i=0; i<=10; i++) {
				myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({-5.f, i*20.f/10.f-10.f, 1.f});
				myEngine.mvMatrixStack.addHomothety({0.5,0.5,3});
				myEngine.updateMvMatrix();
				cube2->draw();
				myEngine.mvMatrixStack.popMatrix();

				//rembarde
				myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({-5.f, i*20.f/10.f-10.f, 2.5f});
				myEngine.mvMatrixStack.addHomothety({1.f,2.f,0.3});
				myEngine.updateMvMatrix();
				cube2->draw();
				myEngine.mvMatrixStack.popMatrix();
			}

		//poteaux bois gauche
		myEngine.setFlatColor(0.431, 0.404, 0.38);
			for (int i=0; i<=3; i++) {
				myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({i*20.f/10.f-5.f,-10.f, 1.f});
				myEngine.mvMatrixStack.addHomothety({0.5,0.5,3});
				myEngine.updateMvMatrix();
				cube2->draw();
				myEngine.mvMatrixStack.popMatrix();

				//rembarde
				myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({i*20.f/10.f-5.f,-10.f, 2.5f});
				myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
				myEngine.mvMatrixStack.addHomothety({1.f,2.f,0.3});
				myEngine.updateMvMatrix();
				cube2->draw();
				myEngine.mvMatrixStack.popMatrix();
			}

		//poteau bois droite
			for (int i=0; i<=3; i++) {
				myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({i*20.f/10.f-5.f,10.f, 1.f});
				myEngine.mvMatrixStack.addHomothety({0.5,0.5,3});
				myEngine.updateMvMatrix();
				cube2->draw();
				myEngine.mvMatrixStack.popMatrix();

				//rembarde
				myEngine.setFlatColor(0.431, 0.404, 0.0);
				myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({i*20.f/10.f-5.f,10.f, 2.5f});
				myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
				myEngine.mvMatrixStack.addHomothety({1.f,2.f,0.3});
				myEngine.updateMvMatrix();
				cube2->draw();
				myEngine.mvMatrixStack.popMatrix();

			}
		
	
	
 } 