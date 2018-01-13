/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 16:00:51 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include "Input.hpp"

class Entity
{

public:

	class Point
	{
	public:

		Point(void);
		Point(int X, int Y);

		int x;
		int y;
	};

	Entity(void);
	Entity(int life, char name, int x, int y);
	Entity(int life, char name, Point pos);
	Entity(Entity const &src);
	virtual ~Entity(void);

	virtual Entity &operator=(Entity const &rhs);

	virtual void update(int input);

	bool isAlive(void) const;
	int getLife(void) const;
	void setLife(int life);
	char getName(void) const;
	void setName(char name);
	Point getPos(void) const;
	int getX(void) const;
	int getY(void) const;
	void setPos(Point pos);
	void setPos(int x, int y);

protected:

	bool _alive;//En vie ou pas (si non, DELETE)
	int _life;//Vie restante
	char _name;//Nom d'affichage (le char pour ncurse)
	Point _pos;//Position de l'entité
	//Movement class; ???
	//Colision class; ???
};

#endif
