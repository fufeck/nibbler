// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Nibbler.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 17:46:59 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 17:47:00 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <unistd.h>
#include <dlfcn.h>
#include <cstdlib>
#include "Nibbler.hpp"

Nibbler::Nibbler(int height, int width) : _indexLib(0), _currentLib(NULL) {
	if (height < 10 && height > 40 && width < 10 && width > 50) {
		throw Nibbler::SizeMapException();
	}
	this->_game = new Game(height, width);
	this->_height = height;
	this->_width = width;
}

Nibbler::~Nibbler(void) {
	delete this->_game;
	dlclose(this->_loadLibs);
}

void		Nibbler::_activatLib(int nbLibrary) {
	const char *dlsym_error;
	fptr 	maker;
	
	if (this->_indexLib != nbLibrary || this->_currentLib == NULL) {

		this->_indexLib = nbLibrary;
		if (this->_currentLib != NULL)
			this->_currentLib->destroyLib();
			this->_currentLib = NULL;

		dlclose(this->_loadLibs);
		if (this->_indexLib == 0) {
			std::cout << LIB_F1 << std::endl;
			this->_loadLibs = dlopen(LIB_F1, RTLD_LAZY);
		} else if (this->_indexLib == 1) {
			std::cout << LIB_F2 << std::endl;
			this->_loadLibs = dlopen(LIB_F2, RTLD_LAZY);
		}
		if (this->_loadLibs == NULL) {
			throw Nibbler::DinamicLibException();
		}
		dlerror();
		maker = reinterpret_cast<fptr>(dlsym(this->_loadLibs, "maker"));
		dlsym_error = dlerror();
		if (maker == NULL || dlsym_error) {
			throw Nibbler::DinamicLibException();
		}
		this->_currentLib = maker(this->_width, this->_height);
		if (this->_currentLib == NULL) {
			throw Nibbler::DinamicLibException();
		}
		this->_game->setLib(this->_currentLib);
	}
	return ;
}

void		Nibbler::whileGame(void) {
	bool	end = false;

	this->_activatLib();
	int 	key = this->_currentLib->getKey();
	while (key != EXIT && end == false) {
		if (key > 6 && key < 9) {
			this->_activatLib(key - 7);
			std::cout << "key = " << key << std::endl;
		} else {
			end = this->_game->refreshSnake(key);
			this->_currentLib->refreshScreen();
		}
		key = this->_currentLib->getKey();
		usleep(100000);
	}
	this->_currentLib->destroyLib();
	std::cout << "Game Over !!" << std::endl;
	return ;
}
