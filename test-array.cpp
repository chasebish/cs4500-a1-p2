#include <assert.h>
#include <stdio.h>
#include "array.h"
#include "object.h"
#include "string.h"
#include "bool_array.h"
#include "int_array.h"
#include "float_array.h"
#include "string_array.h"

void FAIL() { exit(1); }
void OK(const char* m) { printf("%s\n", m); }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

bool float_equals(float f1, float f2) {
	return (f1 - f2) > 0.01 || (f1 - f2) < -0.01;
}
	
void test1a() { // push
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
    OK("1-array");
}

void test1b() { // push
    BoolArray* arr = new BoolArray();
    t_true(arr->size() == 0);
    arr->push(1);
    t_true(arr->bool_get(0) == 1);
    t_true(arr->size() == 1);
    arr->push(0);
    arr->push(1);
    t_true(arr->bool_get(1) == 0);
    t_true(arr->bool_get(2) == 1);
    t_true(arr->index_of(0) == 1);
    t_true(arr->index_of(1) == 0);
    delete arr;
    OK("1-bool");
}

void test1i() { // push
    IntArray* arr = new IntArray();
    t_true(arr->size() == 0);
    arr->push(-1);
    t_true(arr->int_get(0) == -1);
    t_true(arr->size() == 1);
    arr->push(10);
    arr->push(23);
    t_true(arr->int_get(1) == 10);
    t_true(arr->int_get(2) == 23);
    t_true(arr->index_of(10) == 1);
    t_true(arr->index_of(23) == 2);
    delete arr;
    OK("1-integer");
}

void test1f() { // push
    FloatArray* arr = new FloatArray();
    t_true(arr->size() == 0);
    arr->push(1.2);
    t_true(float_equals(arr->float_get(0), 1.2));
    t_true(arr->size() == 1);
    arr->push(2.3);
    arr->push(-12.5);
    t_true(float_equals(arr->float_get(1), 2.3));
    t_true(float_equals(arr->float_get(2), -12.5));
    t_true(arr->index_of(2.3) == 1);
    t_true(arr->index_of(-12.5) == 2);
    delete arr;
    OK("1-float");
}

void test1s() { // push
    StringArray* arr = new StringArray();
    t_true(arr->size() == 0);
    String* s1 = new String("");
    String* s2 = new String("hello");
    String* s3 = new String("world");
    arr->push(s1);
    t_true(arr->str_get(0)->equals(s1));
    t_true(arr->size() == 1);
    arr->push(s2);
    arr->push(s3);
    t_true(arr->str_get(1)->equals(s2));
    t_true(arr->str_get(2)->equals(s3));
    t_true(arr->index_of(s2) == 1);
    t_true(arr->index_of(s3) == 2);
    delete arr;
    delete s1;
    delete s2;
    delete s3;
    OK("1-string");
}

void test2a() { // add
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
    OK("2-array");
}

void test2b() { // add
    BoolArray* arr = new BoolArray();
    bool b1 = 1;
    bool b2 = 0;
    bool b3 = 1;
    bool b4 = 1;
    bool b5 = 0;
    arr->add(0, b1); // 2
    arr->add(0, b2); // 0
    arr->add(2, b3); // 4
    arr->add(1, b4); // 1
    arr->add(3, b5); // 3
    t_true(arr->bool_get(0) == b2);
    t_true(arr->bool_get(1) == b4);
    t_true(arr->bool_get(2) == b1);
    t_true(arr->bool_get(3) == b5);
    t_true(arr->bool_get(4) == b3);
    delete arr;
    OK("2-bool");
}

void test2i() { // add
    IntArray* arr = new IntArray();
    int i1 = 10;
    int i2 = 55;
    int i3 = -12;
    int i4 = 66;
    int i5 = -100;
    arr->add(0, i1); // 2
    arr->add(0, i2); // 0
    arr->add(2, i3); // 4
    arr->add(1, i4); // 1
    arr->add(3, i5); // 3
    t_true(arr->int_get(0) == i2);
    t_true(arr->int_get(1) == i4);
    t_true(arr->int_get(2) == i1);
    t_true(arr->int_get(3) == i5);
    t_true(arr->int_get(4) == i3);
    delete arr;
    OK("2-integer");
}

