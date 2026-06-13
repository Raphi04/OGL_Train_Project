#include "cow.hpp"

IndexedMesh* cube4;
bool rotationArmIncreased;
float rotationArm;
bool flag_anim_rot_arm=true;
float x_trans;

void initCow() {
    cube4 = basicCube();
    cube4->createVAO();
}

void drawCow() {
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addHomothety({2.f, 1.f, 1.f});
        myEngine.updateMvMatrix();

        	//VACHE//////////////////////////////////////////////////////////////////////////
	//pour mouvement
	
    // Si l'angle est inférieur à l'équivalent de 20° en radiant alors on augmentera et inversement pour la diminution
    if(rotationArm < -2 * M_PI / 350.f) {
        rotationArmIncreased = true;
    } else if (rotationArm > 20 * M_PI / 100.f) {
        rotationArmIncreased = false;
    }

    // Exercice 05 -> 02. | Rotation du balancier (incrémentation)
    if(flag_anim_rot_arm) {
        if(rotationArmIncreased) {
            rotationArm = rotationArm + 0.01;
			x_trans= x_trans-0.02;
        } else {
            rotationArm = rotationArm -0.01;
			x_trans= x_trans+0.02;
        }
    }

// ===================
// CORPS
// ===================
myEngine.activateTexturing(true);
cowTexture.attachTexture();
myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.f, 0.75f, 2.f});
    myEngine.mvMatrixStack.addHomothety({1.5f, 2.2f, 1.5f});
    myEngine.updateMvMatrix();
    cube4->draw();
myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();


// ===================
// TÊTE
// ===================
myEngine.mvMatrixStack.pushMatrix();
myEngine.mvMatrixStack.addTranslation({x_trans, 0.f, 0.f});
myEngine.mvMatrixStack.addRotation(rotationArm,{0,1,0});


	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({1.f, 0.65f, 2.6f});
		myEngine.mvMatrixStack.addHomothety({0.8f, 0.8f, 0.8f});
		
		myEngine.updateMvMatrix();
		cube4->draw();
		cowTexture.detachTexture();
		myEngine.activateTexturing(false);
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	// ===================
	// YEUX
	// ===================
	myEngine.setFlatColor(0, 0, 0);
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({1.5f, 0.5f, 2.7f});
		myEngine.mvMatrixStack.addHomothety({0.12f, 0.12f, 0.2f});
		myEngine.updateMvMatrix();
		cube4->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();


	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({1.5f, 1.f, 2.7f});
		myEngine.mvMatrixStack.addHomothety({0.12f, 0.12f, 0.2f});
		myEngine.updateMvMatrix();
		cube4->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	// ===================
	// MUSEAU
	// ===================
	myEngine.setFlatColor(0.55, 0.34, 0.17);

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({1.5f, 0.75f, 2.45f});
		myEngine.mvMatrixStack.addHomothety({0.25f, 0.45f, 0.25f});
		myEngine.updateMvMatrix();
		cube4->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();


	// ===================
	// CORNE GAUCHE
	// ===================
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({1.1f, 1.05f, 3.f});
		myEngine.mvMatrixStack.addHomothety({0.08f, 0.08f, 0.4f});
		myEngine.updateMvMatrix();
		cube4->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();


	// ===================
	// CORNE DROITE
	// ===================
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({1.1f, 0.45f, 3.f});
		myEngine.mvMatrixStack.addHomothety({0.08f, 0.08f, 0.4f});
		myEngine.updateMvMatrix();
		cube4->draw();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();


// ===================
// PATTE AVANT GAUCHE
// ===================
myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.55f, 1.60f, 0.8f});
    myEngine.mvMatrixStack.addHomothety({0.25f, 0.25f, 1.2f});
    myEngine.updateMvMatrix();
    cube4->draw();
myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();


// ===================
// PATTE AVANT DROITE
// ===================
myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({0.55f, -0.10f, 0.8f});
    myEngine.mvMatrixStack.addHomothety({0.25f, 0.25f, 1.2f});
    myEngine.updateMvMatrix();
    cube4->draw();
myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();


// ===================
// PATTE ARRIÈRE GAUCHE
// ===================
myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-0.55f, 1.60f, 0.8f});
    myEngine.mvMatrixStack.addHomothety({0.25f, 0.25f, 1.2f});
    myEngine.updateMvMatrix();
    cube4->draw();
myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();


// ===================
// PATTE ARRIÈRE DROITE
// ===================
myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-0.55f, -0.10f, 0.8f});
    myEngine.mvMatrixStack.addHomothety({0.25f, 0.25f, 1.2f});
    myEngine.updateMvMatrix();
    cube4->draw();
myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();


// ===================
// QUEUE
// ===================
myEngine.mvMatrixStack.pushMatrix();
    myEngine.mvMatrixStack.addTranslation({-0.8f, 0.75f, 1.8f});
    myEngine.mvMatrixStack.addRotation(M_PI / 10.f, {0, 1, 0});
    myEngine.mvMatrixStack.addHomothety({0.08f, 0.08f, 0.7f});
    myEngine.updateMvMatrix();
    cube4->draw();
myEngine.mvMatrixStack.popMatrix();
myEngine.updateMvMatrix();

    myEngine.mvMatrixStack.popMatrix();
    myEngine.updateMvMatrix();
}