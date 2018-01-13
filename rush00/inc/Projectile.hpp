/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 19:21:00 by qhonore          ###   ########.fr       */
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
	Projectile(int damage, int x, int y, Map &map);
	Projectile(Projectile const &src);
	virtual ~Projectile(void);

	virtual Projectile &operator=(Projectile const &rhs);

	int getDamage(void) const;
	void setDamage(int damage);

protected:

	int _damage;
};

#endif
