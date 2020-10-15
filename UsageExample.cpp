#ifndef NULL
  #define NULL nullptr
#endif

// Structures
#include "DataStructures.h"
// Output
#include <iostream>
// Strings
#include <string>

using namespace std;

// Names
const string _astrNames[5] = {
  "Aaron", "Charlie", "Jake", "Harry", "Vincent",
};

// Ages
const int _aiAges[5] = {
  30, 22, 15, 47, 26,
};

// Custom types
typedef CDMap<string, int> CAgeMap;

int main() {
  // Arrays
  {
    // Array of numbers
    CDArray<int> aiArray;
    aiArray.New(2);
    
    aiArray[0] = 1;
    aiArray[1] = -10;
    
    // Add another number
    aiArray.Resize(3);
    aiArray[2] = 333;
    
    cout << "-- Array:";
    
    for (int i = 0; i < aiArray.Count(); i++) {
      cout << " " << aiArray[i];
    }
    
    cout << "\n";
  }
  
  // Lists
  {
    // List of pointers
    CDList<string *> astrNames;
    
    cout << "\n-- List:\n";
    
    // Add 5 strings
    for (int i = 0; i < 5; i++) {
      int iStr = astrNames.Add(new string);
      *astrNames[iStr] = _astrNames[iStr];
      
      cout << "Added " << *astrNames[iStr] << "\n";
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
    for (int i = 0; i < 5; i++) {
      string strName = _astrNames[i];
      int iAge = _aiAges[i];
      
      mapAges[strName] = iAge;
      
      // Also valid
      // mapAges.Add(strName, cAge);
    }
    
    // Another map
    CAgeMap mapMoreAges;
    mapMoreAges.Add("Seth", 36);
    mapMoreAges.Add("Daniel", 10);
    mapMoreAges.Add("Harry", 50);
    
    // Add people from another map (and replace values under existing keys)
    mapMoreAges.AddFrom(mapAges, true);
    
    cout << "\n-- Map:\n";
    
    for (int iMap = 0; iMap < mapMoreAges.Count(); iMap++) {
      cout << mapMoreAges.GetKey(iMap) << ", age " << mapMoreAges.GetValue(iMap) << "\n";
    }
  }
  
  // Stacks
  {
    CDStack<short> aStack;
    
    for (int i = 0; i < 10; i++) {
      short iNum = (i*i + 2);
      aStack.Push(iNum);
    }
    
    cout << "\n-- Stack:\n";
    
    // Get the top value
    cout << "Top: " << aStack.Top() << "\n";
    
    // Pop until the certain number
    aStack.PopUntil(38);
    
    cout << "Remaining:";
    
    for (int iStack = 0; iStack < aStack.Count(); iStack++) {
      cout << " " << aStack[iStack];
    }
    
    cout << "\n";
  }
  
  return 0;
};
