/******************************************************************************
# Author:           Stephanie Ramirez
# Assignment:       Assignment 5
# Date:             11/28/2022
# Description:      I will be writing a caffeine calculating program to help 
                    people from consuming too much caffeine! The program will 
                    display a menu with three options: choice 1 allows the user
                    to enter their drink information (drink name, mg per cup, 
                    cups) 2 calculates and print the total milligrams of caffeine 
                    consumed with the percentage out of the daily recommended 
                    amount followed by a message if they have consumed a safe or
                    dangerous amount of caffeine 3 allows the user to exit the 
                    program. 
# Sources:          Assignment 5 Instructions, zyBooks Chapter 10 & 11
#******************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
#include "valid.h"
using namespace std;

void printMenu();
void printWelcome();
void printGoodbye();
void printCafTotal(string prompt, int totalCaf);
void printDrinks(string drinks[], float milligrams[], int cups[], int array);
int getChoice();
string getDrink();
int getCups();
float getMgPerCup();
float calcTotalCaf(float milligrams[], int cups[], int array);
void printPerc(int totalCaf);

const int ENTER_DRINK = 1;
const int CALCULATE = 2;
const int QUIT = 3;
const float DAILY_REC_AMT = 400.00;
const int MAX = 4;


int main(){
  int totalCaf = 0;
  int choice = 0;
  string drinks[MAX] = {};
  float milligrams[MAX] = {};
  int cups[MAX] = {};
  int array = 0;
    
    printWelcome();
    while (choice != QUIT) {
        printMenu();
        choice = getChoice();
        if (choice  == ENTER_DRINK) {
            drinks[array] = getDrink();
            milligrams[array] = getMgPerCup();
            cups[array] = getCups();
            array++;
    }
      
  }      if (choice == CALCULATE) {
           totalCaf = calcTotalCaf(milligrams, cups, array);
           printCafTotal("\nTotal milligrams of caffeine  consumed are ", totalCaf);
           printPerc(totalCaf);
}               
         else if (totalCaf > 0)
              printDrinks(drinks, milligrams, cups, array); 
         else 
           cout << "\nNo drinks were entered!" << endl;
    
    printGoodbye(); 

    return 0;
}
  

void printMenu() {
      cout << "\n1. Enter Drink" << endl;
      cout << "2. Calculate Total" << endl;
      cout << "3. Quit" << endl;

}


void printWelcome() {
  cout << "           |  WELCOME TO THE CAFFEINE CALCULATOR  |    \n\n";
  cout << "Lets find out how many milligrams of caffeine you’ve had today!\n\n";

}


void printGoodbye() {
  cout << "\nGoodbye!" << endl;

}


void printCafTotal(string prompt, int totalCaf){
     cout << fixed << setprecision(2);
     cout << prompt << totalCaf << endl;   
    //     if (totalCaf <= 0){
    //     cout << "\nError. No drink was entered." << endl;
    // }
  }

void printDrinks(string drinks[], float milligrams[], int cups[], int array){
    cout << fixed << setprecision(2);
    cout << setw(17) << left << "\nDrink Name" 
         << setw(15) << " Milligrams" 
         << setw(10) << " Cups" 
         << setw(10) << " Total Caffeine" << endl;
    cout << setw(17) << left << "------------" 
         << setw(15) << "-----" 
         << setw(10) << "--" 
         << setw(1) << "-----" << endl;
    for (int i = 0; i < array; i++) {
        cout << setw(17) << left << drinks[i] 
             << setw(15) << milligrams[i] 
             << setw(10) << cups[i] 
             << setw(5) << milligrams[i] * cups[i] 
             << endl;       
    }   
  }


 float calcTotalCaf(float milligrams[], int cups[], int array) {
    float total = 0.0;
    for (int i = 0; i < array; i++) {
        total = total + milligrams[i] * cups[i];
    }

    return total;
}


 int getChoice() {
    int choice = 0;
    choice = getInt("\nEnter choice: ");
    while (choice < 1 || choice > 3) {
        cout << "Invalid choice." << endl;
        choice = getInt("\nEnter choice: ");
    }
    return choice;
}


  string getDrink() {
    string drink = "";
    cout << "\nLet's begin calculating!";
    cout << "\nEnter a drink: ";
    getline(cin, drink);
    while (drink == ""){
        cout << "No drink entered!" << endl;
        cout << "\nEnter a drink: ";
        getline(cin, drink);
    }
    return drink;

  }


 float getMgPerCup() {
    float mg = 0.00;
    mg = getFloat("Enter milligrams of caffeine per cup: ");
    while (mg < 1 || mg > 715) {
        cout << "Error. Enter a valid milligram amount.\n";
        mg = getInt("Enter milligrams of caffeine per cup: ");
      
    }
  
    return mg;
}


 int getCups() {
    int cup = 0;
    cup = getInt("Enter cups: ");
    while (cup < 1 || cup > 4) {
      cout << "Error. The daily remommended amount is between 1-4 cups!\n";
      cout << "Try again.\n";
      cup = getInt("\nEnter cups: ");
    }
    return cup;
}


 void printPerc(int totalCaf){
    int perc = 0;
    perc = (totalCaf / DAILY_REC_AMT) * 100;
    cout << "That is " << perc << '%' 
      << " of the daily recommended amount of 400 milligrams";
   
    if (perc < 100){
    cout << ("\nYou are safely caffeinated.") << endl;
   }
    else (perc > 100);
    cout << ("\nYOU ARE DANGEROUSLY CAFFEINATED!") << endl;
}
