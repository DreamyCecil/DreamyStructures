# Dreamy Structures
========================

This is a small collection of custom made data structures (templates) that are easy to understand and use. Doesn't use the standard library.

Includes:
* `CDArray` *Dreamy Array* - a standard array structure that allows the creation of resizable arrays of any type.
* `CDList` *Dreamy List* - a list-type structure. Allows the creation of lists that can be filled with new entries or inserted/deleted from the middle of the list.
* `CDMap` *Dreamy Map* - a map-type structure that consists of a key-value pair of any types. Can contain different values under the same key name.
* `CDStack` *Dreamy Stack* - a stack-type structure that allows pushing new values on top of the stack and popping them right back. Based on the *Dreamy List* type and can use its functions.

Structures are templates and support any value types (even pointers, but they need to be manually deleted).
Usage examples can be found in the `UsageExample.cpp` file that isn't required for the structures to work.

Building
--------

In order to build a project with Dreamy Structures, the source files need to be included into the project (preferably in the headers folder) and need to have `DataStructures.h` file included into source files.