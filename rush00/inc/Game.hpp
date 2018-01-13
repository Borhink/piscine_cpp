/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 17:00:39 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <ncurses.h>
# include <ctime>
# include "Input.hpp"
// # include "Map.hpp"

# define TICK_PER_SECOND (1.0f / 60.0f)

class Game
{

public:

	Game(void);
	Game(Game const &src);
	~Game(void);

	Game &operator=(Game const &rhs);

	void render(void) const;
	void update(void);
	void run(void);

private:

	bool _run;
	// Map *_map;
};

#endif
