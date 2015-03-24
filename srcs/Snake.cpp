// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Snake.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 17:09:01 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 17:09:02 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Snake.hpp"

Snake::Snake(int height, int width) {
	this->_height = height;
	this->_width = width;
	this->_dir = LEFT;
	this->_nbElem = 0;
	this->_nbPast = 0;
	this->_pushFront(height / 2, width / 2);
	this->_pushFront();
	this->_pushFront();
	this->_pushFront();
}

Snake::~Snake() {
}

void			Snake::_pushFront(int height, int width) {
	Elem 		*newElem = new Elem;

	newElem->state = NEW;
	newElem->dir = this->_dir;
	if (this->_head) {
		if (this->_dir == UP) {
			newElem->height = this->_head->height - 1;
			newElem->width = this->_head->width;
		} else if (this->_dir == RIGHT) {
			newElem->height = this->_head->height;
			newElem->width = this->_head->width + 1;
		} else if (this->_dir == DOWN) {
			newElem->height = this->_head->height + 1;
			newElem->width = this->_head->width;
		} else if (this->_dir == LEFT) {
			newElem->height = this->_head->height;
			newElem->width = this->_head->width - 1;
		}
	} else {
		newElem->height = height;
		newElem->width = width;
	}
	newElem->next = this->_head;
	this->_head = newElem;
	this->_nbElem++;
}

void			Snake::_pushBack(void) {
	Elem 			*newElem = this->_head;

	if (this->_nbPast > 0) {
		while (newElem != NULL && newElem->state != PAST && newElem->state != DEL)
			newElem = newElem->next;
		if (newElem != NULL)
			newElem->state = NEW;
		this->_nbElem++;
		this->_nbPast--;
	}
}

void			Snake::_popFront(void) {
	Elem 		*delElem = this->_head;

	if (this->_nbElem > 0) {
		this->_head = this->_head->next;
		this->_nbElem--;
		delete delElem;
	}
}

void			Snake::_popBack(void) {
	Elem 		*delElem = this->_head;
	Elem 		*delElem2 = this->_head;

	if (this->_nbPast > 0) {
		while (delElem != NULL && delElem->next != NULL) {
			delElem2 = delElem;
			delElem = delElem->next;
		}
		if (delElem != NULL) {
			delElem2->next = NULL;
			this->_nbPast--;
			delete delElem;
		}
	}
}

void			Snake::_pushLastPast(void) {
	Elem 		*ptr = this->_head;

	if (this->_nbElem > 0) {
		while (ptr != NULL && ptr->next != NULL && ptr->next->state != DEL)
			ptr = ptr->next;
		if (ptr != NULL) {
			this->_nbPast++;
			ptr->state = PAST;
		}
	}
}

int 			Snake::getDir(void) const {
	return this->_dir;
}

void			Snake::setDir(int dir) {
	if (dir % 2 == 0 && this->_dir % 2 != 0)
		this->_dir = dir;
	else if (dir % 2 == 1 && this->_dir % 2 != 1)
		this->_dir = dir;
}


void			Snake::move(void) {
	this->_pushFront();
	this->_pushLastPast();
	if (this->_nbPast > 60)
		this->_popBack();
}

bool			Snake::movePast(void) {
	if (this->_nbPast > 0) {
		this->_head->state = BEFO;
		this->_pushBack();
		this->_dir = this->_head->next->dir;
	}
	return (this->_nbPast > 0) ? (true) : (false);
}

void			Snake::addElem(void) {
	this->_pushBack();
}

void			Snake::displaySnake(ILibraryDisplay *lib) {
	Elem 		*ptr = this->_head;

	while (ptr != NULL) {
		if (lib->getDisplayMode() == true && ptr->state == DISPLAY) {
			lib->displayElem(ptr->height, ptr->width, WHITE);
		}
		if (ptr->state == NEW) {
			lib->displayElem(ptr->height, ptr->width, WHITE);
			ptr->state = DISPLAY;
		} else if (ptr->state == PAST) {
			lib->displayElem(ptr->height, ptr->width, BLACK);
			ptr->state = DEL;
		} else if (ptr->state == BEFO) {
			lib->displayElem(ptr->height, ptr->width, BLACK);
		}
		ptr = ptr->next;
	}
	if (this->_head->state == BEFO) {
		this->_popFront();
	}
}

bool			Snake::onSnake(int height, int width) {
	Elem 		*ptr = this->_head;

	while (ptr != NULL && ptr->state != PAST && ptr->state != DEL) {
		if (ptr->height == height && ptr->width == width) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

bool			Snake::endSnake(void) {
	Elem 		*ptr = this->_head;
	Elem 		*elem = this->_head->next;

	if (ptr == NULL)
		return true;
	if (ptr->height < 0 || ptr->height >= this->_height || ptr->width < 0 || ptr->width >= this->_width)
		return true;
	while (ptr != NULL && elem != NULL && elem->state != PAST && elem->state != DEL) {
		if (ptr->height == elem->height && ptr->width == elem->width) {
			return true;
		}
		elem = elem->next;
	}
	return false;
}

void			Snake::changeLib(void) {
	Elem 		*ptr = this->_head;

	while (ptr != NULL) {
		if (ptr->state == DISPLAY) {
			ptr->state = NEW;
		}
		ptr = ptr->next;
	}
}
