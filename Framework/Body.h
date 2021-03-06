#ifndef BODY_H
#define BODY_H
#include "Vector.h"
#include <SDL_stdinc.h>
#include <SDL_timer.h>
#pragma once
using namespace MATH;

class Body {
private:
	Vec3 pos;
	Vec3 vel;
	Vec3 accel;
	float mass;
public:
	Body();
	Body(Vec3 pos_);
	~Body();
	void Update(float deltaTime);
	Vec3 getPos() { return pos; }
	void setAccel(const Vec3 &accel_) {
		accel.x = accel_.x;
		accel.y = accel_.y;
		accel.z = accel_.z;
	}
};

#endif