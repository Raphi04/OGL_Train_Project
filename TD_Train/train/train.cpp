#include "train.hpp"

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
 	std::vector<float> normals_disque;
 	std::vector<float> uvs_disque;
	//remplir tab ac points nécéessaire
 	for (int i=0; i<=50; i++){
		float angle_bis= 2*M_PI*i /50;
		pts_disque.push_back(cos(angle_bis)); //on garde rayon 1 on fera homotéthie pr rayon de 6
		pts_disque.push_back(sin(angle_bis));
		pts_disque.push_back(0.0f);

		normals_disque.push_back(0.f); //on garde rayon 1 on fera homotéthie pr rayon de 6
		normals_disque.push_back(0.f);
		normals_disque.push_back(1.f);

		uvs_disque.push_back(0.5 + 0.5 * cos(angle_bis)); //on garde rayon 1 on fera homotéthie pr rayon de 6
		uvs_disque.push_back(0.5 + 0.5 * sin(angle_bis));
 }
	disque.initShape(pts_disque, normals_disque, uvs_disque);
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

if(lightToggle) {
	myEngine.setLightPosition({-5.f, 1.f, 5.f, 0.f}, 1);
	myEngine.setLightPosition({-5.f, -1.f, 5.f, 0.f}, 2);
}
	
