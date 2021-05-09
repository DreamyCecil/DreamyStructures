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

#pragma once

#include "DataTemplates.h"

DS_TEMP class CDLinked;

// Data node
DS_TEMP class CDNode {
  public:
    CDLinked<cType> *dn_pList; // list this node belongs to

    CDNode<cType> *dn_pPrev; // previous node
    CDNode<cType> *dn_pNext; // next node

    cType dn_Value; // value itself

  public:
    // Constructors
    inline CDNode(void);
    inline CDNode(CDLinked<cType> *pList, cType *pValue);

    // Type casting
    operator cType() {
      return dn_Value;
    };
};

// Linked data list
DS_TEMP class CDLinked {
  public:
    CDNode<cType> *dl_dnHead; // head of the list
    CDNode<cType> *dl_dnTail; // tail of the list
    
  public:
    // Constructor & Destructor
    inline CDLinked(void);
    inline ~CDLinked(void);

    // Clear the list
    inline void Clear(void);

    // Add new element to the list
    inline int Add(cType pObject);
    // Insert new element somewhere in the list
    inline void Insert(const int &iPos, cType pObject);
    // Delete some element
    inline void Delete(const int &iPos);

    // Get the node
    inline CDNode<cType> &operator[](int iObject);
    inline const CDNode<cType> &operator[](int iObject) const;

    // Count nodes
    int Count(void) const;
    // Find node index
    int Index(CDNode<cType> *pNode);
    // Find element index
    int FindIndex(cType pObject);
};

// Go through every node in the list
#define FOREACH_CDNode(_List, _Type, _Node) \
  for (CDNode<_Type> *_Node = _List.dl_dnHead; \
       _Node != NULL; \
       _Node = _Node->dn_pNext)

#include "DataLinkedList.inl"
