/* Copyright (c) 2020 Dreamy Cecil

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

#include "DataList.h"

// Data map
MAP_TEMP class CDMap : public CDArray<cType> {
private:
  CDList<cKey> map_aKeys;

public:
  // Destructor
  ~CDMap(void) {
    Clear();
  };
  
  // Clear the map
  inline void Clear(void);

  // Add new key
  inline int Add(cKey mapKey);
  // Add new key and assign a value to it
  inline int Add(cKey mapKey, cType pObject);
  // Delete value under some key
  inline void Delete(cKey mapKey);

  // Find index of a specific key
  inline int FindKeyIndex(cKey mapKey);
  // Get the key under some index
  inline cKey &GetKey(int iValue);
  
  // Value access via the key
  inline cType &operator[](cKey mapKey);
  inline const cType &operator[](cKey mapKey) const;
  // Value access via the index
  inline cType &GetValue(int iValue);
  inline const cType &GetValue(int iValue) const;
  
  // Copy elements from the other map
  void CopyMap(const CDMap<cKey, cType> &mapOther);
  // Move elements from one map to this one
  void MoveMap(CDMap<cKey, cType> &mapOther);
  // Add elements from the other map and replace values of existing ones if needed
  void AddFrom(CDMap<cKey, cType> &mapOther, bool bReplace = false);

  // Assignment
  CDMap<cKey, cType> &operator=(const CDMap<cKey, cType> &mapOther);
};

#include "DataMap.inl"
