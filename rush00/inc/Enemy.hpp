/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 12:53:48 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Entity.hpp"

class Enemy : public Entity
{

public:

	Enemy(void);
	Enemy(int life, int score, int x, int y);
	Enemy(Enemy const &src);
	virtual ~Enemy(void);

	virtual Enemy &operator=(Enemy const &rhs);

	int getScore(void) const;
	void setScore(int score);

private:

	int _score;//Score que l'ennemi rapporte
};

#endif
