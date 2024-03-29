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

// Add new element to the end of the stack
DS_TEMP int DSStack<cType>::Push(cType pObject) {
  return this->Add(pObject);
};

// Add empty element to the end of the stack
DS_TEMP cType &DSStack<cType>::Push(void) {
  return this->Add();
};

// Get the top element from the stack
DS_TEMP cType &DSStack<cType>::Top(void) {
  // get the last element
  int iPos = this->Count() - 1;

  return (*this)[iPos];
};

// Remove one element from the end of the stack
DS_TEMP cType DSStack<cType>::Pop(void) {
  // get the last element
  int iPos = this->Count() - 1;
  cType pValue = (*this)[iPos];
  
  // remove it from the list
  this->Delete(iPos);
  
  return pValue;
};

// Remove elements from the end of the stack until a certain element
DS_TEMP int DSStack<cType>::PopUntil(cType pUntil) {
  int ctRemoved = 0;
  cType pFound = (*this)[size() - 1];

  while (size() > 0 && pFound != pUntil) {
    pop_back();
    ctRemoved++;

    pFound = (*this)[size() - 1];
  }
  
  return ctRemoved;
};
