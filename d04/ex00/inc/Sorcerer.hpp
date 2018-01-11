/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/11 14:02:19 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer
{

public:

	Sorcerer(std::string const &name, std::string const &title);
	Sorcerer(Sorcerer const &src);
	~Sorcerer(void);

	Sorcerer &operator=(Sorcerer const &rhs);

	void polymorph(Victim const &victim) const;

	std::string const &getName(void) const;
	void setName(std::string const &name);
	std::string const &getTitle(void) const;
	void setTitle(std::string const &title);

private:
	Sorcerer(void);

	std::string _name;
	std::string _title;
};

std::ostream &operator<<(std::ostream &o, Sorcerer const &rhs);

# endif
