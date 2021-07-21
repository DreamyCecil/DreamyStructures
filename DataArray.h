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

#pragma once

#include "DataTemplates.h"

// Data array
DS_TEMP class DSArray {
  protected:
    int da_ctSize;
    cType *da_aArray;

  public:
    // Constructors & Destructor
    inline DSArray(void);
    inline DSArray(const DSArray<cType> &aOriginal);
    inline ~DSArray(void);

    // Reset the array
    inline void Reset(void);
    // New array
    inline void New(const int &iCount);
    // Resize the array
    inline void Resize(const int &iNewCount);
    // Clear the array
    inline void Clear(void);

    // Get the element
    inline cType &operator[](const int &iObject);
    inline const cType &operator[](const int &iObject) const;

    // Count elements
    int Count(void) const;

    // Element index in the array
    int Index(cType *pObject) const;

    // Copy elements from the other array
    void CopyArray(const DSArray<cType> &aOriginal);
    // Move elements from one array to this one
    void MoveArray(DSArray<cType> &aOther);

    // Assignment
    DSArray<cType> &operator=(const DSArray<cType> &aOther);
};

#include "DataArray.inl"
