/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:04:23 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/15 19:44:42 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{

public:

	class GradeTooHighException : public std::exception
	{

	public:

		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const &src);
		virtual ~GradeTooHighException(void) throw();

		GradeTooHighException &operator=(GradeTooHighException const &rhs);

		virtual char const *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{

	public:

		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const &src);
		virtual ~GradeTooLowException(void) throw();

		GradeTooLowException &operator=(GradeTooLowException const &rhs);

		virtual char const *what() const throw();
	};

	Bureaucrat(void);
	Bureaucrat(std::string name);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);

	Bureaucrat &operator=(Bureaucrat const &rhs);
	Bureaucrat &operator++(void);
	Bureaucrat &operator--(void);
	Bureaucrat operator++(int);
	Bureaucrat operator--(int);

	void incrementGrade(void);
	void decrementGrade(void);

	std::string const &getName(void) const;
	int getGrade(void) const;

private:

	std::string const _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
