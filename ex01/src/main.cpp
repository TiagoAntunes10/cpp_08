/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:09:17 by tialbert          #+#    #+#             */
/*   Updated: 2025/09/02 09:36:59 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/includes.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

void big_test(void) {
  unsigned int size = 300000;
  int arr[size + 1];
  Span sp = Span(size);

  std::srand(time(0));
  for (unsigned int i = 0; i < size; i++)
    arr[i] = std::rand() % size + 1;

  sp.fillSpan(arr, arr + size);

  std::cout << BLUE << "Shortest span: " << END << sp.shortestSpan()
            << std::endl;
  std::cout << BLUE << "Longest span: " << END << sp.longestSpan() << std::endl;
}

int main(void) {
  Span sp = Span(5);

  std::cout << YELLOW << "SMALL ARRAY TESTS" << END << std::endl;
  std::cout << std::endl;

  try {
    sp.shortestSpan();
  } catch (std::exception &e) {
    std::cout << RED << "Shortest Span without numbers stored: " << END
              << e.what() << std::endl;
  }

  try {
    sp.longestSpan();
  } catch (std::exception &e) {
    std::cout << RED << "Longest Span without numbers stored: " << END
              << e.what() << std::endl;
  }

  sp.addNumber(6);

  try {
    sp.shortestSpan();
  } catch (std::exception &e) {
    std::cout << RED << "Shortest Span with 1 number stored: " << END
              << e.what() << std::endl;
  }

  try {
    sp.longestSpan();
  } catch (std::exception &e) {
    std::cout << RED << "Longest Span with 1 number stored: " << END << e.what()
              << std::endl;
  }

  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  try {
    sp.addNumber(100);
  } catch (std::exception &e) {
    std::cout << RED
              << "Trying to add a new number after exceeding capacity: " << END
              << e.what() << std::endl;
  }

  std::cout << std::endl;

  std::cout << BLUE << "Shortest span: " << END << sp.shortestSpan()
            << std::endl;
  std::cout << BLUE << "Longest span: " << END << sp.longestSpan() << std::endl;
  std::cout << std::endl;

  std::cout << YELLOW << "BIG ARRAY TESTS" << END << std::endl;
  std::cout << std::endl;
  big_test();

  return 0;
}