void test2f() { // add
    FloatArray* arr = new FloatArray();
    float f1 = 12.4;
    float f2 = -6.9;
    float f3 = -115.0;
    float f4 = -678.9993;
    float f5 = 123.45;
    arr->add(0, f1); // 2
    arr->add(0, f2); // 0
    arr->add(2, f3); // 4
    arr->add(1, f4); // 1
    arr->add(3, f5); // 3
    t_true(float_equals(arr->float_get(0), f2));
    t_true(float_equals(arr->float_get(1), f4));
    t_true(float_equals(arr->float_get(2), f1));
    t_true(float_equals(arr->float_get(3), f5));
    t_true(float_equals(arr->float_get(4), f3));
    delete arr;
    OK("2-float");
}

void test2s() { // add
    StringArray* arr = new StringArray();
    String* s1 = new String("this");
    String* s2 = new String("is");
    String* s3 = new String("too");
    String* s4 = new String("many");
    String* s5 = new String("tests");
    arr->add(0, s1); // 2
    arr->add(0, s2); // 0
    arr->add(2, s3); // 4
    arr->add(1, s4); // 1
    arr->add(3, s5); // 3
    t_true(arr->str_get(0)->equals(s2));
    t_true(arr->str_get(1)->equals(s4));
    t_true(arr->str_get(2)->equals(s1));
    t_true(arr->str_get(3)->equals(s5));
    t_true(arr->str_get(4)->equals(s3));
    delete arr;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    OK("2-string");
}

void test3a() {
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
    
    OK("3-array");
}

void test3b() {
    // addall
    BoolArray* arr = new BoolArray();
    bool b1 = 0;
    bool b2 = 1;
    bool b3 = 0;
    bool b4 = 1;
   	bool b5 = 0;
    arr->push(b1);
    arr->push(b2);
    arr->push(b3);
    BoolArray* arr2 = new BoolArray();
    arr2->push(b4);
    arr2->push(b5);
    arr2->add_all(0, arr);

    t_true(arr2->bool_get(0) == (b1));
    t_true(arr2->bool_get(1) == (b2));
    t_true(arr2->bool_get(2) == (b3));
    t_true(arr2->bool_get(3) == (b4));
    t_true(arr2->bool_get(4) == (b5));
    
    delete arr;
    delete arr2;
    OK("3-bool");
}

void test3i() {
    // addall
    IntArray* arr = new IntArray();
    int i1 = 5;
    int i2 = -5;
    int i3 = 10;
    int i4 = 23;
    int i5 = 21239;
    arr->push(i1);
    arr->push(i2);
    arr->push(i3);
    IntArray* arr2 = new IntArray();
    arr2->push(i4);
    arr2->push(i5);
    arr2->add_all(0, arr);

    t_true(arr2->int_get(0) == (i1));
    t_true(arr2->int_get(1) == (i2));
    t_true(arr2->int_get(2) == (i3));
    t_true(arr2->int_get(3) == (i4));
    t_true(arr2->int_get(4) == (i5));
    
    delete arr;
    delete arr2;
    
    OK("3-integer");
}
void test3f() {
    // addall
    FloatArray* arr = new FloatArray();
    float f1 = -1.0;
    float f2 = 2.56;
    float f3 = 8.45;
    float f4 = 6.2;
    float f5 = -13.4;
    arr->push(f1);
    arr->push(f2);
    arr->push(f3);
    FloatArray* arr2 = new FloatArray();
    arr2->push(f4);
    arr2->push(f5);
    arr2->add_all(0, arr);

    t_true(float_equals(arr2->float_get(0), f1));
    t_true(float_equals(arr2->float_get(1), f2));
    t_true(float_equals(arr2->float_get(2), f3));
    t_true(float_equals(arr2->float_get(3), f4));
    t_true(float_equals(arr2->float_get(4), f5));
    
    delete arr;
    delete arr2;
    OK("3-float");
}

void test3s() {
    // addall
    StringArray* arr = new StringArray();
    String* s1 = new String("");
    String* s2 = new String("hello");
    String* s3 = new String("pizza");
    String* s4 = new String("teehee");
    String* s5 = new String("lalala");
    arr->push(s1);
    arr->push(s2);
    arr->push(s3);
    StringArray* arr2 = new StringArray();
    arr2->push(s4);
    arr2->push(s5);
    arr2->add_all(0, arr);

    t_true(arr2->str_get(0)->equals(s1));
    t_true(arr2->str_get(1)->equals(s2));
    t_true(arr2->str_get(2)->equals(s3));
    t_true(arr2->str_get(3)->equals(s4));
    t_true(arr2->str_get(4)->equals(s5));
    
    delete arr;
    delete arr2;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    
    OK("3-string");
}

