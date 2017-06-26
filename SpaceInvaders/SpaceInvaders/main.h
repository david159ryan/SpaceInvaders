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
int LOGICAL_WIDTH;
int LOGICAL_HEIGHT;
int SCALE;

int ProcessEvents(SDL_Window *window);
void InitSDL(SDL_Window **window, SDL_Renderer **renderer);