/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 18:53:08 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:

	typedef void (FragTrap::*funcPtr)(std::string const &);

	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void atomicBeam(std::string const &target);
	void fireBall(std::string const &target);
	void killProcess(std::string const &target);
	void vaulthunter_dot_exe(std::string const &target);

	FragTrap &operator=(FragTrap const &rhs);

	int getAtomicBeamDamage(void) const;
	void setAtomicBeamDamage(int const val);

private:

	int _atomicBeamDamage;
	static funcPtr const _functions[5];
};

# endif
