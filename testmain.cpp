#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<SDL2/SDL2_gfxPrimitives.h>
#include<SDL2/SDL2_rotozoom.h>
#include <string>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<SDL2/SDL_ttf.h>
#undef main
using namespace std;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 750;
bool quit = false;
SDL_Surface* Surface = NULL;
SDL_Window* window = NULL;
SDL_Renderer* render = NULL;
SDL_Event event;
int boxcount=6;
vector<bool>boxfull(boxcount,0);
class brick {
public:
	int x1;
	int x2;
	int y1;
	int y2;
	int vy = 0;
	bool show = 0;
public:
	void initialize(int x11, int x12, int y11, int y12) {
		x1 = x11;
		x2 = x12;
		y1 = y11;
		y2 = y12;
	boxRGBA(render, x1, y1, x2, y2, 255, 153, 102, 255);
	}
	
};
class circle
{
public:
  int x=300;
  int y=740;
  int r=10;
  circle()
  {
      filledCircleRGBA(render , x , y , r , 0, 0, 255, 255);
  }
  void move()
  {
    int teta=45;
    int dx=1;
    int dy=tan(teta)*dx;
    while (600 - x >10)
    {
      x+=dx;
      y-=dy;
      SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0x00);
      SDL_RenderClear(render);
      filledCircleRGBA(render , x , y , r , 0, 0, 255, 255);
      SDL_Delay(10);
      SDL_RenderPresent(render);
    }
  }
};

vector<brick>box(6);
void init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) {
		printf("error creating window: %s\n", SDL_GetError());
		SDL_Quit();
	}
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!render)
	{
		printf("error creating renderer: %s\n", IMG_GetError());
		getchar();
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	/*TTF_init(){

	}*/

}

void playertime() {
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
				return;
			}
			// else {}
	
	}
	SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(render);
	}
}
void timetogo() {
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
				return;
			}
		}
		SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(render);
	}
	SDL_RenderPresent(render);
	//SDL_Delay(20);
}

void beforePLayerTurn() {
	boxcount+=6;
	//box.resize(boxCount);
	//boxfull.resize(boxcount);
}

void close() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
	SDL_Quit();
	// TTF_Quit();
}
void GameLoop() {
	while (!quit) {

		playertime();
		if (!quit) {
			timetogo();
		}
		if (!quit) {
			beforePLayerTurn();
		}
	}
}
int main() {
	srand(time(0));
	init();
	circle c;
	c.move();
	int bricknum=rand()%6+1;
	for(int i=0;i<bricknum;i++){
	boxfull[rand()%6]=1;
	}
    for(int i=0;i<6;i++){
		if(boxfull[i]==1){
			box[i].initialize(i*85,i*85+70,box[i].vy,50);

		}
	}
	SDL_RenderPresent(render);
	if (!quit) {
		GameLoop();
	}
	close();
	return 0;
}