/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:24:46 by tialbert          #+#    #+#             */
/*   Updated: 2025/08/25 15:14:21 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/includes.hpp"
#include <list>

int main(void) {
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::list<int> mlist;

  mlist.push_back(5);
  mlist.push_back(17);

  std::cout << RED << "Mutant" << END << " | " << GREEN << "List" << END
            << std::endl
            << std::endl;
  std::cout << RED << mstack.top() << END << " = ";
  std::cout << GREEN << mlist.back() << END << std::endl;
  mstack.pop();
  mlist.pop_back();
  std::cout << RED << mstack.size() << END << " = ";
  std::cout << GREEN << mlist.size() << END << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);

  mlist.push_back(3);
  mlist.push_back(5);
  mlist.push_back(737);
  //[...]
  mlist.push_back(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  std::list<int>::iterator it_l = mlist.begin();

  ++it;
  --it;

  ++it_l;
  --it_l;

  while (it != ite) {
    std::cout << RED << *it << END << " = ";
    std::cout << GREEN << *it_l << END << std::endl;
    ++it;
    ++it_l;
  }

  std::stack<int> s(mstack);
  return 0;
}
