#pragma once

#include "object.h"
#include "string.h"
#include <assert.h>
#include "array.h"

// this is an array of String* values 
// the strings in this array are not owned
class StringArray : public Array {
    public:
        //empty constructor
        StringArray() {}
        
        // creates an array of the given size
        StringArray(size_t array_size) {}

        // copies the elements of the given array String*o this array
        StringArray(StringArray* copy_array) {}

        //deconstructor
        virtual ~StringArray() {}

        // returns the index of the given String in this array
        // returns an index greater than this array's size if there is no such element
        virtual size_t index_of(String* s) {}

        // pushes the given String onto the end of this array
        // @post size = size + 1
        virtual void push(String* s) {}
        
        // add the given element to the array at the given index
        // @post size = size + 1
        virtual void add(size_t idx, String* s) {}
        
        //adds all given elements to the array at the given index
        //@post size = size + a -> size_
        virtual void add_all(size_t idx, StringArray* a) {}

        //sets the given index to the given element
        //@returns the overwritten String value
        virtual String* set(size_t idx, String* s) {}
        
        //returns the element of the array at the given index
        //@pre the index is in bounds
        virtual String* str_get(size_t idx) {}
        
        //removes the string at the given index
        //@pre the index is in bounds
        //@return the overwritten String value
        virtual String* str_remove(size_t idx) {}
};
