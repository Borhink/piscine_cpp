/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:47:48 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/12 13:59:25 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "Ice.hpp"
# include "Cure.hpp"
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

public:

	MateriaSource(void);
	MateriaSource(const MateriaSource &src);
	~MateriaSource(void);

	MateriaSource &operator=(const MateriaSource &rhs);

	virtual void learnMateria(AMateria *materia);
	virtual AMateria *createMateria(std::string const &type);

private:

	AMateria *_materias[4];
};

#endif
