/* Copyright (c) 2018 Allen Wu. All rights reserved.
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
 * @date   2018-06-06
 * @file   lib/libstd/Assert.hpp
 * @brief  
 */

#ifndef ALLENOS_LIBSTD_ASSERT_HPP
#define ALLENOS_LIBSTD_ASSERT_HPP

#if defined(__ASSERT__) && !defined(__HOST__)

#include "Macros.hpp"
#include "Types.hpp"

#ifdef __SERVER__
#include <LogMessage.h>
#include <stdlib.h>
#endif /* __SERVER__ */

/**
 * @brief Runtime functions
 * @{
 */

/**
 * @brief Function which prints a message, and then terminates itself
 * @param fmt Formatted message.
 * @param ... Argument list.
 */
extern C void __assertFailure(const char *fmt, ...);

/**
 * @brief Verify that the given address is readable.
 * @param addr Address to verify.
 */
extern C int __assertRead(Address addr);

/**
 * @brief Verify that the given address is writeable.
 * @param addr Address to verify.
 */
extern C int __assertWrite(Address addr);

/**
 * @}
 */ /* Runtime functions */

/**
 * @brief Preprocessor macros
 * @{
 */

/**
 * @brief Invokes __assertFailure for applications, and log() + exit() for servers.
 * @param fmt Formatted string.
 * @param ... Argument list.
 * @return Never.
 */
#ifdef __SERVER__
#define raiseFailure(fmt, ...) \
    log(fmt, ##__VA_ARGS__); \
    exit(1);
#else
#define raiseFailure(fmt, ...) \
    __assertFailure(fmt, ##__VA_ARGS__);
#endif /* __SERVER__ */

/**
 * @brief Verify that a given expression evaluates to true.
 * @param exp Boolean expression.
 */
#define assert(exp) \
    if (!(exp)) \
    { \
        raiseFailure("[%s:%d]: *** Assertion `%s' failed ***\n", \
                    __FILE__, __LINE__, #exp); \
    }

/**
 * @brief Presume that the given address is readable.
 * @param addr Address to check.
 */
#define assertRead(addr) \
    assert(__assertRead((Address)addr))

/**
 * @brief Presume that the given address is writeable.
 * @param addr Address to check.
 */
#define assertWrite(addr) \
    assert(__assertWrite((Address)addr))

/**
 * @}
 */ /* Preprocessor macros */

#else

/**
 * @brief Dummy preprocessor macros
 * @{
 */

/**
 * @brief Dummy assertion function which does not perform any check.
 * @param exp Expression is ignored.
 */
#define assert(exp)

/**
 * @brief Dummy assertion function for checking read access on an address.
 * @param addr Address is ignored.
 */
#define assertRead(addr)

/**
 * @brief Dummy assertion function for checking write access on an address.
 * @param addr Address is ignored.
 */
#define assertWrite(addr)
/**
 * @}
 */ /* Dummy preprocessor macros  */

#endif /* defined(__ASSERT__) && !defined(__HOST__) */
#endif /* ALLENOS_LIBSTD_ASSERT_HPP */

