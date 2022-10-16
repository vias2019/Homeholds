#pragma once

#include <iostream> 
using namespace std;

class Test {
public:
   //toClean(string str) 
   //to test toClean(string str) function to make sure that address codes are properly built.
   void test_toClean(string test, string expected); 
   
   //addToHash(string str, string str1)
   //to test addToHash(string str, string str1) function to make sure that the function adds an element to the hash table
   void test_addToHash(string input1, string input2);

   //parseRowsToDatabase(string str)
   //to test parseRowsToDatabase(string str) function to make sure that it adds values to the hash table and the database vector
   void test_parseRowsToDatabase(string str, tuple< string, string, string, string, string, string, int> expected);

};