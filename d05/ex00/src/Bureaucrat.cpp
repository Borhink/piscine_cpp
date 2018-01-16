/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:03:58 by qhonore           #+#    #+#             */
/*   Updated: 2018/01/15 19:45:26 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):
_name("Default"),
_grade(1)
{
	return;
}

Bureaucrat::Bureaucrat(std::string name):
_name(name),
_grade(1)
{
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat &Bureaucrat::operator++(void)
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	else
		this->_grade--;
	return (*this);
}

Bureaucrat &Bureaucrat::operator--(void)
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	else
		this->_grade++;
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat bureaucrat(*this);

	if (this->_grade <= 1)
		throw GradeTooHighException();
	else
		this->_grade--;
	return (bureaucrat);
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat bureaucrat(*this);

	if (this->_grade >= 150)
		throw GradeTooLowException();
	else
		this->_grade++;
	return (bureaucrat);
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	else
		this->_grade--;
	return;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	else
		this->_grade++;
	return;
}

std::string const &Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
	return;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return;
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (o);
}
