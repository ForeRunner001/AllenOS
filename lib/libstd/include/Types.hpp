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
// Created by allen on 18-5-13.

#ifndef ALLENOS_LIB_LIBSTD_INCLUDE_TYPES_HPP__
#define ALLENOS_LIB_LIBSTD_INCLUDE_TYPES_HPP__

#ifndef __ASSEMBLER__

/**
 * @defgroup types types
 * @{
 */

/**
 * Restrict bit operations.
 * @see http://kerneltrap.org/node/3848
 */
#if 0
#define BITWISE __attribute__((bitwise))
#else
#define BITWISE
#endif

/**
 * @name Unsigned integers.
 * @{
 */

/** Unsigned integer number. */
typedef unsigned int uint;

/** Unsigned long number. */
typedef unsigned long ulong;

/** Unsigned 64-bit number. */
typedef unsigned long long uint64;

/** Unsigned 32-bit number. */
typedef unsigned int uint32;

/** Unsigned 16-bit number. */
typedef unsigned short uint16;

/** Unsigned 8-bit number. */
typedef unsigned char uint8;

/**
 * @}
 */

/**
 * @name Signed integers.
 * @{
 */

/** Signed integer number. */
typedef signed int sint;

/** Signed long number. */
typedef signed long slong;

/** Signed 64-bit number. */
typedef signed long long sint64;

/** Signed 32-bit number. */
typedef signed int sint32;

/** Signed 16-bit number. */
typedef signed short sint16;

/** Signed 8-bit number. */
typedef signed char sint8;

/**
 * @}
 */

/**
 * @name Bitwise checked integers.
 * @see http://kerneltrap.org/node/3848
 * @{
 */

/** Unsigned 64-bit little endian number. */
typedef uint64 BITWISE le64;

/** Unsigned 64-bit big endian number. */
typedef uint64 BITWISE be64;

/** Unsigned 32-bit little endian number. */
typedef uint32 BITWISE le32;

/** Unsigned 32-bit big endian number. */
typedef uint32 BITWISE be32;

/** Unsigned 16-bit little endian number. */
typedef uint16 BITWISE le16;

/** Unsigned 16-bit big endian number. */
typedef uint16 BITWISE be16;

/** Unsigned 8-bit little endian number. */
typedef uint8 BITWISE le8;

/** Unsigned 8-bit big endian number. */
typedef uint8 BITWISE be8;

/**
 * @}
 */

/** Any sane size indicator cannot go negative. */
typedef uint32 Size;

/** A memory address */
typedef uint64 Address;

/** User Identity. */
typedef uint16 UserID;

/** Group Identity. */
typedef uint16 GroupID;

/** Process Identification Number */
typedef uint16 ProcessID;

/**
 * Describes a device ID number.
 */
typedef struct DeviceID {
	/** Major device ID number is a PID. */
	ProcessID major;

	/** Device specific minor ID number. */
	ProcessID minor;
} DeviceID;

/**
 * Error code defined in Error.hpp
 * @see Error.hpp
 */
typedef slong Error;

#ifdef __cplusplus
namespace Number {
	/**
	 * Numeral system base type
	 */
	 typedef enum Base {
		Dec,    // Decimal: 0-10
		Hex,    // Hexadecimal: 0x0-0xf
	 } Base;
};
#endif  // __cplusplus

/**
 *@}
 */

#endif  // __ASSEMBLER__
#endif  // ALLENOS_LIB_LIBSTD_INCLUDE_TYPES_HPP__
