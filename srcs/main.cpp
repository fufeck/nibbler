// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 16:41:20 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 16:41:20 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Nibbler.hpp"



int			main(int ac, char **av) {
	Nibbler	*nibbler;
	int 	height = 20;
	int 	width = 20;

	(void)av;
	if (ac == 3) {
		try {
			nibbler = new Nibbler(height, width);
			nibbler->whileGame();
		} catch (std::exception & e) {
			std::cerr << "Exception : " << e.what() << std::endl;
		}
	} else {
		std::cerr << "USAGE : ./Nibbler height width" << std::endl;
	}
	return 0;
}