/******************************************************************************
# Author:           Stephanie Ramirez
# Assignment:       Assignment 3
# Date:             10/29/2022
# Description:      This program prompts a user to select 1. Enter a drink 
                    or 2. Quit. If 1 is selected the user will be prompted to                              enter the amount of mg of caffeine that drink has per cup                              and the amount of cups they had then outputs how many mg of                            caffeine they’ve consumed. 
# Sources: Assignment 3 Instructions, https://www.fda.gov/consumers/consumer
-updates/spilling-beans-how-much-caffeine-too-much#
#******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
void printMenu();
void printWelcome();
void printGoodbye();
int getChoice();
string getDrink();
int getCups();
int getMgPerCup();
int calcTotalCaf(int mg, int cups);
void printCafTotal(int cafTotal);

const int ENTER_DRINK = 1;
const int QUIT = 2;

int main () {
  string drink = " ";
  int mg = 0;
  int cups = 0;
  int cafTotal = 0;
  int choice = 0;
  
  printWelcome();
  
while (choice != QUIT) {  
       printMenu();
       choice = getChoice();
  if (choice == ENTER_DRINK) {
      drink = getDrink();
      cout << endl;
      mg = getMgPerCup();
      cups = getCups();
      cafTotal = calcTotalCaf(mg, cups);
    
  printCafTotal(cafTotal);
}
  else if (choice == QUIT){
  printGoodbye();

 return 0;
    }
}
}

//functions
//print menu & get selection
void printMenu() {
      cout << "1. Enter Drink" << endl;
      cout << "2. Quit" << endl;
}


// prints welcome message
void printWelcome() {
  cout << "Would you like to find out how many milligrams " 
       <<  "of caffeine you’ve had today?\n" << endl;

}

// prints goodbye message
void printGoodbye() {
  cout << "\nGoodbye!";

}


// prints caffeine total per mg after calculating
void printCafTotal(int cafTotal) {
  cout << "\nYou've had " << cafTotal << " milligrams of caffeine!\n\n";
  
}


// prompts user to enter a choice  
int getChoice() {
    int choice = 0;
    cout << "Enter choice: ";
    cin >> choice;
    cin.get();
    return choice;
}


// prompts for drink and returns
string getDrink() {
    string drink = " ";
    cout << "\nEnter drink: ";
    cin >> drink;    
    return drink;
}

  
// prompts for mg per cup and returns
int getMgPerCup() {
    int mg = 0;
    cout << "Enter milligrams of caffeine per cup: ";
    cin >> mg;
    return mg;
}


// prompts for cups and returns
int getCups() {
    int cups = 0;
    cout << "\nEnter cups: ";
    cin >> cups;
    return cups;
    cout << endl;

}


// calculates for total
int calcTotalCaf(int mg, int cups) {
    return mg * cups;

}
