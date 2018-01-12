/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 13:33:11 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy
{

public:

	Enemy(int hp, std::string const &type);
	Enemy(Enemy const &src);
	virtual ~Enemy(void);

	Enemy &operator=(Enemy const &rhs);

	virtual void takeDamage(int amount);

	std::string const &getType(void) const;
	void setType(std::string const &type);
	int getHP(void) const;
	void setHP(int hp);

protected:

	Enemy(void);

	std::string _type;
	int _hp;
};

# endif
