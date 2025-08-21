/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:11:02 by tialbert          #+#    #+#             */
/*   Updated: 2025/08/21 15:15:47 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span {
public:
  Span(void);
  Span(unsigned int n);
  Span(Span const &span);
  Span &operator=(Span const &span);
  ~Span(void);
  void addNumber(int n);
  int shortestSpan(void);
  int longestSpan(void);
  template <class T> void fillSpan(T first, T last) {
    unsigned int array_size = last - first;

    if (array_size > _size || _filled == _size)
      throw std::exception();
    while (first != last) {
      addNumber(*first);
      first++;
    }
  };

private:
  unsigned int _size;
  unsigned int _filled;
  int *_arr;
};

#endif
