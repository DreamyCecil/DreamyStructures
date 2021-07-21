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

// Constructors & Destructor
DS_TEMP DSArray<cType>::DSArray(void) {
  Reset();
};
DS_TEMP DSArray<cType>::DSArray(const DSArray<cType> &aOriginal) {
  Reset();
  CopyArray(aOriginal);
};
DS_TEMP DSArray<cType>::~DSArray(void) {
  Clear();
};

// Reset the array
DS_TEMP void DSArray<cType>::Reset(void) {
  // Empty array
  da_aArray = NULL;
  da_ctSize = 0;
};

// New array
DS_TEMP void DSArray<cType>::New(const int &iCount) {
  // Too small
  if (iCount <= 0) {
    return;
  }

  da_ctSize = iCount;
  da_aArray = new cType[iCount];
};

// Resize the array
DS_TEMP void DSArray<cType>::Resize(const int &iNewCount) {
  // Clear the array
  if (iNewCount <= 0) {
    Clear();
    return;
  }

  // Empty
  if (da_ctSize <= 0) {
    New(iNewCount);
    return;
  }
  
  // Same size
  if (da_ctSize == iNewCount) {
    return;
  }

  // Copy elements
  cType *aNew = new cType[iNewCount];
  const int ctCopy = (da_ctSize < iNewCount) ? da_ctSize : iNewCount;

  for (int iOld = 0; iOld < ctCopy; iOld++) {
    aNew[iOld] = da_aArray[iOld];
  }

  delete[] da_aArray;

  da_ctSize = iNewCount;
  da_aArray = aNew;
};

// Clear the array
DS_TEMP void DSArray<cType>::Clear(void) {
  // Destroy the array
  if (da_ctSize > 0) {
    delete[] da_aArray;
    Reset();
  }
};

// Get the element
DS_TEMP cType &DSArray<cType>::operator[](const int &iObject) {
  return da_aArray[iObject];
};

DS_TEMP const cType &DSArray<cType>::operator[](const int &iObject) const {
  return da_aArray[iObject];
};



// --- FUNCTIONS ---

// Count elements
DS_TEMP int DSArray<cType>::Count(void) const {
  return da_ctSize;
};

// Element index in the array
DS_TEMP int DSArray<cType>::Index(cType *pObject) const {
  return pObject - da_aArray;
};

// Copy elements from the other array
DS_TEMP void DSArray<cType>::CopyArray(const DSArray<cType> &aOriginal) {
  // clear previous contents
  Clear();

  int ctOriginal = aOriginal.Count();

  // no objects in the other array
  if (ctOriginal <= 0) {
    return;
  }

  New(ctOriginal);

  // copy the objects
  for (int iNew = 0; iNew < ctOriginal; iNew++) {
    da_aArray[iNew] = aOriginal[iNew];
  }
};

// Move elements from one array to this one
DS_TEMP void DSArray<cType>::MoveArray(DSArray<cType> &aOther) {
  // clear previous contents
  Clear();

  // no objects in the other array
  if (aOther.Count() <= 0) {
    return;
  }

  // move data from the other array into this one and clear the other one
  da_ctSize = aOther.da_ctSize;
  da_aArray = aOther.da_aArray;
  aOther.Reset();
};

// Assignment
DS_TEMP DSArray<cType> &DSArray<cType>::operator=(const DSArray<cType> &aOther) {
  if (this == &aOther) {
    return *this;
  }

  CopyArray(aOther);
  return *this;
};
