/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:44 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/14 20:00:35 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Input.hpp"

Game::Game(void):
_run(true), _map(new Map(30, 150)), _player(new Player(3, 3, *(this->_map))),
_input(new Input()), _spawnRate(8.0f), _spawnDelay(1.0f)
{
	std::srand(std::time(0));
	this->_map->addEntity(this->_player, this->_player->getY(), this->_player->getX());
	return;
}

Game::Game(int x, int y):
_run(true), _map(new Map(y - 6, x - 4)), _player(new Player(3, 3, *(this->_map))),
_input(new Input()), _spawnRate(8.0f), _spawnDelay(1.0f)
{
	std::srand(std::time(0));
	this->_map->addEntity(this->_player, this->_player->getY(), this->_player->getX());
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
	std::stringstream strs;

	this->_map->draw();
	strs << "Score: " << this->_player->getScore();
	mvprintw(1, COLS / 2 - 10 , (char*)(strs.str().c_str()));
	strs.str("");
	strs << "Life: " << this->_player->getLife() << "   ";
	mvprintw(1, COLS / 2 + 10, (char*)(strs.str().c_str()));
	return;
}

void Game::update(void)
{
	if (this->_player->isAlive())
	{
		this->_player->update(*this->_input);
		this->_enemy_generator();
		this->_map->update();
		this->_map->update_background();
	}
	if (!this->_player->isAlive())
		mvprintw(3, COLS / 2, "GAME OVER");
	if (this->_input->getEntry(ESCAPE))
		this->_run = false;
	this->_input->clearEntries();
	return;
}

void Game::_enemy_generator(void)
{
	this->_spawnDelay += this->_spawnRate / UPS;
	if (this->_spawnDelay >= 1.0f)
	{
		this->_spawnDelay -= 1.0f;
		this->_create_enemy(1, 10);
	}
}

void Game::_create_enemy(int life, int score)
{
	int random;

	random = rand() % this->_map->getH();
	Entity *enemy = new Enemy(life, score, this->_map->getW() - 1, random, *this->_map);
	this->_map->addEntity(enemy, random, this->_map->getW() - 1);
}

void Game::run(void)
{
	clock_t update = clock();
	clock_t timer = clock();
	double elapsed = 0.0f;
	int ups = 0;
	int fps = 0;
	int key = 0;
	std::stringstream strs;

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
			strs.str("");
			strs << "UPS: " << ups;
			mvprintw(0, 0, (char*)(strs.str().c_str()));
			strs.str("");
			strs << "FPS: " << fps;
			mvprintw(1, 0, (char*)(strs.str().c_str()));
			ups = 0;
			fps = 0;
			timer = clock();
		}
	}
	return;
}
