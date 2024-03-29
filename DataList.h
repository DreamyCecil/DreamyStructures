/* Copyright (c) 2020-2021 Dreamy Cecil

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#ifndef DSTRUCT_INCL_LIST_H
#define DSTRUCT_INCL_LIST_H
#ifdef PRAGMA_ONCE
  #pragma once
#endif

#include "DataArray.h"

// Data list
DS_TEMP class DSList : public DSArray<cType> {
  public:
    // Add new element to the list
    inline int Add(cType pObject);
    // Add empty element to the list
    inline cType &Add(void);

    // Insert new element somewhere in the list
    inline void Insert(const int &iPos, cType pObject);
    // Delete some element
    inline void Delete(const int &iPos);

    // Find index of a specific element
    const int FindIndex(const cType &pObject) const;
};

#include "DataList.inl"

#endif // DSTRUCT_INCL_LIST_H
