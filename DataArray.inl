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

// Reset the array
DS_TEMP void DSArray<cType>::Reset(void) {
  // Empty array
  clear();
};

// New array
DS_TEMP void DSArray<cType>::New(const int &iCount) {
  resize(iCount);
};

// Resize the array
DS_TEMP void DSArray<cType>::Resize(const int &iNewCount) {
  resize(iNewCount);
};

// Clear the array
DS_TEMP void DSArray<cType>::Clear(void) {
  // Destroy the array
  clear();
};

// Count elements
DS_TEMP int DSArray<cType>::Count(void) const {
  return size();
};

// Copy elements from the other array
DS_TEMP void DSArray<cType>::CopyArray(const DSArray<cType> &aOriginal) {
  (std::vector<cType> &)*this = (const std::vector<cType> &)aOriginal;
};

// Move elements from one array to this one
DS_TEMP void DSArray<cType>::MoveArray(DSArray<cType> &aOther) {
  Clear();

  // no objects in the other array
  if (aOther.Count() <= 0) {
    return;
  }

  // move data from the other array into this one and clear the other one
  (std::vector<cType> &)*this = (const std::vector<cType> &)aOther;
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
