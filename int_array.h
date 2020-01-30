#pragma once

#include "array.h"
#include "object.h"
#include <assert.h>

// this is an array of integer values 
class IntArray : public Array {
    public:
        //empty constructor
        IntArray() {}
        
        // creates an array of the given size
        IntArray(size_t array_size) {}

        // copies the elements of the given array into this array
        IntArray(IntArray* copy_array) {}

        //deconstructor
        virtual ~IntArray() {}

        // returns the index of the given integer in this array
        // returns an index greater than this array's size if there is no such element
        virtual size_t index_of(int n) {}

        // pushes the given integer onto the end of this array
        // @post size = size + 1
        virtual void push(int n) {}
        
        // add the given element to the array at the given index
        // @post size = size + 1
        virtual void add(size_t idx, int n) {}
        
        //adds all given elements to the array at the given index
        //@post size = size + a -> size_
        virtual void add_all(size_t idx, IntArray* a) {}
        
        //sets the given index to the given element
        //@returns the overwritten integer value
        virtual int set(size_t idx, int n) {}
        
        //returns the element of the array at the given index
        //@pre the index is in bounds
        virtual int int_get(size_t idx) {}

        //removes the integer at the given index
        //@pre the index is in bounds
        //@return the overwritten integer value
        virtual int int_remove(size_t idx) {}
};
