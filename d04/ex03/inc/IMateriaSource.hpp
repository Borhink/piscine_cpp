/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:47:32 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/12 13:47:46 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{

public:

	virtual ~IMateriaSource(void) {}

	virtual void learnMateria(AMateria *materia) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
