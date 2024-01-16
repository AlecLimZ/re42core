/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:51:20 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/12 19:29:34 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT
#include "lib.hpp"
#include "vector.hpp"
#include "doctest.hpp"

int	doc(int *ac, char **av)
{
	doctest::Context context;
	context.addFilter("test-case-exclude", "*math*");
	context.setOption("abort-after", 5);
	context.setOption("order-by", "name");
	context.applyCommandLine(*ac, av);
	context.setOption("no-breaks", true);
	int res = context.run();
	if (context.shouldExit())
		return res;
	int client_stuff_return_code = 0;
	return (res + client_stuff_return_code);
}

void	test(void)
{
	std::vector<int> vstd;
	ft::Vector<int> vft;
	for (int i = 1; i <= 20; i++)
	{
		vstd.push_back(i);
		vft.push_back(i);
	}
	
	typedef std::vector<int>::const_iterator	stditer;
	ft::Vector<int>::const_iterator	vit = vft.begin();
	ft::Vector<int>::const_iterator	vite = vft.end();
	stditer sit = vstd.begin();
	stditer site = vstd.end();

	cout << "std iterator" << endl;
	int i = 0;
	while (sit != site)
		cout << ++i << ": " << *++sit << "| ";
	cout << endl;

	i = 0;
	cout << "my ft iterator" << endl;
	while (vit != vite)
		cout << ++i << ": " << *++vit << "| ";
	cout << endl;
}

int main(int argc, char **argv)
{
	test();
#ifdef noasan
	system("leaks main");
#endif
	return (doc(&argc, argv));
}
