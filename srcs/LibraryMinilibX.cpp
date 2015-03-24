// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   LibraryMinilibX.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 19:39:06 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 19:39:12 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "LibraryMinilibX.hpp"

LibraryMinilibX::LibraryMinilibX(int height, int width) : _height(height), _width(width) {
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		if ((this->_window = SDL_CreateWindow("ft_nibbler", 0, 0, width, height, SDL_WINDOW_SHOWN)) == NULL)
			throw std::exception();
		if ((this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
			throw std::exception();
	}
	else {
		throw std::exception();
	}
	SDL_RenderClear(this->_renderer);
}

LibraryMinilibX::~LibraryMinilibX() {
	SDL_DestroyRenderer(this->_renderer);
	SDL_DestroyWindow(this->_window);
	SDL_Quit();
}

void			LibraryMinilibX::destroyLib(void) {
	SDL_DestroyRenderer(this->_renderer);
	SDL_DestroyWindow(this->_window);
	SDL_Quit();
}


int				LibraryMinilibX::getKey(void) {
	
}

bool			LibraryMinilibX::displayElem(int height, int width, int color) {

}

bool			LibraryMinilibX::displayFood(int height, int width, int color) {

}

void			LibraryMinilibX::refreshScreen(void) {
	
}

extern "C"  ILibraryDisplay	*maker(int height, int width) {
	return new LibraryMinilibX(height, width);
}