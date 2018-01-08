/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 18:46:45 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{

public:

	HumanA(std::string name, class Weapon &weapon);
	~HumanA(void);

	void attack(void) const;
	std::string const &getName(void) const;
	void setName(std::string name);
	class Weapon const &getWeapon(void) const;

private:

	std::string _name;
	class Weapon &_weapon;
};

# endif
