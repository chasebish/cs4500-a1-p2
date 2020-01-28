//lang::CwC
#pragma once

#include "object.h"
#include "string.h"

/**
 * An Array class to which bools can be added to and removed from.
 * author: chasebish */
class BoolArray : public Object {
public:
  /** CONSTRUCTORS & DESTRUCTORS **/

  /* Creates an Array of desired size */
  BoolArray(size_t size);

  /* Creates an Array of desired size */
  BoolArray(const size_t size);

  /* Copies the contents of an already existing Array */
  BoolArray(BoolArray* arr);

  /* Clears Array from memory */
  ~BoolArray();


  /** INHERITED METHODS **/

  /* Inherited from Object, checks equality between an Array and an Object */
  bool equals(bool obj);

  /* Inherited from Object, generates a hash for an Array */
  size_t hash();


  /** ARRAY METHODS **/
  
  /* Removes all elements from the Array */
  void clear();

  /* Adds an Array to existing contents */
  void concat(BoolArray* arr);

  /* Gets an bool at the given index */
  bool get(size_t index);

  /* Returns the index of the given bool, -1 if bool is not found */
  size_t index_of(bool to_find);

  /* Returns the current length of the contents in an Array */
  size_t length();

  /* Removes the last bool of the Array, returns the removed bool */
  bool pop();

  /* Adds an bool to the end of the Array, returns the new length */
  size_t push(bool to_add);

  /* Removes an bool at the given index, returns removed bool */
  bool remove(size_t index);

  /* Replaces an bool at the given index with the given bool, returns the replaced bool */
  bool replace(size_t index, bool to_add);
};

/**
 * An Array class to which floats can be added to and removed from.
 * author: chasebish */
class FloatArray : public Object {
public:
  /** CONSTRUCTORS & DESTRUCTORS **/

  /* Creates an Array of desired size */
  FloatArray(size_t size);

  /* Creates an Array of desired size */
  FloatArray(const size_t size);

  /* Copies the contents of an already existing Array */
  FloatArray(FloatArray* arr);

  /* Clears Array from memory */
  ~FloatArray();


  /** INHERITED METHODS **/

  /* Inherited from Object, checks equality between an Array and an Object */
  bool equals(Object* obj);

  /* Inherited from Object, generates a hash for an Array */
  size_t hash();


  /** ARRAY METHODS **/
  
  /* Removes all elements from the Array */
  void clear();

  /* Adds an Array to existing contents */
  void concat(FloatArray* toAdd);

  /* Gets an float at the given index */
  float get(size_t index);

  /* Returns the index of the given float, -1 if float is not found */
  size_t index_of(float to_find);

  /* Returns the current length of the contents in an Array */
  size_t length();

  /* Removes the last float of the Array, returns the removed float */
  float pop();

  /* Adds an float to the end of the Array, returns the new length */
  size_t push(float to_add);

  /* Removes an float at the given index, returns removed float */
  float remove(size_t index);

  /* Replaces a float at the given index with the given float, returns the replaced float */
  float replace(size_t index, float to_add);
};

/**
 * An Array class to which ints can be added to and removed from.
 * author: chasebish */
class IntArray : public Object {
public:
  /** CONSTRUCTORS & DESTRUCTORS **/

  /* Creates an Array of desired size */
  IntArray(size_t size);

  /* Creates an Array of desired size */
  IntArray(const size_t size);

  /* Copies the contents of an already existing Array */
  IntArray(IntArray* arr);

  /* Clears Array from memory */
  ~IntArray();


  /** INHERITED METHODS **/

  /* Inherited from Object, checks equality between an Array and an Object */
  bool equals(Object* obj);

  /* Inherited from Object, generates a hash for an Array */
  size_t hash();


  /** ARRAY METHODS **/
  
  /* Removes all elements from the Array */
  void clear();

  /* Adds an Array to existing contents */
  void concat(IntArray* arr);

  /* Gets an int at the given index */
  int get(size_t index);

  /* Returns the index of the given int, -1 if int is not found */
  size_t index_of(int to_find);

  /* Returns the current length of the contents in an Array */
  size_t length();

  /* Removes the last int of the Array, returns the removed int */
  int pop();

  /* Adds an int to the end of the Array, returns the new length */
  size_t push(int to_add);

  /* Removes an int at the given index, returns removed int */
  int remove(size_t index);

  /* Replaces an int at the given index with the given int, returns the replaced int */
  int replace(size_t index, int to_add);
};

/**
 * An Array class to which Strings can be added to and removed from.
 * author: chasebish */
class StringArray : public Object {
public:
  /** CONSTRUCTORS & DESTRUCTORS **/

  /* Creates an Array of desired size */
  StringArray(size_t size);

  /* Creates an Array of desired size */
  StringArray(const size_t size);

  /* Copies the contents of an already existing Array */
  StringArray(StringArray* arr);

  /* Clears Array from memory */
  ~StringArray();


  /** INHERITED METHODS **/

  /* Inherited from Object, checks equality between an Array and an Object */
  bool equals(Object* obj);

  /* Inherited from Object, generates a hash for an Array */
  size_t hash();


  /** ARRAY METHODS **/

  /* Removes all elements from the Array */
  void clear();

  /* Adds an StringArray to existing contents */
  void concat(StringArray* arr);

  /* Returns the index of the given String, -1 if String is not found */
  size_t index_of(String* to_find);

  /* Removes the last String of the Array, returns the removed String */
  String* pop();

  /* Gets a String at the given index */
  String* get(size_t index);

  /* Returns the current length of the contents in an Array */
  size_t length();

  /* Adds a String to the end of the Array, returns the new length */
  size_t push(String* to_add);

  /* Removes a String at the given index, returns removed String */
  String* remove(size_t index);

  /* Replaces a String at the given index with the given String, returns the replaced String */
  String* replace(size_t index, String* to_add);
};
