/*
 * 30.cpp
 *
 *  Created on: Apr 12, 2006
 *      Author: user
 */

#include<SDL2/SDL.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
	SDL_Window *win;
	SDL_Renderer *ren;
	if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		printf("\n SDL_Init Error:%s",SDL_GetError());
		return 1;
	}
}
win=SDL_CreateWindow("My SDL Window",SDL_WINDOWPOS_CENTERED,SDL_WINDOW_SHOWN|SDL_WINDOW_MAXIMIZED);
if(win==NULL){
	printf("\N SDL_Create Window Error:%s",SDL_GetError());
	return 1;
	SDL_Quit();
	return 1;
}
ren=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED,SDL_RENDERER_PRESENTSVSYNC);
if(ren==NULL){
	printf("\N SDL_CreateRenderer:%s",SDL_GetError());
	return 1;
	SDL_Quit();
	return 1;
}
SDL_Surface *bmp=SDL_LoadBMP("mice.bmp");
if(bmp==NULL){
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	printf("\nSDL_LoadBMP Error:%s",SDL_GetError());
	SDL_Quit();
	return 1;
}
SDL_Texture *tex=SDL_CreateTextureFromSurface(ren,bmp);
SDL_FreeSurface(bmp);
if(tex=NULL){
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	printf("\nSDL_CreateTextureFromSurface:%s",SDL_GetError());
	SDL_Quit();
	return 1;
}
{
SDL_RenderClear(ren);
SDL_RenderCopy(ren,tex,NULL,NULL);
SDL_RenderPresent(ren);
SDL_Delay(3000);
SDL_DestroyTexture(tex);
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();
return 0;
}
