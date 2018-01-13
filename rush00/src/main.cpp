/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:21:49 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/13 17:09:51 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>

#include <iostream>
#include <ncurses.h>
#include "Game.hpp"

int main()
{
	Game game;

	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	game.run();

	curs_set(1);
	endwin();
	return (0);
}
