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

#ifndef NULL
  #define NULL nullptr
#endif

// Structures
#define DSTRUCT_EXPORT
#include "DataStructures.h"

// Output
#include <iostream>

// Strings
#include <string>

typedef std::string string;

// Names
static const string _astrNames[5] = {
  "Aaron", "Charlie", "Jake", "Harry", "Vincent",
};

// Ages
static const int _aiAges[5] = {
  30, 22, 15, 47, 26,
};

// Custom types
typedef DSMap<string, int> CAgeMap;

// Entry point
int main() {
  // Arrays
  {
    // Array of numbers
    DSArray<int> aiArray;
    aiArray.New(2);
    
    aiArray[0] = 1;
    aiArray[1] = -10;
    
    // Add another number
    aiArray.Resize(3);
    aiArray[2] = 333;
    
    // Print the array contents
    std::cout << "-- Array:";
    
    for (int i = 0; i < aiArray.Count(); i++) {
      std::cout << " " << aiArray[i];
    }
    
    std::cout << "\n";
  }
  
  // Lists
  {
    // List of pointers
    DSList<string *> astrNames;
    
    std::cout << "\n-- List:\n";
    
    // Add 5 strings
    for (int i = 0; i < 5; i++)
    {
      int iStr = astrNames.Add(new string);
      *astrNames[iStr] = _astrNames[i];
      
      std::cout << "Added " << *astrNames[iStr] << "\n";
    }
    
    // Delete strings
    while (astrNames.Count() > 0) {
      delete astrNames[0];
      astrNames.Delete(0);
    }
  }
  
  // Maps
  {
    CAgeMap mapAges;
    
    // Set ages
    for (int i = 0; i < 5; i++)
    {
      string strName = _astrNames[i];
      int iAge = _aiAges[i];
      
      // Might not work correctly on some compilers, consider the line below
      mapAges[strName] = iAge;
      
      // Also valid
      // mapAges.Add(strName, iAge);
    }
    
    // Another map
    CAgeMap mapMoreAges;
    mapMoreAges.Add("Seth", 36);
    mapMoreAges.Add("Daniel", 10);
    mapMoreAges.Add("Harry", 50);
    
    // Add people from another map (and replace values under existing keys)
    mapMoreAges.AddFrom(mapAges, true);
    
    // Print the map contents
    std::cout << "\n-- Map:\n";
    
    for (int iMap = 0; iMap < mapMoreAges.Count(); iMap++)
    {
      string strKey = mapMoreAges.GetKey(iMap);
      int iValue = mapMoreAges.GetValue(iMap);
      
      std::cout << strKey << ", age " << iValue << "\n";
    }
  }
  
  // Stacks
  {
    DSStack<short> aStack;
    
    for (int i = 0; i < 10; i++)
    {
      short iNum = (i*i + 2);
      aStack.Push(iNum);
    }
    
    std::cout << "\n-- Stack:\n";
    
    // Get the top value
    std::cout << "Top: " << aStack.Top() << "\n";
    
    // Pop until the certain number
    aStack.PopUntil(38);
    
    // Print the stack contents
    std::cout << "Remaining:";
    
    for (int iStack = 0; iStack < aStack.Count(); iStack++) {
      std::cout << " " << aStack[iStack];
    }
    
    std::cout << "\n";
  }
  
  return 0;
};
