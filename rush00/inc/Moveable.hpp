/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moveable.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/14 19:24:06 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEABLE_HPP
# define MOVEABLE_HPP

# include "Input.hpp"
# include "Map.hpp"
# include "Game.hpp"

# define DIR_UP 0
# define DIR_DOWN 1
# define DIR_RIGHT 2
# define DIR_LEFT 3

class Moveable
{

public:

	Moveable(void);
	Moveable(int speed);
	Moveable(Moveable const &src);
	~Moveable(void);

	Moveable &operator=(Moveable const &rhs);

	bool collide(Entity *e, int x, int y, Map &map);
	bool canMove(Entity *e, int dir, Map &map);
	void moveTarget(Entity *e, int dir, Map &map, bool isMap);
	void move(Entity *e, int dir, Map &map);

protected:

	float _speed;
};

#endif
