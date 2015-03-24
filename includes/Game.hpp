// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/02 11:59:19 by ftaffore          #+#    #+#             //
//   Updated: 2015/03/02 11:59:20 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>
#include <stdexcept>
#include "ILibraryDisplay.hpp"
#include "Snake.hpp"

#define					NB_CMDS		6

class Game
{

typedef					void (Game::*funcAction)(int);

private:
	int					_height;
	int					_width;
	Snake				_snake;

	int					_pastActive;
	ILibraryDisplay		*_currentLib;
	int					_gift[2];
	funcAction			_cmds[NB_CMDS];

	void				_displayGift(void);
	void				_newGift(bool = false);

	void				_move(int = 0);
	void				_movePast(int = 0);
	void				_changeDirection(int);
	void				_returnSnake(int);


	Game(void);
	Game(Game const &);
	Game&			operator=(Game const &);
public:
	Game(int height, int width);
	~Game(void);
	
	bool				refreshSnake(int cmd);
	void 				setLib(ILibraryDisplay *lib);

};

#endif