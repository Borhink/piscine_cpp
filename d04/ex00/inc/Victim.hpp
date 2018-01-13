/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/12 15:08:47 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{

public:

	Victim(std::string const &name);
	Victim(Victim const &src);
	virtual ~Victim(void);

	Victim &operator=(Victim const &rhs);

	virtual void getPolymorphed(void) const;

	std::string const &getName(void) const;
	void setName(std::string const &name);

protected:
	Victim(void);

	std::string _name;
};

std::ostream &operator<<(std::ostream &o, Victim const &rhs);

# endif
