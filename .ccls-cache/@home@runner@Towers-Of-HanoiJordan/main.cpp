/* 
School: Tarrant County College District 
Teacher: Tyson McMillan 
Date: 12/07/2022 
Purpose: Recursion in C++ 
Skills Gained: Towers of Hanoi, Recursion, Validate input, color */
/* credit to ios App 'Algorithm' created by Moriteru Ishida, Yuki Mitsumori, & (Anthony, Brewer Michael Hahn Eglish Translation)
'Algorithm' helped me by being able to visualize and plan for The Towers of Hanoi program.*/
/* Further credit to Udemy's Class Beginning C++ Programming - From Beginner to Beyond
Tim Buchalka's Learn Programming Academy, Dr. Frank Mitropoulos for his explanation of recursion in C++ */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int toh(int n)
{
  if(n==0)
  {
    return 0;
  }
  
  return toh(n-1)+1+toh(n-1);
}

void printSteps(int n, char startPeg, char endPeg, char tempPeg)
{
  if (n==0)
  {
    return;
  }
  printSteps(n-1, startPeg, tempPeg, endPeg);
  cout << "\x1b[95;1m Move disk \x1b[97;0m" << n << "\x1b[95;1m from peg \x1b[97;0m" << startPeg 
       << "\x1b[95;1m to peg \x1b[97;0m" << endPeg << "." << endl;
  printSteps(n-1, tempPeg, endPeg, startPeg);
}
int main() 
{
  cout << "\x1b[96;1m***** [ TOWERS OF HANOI ] *****\n"<< endl;;
  int n{}; 
  bool done = false;
  while(!done)
  {
    cout << "Enter the number of disks: \x1b[97;0m";
     if (cin >> n)
     {
       if (n > 0)
         done = true;
       else if (n < 0)
         cout << n << " is not a positive integer. Please enter a valid number.\n" <<endl;
     }
  
    else 
    {
    cout << "Invalid entry. Try again.\n";
      cin.clear();
      cin.ignore();
      cout << endl;
    }
  }
  
  cout << "\x1b[96;1m\nWith \x1b[97;0m" << n << "\x1b[96;1m disks \x1b[95;1m" 
       << toh(n) << "\x1b[96;1m moves are required.\n\x1b[97;0m"<< endl;
  
  printSteps(n, 'A', 'C', 'B');

  return 0;
}