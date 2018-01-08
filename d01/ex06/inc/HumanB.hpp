/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 18:46:48 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{

public:

	HumanB(std::string name);
	~HumanB(void);

	void attack(void) const;
	std::string const &getName(void) const;
	void setName(std::string name);
	class Weapon const *getWeapon(void) const;
	void setWeapon(class Weapon &weapon);

private:

	std::string _name;
	class Weapon *_weapon;
};

# endif
