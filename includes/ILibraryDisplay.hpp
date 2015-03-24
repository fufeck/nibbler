// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ILibraryDisplay.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 16:47:16 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 16:47:17 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef I_LIBRARY_DISPLAY
# define I_LIBRARY_DISPLAY

#define		SIZE		10

class Game;

enum Color { WHITE, BLACK };
enum Commands { NOTHING, UP, RIGHT, DOWN, LEFT, RETURN, EXIT, F1, F2, F3 };

class ILibraryDisplay
{

public:
	virtual bool		getDisplayMode(void) = 0;
	virtual void		destroyLib(void) = 0;
	virtual int			getKey(void) = 0;
	virtual void		refreshScreen(void) = 0;
	virtual bool		displayElem(int height, int width, int color) = 0;
	virtual bool		displayFood(int height, int width, int color) = 0;
};

#endif