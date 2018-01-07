/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 20:15:55 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <cstdlib>
# include "Zombie.hpp"

class ZombieHorde
{

public:

	ZombieHorde(int n);
	~ZombieHorde(void);

	void announce(void) const;

private:

	int _nbZombies;
	class Zombie *_horde;
	static const std::string _randomNames[8];
	static const std::string _randomTypes[8];
};

# endif
