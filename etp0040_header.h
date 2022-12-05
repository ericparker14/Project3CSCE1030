#ifndef  CODE_ETP0040_HEADER_H
#define  CODE_ETP0040_HEADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string.h>
#include <unistd.h>

using namespace std;
int getNumber();

enum menu {Add = 1, Remove = 2, Display = 3, Search = 4, Results = 5, Quit = 6};
const int NUM_TESTS = 5;

struct Student{
    string firstN;
    string lastN;
    int studentID;
    int testsTaken;
    int* ptr = nullptr;
    double averageScore;
};



void add_Student();
void remove_Student(int);
void display();
void search(int);
void exportResults();
int findMinimum(int*, int);
int getNumber();


#endif //CODE_ETPOO40_HEADER_H
