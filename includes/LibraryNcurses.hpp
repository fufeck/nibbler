// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   LibraryNcurses.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 19:35:47 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 19:35:48 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LIBRARY_NCURSES
# define LIBRARY_NCURSES

#include <iostream>
#include <map>
#include <exception>
#include <signal.h>
#include <sys/ioctl.h>
#include "ncurses.h"
#include "ILibraryDisplay.hpp"
#include "Game.hpp"

class LibraryNcurses : public ILibraryDisplay
{

private:
	WINDOW				*_win;

	int					_height;
	int					_width;

	std::map<int, int>	_tab;

	LibraryNcurses();
	LibraryNcurses(LibraryNcurses const & src);
	LibraryNcurses const	&operator=(LibraryNcurses const & src);

public:
	LibraryNcurses(int height, int width);
	virtual ~LibraryNcurses();

//	void				checkSize(int sign);
	virtual bool		getDisplayMode(void);
	void				destroyLib(void);
	int					getKey(void);
	void				refreshScreen(void);
	virtual bool		displayElem(int height, int width, int color);
	virtual bool		displayFood(int height, int width, int color);
};

#endif