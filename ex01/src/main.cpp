/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:09:17 by tialbert          #+#    #+#             */
/*   Updated: 2025/08/21 15:29:42 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/includes.hpp"
#include <cstdlib>
#include <ctime>

void big_test(void) {
  unsigned int size = 2000000;
  int arr[size + 1];
  Span sp = Span(size);

  std::srand(time(0));
  for (unsigned int i = 0; i < size; i++)
    arr[i] = std::rand() % size + 1;

  sp.fillSpan(arr, arr + size);

  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

int main(void) {
  Span sp = Span(5);

  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  std::cout << std::endl;

  big_test();

  return 0;
}
