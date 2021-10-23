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

// Clear the map
MAP_TEMP void DSMap<cKey, cType>::Clear(void) {
  DSArray<cType>::Clear();
  map_aKeys.Clear();
};

// Add new key
MAP_TEMP cType &DSMap<cKey, cType>::Add(cKey mapKey) {
  int iNewKey = map_aKeys.Add(mapKey);
  this->Resize(iNewKey + 1);

  return ((DSArray<cType> &)*this)[iNewKey];
};

// Add new key and assign a value to it
MAP_TEMP int DSMap<cKey, cType>::Add(cKey mapKey, cType pObject) {
  this->Add(mapKey) = pObject;
  return Count();
};

// Delete value under some key
MAP_TEMP void DSMap<cKey, cType>::Delete(cKey mapKey) {
  int iKey = FindKeyIndex(mapKey);

  // Key doesn't exist
  if (iKey == -1) {
    return;
  }

  // Just one object left
  if (Count() == 1) {
    map_aKeys.Clear();
    Clear();
    return;
  }

  map_aKeys.Delete(iKey);
  erase(begin() + iKey);
};

// Find index of a specific key
MAP_TEMP const int DSMap<cKey, cType>::FindKeyIndex(cKey mapKey) const {
  return map_aKeys.FindIndex(mapKey);
};

// Get the key under some index
MAP_TEMP cKey &DSMap<cKey, cType>::GetKey(int iValue) {
  return map_aKeys[iValue];
};

// Value access via the key
MAP_TEMP cType &DSMap<cKey, cType>::operator[](cKey mapKey) const {
  int iKey = FindKeyIndex(mapKey);
  return ((DSArray<cType> &)*this)[iKey];
};

MAP_TEMP cType &DSMap<cKey, cType>::GetValue(const int &iValue) {
  return ((DSArray<cType> &)*this)[iValue];
};

MAP_TEMP const cType &DSMap<cKey, cType>::GetValue(const int &iValue) const {
  return ((DSArray<cType> &)*this)[iValue];
};
  
// Copy elements from the other map
MAP_TEMP void DSMap<cKey, cType>::CopyMap(const DSMap<cKey, cType> &mapOther) {
  map_aKeys.CopyArray(mapOther.map_aKeys);
  this->CopyArray(mapOther);
};

// Move elements from one map to this one
MAP_TEMP void DSMap<cKey, cType>::MoveMap(DSMap<cKey, cType> &mapOther) {
  map_aKeys.MoveArray(mapOther.map_aKeys);
  this->MoveArray(mapOther);
};

// Add elements from the other map
MAP_TEMP void DSMap<cKey, cType>::AddFrom(DSMap<cKey, cType> &mapOther, const bool &bReplace) {
  int ctAdd = mapOther.Count();

  // for each element
  for (int iAdd = 0; iAdd < ctAdd; iAdd++) {
    cKey pOtherKey = mapOther.GetKey(iAdd);
    cType pValue = mapOther.GetValue(iAdd);

    // if should be replaced
    if (bReplace) {
      int iKey = FindKeyIndex(pOtherKey);

      // change the value
      if (iKey != -1) {
        ((DSArray<cType> &)*this)[iKey] = pValue;
        continue;
      }
    }

    // just add a new element
    Add(pOtherKey, pValue);
  }
};

// Assignment
MAP_TEMP DSMap<cKey, cType> &DSMap<cKey, cType>::operator=(const DSMap<cKey, cType> &mapOther) {
  if (this == &mapOther) {
    return *this;
  }

  CopyMap(mapOther);
  return *this;
};
