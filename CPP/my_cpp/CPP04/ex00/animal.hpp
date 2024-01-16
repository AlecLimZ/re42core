/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:04:17 by leng-chu          #+#    #+#             */
/*   Updated: 2022/08/01 13:58:09 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "color.hpp"

class	Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(Animal const & src);
		Animal & operator=(Animal const & rhs);

		std::string getType(void) const;
		void setType(std::string n);

		virtual void makeSound() const;
};

class	Cat: public Animal
{
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const & src);
		Cat & operator=(Cat const & rhs);

		virtual void makeSound() const;
};

class	Dog: public Animal
{
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const & src);
		Dog & operator=(Dog const & rhs);

		virtual void makeSound() const;
};

#endif
