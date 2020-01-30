#pragma once

#include <stdlib.h>

/**
 * Object - generic object type
 *
 * @author Zoe Corning, Rucha Khanolkar
 */
 
class Object {
    public:
        Object() {}
        
        /**
         * tests if this Object is equal to the given Object
         */
        virtual bool equals(Object* other) {}

        /**
         * hashes this Object
         */
        virtual size_t hash() {}
};
