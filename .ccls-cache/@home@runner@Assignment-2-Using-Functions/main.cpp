/******************************************************************************
# Author:           Stephanie Ramirez
# Assignment:       Assignment 1
# Date:             10/08/2022
# Description:      This program prompts a user to enter a drink type, the
amount of mg of caffeine that drink has per cup and the amount of cups they         
had then outputs how many mg of caffeine they’ve consumed. 
# Sources: Week 1 & 2 Lecture Slides, https://www.fda.gov/consumers/consumer
-updates/spilling-beans-how-much-caffeine-too-much#
#******************************************************************************/
#include <iostream>

using namespace std;
#include <iomanip>

int main() {
  // declaring variables

  string drink = " ";
  double mgPerCup = 0.0;
  double cupQuantity = 0.0;
  double caffeineTotal = 0.0;

  cout << "Welcome to the caffeine calculator!\n";
  cout << endl;
  
  // prompting user for input & adding the ability for the user to enter a
  // multi-word drink type (such as, energy drink or iced coffee).

  cout << "Enter your drink type: ";
  getline(cin, drink);
  cout << endl;

  cout << "How many mg of caffeine does this drink have per cup? ";
  cin >> mgPerCup;
  cout << endl;
  
  cout << "Enter cup amount: ";
  cin >> cupQuantity;
  cout << endl;

  // calculating the total caffeine amount

  caffeineTotal = mgPerCup * cupQuantity;

  cout << fixed << setprecision(2);

  cout << "You have had " << caffeineTotal << " mg of caffeine.";

  return 0;
}