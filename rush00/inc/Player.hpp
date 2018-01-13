/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/13 16:01:01 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Entity.hpp"

class Player : public Entity
{

public:

	Player(void);
	Player(int x, int y);
	Player(Player const &src);
	virtual ~Player(void);

	virtual Player &operator=(Player const &rhs);

	virtual void update(int input);

	int getScore(void) const;
	void setScore(int score);

private:

	int _score;//Score du joueur
};

#endif
