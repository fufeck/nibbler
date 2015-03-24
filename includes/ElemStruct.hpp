// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ElemStruct.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/27 17:04:09 by ftaffore          #+#    #+#             //
//   Updated: 2015/02/27 17:04:10 by ftaffore         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ELEM_STRUCT_HPP
# define ELEM_STRUCT_HPP

enum State {BEFO, NEW, DISPLAY, PAST, DEL};

struct Elem
{
	int 	dir;
	int		state;
	int		height;
	int		width;
	Elem	*next;
};

#endif