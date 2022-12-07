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
  cout << "Move disk " << n << " from peg " << startPeg 
       << " to peg " << endPeg << "." << endl;
  printSteps(n-1, tempPeg, endPeg, startPeg);
}
int main() 
{
  cout << "***** [ TOWERS OF HANOI ] *****\n";
  int n{}; 
  bool done = false;
  while(!done)
  {
    cout << "Enter the number of disks: ";
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
  cout << "\nWith " << n << " disks " 
       << toh(n) << " moves are required.\n"<< endl;
  
  printSteps(n, 'A', 'C', 'B');

  return 0;
}