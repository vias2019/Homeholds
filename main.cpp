#include "Homeholds.h"
#include "Test.h"
using namespace std;

int main() {

   //The program asks a user if they want to run a program or tests.
   string userResponse;
   cout << "Would you like to run tests? (y/n): ";
   cin >> userResponse;

   // depends on the user response - "y" or "n", the program will run either the program or tests
   if (userResponse == "n") {
      Homeholds instance;
      instance.runFunction();
   }
   else {
      //testing section
      cout << endl;
      Test obj;
      obj.test_toClean("125  3 ave", "1253ave");

      obj.test_addToHash("123mainst", "123 Main St.");

      //negative test case
      obj.test_parseRowsToDatabase("\"Lisa\",\"Smith\",\"123 main st.\",\"seattle\",\"wa\",\"43\"", { "123wallst", "Smith", "Lisa", "123 wall st.", "seattle", "wa", 43 });

      //negativa test case
      obj.test_parseRowsToDatabase("\"Tom\",\"Doe\",\"3 main st.\",\"Boston\",\"MA\",\"33\"", { "3mainst", "Doe", "Tom", "3 main st.", "boston", "MA", 33 });

      //negativa test case
      obj.test_parseRowsToDatabase("\"Tom\",\"Doe\",\"3 main st.\",\"Boston\",\"MA\",\"33\"", { "3mainst", "Doe", "Tom", "3 main st.", "Boston", "MA", 33 });
   }

   cout << "The End" << endl;
}