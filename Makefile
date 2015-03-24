#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 15:15:50 by ftaffore          #+#    #+#              #
#    Updated: 2015/01/18 16:24:19 by chery            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC					=	g++

RM					=	rm -rf

CFLAGS				=	-Werror -Wall -Wextra

CFLAGS_LIB			=	-dynamiclib


NAME				=	Nibbler

NAME_NCURSE			=	libncurses.dylib

NAME_SDL			=	libsdl.dylib


INCLUDES			=	-I includes

INCLUDES_NCURSES	=	-I includes

INCLUDES_SDL		=	-I includes \
						-I $(HOME)/Library/Frameworks/SDL2.framework/Headers 			\
						-I $(HOME)/Library/Frameworks/SDL2_image.framework/Headers 		\
						-I $(HOME)/Library/Frameworks/SDL2_ttf.framework/Headers


LIBS				=	

LIBS_NCURSE			=	-lncurses

LIBS_SDL			=	$(HOME)/Library/Frameworks/SDL2.framework/SDL2 				\
						$(HOME)/Library/Frameworks/SDL2_image.framework/SDL2_image 	\
						$(HOME)/Library/Frameworks/SDL2_ttf.framework/SDL2_ttf 		\
						-framework GLUT -framework OpenGL -framework Cocoa

SRCS				=	srcs/main.cpp				\
						srcs/Nibbler.cpp			\
						srcs/Game.cpp				\
						srcs/Snake.cpp


SRCS_NCURSE			=	srcs/LibraryNcurses.cpp

SRCS_SDL			=	srcs/LibrarySdl.cpp

OBJS				=	$(SRCS:.cpp=.o)

all					:	$(NAME) $(NAME_NCURSE) $(NAME_SDL)

$(NAME)				:	$(OBJS)
						$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDES)

$(NAME_NCURSE)		:	$(SRCS_NCURSE)
						$(CC) -o $@ $(CFLAGS_LIB) $(SRCS_NCURSE) $(LIBS_NCURSE) $(INCLUDES_NCURSES)

$(NAME_SDL)			:	$(SRCS_SDL)
						$(CC) -o $@ $(CFLAGS_LIB) $(SRCS_SDL) $(INCLUDES_SDL) $(LIBS_SDL) 

.cpp.o				:
						$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean				:
						$(RM) $(OBJS)

fclean				:	clean
						$(RM) $(NAME) $(NAME_NCURSE) $(NAME_SDL)

re					:	fclean all

.PHONY				:	all clean fclean re
