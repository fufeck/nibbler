// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   LibrarySdl.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 19:38:54 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 19:38:55 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <SDL.h>
#include <unistd.h>
#include "LibrarySdl.hpp"

LibrarySdl::LibrarySdl(int height, int width) : _height(height), _width(width) {
	this->_tab[SDLK_UP] = UP;
	this->_tab[SDLK_DOWN] = DOWN;
	this->_tab[SDLK_RIGHT] = RIGHT;
	this->_tab[SDLK_LEFT] = LEFT;
	this->_tab[SDLK_BACKSPACE] = RETURN;
	this->_tab[SDLK_ESCAPE] = EXIT;
	this->_tab[SDLK_KP_1] = F1;
	this->_tab[SDLK_KP_2] = F2;
	this->_tab[SDLK_KP_3] = F3;

	this->_elem = SDL_LoadBMP("image.bmp");
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		if ((this->_window = SDL_CreateWindow("ft_nibbler", 0, 0, width * BLOC_SIZE, height * BLOC_SIZE, SDL_WINDOW_SHOWN)) == NULL)
			throw std::exception();
		if ((this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
			throw std::exception();
	}
	else {
		throw std::exception();
	}
	SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->_renderer);
}

LibrarySdl::~LibrarySdl() {
	SDL_DestroyRenderer(this->_renderer);
	SDL_DestroyWindow(this->_window);
	SDL_Quit();
}

void			LibrarySdl::destroyLib(void) {
	SDL_DestroyRenderer(this->_renderer);
	SDL_DestroyWindow(this->_window);
	SDL_Quit();
}


bool			LibrarySdl::getDisplayMode(void) {
	return true;
}

int				LibrarySdl::getKey(void) {
	SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->_renderer);
	while (SDL_PollEvent(&(this->e)) != 0) {
		if (this->_tab.find(this->e.key.keysym.sym) == this->_tab.end())
			return NOTHING;
		return this->_tab[this->e.key.keysym.sym];
	}

	return 0;
}

bool			LibrarySdl::displayElem(int height, int width, int color) {
	if (color == WHITE)
		SDL_SetRenderDrawColor(this->_renderer, 255, 255, 102, 255);
	else
		SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
	for (int x = 0; x < BLOC_SIZE; x++) {
		for (int y = 0; y < BLOC_SIZE; y++) {
			SDL_RenderDrawPoint(this->_renderer, (width * BLOC_SIZE) + x, (height * BLOC_SIZE) + y);
		}
	}
	(void)color;
	return true;
}

bool			LibrarySdl::displayFood(int height, int width, int color) {
	SDL_SetRenderDrawColor(this->_renderer, 55, 65, 102, 255);

	for (int x = 0; x < BLOC_SIZE; x++) {
		for (int y = 0; y < BLOC_SIZE; y++) {
			SDL_RenderDrawPoint(this->_renderer, (width * BLOC_SIZE) + x, (height * BLOC_SIZE) + y);
		}
	}
	(void)color;
	return true;
}

void			LibrarySdl::refreshScreen(void) {
	SDL_RenderPresent(this->_renderer);
}

extern "C"  ILibraryDisplay	*maker(int height, int width) {
	return new LibrarySdl(height, width);
}
