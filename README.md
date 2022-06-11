# Dreamy Structures

### This repository is now deprecated and therefore archived because it was nothing but me learning how to implement my own data structures and also early unwillingness to learn data structures from STL!

----

This is a small collection of custom made data structures (templates) that are easy to understand and use. Uses `std::vector` at its base (previously hasn't used it).

Includes:
* `DSArray` - a standard array structure that allows the creation of resizable arrays of any type.
* `DSList` - a list-type structure. Allows the creation of lists that can be filled with new entries or inserted/deleted from the middle of the list.
* `DSMap` - a map-type structure that consists of a key-value pair of any types. Can contain different values under the same key name.
* `DSStack` - a stack-type structure that allows pushing new values on top of the stack and popping them right back. Based on the `DSList` type and can use its functions.

Structures are templates and support any value types (even pointers, but they need to be manually deleted).
Usage examples can be found in the `UsageExample.cpp` file that isn't required for the structures to work.

Building
--------

In order to build a project with Dreamy Structures, the source files need to be included into the project (preferably in the headers folder) and need to have `DataStructures.h` file included into source files.