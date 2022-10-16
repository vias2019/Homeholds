#pragma once
#include <vector> //vector data structure
#include <unordered_map> // hash table structure
#include <string> 
using namespace std;

class Homeholds {

   /*"hash" is a hash table which stores information about unique addresses. the value is the number of occupants and an address of residence.*/
   unordered_map <string, pair<int, string>> hash;

   /*"database" is a vector of tuples of strings, which stores information about occupants(address code, last name, first name, address, city, state, age)*/
   vector<tuple<string, string, string, string, string, string, int>> database;

   /* readFile() function reads data from input.txt file (stored in the same location) and calls parseRowsToDatabase() function*/
   void readFromFile();
      

   /*parseRowsToDatabase(string str) parses a row by removing quotes, removes dividing strings commas, and saves all data from a line in a temporary vector of strings called "temp". The function calls addToHash() function. "convert" variable builds a tuple from data in the "temp" variable. Finally,  "convert" is pushed to the "database" vector. */
   void parseRowsToDatabase(string str); 
   

   /*toClean() function cleans a string from any white space and punctuation in order to build an address code. Since entries for the same address might be different, for example, some are in lower case, some have extra punctuation or additional space, the address code helps to make the same entries match. The function returns an address code.*/
   string toClean(string str);

   /* addToHash() function appends data to the hash table and counts residence occupants. The key  is an address code and value is a pair of number of occupants and address name.*/
   void addToHash(string str, string str1);

   /*printOutput() function prints data from "hashtable" and "database" to console and ouput.txt file.*/
   void printOutput(); 

   // save output to output.txt file
   void saveToFile(string text); 

public:     
   /*runFunction() is a driver function which runs the application. it reads from a file, sorts data in the "database" table, and prints an output to Console and a file.*/
   void runFunction();

   //to give "Test" class a "friend" status, so it will have access to the private properties of "Homeholds" class
   friend class Test;

};
