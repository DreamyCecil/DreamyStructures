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

// --- INLINE ---

// Add new element to the list
DS_TEMP int DSList<cType>::Add(cType pObject) {
  int ctCount = this->da_ctSize;
  this->Resize(ctCount+1);
  this->da_aArray[ctCount] = pObject;

  return ctCount;
};

// Insert new element somewhere in the list
DS_TEMP void DSList<cType>::Insert(const int &iPos, cType pObject) {
  // Empty
  if (this->da_ctSize <= 0) {
    this->New(iPos+1);
  
  // Copy elements
  } else {
    cType *aNew = new cType[this->da_ctSize+1];

    for (int iOld = 0; iOld < this->da_ctSize; iOld++) {
      // Shift to make space for a new element
      int iShift = (iOld >= iPos) ? 1 : 0;
      aNew[iOld+iShift] = this->da_aArray[iOld];
    }

    delete[] this->da_aArray;

    this->da_ctSize++;
    this->da_aArray = aNew;
  }

  this->da_aArray[iPos] = pObject;
};

// Delete some element
DS_TEMP void DSList<cType>::Delete(const int &iPos) {
  // Position doesn't exist
  if (iPos >= this->da_ctSize) {
    return;
  }

  // Just one object left
  if (this->da_ctSize == 1) {
    this->Clear();
    return;
  }

  // Copy elements
  cType *aNew = new cType[this->da_ctSize-1];

  for (int iOld = 0; iOld < this->da_ctSize; iOld++) {
    // Skip the position
    if (iOld == iPos) {
      continue;
    }

    // Shift to make space for a new element
    int iShift = (iOld >= iPos);
    aNew[iOld-iShift] = this->da_aArray[iOld];
  }

  delete[] this->da_aArray;

  this->da_ctSize--;
  this->da_aArray = aNew;
};



// --- FUNCTIONS ---

// Find index of a specific element
DS_TEMP int DSList<cType>::FindIndex(cType pObject) {
  return ((const DSList<cType>*)this)->FindIndex(pObject);
};

DS_TEMP const int DSList<cType>::FindIndex(cType pObject) const {
  const int ctObjects = this->Count();

  for (int i = 0; i < ctObjects; i++) {
    if (this->da_aArray[i] == pObject) {
      return i;
    }
  }
  return -1;
};
