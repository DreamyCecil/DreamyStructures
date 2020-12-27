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

// --- INLINE ---

// Clear the map
MAP_TEMP void CDMap<cKey, cType>::Clear(void) {
  CDArray<cType>::Clear();
  map_aKeys.Clear();
};

// Add new key
MAP_TEMP int CDMap<cKey, cType>::Add(cKey mapKey) {
  int iNewKey = map_aKeys.Add(mapKey);
  this->Resize(iNewKey+1);

  return iNewKey;
};

// Add new key and assign a value to it
MAP_TEMP int CDMap<cKey, cType>::Add(cKey mapKey, cType pObject) {
  int iNewKey = this->Add(mapKey);
  this->da_aArray[iNewKey] = pObject;

  return iNewKey;
};

// Delete value under some key
MAP_TEMP void CDMap<cKey, cType>::Delete(cKey mapKey) {
  int iKey = FindKeyIndex(mapKey);

  // Key doesn't exist
  if (iKey == -1) {
    return;
  }

  // Just one object left
  if (this->da_ctSize == 1) {
    map_aKeys.Clear();
    Clear();
    return;
  }

  map_aKeys.Delete(iKey);

  // Copy elements
  cType *aNew = new cType[this->da_ctSize-1];

  for (int iOld = 0; iOld < this->da_ctSize; iOld++) {
    // Skip the position
    if (iOld == iKey) {
      continue;
    }

    // Shift to make space for a new element
    int iShift = (iOld >= iKey);
    aNew[iOld-iShift] = this->da_aArray[iOld];
  }

  delete[] this->da_aArray;

  this->da_ctSize--;
  this->da_aArray = aNew;
};

// Find index of a specific key
MAP_TEMP int CDMap<cKey, cType>::FindKeyIndex(cKey mapKey) {
  return ((const CDMap<cKey, cType>*)this)->FindKeyIndex(mapKey);
};

MAP_TEMP const int CDMap<cKey, cType>::FindKeyIndex(cKey mapKey) const {
  return map_aKeys.FindIndex(mapKey);
};

// Get the key under some index
MAP_TEMP cKey &CDMap<cKey, cType>::GetKey(int iValue) {
  return map_aKeys[iValue];
};

// Value access via the key
MAP_TEMP cType &CDMap<cKey, cType>::operator[](cKey mapKey) {
  int iKey = FindKeyIndex(mapKey);

  // Add a new key
  if (iKey == -1) {
    return this->da_aArray[Add(mapKey)];
  }
  return this->da_aArray[iKey];
};

MAP_TEMP const cType &CDMap<cKey, cType>::operator[](cKey mapKey) const {
  int iKey = FindKeyIndex(mapKey);
  return this->da_aArray[iKey];
};

MAP_TEMP cType &CDMap<cKey, cType>::GetValue(int iValue) {
  return this->da_aArray[iValue];
};

MAP_TEMP const cType &CDMap<cKey, cType>::GetValue(int iValue) const {
  return this->da_aArray[iValue];
};



// --- FUNCTIONS ---
  
// Copy elements from the other map
MAP_TEMP void CDMap<cKey, cType>::CopyMap(const CDMap<cKey, cType> &mapOther) {
  map_aKeys.CopyArray(mapOther.map_aKeys);
  this->CopyArray(mapOther);
};

// Move elements from one map to this one
MAP_TEMP void CDMap<cKey, cType>::MoveMap(CDMap<cKey, cType> &mapOther) {
  map_aKeys.MoveArray(mapOther.map_aKeys);
  this->MoveArray(mapOther);
};

// Add elements from the other map
MAP_TEMP void CDMap<cKey, cType>::AddFrom(CDMap<cKey, cType> &mapOther, bool bReplace) {
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
        this->da_aArray[iKey] = pValue;
        continue;
      }
    }

    // just add a new element
    Add(pOtherKey, pValue);
  }
};

// Assignment
MAP_TEMP CDMap<cKey, cType> &CDMap<cKey, cType>::operator=(const CDMap<cKey, cType> &mapOther) {
  if (this == &mapOther) {
    return *this;
  }

  CopyMap(mapOther);
  return *this;
};
