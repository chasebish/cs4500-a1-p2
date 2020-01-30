//lang::CwC
#pragma once

#include "object.h"
#include "string.h"

//this is an array of objects 
//the elements of the array are not owned by the array
class Array : public Object {
    public:        
        //empty constructor
        Array() : Object() {}
        
        // creates an array of the given size
        Array(size_t array_size) : Object() {}

        //deconstructor
        virtual ~Array() {}

        // returns the number of elements in this array
        virtual size_t size() {}

        // returns the index of the given object in this array
        // returns an index greater than this array's size if there is no such element
        size_t index_of(Object* o) {}

        // pushes the given object onto the end of this array
        // @pre the given object is not null
        // @post size = size + 1
        // @invariant no elements are null
        void push(Object* o) {}
        
        // add the given element to the array at the given index
        // @pre the given object is not null
        // @post size = size + 1
        // @invariant no elements are null
        void add(size_t idx, Object* o) {}
        
        //returns the element of the array at the given index
        //@pre the index is in bounds
        Object* get(size_t idx) {}

        //sets the given index to the given element
        //@returns the overwritten object
        Object* set(size_t idx, Object* o) {}

        //removes the object at the given index
        //@pre the index is in bounds
        //@return the overwritten object
        Object* remove(size_t idx) {}

        //removes all elements from the array
        virtual void clear() {}

        //checks if this array is equal to the given object
        virtual bool equals(Object* o) {}

        //hash function
        virtual size_t hash() {}
};
