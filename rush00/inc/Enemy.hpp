/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/14 18:19:37 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Entity.hpp"
# include "Moveable.hpp"

class Enemy : public Entity, public Moveable
{

public:

	Enemy(int life, int score, int x, int y, Map &map);
	Enemy(Enemy const &src);
	virtual ~Enemy(void);

	virtual Enemy &operator=(Enemy const &rhs);

	virtual void update(void);

	void shoot(void);

	int getScore(void) const;
	void setScore(int score);

private:

	Enemy(void);

	int _score;//Score que l'ennemi rapporte
	float _fireRate;
	float _shootDelay;
};

#endif
