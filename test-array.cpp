#include <assert.h>
#include <stdio.h>
#include "array.h"
#include "object.h"

void FAIL() { exit(1); }
void OK(const char* m) { printf("%s\n", m); }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

void test1() { // push
    Array* arr = new Array();
    t_true(arr->size() == 0);
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    arr->push(o1);
    t_true(arr->get(0) == o1);
    t_true(arr->size() == 1);
    arr->push(o2);
    arr->push(o3);
    t_true(arr->get(1) == o2);
    t_true(arr->get(2) == o3);
    t_true(arr->index_of(o2) == 1);
    t_true(arr->index_of(o3) == 2);
    delete arr;
    delete o1;
    delete o2;
    delete o3;
    OK("1");
}

void test2() { // add
    Array* arr = new Array();
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* o4 = new Object();
    Object* o5 = new Object();
    arr->add(0, o1); // 2
    arr->add(0, o2); // 0
    arr->add(2, o3); // 4
    arr->add(1, o4); // 1
    arr->add(3, o5); // 3
    t_true(arr->get(0)->equals(o2));
    t_true(arr->get(1)->equals(o4));
    t_true(arr->get(2)->equals(o1));
    t_true(arr->get(3)->equals(o5));
    t_true(arr->get(4)->equals(o3));
    delete arr;
    delete o1;
    delete o2;
    delete o3;
    delete o4;
    delete o5;
    OK("2");
}

void test3() {
    // addall
    Array* arr = new Array();
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* o4 = new Object();
    Object* o5 = new Object();
    arr->push(o1);
    arr->push(o2);
    arr->push(o3);
    Array* arr2 = new Array();
    arr2->push(o4);
    arr2->push(o5);
    arr2->add_all(0, arr);

    t_true(arr2->get(0)->equals(o1));
    t_true(arr2->get(1)->equals(o2));
    t_true(arr2->get(2)->equals(o3));
    t_true(arr2->get(3)->equals(o4));
    t_true(arr2->get(4)->equals(o5));
    
    delete arr;
    delete arr2;
    delete o1;
    delete o2;
    delete o3;
    delete o4;
    delete o5;
    
    OK("3");
}

void test4() {
    // remove
    // clear
    
    Array* arr = new Array();
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* o4 = new Object();
    Object* o5 = new Object();
    arr->push(o1);
    arr->push(o2);
    arr->push(o3);
    arr->push(o4);
    arr->push(o5);
    t_true(arr->remove(3)->equals(o4));
    t_true(arr->size() == 4);
    t_true(arr->remove(3)->equals(o5));
    t_true(arr->remove(0)->equals(o1));
    arr->clear();
    t_true(arr->size() == 0);
    
    delete arr;
    delete o1;
    delete o2;
    delete o3;
    delete o4;
    delete o5;
    
    OK("4");
}

void test5() {
    Array* arr1 = new Array();
    Array* arr2 = new Array();
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();

    arr1->push(o1);
    arr2->push(o1);
    arr1->push(o2);
    arr2->push(o2);
    arr1->push(o3);
    arr2->push(o3);

    t_true(arr1->hash() > 0);
    t_true(arr2->equals(arr1));
    t_true(arr1->equals(arr2));

    arr1->remove(1);

    t_false(arr1->equals(arr2));
    t_false(arr2->equals(arr1));
    
    delete arr1;
    delete arr2;
    delete o1;
    delete o2;
    delete o3;

    OK("5");
}

void test6() {
    Array* arr = new Array();
    Object* o1 = new Object();
    Object* o2 = new Object();
    Object* o3 = new Object();
    Object* o4 = new Object();
    Object* o5 = new Object();
    arr->push(o1);
    arr->push(o2);
    arr->push(o3);
    arr->push(o4);
    arr->push(o5);
    t_true(arr->set(0, o3)->equals(o1));
    t_true(arr->set(0, o1)->equals(o3));
    t_true(arr->set(3, o5)->equals(o4));
    t_true(arr->get(3)->equals(o5));
    t_true(arr->size() == 5);
    
    delete arr;
    delete o1;
    delete o2;
    delete o3;
    delete o4;
    delete o5;

    OK("6");
}

int main(int argc, char** argv) {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}
