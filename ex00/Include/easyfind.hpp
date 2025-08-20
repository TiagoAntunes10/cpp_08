/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:13:16 by tialbert          #+#    #+#             */
/*   Updated: 2025/08/20 11:57:30 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_HPP
#define EASY_HPP

#include <algorithm>
#include <exception>
#include <iostream>

template <class T> bool easyfind(const T &cont, const int &val) {
  if (std::find(cont.begin(), cont.end(), val) == cont.end())
    throw std::exception();

  return (true);
}

#endif
