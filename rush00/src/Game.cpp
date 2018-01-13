/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 20:41:36 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Player.hpp"
#include "Input.hpp"

Game::Game(void):
_run(true), _map(new Map(50, 200)), _player(new Player(2, 2, *(this->_map))),
_input(new Input())
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
	delete this->_map;
	delete this->_player;
	delete this->_input;
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
	int x = this->_player->getX();
	int y = this->_player->getY();
	char tab[2] = {this->_player->getName(), 0};
	char str[1000] = "";

	this->_map->draw();
	sprintf(str, "Pos: x%f, y%f", this->_player->getXF(), this->_player->getYF());
	mvprintw(4, 0, str);

	mvprintw(y, x, tab);
	return;
}

void Game::update(void)
{
	this->_player->update(*this->_input);
	if (this->_input->getEntry(ESCAPE))
		this->_run = false;
	this->_map->update();
	this->_input->clearEntries();
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
	int key = 0;

	while (this->_run)
	{
		elapsed += (double)(clock() - update) / CLOCKS_PER_SEC;
		update = clock();
		while ((key = getch()) != ERR)
			this->_input->setEntry(key, true);
		if (elapsed > TICK_PER_SECOND)
		{
			elapsed -= TICK_PER_SECOND;
			this->update();
			ups++;
		}
		else
		{
			this->render();
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
