/* Copyright (c) 2018 Allen Wu. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*******************
 * @author allen wu
 * @date   2018-06-17
 * @file   lib/libstd/Comparable.hpp
 * @brief  template class Comparabel
 *******************/
#ifndef ALLENOS_LIBSTD_COMPARABLE_HPP
#define ALLENOS_LIBSTD_COMPARABLE_HPP

#include "Types.hpp"

/**
 * @brief Objects which can be campared to each other.
 */
template <typename T> class Comparable {
 public:
    /**
     * @brief Class destuctor.
     */
    virtual ~Comparable() {}

    /**
     * @brief Test if an object is equal to an other object.
     */
    virtual bool equals(const T &t) const {
        return compareTo(t) == 0;
    }

    /**
     * @brief Compares this Comparable to the given Comparable
     * @note This function checks whether this Comparable is equal to,
     *       less, or greater than the given Comparable.
     * @param c The Comparable to compare us to.
     * @return an int '< 0', '0', '> 0' if we are respectively less than,
     *         equal to or greater than the given Comparable.
     */
    virtual int compareTo(const T &c) const = 0;

};  // class Comparable

#endif  // ALLENOS_LIBSTD_COMPARABLE_HPP
