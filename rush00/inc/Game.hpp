/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/14 20:02:34 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <ncurses.h>
# include <ctime>
# include <sstream>
# include "Map.hpp"

class Player;
class Enemy;
class Input;

# define UPS 60.0f
# define TICK_PER_SECOND (1.0f / UPS)

class Game
{

public:

	Game(void);
	Game(int x, int y);
	Game(Game const &src);
	~Game(void);

	Game &operator=(Game const &rhs);

	void run(void);

private:

	void render(void) const;
	void update(void);
	void _create_enemy(int life, int score);
	void _enemy_generator(void);

	bool _run;
	Map *_map;
	Player *_player;
	Input *_input;
	float _spawnRate;
	float _spawnDelay;
};

#endif
