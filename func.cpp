#include "etp0400_header.h"
using namespace std;

void add_Student(){
ofstream outFS;    
int testScore;
Student* newStudent = nullptr;
newStudent = new Student;
    // get all info
    cout << "First name:";
    cin >> newStudent->firstN;
    cout << "Last name:";
    cin >> newStudent->lastN;
    cout << "Student ID:";
    cin >> newStudent->studentID;
    // create dyn array given # tests
    cout << "# Tests taken:";
    cin >> newStudent->testsTaken;
    newStudent->ptr = new int(newStudent->testsTaken);
    cout << "newStudent.ptr = " << *newStudent->ptr << endl;
    // take in test scores input
    cout << "Test scores:";
    for (int i = 0; i < newStudent->testsTaken; i++){
        cin >> testScore;
        newStudent->ptr[i] = testScore;
    }
    // open file to write to
    outFS.open("student.dat");
    if(!outFS.is_open()){
        cout << "File failed to open.";
        exit(1);
    }

    outFS <<newStudent->lastN<<","<<newStudent->firstN<<","
    <<newStudent->studentID<<","<<newStudent->testsTaken<<",";
    for(int i = 0; i < newStudent->testsTaken; i++){
        outFS << newStudent->ptr[i] << ",";
    }
    outFS.close();
}


void remove_Student(int remove_studentID){
	    /* call getNumber();
     * create dynamic array with Student
     * open student.dat to read
     * read one line at a time store data in array
     * while reading check if student id matches student id user entered
     * use bool
     * copy entire file to the dynamic array whether or not there is a match
     * close file*/
	ifstream inFS;
    int numStudents = getNumber();
	int i = 0;
	bool remove = false;
    cout << "numStudents = " << numStudents << endl;
	
	Student* studentArr = nullptr;
	studentArr = (Student*)malloc(numStudents * sizeof(Student));
	
	inFS.open("student.dat");
	if(!inFS.is_open()){
		cout << "Error opening file.\nClosing Program.";
		exit(1);
	}
	string fromData;
	while(inFS.eof()){
		getline(inFS, fromData);

		istringstream inSS(fromData);
		string changeStrToInt;
		
		getline(inSS, studentArr[i].lastN, ',');
cout << studentArr[i].lastN;
		getline(inSS, studentArr[i].firstN, ',');
		
		getline(inSS, changeStrToInt, ',');
		studentArr[i].studentID = stoi(changeStrToInt);
		if(remove_studentID == studentArr[i].studentID){
			remove = true;
			continue;
		}
		getline(inSS, changeStrToInt, ',');
		studentArr[i].testsTaken = stoi(changeStrToInt);
		studentArr[i].ptr = new int[studentArr[i].testsTaken];
		for(int num = 0; num < studentArr[i].testsTaken; num++){
			getline(inSS, changeStrToInt, ',');
			studentArr[i].ptr[num] = stoi(changeStrToInt);
		}
		i++;
	}
	
	inFS.close();
	
	if(remove){
		ofstream outFS;
		i--;
		outFS.open("student.dat");
		if(!outFS.is_open()){
			cout << "Failed to open file.\nClosing Program.\n";
			exit(1);
		}
		for(int j = 0; j < i; j++){
			outFS << studentArr[j].lastN << "," << studentArr[j].firstN << "," << studentArr[j].studentID <<
			"," << studentArr[j].testsTaken << ",";
			for(int num; num < studentArr[j].testsTaken; num++){
				outFS << studentArr[j].ptr[num] << ",";
				
			}
			outFS << endl;
		}
		cout << "Data removed for student with ID#" << remove_studentID << endl;
		outFS.close();
	}
	else{
		cout << "Data for student with ID#" << remove_studentID << " not found.\n";
	}
}
void display(){
	ifstream inFS;
	string getData;
	inFS.open("student.dat");
	if(!inFS.is_open()){
		cout << "Failed to open file.\nClosing file.\n";
		exit(1);
	}
	int count = getNumber();
	int i = 0;
	Student* disArr = nullptr;
	disArr = (Student*)malloc(count * sizeof(Student));
	while(inFS.eof()){
		getline(inFS, getData);

		istringstream inSS(getData);
		string changeStrToInt;
		getline(inSS, disArr[i].lastN, ',');
		getline(inSS, disArr[i].firstN, ',');
		string name = disArr[i].lastN + "," + disArr[i].firstN;
		
		getline(inSS, changeStrToInt, ',');
		disArr[i].studentID = stoi(changeStrToInt);
		getline(inSS, changeStrToInt, ',');
		disArr[i].testsTaken = stoi(changeStrToInt);
		disArr[i].ptr = new int[disArr[i].testsTaken];
		for(int num = 0; num < disArr[i].testsTaken; num++){
			getline(inSS, changeStrToInt, ',');
			disArr[i].ptr[num] = stoi(changeStrToInt);
		}
		cout << setw(30) << name;
		cout << setw(15) << disArr[i].studentID;
		for(int j = 0; j < disArr[i].testsTaken; j++){
			cout << setw(5) << disArr[i].ptr[j];
		}
		cout << endl;
		i++;
	}
	inFS.close();
	
}
void search(int ID){
	ifstream inFS;
	bool match = false;
	inFS.open("data.dat");
	if(!inFS.is_open()){
		cout << "Failed to open file.\nClosing program\n";
		exit(1);
	}
	Student* lookFor = nullptr;
	do{
		string change;
		getline(inFS, lookFor->lastN, ',');
		getline(inFS, lookFor->firstN, ',');
		getline(inFS, change, ',');
		lookFor->studentID = stoi(change);
		getline(inFS, change, ',');
		lookFor->testsTaken = stoi(change);
		lookFor->ptr = new int[lookFor->testsTaken];
		for(int i = 0; i < lookFor->testsTaken; i++){
			getline(inFS, change, ',');
			lookFor->ptr[i] = stoi(change);
		}
	string name = lookFor->lastN + "," + lookFor->firstN;
		if(lookFor->studentID == ID){
			match = true;
			cout << "Student with ID#" << ID <<" was found:\n";
			cout << setw(30) << name;
			cout << setw(15) << lookFor->studentID;
			for(int j = 0; j < lookFor->testsTaken; j++){
				cout << setw(5) << lookFor->ptr[j];
			}
			cout << endl;
		}
	}while((!inFS.eof())||(!match));

	if(!match){
		cout << "No student found with ID#" << ID << endl;
	}
	
	}

