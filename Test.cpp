#include <iostream> 
#include <unordered_map> // hash table
#include <string>
#include <tuple>
#include "Homeholds.h"
#include "Test.h"

using namespace std;


void Test::test_toClean(string test, string expected) {
   Homeholds obj;
   string actual = obj.toClean(test);
   
   if (actual == expected) {
      cout << "toClean(string str) PASSED" << endl;
   }
   else {
      cout << "toClean(string str) FAILED" << endl;
   }
}


void Test::test_addToHash(string input1, string input2) {
   Homeholds obj;
   obj.addToHash(input1, input2);
   auto it = obj.hash.find(input1);
   if (it == obj.hash.end()) {
      cout << "addToHash(string str1, string str2) FAILED" << endl;
   }
   else {
      cout << "addToHash(string str1, string str2) PASSED" << endl;
   }
}

void Test::test_parseRowsToDatabase(string str, tuple< string, string, string, string, string, string, int> expected) {
   Homeholds obj;
   obj.parseRowsToDatabase(str);

   int len = obj.database.size();

   //get last added element from the database
   tuple< string, string, string, string, string, string, int>  actual = obj.database[len - 1];

   //get the first element from the tuple
   string code = get<0>(obj.database[len - 1]);

   //search in the hash table
   auto it = obj.hash.find(code);
   
   //if expected differs from actual in values - the parseRowsToDatabase(string str) function fails
   if (expected != actual) {
      cout << "parseRowsToDatabase(string str) FAILED (tuples are with different values)" << endl;
   }
   //if key is not found in the hash, parseRowsToDatabase(string str) function failed to update the hash table
   else {
      if (it == obj.hash.end()) {
         cout << "parseRowsToDatabase(string str) FAILED (hash table insertion error)" << endl;
      }
      else {
         cout << "parseRowsToDatabase(string str) PASSED" << endl;
      }
   }
}







