#include "Body.h"
#include "SDL_timer.h"

Body::Body(){
	pos.x = 2.0f;
	pos.y = 12.5f;
	pos.z = 0.0f;

	vel.x = 15.0f;
	vel.y = 0.0f;
	vel.z = 0.0f;

	accel.x = 0.0f;
	accel.y = -9.81f;
	accel.z = 0.0f;

	mass = 0.0f;
}


Body::Body(Vec3 pos_) {
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;

	vel.x = 0.0f;
	vel.y = 0.0f;
	vel.z = 0.0f;

	accel.x = 0.0f;
	accel.y = 0;
	accel.z = 0.0f;

	mass = 0.0f;
}

Body::~Body(){

}



void Body::Update(float deltaTime){
	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime;
	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime;
	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime;

	vel.x += accel.x * deltaTime;
	vel.y += accel.y * deltaTime;
	vel.z += accel.z * deltaTime;


	// floor collision
	if (pos.y < 2.2f) {
		vel.y *= 0;
		accel.x = 0;
		vel.x = 0;
		pos.y = 2.2f; 
		for (int i = 0; i < 10001; i++) {
			printf("time %i\n", i);
			if (i == 10000) {
				printf("reset\n");
				pos.x = 2.0f;
				pos.y = 16.5f;
				pos.z = 0.0f;

				vel.x = 15.0f;
				vel.y = 0.0f;
				vel.z = 0.0f;

				accel.x = 0.0f;
				accel.y = -9.81f;
				accel.z = 0.0f;

				mass = 0.0f;
			}
		}
	}

	//roof collision
	if (pos.y > 15.0f) {
		vel.y *= -1.f;
		pos.y = 15.0f;
	}

	// right wall colloision
	if (pos.x > 27.5f) {
		vel.x = -vel.x;
		pos.x = 27.5f;
	}

	// left wall collision
	else if (pos.x < 0.0f) {
		vel.x = -vel.x;
		pos.x = 0.0f;
	}
}
