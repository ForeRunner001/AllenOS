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

#ifndef ALLENOS_SINGLETON_HPP
#define ALLENOS_SINGLETON_HPP
/**
 * Singleton design pattern; only one instance is allowed
 */
 template <typename T>
 class Singleton {
 public:
     /**
      * Constructor
      * @param instance New instance of T.
      */
      Singleton<T>(T *obj){
        instance = obj;
      }

      /* One and only instance */
     static T *instance;
 };

 /* Initialize the static member obj. */
template <typename T>
T* Singleton<T>::instance = 0;

#endif //ALLENOS_SINGLETON_HPP
