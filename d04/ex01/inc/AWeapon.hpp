/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/11 17:27:55 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>

class AWeapon
{

public:

	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &src);
	~AWeapon(void);

	AWeapon &operator=(AWeapon const &rhs);

	std::string const &getName(void) const;
	void setName(std::string const &name);
	int getAPCost(void) const;
	void setAPCost(int const apcost);
	int getDamage(void) const;
	void setDamage(int const damage);

	virtual void attack(void) const = 0;

protected:

	AWeapon(void);

	std::string _name;
	int _apcost;
	int _damage;
};

# endif
