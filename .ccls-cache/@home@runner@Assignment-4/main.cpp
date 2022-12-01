/******************************************************************************
# Author:           Stephanie Ramirez
# Assignment:       Assignment 4
# Date:             11/19/2022
# Description:      This program prompts a user to select 1. Enter a drink or                 
                    2. Quit. If 1 is selected the user will be prompted to enter              
                    the drink name, the amount of mg of caffeine that drink has            
                    per cup, the amount of cups they had then outputs how many              
                    mg of caffeine they’ve consumed. 
# Sources:          Assignment 4 Instructions, zyBooks Section 10.5
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include "valid.h"
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
  string drink = "";
  int mg = 0;
  int cups = 0;
  int cafTotal = 0;
  int choice = 0;
  
  printWelcome();
  printMenu();
  
  choice = getChoice();

  while (choice != QUIT) {
    if (choice == ENTER_DRINK) {
      drink = getDrink();
      mg = getMgPerCup();
      cups = getCups();
      cafTotal = calcTotalCaf(mg, cups);
      printCafTotal(cafTotal);
      break;
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
  cout << "           |  WELCOME TO THE CAFFEINE CALCULATOR  |    \n\n";
  cout << "Lets find out how many milligrams of caffeine you’ve had today!\n\n";

}


// prints goodbye message
void printGoodbye() {
  cout << "\nGoodbye!";

}


// prints caffeine total per mg after calculating
void printCafTotal(int cafTotal) {
  cout << "\nYou've had " << cafTotal << " milligrams of caffeine!\n\n";
  
}


// prompts for and returns a valid option for the menu choice
// valid input: integers 1 and 2
int getChoice() {
    int choice = 0;
    choice = getInt("\nEnter choice: ");
  while (choice < 1 || choice > 2) {
    cout << "Error. Enter a valid choice.\n";
    choice = getInt("\nEnter choice: ");

  }
  return choice;
}


// prompts for the drink name
// valid input: no longer allows blank entries in getString function
  string getDrink() {
    string drink = "";
    cout << "\nLet's begin calculating!";
    drink = getString("\nEnter a drink: ");
    return drink;

  }

  
// prompts for mg per cup and returns
// valid input: real numbers greater than 1 AND less than
// the 715 (highest caffeine containing beverage)
int getMgPerCup() {
    int mg = 0;
    mg = getInt("Enter milligrams of caffeine per cup: ");
  while (mg < 1 || mg > 715) {
    cout << "Error. Enter a valid milligram amount.\n";
    mg = getInt("Enter milligrams of caffeine per cup: ");
    }
  
    return mg;
}


// prompts for cups and returns
// valid input: real numbers greater than 1 AND less than
// the 4 (the highest recommended consumption is 4 cups per day)
int getCups() {
    int cups = 0;
    cups = getInt("Enter cups: ");
  while (cups < 1 || cups > 4) {
    cout << "Error. The daily remommended amount is between 1-4 cups!\n";
    cout << "Try again.";
    cups = getInt("\nEnter cups: ");
    }
    return cups;
}


// calculates for total
int calcTotalCaf(int mg, int cups) {
    return mg * cups;

}
