/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/14 20:09:40 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include "Entity.hpp"
# include "Moveable.hpp"

class Projectile : public Entity, public Moveable
{

public:

	Projectile(void);
	Projectile(Entity *parent, int damage, int dir, int x, int y, Map &map);
	Projectile(Entity *parent, int type, int damage, int dir, int x, int y, Map &map);
	Projectile(Projectile const &src);
	virtual ~Projectile(void);

	virtual Projectile &operator=(Projectile const &rhs);

	virtual void update(void);

	int getDamage(void) const;
	void setDamage(int damage);
	virtual Entity *getParent(void);

protected:

	Entity *_parent;
	int _damage;
	int _dir;
};

#endif
