/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:33:11 by tialbert          #+#    #+#             */
/*   Updated: 2025/08/21 15:22:14 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/includes.hpp"

Span::Span(void) {
  _filled = 0;
  _arr = NULL;
  _size = 0;
}

Span::Span(unsigned int n) {
  _filled = 0;
  _arr = new int[n];
  _size = n;
}

Span::Span(Span const &span) {
  this->_filled = span._filled;
  this->_size = span._size;
  this->_arr = new int[span._size];

  for (unsigned int i = 0; i < this->_filled; i++)
    this->_arr[i] = span._arr[i];
}

Span &Span::operator=(Span const &span) {
  this->_filled = span._filled;
  this->_size = span._size;
  this->_arr = new int[span._size];

  for (unsigned int i = 0; i < this->_filled; i++)
    this->_arr[i] = span._arr[i];

  return (*this);
}

Span::~Span(void) { delete[] _arr; }

void Span::addNumber(int n) {
  if (_filled >= _size)
    throw std::exception();
  _arr[_filled] = n;
  _filled++;
}

int Span::shortestSpan(void) {
  if (_filled <= 1)
    throw std::exception();

  int *cpy = new int[_filled];
  int diff = INT_MAX;

  std::copy(_arr, _arr + _filled, cpy);
  std::sort(cpy, cpy + _filled);

  for (unsigned int i = 1; i < _filled; i++) {
    if (diff > cpy[i] - cpy[i - 1]) {
      diff = cpy[i] - cpy[i - 1];
    }
    if (diff == 0)
      break;
  }

  delete[] cpy;
  return (diff);
}

int Span::longestSpan(void) {
  if (_filled <= 1)
    throw std::exception();

  int *max = std::max_element(_arr, _arr + _filled);
  int *min = std::min_element(_arr, _arr + _filled);

  return (*max - *min);
}
