/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:52:27 by tialbert          #+#    #+#             */
/*   Updated: 2025/08/25 15:15:45 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_HPP
#define MUTANT_HPP

#include <deque>
#include <stack>

template <class T, class Container = std::stack<T> >
class MutantStack : public std::stack<T> {
public:
  typedef typename std::deque<T>::iterator iterator;

  iterator begin(void) { return (Container::c.begin()); };
  iterator end(void) { return (Container::c.end()); };
  iterator rbegin(void) { return (Container::c.rbegin()); };
  iterator rend(void) { return (Container::c.rend()); };
  iterator cbegin(void) { return (Container::c.cbegin()); };
  iterator cend(void) { return (Container::c.cend()); };
  iterator crbegin(void) { return (Container::c.crbegin()); };
  iterator crend(void) { return (Container::c.crend()); };
};
#endif
