#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <spaceInvaders.h>

int WIDTH;
int HEIGHT;

int process_events(SDL_Window *window);
void init_SDL(SDL_Window *window, SDL_Renderer *renderer);