/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 19:57:51 by qhonore          ###   ########.fr       */
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

	int getScore(void) const;
	void setScore(int score);

private:

	Player(void);

	int _score;//Score du joueur
};

#endif
