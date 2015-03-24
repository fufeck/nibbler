// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   LibrarySdl.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 19:29:48 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 19:29:49 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef LIBRARY_SDL
# define LIBRARY_SDL

#include <iostream>
#include <map>
#include <exception>
#include <SDL.h>
#include "ILibraryDisplay.hpp"

#define			BLOC_SIZE		20

class LibrarySdl : public ILibraryDisplay
{
private:
	int					_height;
	int					_width;

	std::map<int, int>	_tab;

	SDL_Window		*_window;
	SDL_Renderer	*_renderer;
	SDL_Event		e;
	SDL_Surface		*_elem;
	SDL_Surface		*_food;

	LibrarySdl();
	LibrarySdl(LibrarySdl const & src);
	LibrarySdl const	&operator=(LibrarySdl const & src);

public:
	LibrarySdl(int height, int width);
	virtual ~LibrarySdl();

	virtual bool		getDisplayMode(void);
	virtual void		destroyLib(void);
	virtual int			getKey(void);
	virtual void		refreshScreen(void);
	virtual bool		displayElem(int height, int width, int color);
	virtual bool		displayFood(int height, int width, int color);
};

#endif