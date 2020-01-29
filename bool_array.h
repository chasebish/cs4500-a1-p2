#pragma once

#include "array.h"
#include "object.h"
#include <assert.h>

// this is an array of boolean values 
class BoolArray : public Array {
    public:
        //empty constructor
        BoolArray() {}
        
        // creates an array of the given size
        BoolArray(size_t array_size) {}

        // copies the elements of the given array into this array
        BoolArray(BoolArray* copy_array) {}

        //deconstructor
        virtual ~BoolArray() {}

        // returns the index of the given boolean in this array
        // returns an index greater than this array's size if there is no such element
        virtual size_t index_of(bool b) {}

        // pushes the given boolean onto the end of this array
        // @post size = size + 1
        virtual void push(bool b) {}
        
        // add the given element to the array at the given index
        // @post size = size + 1
        virtual void add(size_t idx, bool b) {}
        
        //adds all given elements to the array at the given index
        //@post size = size + a -> size_
        virtual void add_all(size_t idx, BoolArray* a) {}

        //sets the given index to the given element
        //@returns the overwritten boolean value
        virtual bool set(size_t idx, bool b) {}

        //returns the element of the array at the given index
        //@pre the index is in bounds
        virtual bool bool_get(size_t idx) {}

        //removes the boolean at the given index
        //@pre the index is in bounds
        //@return the overwritten boolean value
        virtual bool bool_remove(size_t idx) {}
};
