#include "gare.hpp"
using namespace glbasimac;
using namespace STP3D;


IndexedMesh* sphere2;
StandardMesh* body2;
GLBI_Convex_2D_Shape disque2{3};
IndexedMesh* cylindre2;
IndexedMesh* cube2;
IndexedMesh* pyramide;
StandardMesh* a_frame;





 void initGare(){
	 createTexture();
	
     body2 = basicCone(10.0f, 4.0f, 2.50f, 50);
	 body2->createVAO();
	 
	//DISQUE
 	std::vector<float> pts_disque;
	std::vector<float> normals_disque;
 	std::vector<float> uvs_disque;
	
 //remplir tab ac points nécéessaire
 	for (int i=0; i<=50; i++){
		float angle_bis= 2*M_PI*i /50;
		pts_disque.push_back(cos(angle_bis)); //on garde rayon 1 on fera homotéthie pr rayon de 6
		pts_disque.push_back(sin(angle_bis));
		
		normals_disque.push_back(0.f); //on garde rayon 1 on fera homotéthie pr rayon de 6
		normals_disque.push_back(0.f);
		normals_disque.push_back(1.f);

		uvs_disque.push_back(0.5 + 0.5 * cos(angle_bis)); //on garde rayon 1 on fera homotéthie pr rayon de 6
		uvs_disque.push_back(0.5 + 0.5 * sin(angle_bis));
 }
	disque2.initShape(pts_disque, normals_disque, uvs_disque);
 	disque2.changeNature(GL_TRIANGLE_FAN);

	//CYLINDRE 
	cylindre2 = basicCylinder(1.0f, 1.0f, 32, 1);
	cylindre2-> createVAO();

	//CUBE
	cube2=basicCube(1);
	cube2-> createVAO();

	//PYRAMIDE
	 float sommet[] = {
        -1.f, -1.f, 0.f, //bas gauche S0
         1.f, -1.f, 0.f, //bas droite S1
         1.f,  1.f, 0.f, // haut droit S2
        -1.f,  1.f, 0.f, // heut gauche S3
         0.f,  0.f, 1.5f// hau pyramide S4
    };
//pour relier les points, on cree les faces
	 unsigned int indices[] = {
        0,1,2, //face 
        0,2,3,
        0,1,4,
        1,2,4,
        2,3,4,
        3,0,4
    };

	float normals[] = {
        0.f, 0.f, 1.f, //bas gauche S0
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,

		0.f, 0.f, 1.f, //bas gauche S0
		0.f, 0.f, 1.f,
		0.f, 0.f, 1.f,

		0.f, -1.f, 0.f, //bas gauche S0
		0.f, -1.f, 0.f,
		0.f, -1.f, 0.f,

		1.f, 0.f, 0.f, //bas gauche S0
		1.f, 0.f, 0.f,
		1.f, 0.f, 0.f,

		0.f, 1.f, 0.f, //bas gauche S0
		0.f, 1.f, 0.f,
		0.f, 1.f, 0.f,

        -1.f, 0.f, 0.f, //bas gauche S0
		-1.f, 0.f, 0.f,
		-1.f, 0.f, 0.f,
    };
float uvs[] = {
    // Base (carré)
    0.f, 0.f,   // S0 (-1, -1)
    1.f, 0.f,   // S1 ( 1, -1)
    1.f, 1.f,   // S2 ( 1,  1)
    0.f, 1.f,   // S3 (-1,  1)

    // Sommet
    0.5f, 0.5f  // S4 (apex)
};
	pyramide = new IndexedMesh(6, 5, GL_TRIANGLES);
    pyramide->addOneBuffer(0, 3, sommet, "coordinates", true); //coordinate trouvé d'après source
	pyramide->addOneBuffer(1, 3, normals, "normals", true); //coordinate trouvé d'après source
    pyramide->addOneBuffer(2, 2, uvs, "uvs", true); //coordinate trouvé d'après source
    pyramide->addIndexBuffer(indices, true);
    pyramide->createVAO();
    

 }

 void drawToit(){
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0,0,3});
			myEngine.mvMatrixStack.addRotation(-M_PI/10,{0,1,0});
			myEngine.mvMatrixStack.addHomothety({0.7,0.7,7.3});
			myEngine.updateMvMatrix();
			cube2->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({1,0,5.6});
			myEngine.mvMatrixStack.addRotation(M_PI/4,{0,1,0});
			myEngine.mvMatrixStack.addHomothety({0.5,0.5,4});
			myEngine.updateMvMatrix();
			cube2->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
 

		
 }

 void drawStatue(){
	myEngine.setFlatColor(0.435, 0.537, 1);
	myEngine.mvMatrixStack.pushMatrix();
			myEngine.updateMvMatrix();
			pyramide->draw();
		myEngine.mvMatrixStack.popMatrix();

		myEngine.updateMvMatrix();
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0,0,2.2});
			myEngine.mvMatrixStack.addHomothety({1,1,-1.4});
			myEngine.updateMvMatrix();
			pyramide->draw();
		myEngine.mvMatrixStack.popMatrix();

		myEngine.updateMvMatrix();
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0,0,2.1});
			//myEngine.mvMatrixStack.addRotation(-M_PI,{0,1,0});
			myEngine.mvMatrixStack.addHomothety({1,1,1.6});
			myEngine.updateMvMatrix();
			pyramide->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0,0,4.f});
			myEngine.mvMatrixStack.addRotation(-M_PI/10,{0,1,0});
			myEngine.mvMatrixStack.addRotation(-M_PI/10,{1,0,0});
			myEngine.mvMatrixStack.addHomothety({0.6,0.6,1.4});
			myEngine.updateMvMatrix();
			pyramide->draw();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();


 }



 void drawGare(){
	
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({0.5f, 0.5f, 1.f});
		myEngine.updateMvMatrix();

		myEngine.setFlatColor(0.435, 0.537, 0.384);

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
				myEngine.setFlatColor(0.231, 0.22, 0.133);
				myEngine.mvMatrixStack.addTranslation({0.f,0.f,1.2f});
				myEngine.mvMatrixStack.addHomothety({1.f,1,1.5f});
				myEngine.updateMvMatrix();
				cube2->draw();

				//couche 3
				myEngine.setFlatColor(0, 1, 0.118);
				myEngine.mvMatrixStack.addTranslation({0.f,0.f,0.7f});
				myEngine.mvMatrixStack.addHomothety({1.f,1,0.3f});
				myEngine.updateMvMatrix();
				myEngine.activateTexturing(true);
				bois_gareTexture.attachTexture();
				cube2->draw();
				bois_gareTexture.detachTexture();
				myEngine.activateTexturing(false);
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//poteaux bois fond

		myEngine.setFlatColor(0.431, 0.404, 0.38);
		for (int i=0; i<=10; i++) {
			myEngine.setFlatColor( 0.631, 0.608, 0.569);
			myEngine.mvMatrixStack.pushMatrix();

				myEngine.mvMatrixStack.addTranslation({-5.f, i*20.f/10.f-10.f, 1.f});
				myEngine.mvMatrixStack.addHomothety({0.5,0.5,3});
				myEngine.updateMvMatrix();
				cube2->draw();

			myEngine.mvMatrixStack.popMatrix();

			//rembarde
			myEngine.activateTexturing(true);
			acier_gareTexture.attachTexture();
			myEngine.mvMatrixStack.pushMatrix();

				myEngine.mvMatrixStack.addTranslation({-5.f, i*20.f/10.f-10.f, 2.5f});
				myEngine.mvMatrixStack.addHomothety({1.f,2.f,0.3});
				myEngine.updateMvMatrix();
				cube2->draw();
				acier_gareTexture.detachTexture();
				myEngine.activateTexturing(false);
				
			myEngine.mvMatrixStack.popMatrix();
		}

		//poteaux bois gauche
		for (int i=0; i<=3; i++) {
			myEngine.setFlatColor( 0.631, 0.608, 0.569);
			myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({i*20.f/10.f-5.f,-10.f, 1.f});
				myEngine.mvMatrixStack.addHomothety({0.5,0.5,3});
				myEngine.updateMvMatrix();
				cube2->draw();
			myEngine.mvMatrixStack.popMatrix();

			//rembarde
			myEngine.activateTexturing(true);
			acier_gareTexture.attachTexture();
			myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({i*20.f/10.f-5.f,-10.f, 2.5f});
				myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
				myEngine.mvMatrixStack.addHomothety({1.f,2.f,0.3});
				myEngine.updateMvMatrix();
				cube2->draw();
				acier_gareTexture.detachTexture();
			myEngine.activateTexturing(false);
			myEngine.mvMatrixStack.popMatrix();
		}

		//poteau bois droite
		for (int i=0; i<=3; i++) {
			myEngine.setFlatColor( 0.631, 0.608, 0.569);
			myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({i*20.f/10.f-5.f,10.f, 1.f});
				myEngine.mvMatrixStack.addHomothety({0.5,0.5,3});
				myEngine.updateMvMatrix();
				cube2->draw();
			myEngine.mvMatrixStack.popMatrix();

			//rembarde
			myEngine.activateTexturing(true);
			acier_gareTexture.attachTexture();
			myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({i*20.f/10.f-5.f,10.f, 2.5f});
				myEngine.mvMatrixStack.addRotation(M_PI/2,{0,0,1});
				myEngine.mvMatrixStack.addHomothety({1.f,2.f,0.3});
				myEngine.updateMvMatrix();
				cube2->draw();
				acier_gareTexture.detachTexture();
			myEngine.activateTexturing(false);
			myEngine.mvMatrixStack.popMatrix();
		}

		// Poteau toit droit
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({-4,-8.5f, 0});
			myEngine.updateMvMatrix();
			myEngine.activateTexturing(true);
			bois_gareTexture.attachTexture();
			drawToit();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		// Poteau toit gauche
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({-4,8.5f, 0});
			myEngine.updateMvMatrix();
			drawToit();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();
			
		//TOIT
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({-3,0,6.7f});
			myEngine.mvMatrixStack.addRotation(-M_PI/15,{0,1,0});
			myEngine.mvMatrixStack.addHomothety({5.f,20.f,0.4});
			myEngine.updateMvMatrix();
			cube2->draw();
			bois_gareTexture.detachTexture();
			myEngine.activateTexturing(false);
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		//PYRAMIDES TOIT
		myEngine.setFlatColor(1, 1, 0.118);
		myEngine.activateTexturing(true);
		acier_gareTexture.attachTexture();
		for (int i=0; i<=7; i++) {
			myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addTranslation({-2.f, i*20.f/8.f-8.5f, 7.f});
				myEngine.mvMatrixStack.addHomothety({1,1.5,0.8});
				myEngine.updateMvMatrix();
				pyramide->draw();
				
			myEngine.mvMatrixStack.popMatrix();
			myEngine.updateMvMatrix();
		}
		acier_gareTexture.detachTexture();
		myEngine.activateTexturing(false);

		//STATUE 1
		myEngine.activateTexturing(true);
		rockTexture.attachTexture();
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({3.5f,8.7,0.5f});
			myEngine.mvMatrixStack.addRotation(M_PI,{0,0,1});
			myEngine.mvMatrixStack.addHomothety({0.9,0.9,0.9});
			myEngine.updateMvMatrix();
			drawStatue();
			
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();
		
		//STATUE 2
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({3.5f,-8.7,0.5f});
			myEngine.mvMatrixStack.addRotation(-M_PI,{0,0,1});
			myEngine.mvMatrixStack.addHomothety({0.9,0.9,0.9});
			myEngine.updateMvMatrix();
			drawStatue();
		rockTexture.detachTexture();
		myEngine.activateTexturing(false);
			
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();


 } 