#include <etp0040_header.h>

void add_Student(ofstream &outFS, Student newStudent){
    int testScore;
    // get all info
    cout << "First name:";
    cin >> newStudent.firstN;
    cout << "Last name:";
    cin >> newStudent.lastN;
    cout << "Student ID:";
    cin >> newStudent.studentID;
    // create dyn array given # tests
    cout << "# Tests taken:";
    cin >> newStudent.testsTaken;
    newStudent.ptr = new int(newStudent.testsTaken);
    cout << "newStudent.ptr = " << *newStudent.ptr << endl;
    // take in test scores input
    cout << "Test scores:";
    for (int i = 0; i < newStudent.testsTaken; i++){
        cin >> testScore;
        newStudent.ptr[i] = testScore;
    }
    // open file to write to
    outFS.open("student.dat");
    if(!outFS.is_open()){
        cout << "File failed to open.";
        exit(1);
    }

    outFS <<newStudent.lastN<<","<<newStudent.firstN<<","
    <<newStudent.studentID<<","<<newStudent.testsTaken<<",";
    for(int i = 0; i < newStudent.testsTaken; i++){
        outFS << newStudent.ptr[i] << ",";
    }
    outFS.close();







}