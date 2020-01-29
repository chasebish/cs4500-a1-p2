#pragma once

#include <string.h>
#include "object.h"
#include <assert.h>

/**
 * This is an immutable String class
 * It owns its own value and is responsible for freeing its char array
 */
class String : public Object {
    public:

        // initializes to empty string
        String() : Object() {}

        // creates a string using the given char ptr
        // @pre the given char array is null terminated
        String(const char* s) : Object() {}

        // copy constructor for string
        // does full copy of the given strings value (does not take ownership)
        String(String* s) : Object() {}
        
        virtual ~String() {}


        // returns the size of this string
        size_t length() {}

        //gets the character at the given index
        char get(size_t indx) {}

        // same as concat but with just a char array
        // neither this nor the returned string is owned by this class
        String* concat(char* s) {}
        
        // concats this string and the given string
        String* concat(String* s) {}

         // returns true if this string is equal to the given object
        bool equals(Object* o) {}

        // hashes this string
        size_t hash() {}
};
