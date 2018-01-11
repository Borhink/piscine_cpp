/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/11 17:31:45 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <cstddef>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{

public:

	Character(std::string const &name);
	Character(Character const &src);
	~Character(void);

	Character &operator=(Character const &rhs);

	void recoverAP(void);
	void equip(AWeapon *weapon);
	void attack(Enemy *enemy);

	std::string const &getName(void) const;
	void setName(std::string const &name);
	int getAP(void) const;
	void setAP(int const ap);
	AWeapon const *getWeapon(void) const;

protected:

	Character(void);

	std::string _name;
	int _ap;
	AWeapon *_weapon;
};

std::ostream &operator<<(std::ostream &o, Character const &rhs);

# endif
