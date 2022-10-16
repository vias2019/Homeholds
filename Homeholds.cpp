#include <iostream> //input
#include <fstream> //output
#include <string> 
#include <vector>
#include <tuple>
#include <algorithm> // sort()
#include <unordered_map> // hash table structure
#include "Homeholds.h"

using namespace std;

void Homeholds::readFromFile() {
   string line;
   //read from input.txt file
   ifstream myfile("input.txt");

   //open input.txt file, get a line
   if (myfile.is_open())
   {
      while (getline(myfile, line))
      {
         string a = line;
         // if line is not empty -> parse it
         if (a != "") {
            parseRowsToDatabase(line);
         }
      }
      myfile.close();
   }
   else cout << "Unable to open file";
}

void Homeholds::parseRowsToDatabase(string str) {
   string word = "";
   //temporary save words from a line to the "temp" vector
   vector <string> temp;

   // "insideQuotes" checks if quotes are at the beginning of a string or at the end. 
   bool insideQuotes = false;

   for (auto x : str) {

      if (x == '\"' && !insideQuotes) {
         insideQuotes = true;
      }
      else if (x == '\"' && insideQuotes) {
         temp.push_back(word);
         word = "";
         insideQuotes = false;
      }
      else if (x == ',' and !insideQuotes) {
         continue;
      }
      else {
         word = word + x;
      }
   }
   //"residenceCode" builds an address code for the hash table
   string residenceCode = toClean(temp[2]);

   // addToHash() function builds or appends data to the hash table.
   addToHash(residenceCode, temp[2]);

   //"convert" builds a tuple with information from the "temp" vector
   auto convert = make_tuple(residenceCode, temp[1], temp[0], temp[2], temp[3], temp[4], stoi(temp[5]));

   // A row is pushed to the "database" vector
   database.push_back(convert);
}

string Homeholds::toClean(string str) {
   string res = "";
   for (auto x : str) {
      // remove space and punctuation from a string
      if (x != '.' && x != ',' && x != ' ') {
         res = res + static_cast<char>(tolower(x));
      }
   }
   return res;
}

void Homeholds::addToHash(string str, string str1) {
   //"it" is an iterator to search a key in the hash table before inserting it.
   auto it = hash.find(str);
   if (it == hash.end()) {
      hash.insert({ str, {1, str1} });
   }
   else {
      //increases count for key (homehold)
      it->second.first = it->second.first + 1;
   }
}

/*printOutput() prints data from "hashtable" and "database" to console and ouput.txt file.*/
void Homeholds::printOutput() {
   for (auto x : hash) {
      string key = x.first;
      cout << "" << endl;

      //print an official address from key value(the second element in the pair)
      cout << x.second.second << " " << x.second.first << " occupant(s):" << endl;

      //print to file
      string toFile = x.second.second + " " + to_string(x.second.first) + " occupants:";
      saveToFile("");
      saveToFile(toFile);

      //print a list of occupants for each homehold
      for (auto i = 0; i < database.size(); i++) {
         if (key == get<0>(database[i])) {
            if (get<6>(database[i]) > 18) {
               cout << get<2>(database[i]) << " " << get<1>(database[i]) << " " << get<3>(database[i]) << " " << get<4>(database[i]) << " " << get<5>(database[i]) << " " << get<6>(database[i]) << endl;
               string out = get<2>(database[i]) + " " + get<1>(database[i]) + " " + get<3>(database[i]) + " " + get<4>(database[i]) + " " + get<5>(database[i]) + " " + to_string(get<6>(database[i]));
               saveToFile(out);
            }
         }
      }
   }
}

void Homeholds::saveToFile(string text) {
   fstream file("output.txt", std::ios::app);
   //open and write to a file. If file doesn't exist, the system will create one.
   if (file.is_open())
   {
      file << text<< endl;
      file.close();
   }
}

/*runFunction() is a driver function which runs the application. It reads from a file, sorts data in the "database" table, and prints an output to Console and a file.*/
void Homeholds::runFunction(){
      readFromFile();
      sort(database.begin(), database.end());
      printOutput();
   }