void test4a() { // remove and clear
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
    
    OK("4-array");
}

void test4b() { // remove and clear
    BoolArray* arr = new BoolArray();
    bool b1 = 0;
    bool b2 = 0;
    bool b3 = 1;
    bool b4 = 1;
    bool b5 = 0;
    arr->push(b1);
    arr->push(b2);
    arr->push(b3);
    arr->push(b4);
    arr->push(b5);
    t_true(arr->bool_remove(3) == b4);
    t_true(arr->size() == 4);
    t_true(arr->bool_remove(3) == b5);
    t_true(arr->bool_remove(0) == b1);
    arr->clear();
    t_true(arr->size() == 0);
    
    delete arr;
    OK("4-bool");
}

void test4i() { // remove and clear
    IntArray* arr = new IntArray();
    int i1 = -1;
    int i2 = -5;
    int i3 = 2;
    int i4 = 28;
    int i5 = 90;
    arr->push(i1);
    arr->push(i2);
    arr->push(i3);
    arr->push(i4);
    arr->push(i5);
    t_true(arr->int_remove(3) == i4);
    t_true(arr->size() == 4);
    t_true(arr->int_remove(3) == i5);
    t_true(arr->int_remove(0) == i1);
    arr->clear();
    t_true(arr->size() == 0);
    
    delete arr;
    OK("4-integer");
}

void test4f() { // remove and clear
    FloatArray* arr = new FloatArray();
    float f1 = 10.2;
    float f2 = 41.11;
    float f3 = 51.22;
    float f4 = -13.4;
    float f5 = -164;
    arr->push(f1);
    arr->push(f2);
    arr->push(f3);
    arr->push(f4);
    arr->push(f5);
    t_true(float_equals(arr->float_remove(3), f4));
    t_true(arr->size() == 4);
    t_true(float_equals(arr->float_remove(3), f5));
    t_true(float_equals(arr->float_remove(0), f1));
    arr->clear();
    t_true(arr->size() == 0);
    
    delete arr;
    OK("4-float");
}

void test4s() { // remove and clear
    StringArray* arr = new StringArray();
    String* s1 = new String("don't");
    String* s2 = new String("read");
    String* s3 = new String("this");
    String* s4 = new String("message");
    String* s5 = new String("please");
    arr->push(s1);
    arr->push(s2);
    arr->push(s3);
    arr->push(s4);
    arr->push(s5);
    t_true(arr->str_remove(3)->equals(s4));
    t_true(arr->size() == 4);
    t_true(arr->str_remove(3)->equals(s5));
    t_true(arr->str_remove(0)->equals(s1));
    arr->clear();
    t_true(arr->size() == 0);
    
    delete arr;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
   
    OK("4-string");
}

void test5a() {
	//testing if two arrays are equal
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

    OK("5-array");
}

void test5b() {
	//testing if two arrays are equal
    BoolArray* arr1 = new BoolArray();
    BoolArray* arr2 = new BoolArray();
    bool b1 = 0;
    bool b2 = 1;
    bool b3 = 0;

    arr1->push(b1);
    arr2->push(b1);
    arr1->push(b2);
    arr2->push(b2);
    arr1->push(b3);
    arr2->push(b3);

    t_true(arr1->hash() > 0);
    t_true(arr2->equals(arr1));
    t_true(arr1->equals(arr2));

    arr1->remove(1);

    t_false(arr1->equals(arr2));
    t_false(arr2->equals(arr1));
    
    delete arr1;
    delete arr2;
    OK("5-bool");
}

void test5i() {
	//testing if two arrays are equal
    IntArray* arr1 = new IntArray();
    IntArray* arr2 = new IntArray();
    int i1 = 24;
    int i2 = -10;
    int i3 = 138913;

    arr1->push(i1);
    arr2->push(i1);
    arr1->push(i2);
    arr2->push(i2);
    arr1->push(i3);
    arr2->push(i3);

    t_true(arr1->hash() > 0);
    t_true(arr2->equals(arr1));
    t_true(arr1->equals(arr2));

    arr1->remove(1);

    t_false(arr1->equals(arr2));
    t_false(arr2->equals(arr1));
    
    delete arr1;
    delete arr2;
    OK("5-integer");
}

