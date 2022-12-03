#ifndef  CODE_ETP0040_HEADER_H
#define  CODE_ETP0040_HEADER_H
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
using namespace std;

int getNumber();

struct Student{
    string firstN;
    string lastN;
    int studentID;
    int testsTaken;
    int* ptr = nullptr;
    double averageScore;
};

Student newStudent;

void addStudent(ofstream &outFS, Student newStudent);

#endif //CODE_ETPOO40_HEADER_H