// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Nibbler.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 16:52:59 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 16:53:00 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NIBBLER_HPP
# define NIBBLER_HPP

#include <iostream>
#include <stdexcept>
#include "ILibraryDisplay.hpp"
#include "Game.hpp"

#define 		LIB_F1		"libncurses.dylib"
#define 		LIB_F2		"libsdl.dylib"

typedef 		ILibraryDisplay*(*fptr)(int, int);

class Nibbler
{

private:

	int						_height;
	int 					_width;

	Game					*_game;
	void					*_loadLibs;
	int 					_indexLib;
	ILibraryDisplay			*_currentLib;

	void					_loadLibGraphic(std::string const &);
	void					_activatLib(int nbLibrary = 0);

	Nibbler(void);
	Nibbler(Nibbler const &);
	Nibbler&				operator=(Nibbler const &);
public:
	Nibbler(int height, int width);
	~Nibbler(void);

	void					whileGame(void);

	class SizeMapException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Map size is not correct.";
		}
	};

	class DinamicLibException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error during load Library.";
		}
	};
};

#endif