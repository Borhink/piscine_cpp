/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:33:59 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/12 13:08:13 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria
{

public:

	AMateria(void);
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	~AMateria(void);

	AMateria &operator=(AMateria const &rhs);

	virtual AMateria *clone(void) const = 0;
	virtual void use(ICharacter &target) = 0;

	unsigned int getXP(void) const;
	std::string const &getType(void) const;

protected:

	unsigned int _xp;
	std::string _type;
};

#endif
