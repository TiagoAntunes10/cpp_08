/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:13:04 by tialbert          #+#    #+#             */
/*   Updated: 2025/08/20 14:49:04 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/includes.hpp"
#include <deque>
#include <list>
#include <vector>

template <class T> void tests(T container) {
  std::cout << GREEN << " ELEMENTS IN THE CONTAINER" << END << std::endl;
  std::cout << std::endl;

  for (int i = 1; i <= 5; i++) {
    std::cout << BLUE << "  Element " << i << " found: " << END;
    try {
      std::cout << easyfind(container, i) << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  std::cout << RED << " ELEMENTS NOT IN THE CONTAINER" << END << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "  Element 6 found: " << END;
  try {
    std::cout << easyfind(container, 6) << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

int main(void) {
  {
    std::vector<int> vec(1, 1);

    for (int i = 2; i <= 5; i++) {
      vec.insert(vec.end(), i);
    }

    std::cout << YELLOW << "######### VECTOR ###########" << END << std::endl;
    std::cout << std::endl;
    tests(vec);
  }

  {
    std::deque<int> q(1, 1);

    for (int i = 2; i <= 5; i++) {
      q.insert(q.end(), i);
    }

    std::cout << std::endl;
    std::cout << YELLOW << "########## DEQUE ###########" << END << std::endl;
    std::cout << std::endl;
    tests(q);
  }

  {
    std::list<int> l(1, 1);

    for (int i = 2; i <= 5; i++) {
      l.insert(l.end(), i);
    }

    std::cout << std::endl;
    std::cout << YELLOW << "########### LIST ###########" << END << std::endl;
    std::cout << std::endl;
    tests(l);
  }
}
