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

// List node
class DSTRUCT_API CDLinkNode {
  public:
    CDLinkNode *ln_Pred; // previous node (predecessor)
    CDLinkNode *ln_Succ; // next node (successor)

    void *ln_pOwner; // class that owns this node

  public:
    // Default constructor
    inline CDLinkNode(void *pOwner);

    // Destructor
    inline ~CDLinkNode(void);

    // Check that this list node is linked in some list
    bool IsLinked(void) const;

    // Add a node after this node
    void AddAfter(CDLinkNode &node);
    // Add a node before this node
    void AddBefore(CDLinkNode &node);

    // Remove this node from list
    void Remove(void);

    // Check if this list node is head marker of list
    inline bool IsHeadMarker(void) const;
    // Check if this list node is tail marker of list
    inline bool IsTailMarker(void) const;

    // Check if this list node is at the head of list
    inline bool IsHead(void) const;
    // Check if this list node is at the tail of list
    inline bool IsTail(void) const;

    // Get predeccessor of this node
    inline CDLinkNode &Pred(void) const;
    // Get successor of this node
    inline CDLinkNode &Succ(void) const;

    // Find the head of the list that this node is in
    class CDLinkHead &GetHead(void);
};

// List head
class DSTRUCT_API CDLinkHead {
  public:
    CDLinkNode *lh_Head; // first node (head)
    CDLinkNode *lh_Tail; // last node (tail)

  public:
    // Default constructor
    inline CDLinkHead() { Clear(); };

    // Copy constructor
    inline CDLinkHead(const CDLinkHead &lh) {};

    // Assignment
    inline void operator=(const CDLinkHead &lh) {};

    // Clear the list head
    void Clear();

    // Get list head
    inline CDLinkNode &Head(void) const;
    // Get list tail
    inline CDLinkNode &Tail(void) const;

    // Add a new element to head of list
    void AddHead(CDLinkNode &lnNode);
    // Add a new element to tail of list
    void AddTail(CDLinkNode &lnNode);

    // Remove first element from list
    void RemHead(void);
    // Remove last element from list
    void RemTail(void);
    // Remove all elements from list
    void RemAll(void);

    // Check if list is empty
    bool IsEmpty(void) const;

    // Move all elements of another list into this one
    void MoveList(CDLinkHead &lhOther);

    // Return the number of elements in list
    int Count(void) const;
};

#include "DataLinkedList.inl"

// Linked list iteration (from head to tail)
#define LINKEDLIST_H2T(_Head, _Iterator) \
  for (CDLinkNode *_Iterator = _Head.lh_Head; _Iterator != NULL; _Iterator = _Iterator->ln_Succ)

// Linked list iteration (from tail to head)
#define LINKEDLIST_T2H(_Head, _Iterator) \
  for (CDLinkNode *_Iterator = _Head.lh_Tail; _Iterator != NULL; _Iterator = _Iterator->ln_Pred)
