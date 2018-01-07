/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/07 19:43:32 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <cstdlib>
# include "Zombie.hpp"

class ZombieEvent
{

public:

	ZombieEvent(void);
	~ZombieEvent(void);

	void setZombieType(std::string type);
	Zombie* newZombie(std::string name) const;
	Zombie* randomChump(void) const;

private:

	std::string _type;
	static const std::string _randomNames[8];
};

# endif
