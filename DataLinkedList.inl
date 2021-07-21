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

// Default constructor
inline DSLinkNode::DSLinkNode(void *pOwner) {
  // make a non-linked node
  ln_Succ = NULL;
  ln_Pred = NULL;
  ln_pOwner = pOwner;
};

// Destructor
inline DSLinkNode::~DSLinkNode(void) {
  // if node is linked
  if (IsLinked()) {
    // remove it from list
    Remove();
  }
};

// Get predeccessor of this node
inline DSLinkNode &DSLinkNode::Pred(void) const {
  return *ln_Pred;
};

// Get successor of this node
inline DSLinkNode &DSLinkNode::Succ(void) const {
  return *ln_Succ;
};

// Check that this list node is head marker of list
inline bool DSLinkNode::IsHeadMarker(void) const {
  // if this is in fact pointer to list.lh_Head
  if (ln_Pred == NULL) {
    // it is end marker
    return true;
  }

  // otherwise it must be somewhere inside the list
  return false;
};

// Check that this list node is tail marker of list
inline bool DSLinkNode::IsTailMarker(void) const {
  // if this is in fact pointer to list.lh_NULL
  if (ln_Succ == NULL) {
    // it is end marker
    return true;
  }

  // otherwise it must be somewhere inside the list
  return false;
};

// Check if this list node is head of list
inline bool DSLinkNode::IsHead(void) const {
  // if previous is list.lh_NULL
  return ln_Pred->ln_Pred == NULL;
};

// Check that this list node is tail of list
inline bool DSLinkNode::IsTail(void) const {
  // if next is list.lh_NULL
  return ln_Succ->ln_Succ == NULL;
};

// Get list head
inline DSLinkNode &DSLinkHead::Head(void) const {
  return *lh_Head;
};

// Get list tail
inline DSLinkNode &DSLinkHead::Tail(void) const {
  return *lh_Tail;
};


// --- FUNCTIONS ---

// Check is linked in some list
bool DSLinkNode::IsLinked(void) const {
  return ln_Pred != NULL;
};

// Remove a node from list
void DSLinkNode::Remove(void) {
  DSLinkNode &lnPrev = *ln_Pred;
  DSLinkNode &lnNext = *ln_Succ;

  lnNext.ln_Pred = &lnPrev;
  lnPrev.ln_Succ = &lnNext;

  // make a non-linked node
  ln_Succ = NULL;
  ln_Pred = NULL;
};

// Add a node after this node
void DSLinkNode::AddAfter(DSLinkNode &lnToAdd) {
  DSLinkNode &lnPred = *this;
  DSLinkNode &lnSucc = Succ();

  lnSucc.ln_Pred = &lnToAdd;
  lnPred.ln_Succ = &lnToAdd;
  lnToAdd.ln_Succ = &lnSucc;
  lnToAdd.ln_Pred = &lnPred;
};

// Add a node before this node
void DSLinkNode::AddBefore(DSLinkNode &lnToAdd) {
  DSLinkNode &lnPred = Pred();
  DSLinkNode &lnSucc = *this;

  lnSucc.ln_Pred = &lnToAdd;
  lnPred.ln_Succ = &lnToAdd;
  lnToAdd.ln_Succ = &lnSucc;
  lnToAdd.ln_Pred = &lnPred;
};

// Find the head of the list that this node is in
DSLinkHead &DSLinkNode::GetHead(void) {
  // start at this node
  DSLinkNode *pln = this;

  // while current node is not pointer to list.lh_Head
  while (pln->ln_Pred != NULL) {
    // go backwards
    pln = pln->ln_Pred;
  }

  // return the head pointer
  return *(DSLinkHead *)pln;
};

// Initialize a list head
void DSLinkHead::Clear(void) {
  lh_Head = NULL;
  lh_Tail = NULL;
};

// Check if list is empty
bool DSLinkHead::IsEmpty(void) const {
  return (lh_Head == NULL);
};

// Add a node to head of list
void DSLinkHead::AddHead(DSLinkNode &lnElement) {
  if (IsEmpty()) {
    lh_Head = &lnElement;
    lh_Tail = &lnElement;
    return;
  }

  DSLinkNode &lnFirst = *lh_Head;

  lh_Head = &lnElement;
  lnElement.ln_Succ = &lnFirst;
  lnElement.ln_Pred = lnFirst.ln_Pred;
  lnFirst.ln_Pred = &lnElement;
};

// Add a node to tail of list
void DSLinkHead::AddTail(DSLinkNode &lnElement) {
  if (IsEmpty()) {
    lh_Head = &lnElement;
    lh_Tail = &lnElement;
    return;
  }

  DSLinkNode &lnLast = *lh_Tail;

  lh_Tail = &lnElement;
  lnElement.ln_Succ = lnLast.ln_Succ;
  lnElement.ln_Pred = &lnLast;
  lnLast.ln_Succ = &lnElement;
};

// Remove a node from head of list
void DSLinkHead::RemHead(void) {
  lh_Head->Remove();
};

// Remove a node from tail of list
void DSLinkHead::RemTail(void) {
  lh_Tail->Remove();
};

// Remove all elements from list
void DSLinkHead::RemAll(void) {
  // keep removing from the head
  for (DSLinkNode *ln = lh_Head; lh_Head != NULL; ln = lh_Head) {
    ln->Remove();
  }
};

// Move all elements of another list into this one
void DSLinkHead::MoveList(DSLinkHead &lhOther) {
  // if the second list is empty then no moving
  if (lhOther.IsEmpty()) {
    return;
  }

  // get first element in other list
  DSLinkNode &lnOtherFirst = *lhOther.lh_Head;
  // get last element in other list
  DSLinkNode &lnOtherLast = *lhOther.lh_Tail;

  // get last element in this list
  DSLinkNode &lnThisLast = *lh_Tail;

  // relink elements
  lnOtherLast.ln_Succ = lnThisLast.ln_Succ;
  lnThisLast.ln_Succ = &lnOtherFirst;
  lnOtherFirst.ln_Pred = &lnThisLast;
  lh_Tail = &lnOtherLast;

  // clear the other list
  lhOther.Clear();
};

// Return the number of elements in list
int DSLinkHead::Count(void) const {
  int ctCount = 0;

  // walk the list - modification of FOREACHINLIST that works with base DSLinkNode class
  for (DSLinkNode *ln = lh_Head; !ln->IsTailMarker(); ln = ln->ln_Succ) {
    ctCount++;
  }

  return ctCount;
};
