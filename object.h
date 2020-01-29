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
         * tests if this Object is equal to the given Object by checking pointers
         */
        virtual bool equals(Object* other) {}

        /**
         * hashes this Object by returning its pointer value
         */
        virtual size_t hash() {}
};