myEngine.mvMatrixStack.pushMatrix();
myEngine.mvMatrixStack.addTranslation({0.f, 5.f, railParams.balastRayons * 2 + railParams.rail_size});
	myEngine.mvMatrixStack.addRotation(M_PI, {0.f, 0.f, 1.f});
	myEngine.mvMatrixStack.addHomothety({0.7f, 0.7f, 0.7f});
	myEngine.updateMvMatrix();

	myEngine.setFlatColor(0.118, 0.118, 0.118);
	//BASE DU TRAIN

		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.0f,0.f,6.f});
			myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
			myEngine.mvMatrixStack.addHomothety({1.f,0.8f,1.f});
			myEngine.updateMvMatrix();
			body->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//CYLINDRE AVANT 
		myEngine.setFlatColor(0.431, 0.404, 0.38);
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
			myEngine.mvMatrixStack.addRotation(-M_PI-M_PI/16,{1,0,0});
			myEngine.mvMatrixStack.addHomothety({4.5f,1.5f,4.5f});
			myEngine.updateMvMatrix();
			cylindre->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//DISQUE PR FERMER CYL
		myEngine.activateTexturing(true);
		logo_trainTexture.attachTexture();
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.f,0.f,6.f});
			myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
			myEngine.mvMatrixStack.addHomothety({4.5f,4.5f,4.5f});
			myEngine.updateMvMatrix();
			disque.drawShape();
			logo_trainTexture.detachTexture();
		myEngine.activateTexturing(false);
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	//CYLINDRE VIOLET DERRIERE
	myEngine.setFlatColor(0.239, 0.149, 0.094);
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.f,8.f,4.2f});
			myEngine.mvMatrixStack.addRotation(+M_PI-M_PI/16,{1,0,0});
			myEngine.mvMatrixStack.addHomothety({3.f,2.f,3.f});
			myEngine.updateMvMatrix();
			cylindre->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	//PETIT TRUC SUR LE DEVANT AU DESSUS HORIZONTALE
		myEngine.setFlatColor(0.651, 0.529, 0.306);
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

	myEngine.setFlatColor(0.255, 0.365, 0.255);
		myEngine.activateTexturing(true);
		pipeLogoTexture.attachTexture();
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f,0.f,13.f});
		myEngine.mvMatrixStack.addRotation(-M_PI/2,{1,0,0});
		myEngine.mvMatrixStack.addHomothety({0.5f,0.5f,0.5f});


		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.0f,0.f,6.f});
			myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
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
	pipeLogoTexture.detachTexture();
	myEngine.activateTexturing(false);
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	// //2EME ELEMENT VERTICAL AU DESSUS DU TRAIN 

	myEngine.setFlatColor(0.412, 0.369, 0.353);
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
	myEngine.activateTexturing(true);
	goldTexture.attachTexture();
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
		goldTexture.detachTexture();
		myEngine.activateTexturing(false);
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		// 	//petit cone 1
		myEngine.setFlatColor(0.42, 0.38, 0.357);
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

	myEngine.setFlatColor(0.42, 0.38, 0.357);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({-1.f,-1.f,0.f});
		myEngine.mvMatrixStack.addHomothety({1.5f,2.f,2.f});
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

	//myEngine.setFlatColor(1.f, 0.f, 0.20f);
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({-1.f,3,0});
		myEngine.mvMatrixStack.addHomothety({1.5f,2.f,2.f});

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
	myEngine.mvMatrixStack.addTranslation({-7.f,0.f,0.f});

		myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f,-1.f,0.f});

		
			myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addHomothety({1.5f,2.f,2.f});
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


		//ROUES DROITE 

		//myEngine.setFlatColor(1.f, 0.f, 0.20f);
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0,3,0});
			myEngine.mvMatrixStack.addHomothety({1.5f,2.f,2.f});

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
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.f,-4.f,0.f});
	myEngine.mvMatrixStack.addHomothety({1.f,1.2f,1.2f});

		//PAVE DROIT VERTIALE
		myEngine.setFlatColor(0.149, 0.224, 0.251);
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.f,10.5f,5.5f});
			myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
			myEngine.mvMatrixStack.addHomothety({4.5f,0.5f,8.f});
			myEngine.updateMvMatrix();
			cube->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//FENETRES 1
		//myEngine.setFlatColor(1, 0.224, 0.251);
		myEngine.activateTexturing(true);
		glassTexture.attachTexture();
			myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({-1.f,10.5f,7.0f});
				myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
				myEngine.mvMatrixStack.addHomothety({0.5f,0.5f,0.5f});
				myEngine.updateMvMatrix();
				disque.drawShape();
			myEngine.mvMatrixStack.popMatrix();
			myEngine.updateMvMatrix();
		//FENETRE 2
			myEngine.setFlatColor(1, 0.224, 0.251);
			myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({1.f,10.5f,7.0f});
				myEngine.mvMatrixStack.addRotation(M_PI/2-M_PI/16,{1,0,0});
				myEngine.mvMatrixStack.addHomothety({0.5f,0.5f,0.5f});
				myEngine.updateMvMatrix();
				disque.drawShape();
				glassTexture.detachTexture();
				myEngine.activateTexturing(false);
			myEngine.mvMatrixStack.popMatrix();
			myEngine.updateMvMatrix();
			
		//SOL DU WAGON
		myEngine.setFlatColor(0.149, 0.224, 0.251);
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.f,11.f,2.f});
			myEngine.mvMatrixStack.addRotation(-M_PI,{1,0,0});
			myEngine.mvMatrixStack.addHomothety({4.5f,3.f,0.5f});
			myEngine.updateMvMatrix();
			cube->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//BARRIERE GAUCHE
		myEngine.setFlatColor(0.149, 0.224, 0.251);
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({-2.f,11.5f,5.5f});
			myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
			myEngine.mvMatrixStack.addRotation(M_PI/16,{0,1,0});
			myEngine.mvMatrixStack.addHomothety({2.f,0.5f,7.2f});
			myEngine.updateMvMatrix();
			cube->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//BARRIERE DROITE
		myEngine.setFlatColor(0.149, 0.224, 0.251);
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({2.f,11.5f,5.5f});
			myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
			myEngine.mvMatrixStack.addRotation(M_PI/16,{0,1,0});
			myEngine.mvMatrixStack.addHomothety({2.f,0.5f,7.2f});
			myEngine.updateMvMatrix();
			cube->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//TOIT
		//myEngine.setFlatColor(0.255, 0.157, 0.157f);
		myEngine.activateTexturing(true);
		wood2Texture.attachTexture();

		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.f,11.8f,8.7f});
			myEngine.mvMatrixStack.addRotation(-M_PI/16,{1,0,0});
			myEngine.mvMatrixStack.addHomothety({4.6f,2.9f,1.3f}); //(x,z,y)
			myEngine.updateMvMatrix();
			cube->draw();
			wood2Texture.detachTexture();
			myEngine.activateTexturing(false);
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	//BARRE ROUES A DROITE
	myEngine.activateTexturing(true);
	goldTexture.attachTexture();
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({3.5f,7.f,3.5f});
			myEngine.mvMatrixStack.addHomothety({0.3f,7.f,0.7f}); //(x,z,y)
			myEngine.updateMvMatrix();
			cube->draw();
	myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//BARRE ROUES A GAUCHE
	myEngine.setFlatColor(0.925, 0.745, 0.286);
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({-4.f,7.f,3.5f});
			myEngine.mvMatrixStack.addHomothety({0.3f,7.f,0.7f}); //(x,z,y)
			myEngine.updateMvMatrix();
			cube->draw();
			goldTexture.detachTexture();
			myEngine.activateTexturing(false);


	myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	//REMABRDE VERTICALE DROITE
	myEngine.setFlatColor(0.149, 0.224, 0.251);
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({2.f,11.f,3.5f});
			myEngine.mvMatrixStack.addHomothety({0.5f,3.f,2.5f}); //(x,z,y)
			myEngine.updateMvMatrix();
			cube->draw();
	myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	//GAUCHE
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({-2.f,11.f,3.5f});
			myEngine.mvMatrixStack.addHomothety({0.5f,3.f,2.5f}); //(x,z,y)
			myEngine.updateMvMatrix();
			cube->draw();
	myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();
}
