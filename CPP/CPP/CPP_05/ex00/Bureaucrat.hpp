/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:45:07 by jarthaud          #+#    #+#             */
/*   Updated: 2023/12/29 15:17:21 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <typeinfo>

class Bureaucrat {
	private:
		unsigned int 	_grade;
		std::string		_name;
		
	public:
		Bureaucrat( void );  // constructeur par defaut
		Bureaucrat( std::string name, unsigned int grade ); // constructeur par defaut
		Bureaucrat( Bureaucrat const &rhs ); // constructeur de recopie
		~Bureaucrat( void ); //destructeur
		Bureaucrat &operator=( const Bureaucrat &rhs); // operateur d affectation
	
		std::string const 	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();	

		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Grade is too high!");
			}
		};
		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Grade is too low!");
			}
		};
};

std::ostream &operator<<( std::ostream &out, Bureaucrat const &rhs );

#endif