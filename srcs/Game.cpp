// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/02 12:01:52 by ftaffore          #+#    #+#             //
//   Updated: 2015/03/02 12:01:54 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cstdlib>
#include "Game.hpp"

Game::Game(int height, int width) : _height(height), _width(width), _snake(height, width) {
	srandom(time(NULL));
	this->_newGift(true);
	this->_pastActive = false;
	this->_cmds[0] = &Game::_move;
	this->_cmds[1] = &Game::_changeDirection;
	this->_cmds[2] = &Game::_changeDirection;
	this->_cmds[3] = &Game::_changeDirection;
	this->_cmds[4] = &Game::_changeDirection;
	this->_cmds[5] = &Game::_movePast;

}

Game::~Game(void) {

}

void		Game::_displayGift(void) {
	this->_currentLib->displayFood(this->_gift[0], this->_gift[1], WHITE);
}

void		Game::_newGift(bool start) {

	if (start == false)
		this->_currentLib->displayFood(this->_gift[0], this->_gift[1], BLACK);
	this->_gift[0] = random() % this->_height;
	this->_gift[1] = random() % this->_width;
}

void		Game::_move(int cmd) {

	static_cast<void>(cmd);
	if (this->_pastActive == true) {
		this->_movePast(0);
	} else {
		this->_snake.move();
		if (this->_snake.onSnake(this->_gift[0], this->_gift[1])) {
			this->_newGift();
			this->_snake.addElem();
		}
	}
}

void		Game::_movePast(int cmd) {

	static_cast<void>(cmd);
	this->_pastActive = this->_snake.movePast();
	if (this->_snake.onSnake(this->_gift[0], this->_gift[1])) {
		this->_newGift();
		this->_snake.addElem();
	}
}

void		Game::_changeDirection(int cmd) {
	this->_pastActive = false;
	if (cmd != this->_snake.getDir()) {
		this->_snake.setDir(cmd);
	}
	this->_move(cmd);
}

bool		Game::refreshSnake(int cmd) {
	
	if (this->_snake.endSnake() == true)
		return true;
	if (cmd >= 0 && cmd < NB_CMDS) {
		funcAction 		func = this->_cmds[cmd];
		(this->*func)(cmd);
	}
	this->_snake.displaySnake(this->_currentLib);
	this->_displayGift();
	return false;
}

void 		Game::setLib(ILibraryDisplay *lib) {
	this->_snake.changeLib();
	this->_currentLib = lib;
}
