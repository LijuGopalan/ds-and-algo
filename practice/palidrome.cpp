#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

//facebook. Failed. 

//Function to check if a string can become a palindrome with one replacement. 

bool ispalindrome(string str) {

  int i = 0;
  int j = str.length()-1;

  while(i<j) {

    if(str[i] != str[j])
      return false;

    i++;
    j--;

  }
  return true;
}

bool canBePalindrome(string str) {

  int i = 0;
  int j = str.length()-1;

  while (i < j) { 

    if(str[i] != str[j]) {

      //replace left number with right
      int temp = str[i];
      str[i]=str[j];
      if(ispalindrome(str))
        return true;

      str[j]=temp;
      str[i]=temp;
      if(ispalindrome(str))
        return true;


    }

    i++;
    j--;

  }

  return false;
}






int main() {

   string testString1 = "abda";
    string testString2 = "abcbda";
    string testString3 = "aabb";
    string testString4 = "abcda";
    string testString5 = "racecar";
    string testString6 = "madam";
    string testString7 = "a"; // Single character string
    string testString8 = ""; // Empty string

    cout << "\"" << testString1 << "\" can be palindrome with one replacement: " << (canBePalindrome(testString1) ? "true" : "false") << endl; //true
    cout << "\"" << testString2 << "\" can be palindrome with one replacement: " << (canBePalindrome(testString2) ? "true" : "false") << endl; // false
    cout << "\"" << testString3 << "\" can be palindrome with one replacement: " << (canBePalindrome(testString3) ? "true" : "false") << endl; // true
    cout << "\"" << testString4 << "\" can be palindrome with one replacement: " << (canBePalindrome(testString4) ? "true" : "false") << endl; // false
    cout << "\"" << testString5 << "\" can be palindrome with one replacement: " << (canBePalindrome(testString5) ? "true" : "false") << endl; // true
    cout << "\"" << testString6 << "\" can be palindrome with one replacement: " << (canBePalindrome(testString6) ? "true" : "false") << endl; // true
    cout << "\"" << testString7 << "\" can be palindrome with one replacement: " << (canBePalindrome(testString7) ? "true" : "false") << endl; // true
    cout << "\"" << testString8 << "\" can be palindrome with one replacement: " << (canBePalindrome(testString8) ? "true" : "false") << endl; // true

    return 0;


};




 
