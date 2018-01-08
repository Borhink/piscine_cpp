/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:20:55 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/08 18:47:40 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include "Brain.hpp"

class Human
{

public:

	Human(void);
	~Human(void);

	std::string identify(void) const;
	class Brain const &getBrain(void) const;

private:

	class Brain const _brain;
};

# endif
