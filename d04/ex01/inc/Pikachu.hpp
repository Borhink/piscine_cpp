/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pikachu.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 15:30:28 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIKACHU_HPP
# define PIKACHU_HPP

# include <iostream>
# include <string>
# include "Enemy.hpp"

class Pikachu : public Enemy
{

public:

	Pikachu(void);
	Pikachu(Pikachu const &src);
	virtual ~Pikachu(void);

	Pikachu &operator=(Pikachu const &rhs);

	virtual void takeDamage(int amount);
};

# endif
