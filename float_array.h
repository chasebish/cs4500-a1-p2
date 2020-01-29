#pragma once

#include "array.h"
#include "object.h"
#include <assert.h>

// this is an array of float values 
class FloatArray : public Array {
    public:
        //empty constructor
        FloatArray() {}

        // creates an array of the given size
        FloatArray(size_t array_size) {}

        // copies the elements of the given array floato this array
        FloatArray(FloatArray* copy_array) {}

        //deconstructor
        virtual ~FloatArray() {}

        // returns the index of the given float in this array
        // returns an index greater than this array's size if there is no such element
        virtual size_t index_of(float f) {}

        // pushes the given float onto the end of this array
        // @post size = size + 1
        virtual void push(float f) {}
        
        // add the given element to the array at the given index
        // @post size = size + 1
        virtual void add(size_t idx, float f) {}
        
        //adds all given elements to the array at the given index
        //@post size = size + a -> size_
        virtual void add_all(size_t idx, FloatArray* a) {}
        
        //sets the given index to the given element
        //@returns the overwritten float value
        virtual float set(size_t idx, float f) {}
        
        //returns the element of the array at the given index
        //@pre the index is in bounds
        virtual float float_get(size_t idx) {}

        //removes the float at the given index
        //@pre the index is in bounds
        //@return the overwritten float value
        virtual float float_remove(size_t idx) {}
};
