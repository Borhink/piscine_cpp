/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 17:14:00 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(void):
_run(true)
{
	return;
}

Game::Game(const Game &src)
{
	*this = src;
	return;
}

Game::~Game(void)
{
	return;
}

Game &Game::operator=(Game const &rhs)
{
	if (this != &rhs)
	{
		this->_run  = rhs._run;
	}
	return (*this);
}

void Game::render(void) const
{
	// map->draw();
	return;
}

void Game::update(void)
{
	int key = 0;
	char str[1000] = "";

	if ((key = getch()) != ERR)
	{
		sprintf(str, "%d", key);
		mvprintw(0, 50, str);
		if (key == ESCAPE)
			this->_run = false;
	}
	// map->update();
	return;
}

void Game::run(void)
{
	clock_t update = clock();
	clock_t timer = clock();
	double elapsed = 0.0f;
	int ups = 0;
	int fps = 0;
	char str[1000] = "";

	while (this->_run)
	{
		elapsed += (double)(clock() - update) / CLOCKS_PER_SEC;
		update = clock();
		if (elapsed > TICK_PER_SECOND)
		{
			elapsed -= TICK_PER_SECOND;
			this->update();
			ups++;
		}
		else
		{
			this->render();
			refresh();
			fps++;
		}
		if ((double)(clock() - timer) / CLOCKS_PER_SEC > 1.0f)
		{
			sprintf(str, "UPS: %d", ups);
			mvprintw(0, 0, str);
			sprintf(str, "FPS: %d", fps);
			mvprintw(1, 0, str);
			ups = 0;
			fps = 0;
			timer = clock();
		}
	}
	return;
}
