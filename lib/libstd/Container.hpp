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
 * @date   2018-06-08
 * @file   lib/libstd/Container.hpp
 * @brief  class Container
 *******************/

#ifndef ALLENOS_LIBSTD_CONTAINER_HPP
#define ALLENOS_LIBSTD_CONTAINER_HPP

#include "Types.hpp"

/**
 * @brief Container provide access to stored items.
 */
class Container {
 public:
    /**
     * @brief Constructor.
     */
    Container();

    /**
     * @brief Destructor.
     */
    virtual ~Container();

    /**
     * @brief Returns the maximum size of this Container.
     * @return Size The maximum size of this Container.
     */
    virtual Size size() const = 0;

    /**
     * @brief Returns the number of items inside the Container.
     * @return Size Number of items inside the Container.
     */
    virtual Size count() const = 0;

    /**
     * @brief Removes all items from the Container.
     */
    virtual void clear() = 0;

    /**
     * @brief Check if the Container is empty.
     * @return bool
     *  - true  if empty
     *  - false otherwise
     */
    virtual bool isEmpty() const;

    /**
     * @brief Ensure that at least the given size is availabel.
     * @param[in] size Size to reserve in the Container.
     * @return bool
     *     - true  if the given size is reserved
     *     - false otherwise
     */
    virtual bool reserve(Size size);

    /**
     * @brief Shrink the container size by the given amount of items.
     * @param[in] size Number of items to shrink.
     * @return bool
     *  - true  if shrink succeeded
     *  - false otherwise
     */
    virtual bool shrink(Size size);

    /**
     * @brief Try to minimize the memory required in the Container.
     * return Size New size of the Container.
     */
    virtual Size squeeze();

    /**
     * @brief Change the size of the Container.
     * @param[in] size New size of the Container.
     * @return bool
     *  - true  if the resize succeeded
     *  - false otherwise
     */
    virtual bool resize(Size size);
}; /* class Container */


#endif /*ALLENOS_LIBSTD_CONTAINER_HPP*/
