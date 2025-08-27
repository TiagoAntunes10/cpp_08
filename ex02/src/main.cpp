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

static void write_ite(MutantStack<int>::iterator it,
                      MutantStack<int>::iterator ite,
                      std::list<int>::iterator it_l) {
  while (it != ite) {
    std::cout << RED << *it << END << " = ";
    std::cout << GREEN << *it_l << END << std::endl;
    ++it;
    ++it_l;
  }
}

static void write_rite(MutantStack<int>::reverse_iterator rit,
                       MutantStack<int>::reverse_iterator rite,
                       std::list<int>::reverse_iterator rit_l) {
  while (rit != rite) {
    std::cout << RED << *rit << END << " = ";
    std::cout << GREEN << *rit_l << END << std::endl;
    ++rit;
    ++rit_l;
  }
}

int main(void) {
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::list<int> mlist;

  mlist.push_back(5);
  mlist.push_back(17);

  std::cout << BLUE << "STACK METHODS" << END << std::endl;
  std::cout << std::endl;

  std::cout << RED << "Mutant" << END << " | " << GREEN << "List" << END
            << std::endl;
  std::cout << RED << mstack.top() << END << " = ";
  std::cout << GREEN << mlist.back() << END << std::endl;
  mstack.pop();
  mlist.pop_back();
  std::cout << RED << mstack.size() << END << " = ";
  std::cout << GREEN << mlist.size() << END << std::endl;
  std::cout << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  mlist.push_back(3);
  mlist.push_back(5);
  mlist.push_back(737);
  mlist.push_back(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  std::list<int>::iterator it_l = mlist.begin();

  ++it;
  --it;

  ++it_l;
  --it_l;

  std::cout << BLUE << "ITERATOR METHODS" << END << std::endl;
  std::cout << std::endl;
  std::cout << RED << "Mutant" << END << " | " << GREEN << "List" << END
            << std::endl;
  write_ite(it, ite, it_l);
  std::cout << std::endl;

  std::stack<int> s(mstack);

  MutantStack<int>::reverse_iterator rit = mstack.rbegin();
  MutantStack<int>::reverse_iterator rite = mstack.rend();
  std::list<int>::reverse_iterator rit_l = mlist.rbegin();

  std::cout << BLUE << "REVERSE ITERATOR METHODS" << END << std::endl;
  std::cout << std::endl;
  std::cout << RED << "Mutant" << END << " | " << GREEN << "List" << END
            << std::endl;
  write_rite(rit, rite, rit_l);
  std::cout << std::endl;

  return 0;
}
