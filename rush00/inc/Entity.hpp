/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/14 18:52:39 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include <string>
# include "Input.hpp"

enum EntityType
{
	ENTITY = 0,
	PLAYER,
	ENEMY,
	PROJECTILE,
	E_PROJECTILE,
	P_PROJECTILE,

	NB_ENTITY_TYPE
};

# define PATTERN_SIZE 3

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

	Entity(int type, int life, char name, float x, float y, Map &map);
	Entity(int type, int life, char name, Point pos, Map &map);
	Entity(Map &map);
	Entity(Entity const &src);
	virtual ~Entity(void);

	virtual Entity &operator=(Entity const &rhs);

	virtual void update(void);

	bool takeDamage(int damage);
	int getType(void) const;
	void setType(int type);
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
	void setX(float x);
	void setY(float y);
	void moveX(float x);
	void moveY(float y);
	Map &getMap(void) const;

	static int nbEntities;

protected:

	int _type;//Nom d'affichage (le char pour ncurse)
	bool _alive;//En vie ou pas (si non, DELETE)
	int _life;//Vie restante
	char _name;//Nom d'affichage (le char pour ncurse)
	Point _pos;//Position de l'entité
	Map &_map;

private:

	Entity(void);
};

#endif
