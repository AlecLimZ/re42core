/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:15:27 by jarthaud          #+#    #+#             */
/*   Updated: 2024/01/09 17:48:48 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
   	std::srand(time(0)); 
    Base	*base1 = generate();
	Base	*base2 = generate();
	Base	*base3 = generate();

    identify(base1);
	identify(base2);
	identify(base3);
	std::cout << "=================" << std::endl;
    identify(*base1);
	identify(*base2);
	identify(*base3);
    
    delete base1;
    delete base2;
    delete base3;
}
