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

#ifndef DSTRUCT_INCL_MAP_H
#define DSTRUCT_INCL_MAP_H
#ifdef PRAGMA_ONCE
  #pragma once
#endif

#include "DataList.h"

// Data map
MAP_TEMP class DSMap : public DSArray<cType> {
  private:
    DSList<cKey> map_aKeys;

  public:
    // Destructor
    inline ~DSMap(void) {
      Clear();
    };

    // Clear the map
    inline void Clear(void);

    // Add new key
    inline cType &Add(cKey mapKey);
    // Add new key and assign a value to it
    inline int Add(cKey mapKey, cType pObject);
    // Delete value under some key
    inline void Delete(cKey mapKey);

    // Find index of a specific key
    inline const int FindKeyIndex(cKey mapKey) const;
    // Get the key under some index
    inline cKey &GetKey(int iValue);

    // Value access via the key
    inline cType &operator[](cKey mapKey) const;

    // Value access via the index
    inline cType &GetValue(const int &iValue);
    inline const cType &GetValue(const int &iValue) const;

    // Copy elements from the other map
    inline void CopyMap(const DSMap<cKey, cType> &mapOther);
    // Move elements from one map to this one
    inline void MoveMap(DSMap<cKey, cType> &mapOther);
    // Add elements from the other map and replace values of existing ones if needed
    void AddFrom(DSMap<cKey, cType> &mapOther, const bool &bReplace = false);

    // Assignment
    inline DSMap<cKey, cType> &operator=(const DSMap<cKey, cType> &mapOther);
};

#include "DataMap.inl"

#endif // DSTRUCT_INCL_MAP_H
