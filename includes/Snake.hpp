// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Snake.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 16:57:34 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 16:57:34 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef	SNAKE_HPP
# define SNAKE_HPP

#include <iostream>
#include <string>
#include "ElemStruct.hpp"
#include "ILibraryDisplay.hpp"

class Snake
{
private:

	int					_height;
	int 				_width;
	int					_dir;
	int					_nbElem;
	int					_nbPast;
	Elem				*_head;

	void				_pushFront(int height = 0, int width = 0);
	void				_pushBack(void);
	void				_popFront(void);
	void				_popBack(void);
	void				_pushLastPast(void);
	Snake();
	Snake(Snake const &);
	Snake&		operator=(Snake const &);
public:
	Snake(int heightStart, int widthStart);
	~Snake();

	void				setDir(int dir);
	int 				getDir(void) const;

	void				move(void);
	bool				movePast(void);
	void				addElem(void);
	void				displaySnake(ILibraryDisplay *lib);
	bool				onSnake(int height, int width);
	bool				endSnake(void);
	void				changeLib(void);
};

#endif