void exportResults(){
	ofstream outFS;
	ifstream inFS;
	
	outFS.open("averages.dat");
	if(!outFS.is_open()){
		cout << "Failed to open file.\nClosing program";
		exit(1);
	}
	inFS.open("student.dat");
	if(!inFS.is_open()){
		cout << "Failed to open file.\nClosing program";
		exit(1);
	}
	int size = getNumber();
	Student* resultsArr = nullptr;
	resultsArr = (Student*)malloc(size*sizeof(Student));
	string resData;
	string name;
	int i = 0;
	while(inFS.eof()){
		getline(inFS, resData);

		istringstream inSS(resData);
		string changeStrToInt;
		
		getline(inSS, resultsArr[i].lastN, ',');
		getline(inSS, resultsArr[i].firstN, ',');
			
		getline(inSS, changeStrToInt, ',');
		resultsArr[i].studentID = stoi(changeStrToInt);
		
		getline(inSS, changeStrToInt, ',');
		resultsArr[i].testsTaken = stoi(changeStrToInt);
		
		resultsArr[i].ptr = new int[resultsArr[i].testsTaken];
		
		for(int num = 0; num < resultsArr[i].testsTaken; num++){
			getline(inSS, changeStrToInt, ',');
			resultsArr[i].ptr[num] = stoi(changeStrToInt);
		}
		
		i++;
	}

	for(int j = 0; j < size; j++){
		int sum = 0;
		double avg = 0;
		for (int k = 0; k < resultsArr[j].testsTaken; k++){
			sum = sum + resultsArr[j].ptr[k];
		}	
		int drop = findMinimum(resultsArr[j].ptr, resultsArr[j].testsTaken); 
		sum = sum - drop;
		avg = sum / (static_cast<double>(resultsArr[j].testsTaken) - 1.0);
		outFS << setw(15) << resultsArr[j].studentID;
		outFS << avg << endl;
	}
	outFS.close();
	inFS.close();
}
		
	int findMinimum(int* resultsArrM, int SIZE){
		int hold;
		if(SIZE < 5){
			return 0;
		}
		else{
			hold = resultsArrM[0];
			for(int i = 1;i < SIZE; i++){
				if(resultsArrM[i] < hold){
					hold = resultsArrM[i];
				}
			}
			return hold;
		}
	}
				
			
	
