/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:46:47 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/12 13:13:23 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <cstdlib>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{

public:

	Character(void);
	Character(std::string const &name);
	Character(Character const &src);
	~Character(void);

	Character &operator=(Character const &rhs);

	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);

	virtual std::string const &getName(void) const;

private:

	AMateria *_materias[4];
	std::string _name;
};

#endif
