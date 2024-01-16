/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:48:39 by leng-chu          #+#    #+#             */
/*   Updated: 2022/07/25 15:02:57 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap b("Jack");

	while (b.getHp() > 0)
	{
		b.attack("MonsterEvil");
		b.takeDamage(7);
		b.beRepaired(2);
	}
	while (a.getEp() > 0)
	{
		a.attack("BigAnt");
		a.beRepaired(3);
	}
	a.attack("BigAnt");
	a.beRepaired(3);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << ">>>after " << a.getName() << " copy " << b.getName() << "<<<\n" << std::endl;
	a = b;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	return (0);
}
