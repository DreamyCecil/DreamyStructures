/* Copyright (c) 2021 Dreamy Cecil

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

// Constructors
DS_TEMP CDNode<cType>::CDNode(void) {
  dn_pList = NULL;
  dn_pPrev = NULL;
  dn_pNext = NULL;
};
DS_TEMP CDNode<cType>::CDNode(CDLinked<cType> *pList, cType *pValue) {
  dn_pList = pList;
  dn_pPrev = NULL;
  dn_pNext = NULL;

  dn_Value = *pValue;
};

// Constructor & Destructor
DS_TEMP CDLinked<cType>::CDLinked(void) {
  dl_dnHead = NULL;
  dl_dnTail = NULL;
};
DS_TEMP CDLinked<cType>::~CDLinked(void) {
  Clear();
};

// Clear the list
DS_TEMP void CDLinked<cType>::Clear(void) {
  CDNode<cType> *pCurrent = dl_dnHead;
  CDNode<cType> *pDelete = NULL;
  int iNode = 0;

  while (pCurrent != NULL) {
    pDelete = pCurrent;
    pCurrent = pCurrent->dn_pNext;

    delete pDelete;
  }

  dl_dnHead = NULL;
  dl_dnTail = NULL;
};

// Add new element to the list
DS_TEMP int CDLinked<cType>::Add(cType pObject) {
  // create a new node
  CDNode<cType> *pNode = new CDNode<cType>(this, &pObject);

  // first node ever
  if (dl_dnHead == NULL) {
    dl_dnHead = pNode;
    dl_dnTail = pNode;
    return 0;
  }

  // set new's prev node to the last one
  pNode->dn_pPrev = dl_dnTail;

  // set last's next node to the new one
  dl_dnTail->dn_pNext = pNode;

  // set new node as the last one
  dl_dnTail = pNode;

  return Count();
};

// Insert new element somewhere in the list
DS_TEMP void CDLinked<cType>::Insert(const int &iPos, cType pObject) {
  CDNode<cType> *pCurrent = dl_dnHead;

  // no nodes
  if (pCurrent == NULL) {
    Add(pObject);
    return;
  }

  int iNode = 0;

  while (pCurrent != NULL) {
    // matching node
    if (iNode == iPos) {
      break;
    }

    pCurrent = pCurrent->dn_pNext;
    iNode++;
  }

  // over the last one
  if (pCurrent == NULL) {
    Add(pObject);
    return;
  }

  // create a new node
  CDNode<cType> *pNode = new CDNode<cType>(this, &pObject);
  
  // take current's prev node
  pNode->dn_pPrev = pCurrent->dn_pPrev;

  // change prev's next node to the new one
  if (pNode->dn_pPrev != NULL) {
    pNode->dn_pPrev->dn_pNext = pNode;
  }

  // set current's prev node to the new one
  pCurrent->dn_pPrev = pNode;

  // set new's next node to the current one
  pNode->dn_pNext = pCurrent;
};

// Delete some element
DS_TEMP void CDLinked<cType>::Delete(const int &iPos) {
  CDNode<cType> *pCurrent = dl_dnHead;

  // no nodes
  if (pCurrent == NULL) {
    return;
  }

  int iNode = 0;

  while (pCurrent != NULL) {
    // matching node
    if (iNode == iPos) {
      break;
    }

    pCurrent = pCurrent->dn_pNext;
    iNode++;
  }

  // over the last node
  if (pCurrent == NULL) {
    return;
  }

  // set prev's next node to the current's next one
  if (pCurrent->dn_pPrev != NULL) {
    pCurrent->dn_pPrev->dn_pNext = pCurrent->dn_pNext;
  }

  // set next's prev node to the current's prev one
  if (pCurrent->dn_pNext) {
    pCurrent->dn_pNext->dn_pPrev = pCurrent->dn_pPrev;
  }
};

// Get the node
DS_TEMP CDNode<cType> &CDLinked<cType>::operator[](int iObject) {
  CDNode<cType> *pCurrent = dl_dnHead;
  int iNode = 0;

  while (pCurrent != NULL) {
    // matching node
    if (iNode == iObject) {
      return *pCurrent;
    }

    pCurrent = pCurrent->dn_pNext;
    iNode++;
  }
  
  // undefined behavior
  return *pCurrent;
};

DS_TEMP const CDNode<cType> &CDLinked<cType>::operator[](int iObject) const {
  CDNode<cType> *pCurrent = dl_dnHead;
  int iNode = 0;

  while (pCurrent != NULL) {
    // matching node
    if (iNode == iObject) {
      return *pCurrent;
    }

    pCurrent = pCurrent->dn_pNext;
    iNode++;
  }

  // undefined behavior
  return *pCurrent;
};



// --- FUNCTIONS ---

// Count nodes
DS_TEMP int CDLinked<cType>::Count(void) const {
  CDNode<cType> *pCurrent = dl_dnHead;
  int ctNodes = 0;

  while (pCurrent != NULL) {
    pCurrent = pCurrent->dn_pNext;
    ctNodes++;
  }

  return ctNodes;
};

// Find node index
DS_TEMP int CDLinked<cType>::Index(CDNode<cType> *pNode) {
  CDNode<cType> *pCurrent = dl_dnHead;
  int iNode = 0;

  while (pCurrent != NULL) {
    // matching node
    if (pCurrent == pNode) {
      return iNode;
    }

    pCurrent = pCurrent->dn_pNext;
    iNode++;
  }

  return -1;
};

// Find element index
DS_TEMP int CDLinked<cType>::FindIndex(cType pObject) {
  CDNode<cType> *pCurrent = dl_dnHead;
  int iElement = 0;

  while (pCurrent != NULL) {
    // matching element
    if (pCurrent->dn_pValue == pObject) {
      return iElement;
    }

    pCurrent = pCurrent->dn_pNext;
    iElement++;
  }

  return -1;
};
