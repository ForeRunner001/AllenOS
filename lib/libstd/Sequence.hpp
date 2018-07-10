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
 * @date   2018-05-13
 * @file   lib/libstd/Sequence.hpp
 * @brief  template class Sequence
 *******************/

#ifndef ALLENOS_LIBSTD_SEQUENCE_HPP
#define ALLENOS_LIBSTD_SEQUENCE_HPP

#include "Container.hpp"
#include "Comparable.hpp"
#include "Types.hpp"
#include "Macros.hpp"

/**
 * @brief Sequence are containers that provide indexed based storage of items.
 */
template <typename T> class Sequence : public Container, public Comparable<Sequence<T>> {
 public:
    /**
     * @brief Adds the given item to the Sequence, if possible.
     * @param item The item to add to the Sequence.
     * @return Position of the item in Sequence or -1 on failure.
     */
    virtual int insert(const T &item) {
        return -1;
    }

    /**
     * @brief Inserts the given item at the given position.
     * @note If an item exists at the given position, it will be replaced
     *       by the given item.
     * @param position The position to insert the item.
     * @param item The item to insert.
     * @return bool Whether inserting the item at the given position succeeded.
     */
    virtual bool insert(Size position, const T &item) {
        return false;
    }

    /**
     * @brief Fill the Sequence with the given value.
     * @param value New value to fill the Sequence.
     */
    virtual void fill(T value) {
        Size s = this->size();
        for (Size i = 0; i < s; i++) {
            insert(i, value);
        }
    }

    /**
     * @brief Remove all items with the given value.
     * @param value Value to remove.
     * @return Number of items removed.
     */
    virtual int remove(T value) {
        return 0;
    }

    /**
     * @brief Remove the item at the given position.
     * @param position The position of the item to remove.
     * @return bool Whether removing the item succeeded.
     */
    virtual bool removeAt(Size position) {
        return false;
    }

    /**
     * @brief Remove all items from the Sequence.
     */
    virtual void clear() {
        Size s = this->size();
        for (Size i = 0; i < s; ++i) {
            removeAt(i);
        }
    }

    /**
     * @brief Return the item at the given position.
     * @param position The position of the item to get.
     * @return Pointer to the item at the given position or ZERO if no item available.
     */
    virtual const T* get(Size position) const = 0;

    /**
     * @brief Return a reference to the item at the given position.
     * @note Note that this function does not perform bounds checking.
     *       Position must be a valid index.
     * @param position Valid index inside this array.
     * @return Reference to the item at the given position.
     */
    virtual const T& at(Size position) const = 0;

    /**
     * @brief Check if the given item is stored in this Sequence.
     */
    virtual bool contains(const T value) const {
        Size sz = this->size();
        for (Size i = 0; i < sz; ++i) {
            if(at(i) == value) {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Compare this Sequence to another Sequence.
     */
    virtual int compareTo(const Sequence<T> &s) const {
        Size sz  = this->size();
        Size cnt = this->count();
        // Size must be equal
        if (s.size() != sz) {
            return s.size() - sz;
        }
        // Count must be equal
        if (s.count() != cnt) {
            return s.count() - cnt;
        }
        // All elements must be equal
        for (Size i = 0; i < cnt; ++i) {
            if (at(i) != s.at(i)) {
                return i+1;
            }
        }
        return 0;
    }

    /**
     * @brief Return the item at the given position in the Sequence.
     * @param i The index of the item to return.
     * @retuen The item at position i.
     */
    const T& operator [](int i) const {
        return at(i);
    }

    T& operator [](int i) {
        return (T&)at(i);
    }

    const T& operator [](Size i) const {
        return at(i);
    }

    T& operator [](Size i) {
        return (T&)at(i);
    }

};  // class Sequence

#endif  // ALLENOS_LIBSTD_SEQUENCE_HPP