void test5f() {
	//testing if two arrays are equal
    FloatArray* arr1 = new FloatArray();
    FloatArray* arr2 = new FloatArray();
    float f1 = 1.0;
    float f2 = -12.3;
    float f3 = 6.59;

    arr1->push(f1);
    arr2->push(f1);
    arr1->push(f2);
    arr2->push(f2);
    arr1->push(f3);
    arr2->push(f3);

    t_true(arr1->hash() > 0);
    t_true(arr2->equals(arr1));
    t_true(arr1->equals(arr2));

    arr1->remove(1);

    t_false(arr1->equals(arr2));
    t_false(arr2->equals(arr1));
    
    delete arr1;
    delete arr2;

    OK("5-float");
}

void test5s() {
	//testing if two arrays are equal
    StringArray* arr1 = new StringArray();
    StringArray* arr2 = new StringArray();
    String* s1 = new String("");
    String* s2 = new String("hello");
    String* s3 = new String("haha");

    arr1->push(s1);
    arr2->push(s1);
    arr1->push(s2);
    arr2->push(s2);
    arr1->push(s3);
    arr2->push(s3);

    t_true(arr1->hash() > 0);
    t_true(arr2->equals(arr1));
    t_true(arr1->equals(arr2));

    arr1->remove(1);

    t_false(arr1->equals(arr2));
    t_false(arr2->equals(arr1));
    
    delete arr1;
    delete arr2;
    delete s1;
    delete s2;
    delete s3;

    OK("5-string");
}

void test6a() {
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

    OK("6-array");
}

void test6b() {
    BoolArray* arr = new BoolArray();
    bool b1 = 0;
    bool b2 = 1;
    bool b3 = 1;
    bool b4 = 1;
    bool b5 = 0;
    arr->push(b1);
    arr->push(b2);
    arr->push(b3);
    arr->push(b4);
    arr->push(b5);
    t_true(arr->set(0, b3) == b1);
    t_true(arr->set(0, b1) == b3);
    t_true(arr->set(3, b5) == b4);
    t_true(arr->bool_get(3) == b5);
    t_true(arr->size() == 5);
    
    delete arr;
    OK("6-bool");
}

void test6i() {
    IntArray* arr = new IntArray();
    int i1 = 23;
    int i2 = 34;
    int i3 = 45;
    int i4 = 56;
    int i5 = -789;
    arr->push(i1);
    arr->push(i2);
    arr->push(i3);
    arr->push(i4);
    arr->push(i5);
    t_true(arr->set(0, i3) == i1);
    t_true(arr->set(0, i1) == i3);
    t_true(arr->set(3, i5) == i4);
    t_true(arr->int_get(3) == i5);
    t_true(arr->size() == 5);
    
    delete arr;
    OK("6-integer");
}

void test6f() {
    FloatArray* arr = new FloatArray();
    float f1 = 22.1;
    float f2 = 3455.0;
    float f3 = 234.0;
    float f4 = -21;
    float f5 = -890.2;
    arr->push(f1);
    arr->push(f2);
    arr->push(f3);
    arr->push(f4);
    arr->push(f5);
    t_true(float_equals(arr->set(0, f3), f1));
    t_true(float_equals(arr->set(0, f1), f3));
    t_true(float_equals(arr->set(3, f5), f4));
    t_true(float_equals(arr->float_get(3), f5));
    t_true(arr->size() == 5);
    
    delete arr;
    OK("6-float");
}

void test6s() {
    StringArray* arr = new StringArray();
    String* s1 = new String("I");
    String* s2 = new String("hope");
    String* s3 = new String("these");
    String* s4 = new String("tests");
    String* s5 = new String("run");
    arr->push(s1);
    arr->push(s2);
    arr->push(s3);
    arr->push(s4);
    arr->push(s5);
    t_true(arr->set(0, s3)->equals(s1));
    t_true(arr->set(0, s1)->equals(s3));
    t_true(arr->set(3, s5)->equals(s4));
    t_true(arr->str_get(3)->equals(s5));
    t_true(arr->size() == 5);
    
    delete arr;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;

    OK("6-string");
}

int main(int argc, char** argv) {
    test1a();
    test1b();
    test1i();
    test1f();
    test1s();
    test2a();
    test2b();
    test2i();
    test2f();
    test2s();
    test3a();
    test3b();
    test3i();
    test3f();
    test3s();
    test4a();
    test4b();
    test4i();
    test4f();
    test4s();
    test5a();
    test5b();
    test5i();
    test5f();
    test5s();
    test6a();
    test6b();
    test6i();
    test6f();
    test6s();
}
