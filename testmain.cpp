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
int boxstart=0;
vector<bool>boxfull(boxcount,0);
class brick {
public:
	int x1;
	int x2;
	int y1;
	int y2;
	int life;
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
	void hit(){
     life--;
	}
	
};
class circle
{
public:
  int x=300;
  int y=730;
  int r=10;
    int teta;
    float vx;
    float vy;
   float v;
   void bullinit(int t1, float v){
	   teta = t1;
	   vx=v*cos(teta);
	   vy=v*sin(teta);
   }
  circle()
  {
      filledCircleRGBA(render , x , y , r , 0, 0, 255, 255);
      filledCircleRGBA(render , x , y , r , 0, 0, 0, 255);

  }

  void move()
  {
	  while(true){
   if(x>=590||x<=10)
   vx*=(-1);
   if(y>=740||y<=10)
   vy*=(-1);
   x+=vx;
   y+=vy;
   if(y>=740){
	 filledCircleRGBA(render , x , 740 , r , 0, 0, 255, 255); break;
   }
      filledCircleRGBA(render , x , y , r , 0, 0, 255, 255);
	 
	   SDL_RenderPresent(render);
       SDL_Delay(20);
       filledCircleRGBA(render , x , y , r , 0, 0, 0, 255);
      

	
	  }

  }
};

vector<brick>box(boxcount);
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
	//SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
	//SDL_RenderClear(render);
	}
}
void timetogo() {
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
				return;
			}
			     circle c;
				c.bullinit(30,10);
	             c.move();
				 break;
		}
		break;
		//SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
		//SDL_RenderClear(render);
	}
	SDL_RenderPresent(render);
	//SDL_Delay(20);
}

void beforePLayerTurn() {
	boxcount+=6;
	boxstart+=6;
	box.resize(boxcount);
	boxfull.resize(boxcount);
		int bricknum=rand()%6+1;
	for(int i=0;i<bricknum;i++){
		int l=rand()%boxcount; 
	while(boxfull[l]!=1){
		boxfull[l]==1;  
		break;
	};
	}
    for(int i=0;i<boxcount;i++){
		if(boxfull[i]==1){
			box[i].vy+=1;
			box[i].initialize(i*85,i*85+70,box[i].vy*40,box[i].vy*40+50);
		}
	}
}

void close() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
	SDL_Quit();
	// TTF_Quit();
}
void GameLoop() {
	while (!quit) {
		//playertime();
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
	int bricknum=rand()%6+1;
	for(int i=0;i<bricknum;i++){
	boxfull[rand()%6]=1;
	}
    for(int i=0;i<6;i++){
		if(boxfull[i]==1){
			box[i].initialize(i*85,i*85+70,box[i].vy,50);

		}
	}
	//thickLineRGBA
	//c.bullinit(30,10);
	//c.move();
	SDL_RenderPresent(render);
	if (!quit) {
		GameLoop();
	}
	close();
	return 0;
}