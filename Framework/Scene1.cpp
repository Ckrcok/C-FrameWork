#include "Scene1.h"
#include <SDL.h>
#include <SDL_image.h>
Scene1::Scene1(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	balloon1 = new Body(Vec3(15.0f, 14.0f,0.0f )); // (x , y , z)
	balloon2 = new Body(Vec3(3.0f, 10.0f, 0.0f));
	std::cout << "hello from Scene1 \n";
}

Scene1::~Scene1(){
	delete balloon1;
	delete balloon2;
}

bool Scene1::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);// it's gonna be 0 zero bottom 15 hieght 
	projectionMatrix = ndc * ortho;
	



	IMG_Init(IMG_INIT_PNG);
	ballImage = IMG_Load("textures/ball.png");
	if (ballImage == nullptr) {
		std::cout << "Can't Open Image file \n";
		return false;
	}


	return true;
}

void Scene1::OnDestroy() {}

void Scene1::Update(const float deltaTime) {
	//printf("%f\n", deltaTime);
	balloon1->Update(deltaTime);
	balloon2->Update(deltaTime);
}

void Scene1::Render() {
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));
	Vec3 screenCoords;
	SDL_Rect square;


	screenCoords = projectionMatrix * balloon1->getPos();
	square.x = (int) screenCoords.x; /// We must update this with C11 typecasting - SSF
	square.y = (int) screenCoords.y;
	square.w = 30;
	square.h = 30;
	SDL_BlitSurface(ballImage, nullptr,  screenSurface, &square );
	//SDL_FillRect(screenSurface, &square, SDL_MapRGB(screenSurface->format,255, 0, 0));


	screenCoords = projectionMatrix * balloon2->getPos();
	square.x = (int)screenCoords.x; /// We must update this with C11 typecasting - SSF
	square.y = (int)screenCoords.y;
	square.w = 30;
	square.h = 30;
	SDL_BlitSurface(ballImage, nullptr, screenSurface, &square);
	//SDL_FillRect(screenSurface, &square, SDL_MapRGB(screenSurface->format, 0, 0, 255));

	SDL_UpdateWindowSurface(window);
}