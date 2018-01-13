/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 20:31:55 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include "Input.hpp"

class Map;

class Entity
{

public:

	class Point
	{
	public:

		Point(void);
		Point(float X, float Y);

		float x;
		float y;
	};

	Entity(int life, char name, float x, float y, Map &map);
	Entity(int life, char name, Point pos, Map &map);
	Entity(Map &map);
	Entity(Entity const &src);
	virtual ~Entity(void);

	virtual Entity &operator=(Entity const &rhs);

	virtual void update(Input &input);

	bool isAlive(void) const;
	int getLife(void) const;
	void setLife(int life);
	char getName(void) const;
	void setName(char name);
	Point getPos(void) const;
	int getX(void) const;
	int getY(void) const;
	float getXF(void) const;
	float getYF(void) const;
	void setPos(Point pos);
	void setPos(float x, float y);
	Map &getMap(void) const;

protected:

	bool _alive;//En vie ou pas (si non, DELETE)
	int _life;//Vie restante
	char _name;//Nom d'affichage (le char pour ncurse)
	Point _pos;//Position de l'entité
	Map &_map;

private:

	Entity(void);
};

#endif
