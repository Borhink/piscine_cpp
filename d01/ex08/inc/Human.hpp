/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/09 13:53:12 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <string>

class Human
{

public:
	typedef void (Human::*funcPtr)(std::string const &);

	Human(std::string name);
	~Human(void);
	void action(std::string const & action_name, std::string const & target);
	std::string const &getName(void) const;

private:

	void meleeAttack(std::string const & target);
	void rangedAttack(std::string const & target);
	void intimidatingShout(std::string const & target);
	void atomicBeam(std::string const & target);

	std::string _name;
	static funcPtr const _functions[4];
	static std::string const _functionsName[4];
};

# endif
