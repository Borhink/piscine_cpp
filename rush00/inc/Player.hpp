/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/14 18:57:50 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Entity.hpp"
# include "Moveable.hpp"

class Player : public Entity, public Moveable
{

public:

	Player(int x, int y, Map &map);
	Player(Player const &src);
	virtual ~Player(void);

	virtual Player &operator=(Player const &rhs);

	virtual void update(Input &input);
	virtual void update(void);

	int getScore(void) const;
	void setScore(int score);
	void addScore(int score);

private:

	Player(void);
	void shoot(void);

	int _score;//Score du joueur
	float _fireRate;
	float _shootDelay;
	bool _shooting;
};

#endif
