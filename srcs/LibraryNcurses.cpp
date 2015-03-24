// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   LibraryNcurses.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 19:38:46 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 19:38:47 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <unistd.h>
#include "LibraryNcurses.hpp"

LibraryNcurses::LibraryNcurses(int height, int width) : _height(height), _width(width) {

	this->_tab[KEY_UP] = UP;
	this->_tab[KEY_DOWN] = DOWN;
	this->_tab[KEY_RIGHT] = RIGHT;
	this->_tab[KEY_LEFT] = LEFT;
	this->_tab[127] = RETURN;
	this->_tab[27] = EXIT;
	this->_tab[49] = F1;
	this->_tab[50] = F2;
	this->_tab[51] = F3;

	//this->checkSize();
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	curs_set(0);
	this->_win = newwin(this->_height + 2, this->_width + 2, 0, 0);
	wclear(this->_win);
	wborder(this->_win, '|', '|', '=', '=', '/', '\\', '\\', '/');
	wrefresh(this->_win);
	timeout(20);
}

LibraryNcurses::~LibraryNcurses() {
	echo();
    keypad(stdscr, TRUE);
	wclear(this->_win);
	endwin();
}
/*
int				LibraryNcurses::checkSize(void) {
	struct winsize		win;

	ioctl(0, TIOCGWINSZ, &win);
	if (this->_height > win.ws_col ||this->_width > win.ws_row) {
		throw std::exception();
	}
}
*/

void			LibraryNcurses::destroyLib(void) {
	echo();
    nocbreak();
	wclear(this->_win);
	endwin();
}

bool			LibraryNcurses::getDisplayMode(void) {
	return false;
}


int				LibraryNcurses::getKey(void) {
	int key = getch();

	if (this->_tab.find(key) == this->_tab.end())
		return NOTHING;
	return this->_tab[key];
}

bool			LibraryNcurses::displayElem(int height, int width, int color) {
	wmove(this->_win, height + 1, width + 1);
	if (color == WHITE)
		wprintw(this->_win, "o");
	else
		wprintw(this->_win, " ");
	return true;
}

bool			LibraryNcurses::displayFood(int height, int width, int color) {
	wmove(this->_win, height + 1, width + 1);
	if (color == WHITE)
		wprintw(this->_win, "X");
	else
		wprintw(this->_win, " ");
	return true;
}

void			LibraryNcurses::refreshScreen(void) {
	wborder(this->_win, '|', '|', '=', '=', '/', '\\', '\\', '/');
	wrefresh(this->_win);
}

extern "C" ILibraryDisplay	*maker(int height, int width) {
	return new LibraryNcurses(height, width);
}