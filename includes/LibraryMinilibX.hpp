// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   LibraryMinilibX.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 19:35:39 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 19:35:40 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LIBRARY_MINILIBX
# define LIBRARY_MINILIBX

#include <mlx.h>
#include "ILibraryDisplay.hpp"

class LibraryMinilibX : public ILibraryDisplay
{
private:
	int					_height;
	int					_width;
	refreshGame 				*_game;

	LibraryMinilibX();
	LibraryMinilibX(LibraryMinilibX const & src);
	LibraryMinilibX const	&operator=(LibraryMinilibX const & src);

public:
	LibraryMinilibX(int height, int width, refreshGame *game);
	virtual ~LibraryMinilibX();

	virtual int			whileGame(void);
	virtual bool		displayElem(int height, int width, int color);
	virtual bool		displayFood(int height, int width, int color);
};

#endif