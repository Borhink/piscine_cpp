/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/14 20:13:58 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "Game.hpp"

int main()
{
	int x, y;
	Game *game;

	initscr();
	if (COLS < 100 || LINES < 30)
	{
		endwin();
		std::cout << "COLS MINI : 100, LINES MINI 30" << std::endl;
		return (0);
	}
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);

	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	getmaxyx(stdscr,y,x);
	game = new Game(x, y);

	game->run();
	delete game;

	curs_set(1);
	endwin();
	return (0);
}
