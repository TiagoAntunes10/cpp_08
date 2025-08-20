/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:33:11 by tialbert          #+#    #+#             */
/*   Updated: 2025/08/20 16:04:23 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/includes.hpp"
#include <algorithm>
#include <exception>

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

// TODO: Correct this function
int Span::shortestSpan(void) {
  if (_filled <= 1)
    throw std::exception();

  int *max = std::max_element(_arr, _arr + _filled - 1);
  int *min = std::min_element(_arr, _arr + _filled - 1);

  return (*max - *min);
}

int Span::longestSpan(void) {
  if (_filled <= 1)
    throw std::exception();

  int *max = std::max_element(_arr, _arr + _filled - 1);
  int *min = std::min_element(_arr, _arr + _filled - 1);

  return (*max - *min);
}

template <class T> void Span::fillSpan(T first, T last) {
  unsigned int array_size = last - first;

  if (array_size > _size || _filled == _size)
    throw std::exception();
  for (unsigned int i = 0; i < array_size; i++) {
    if (_filled >= _size)
      throw std::exception();
    _arr[_filled] = *(first + i);
    _filled++;
  }
}
