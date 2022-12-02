<<<<<<< HEAD
#include "etp0040_header.h"
int getNumber()
{
    ifstream fin;
    fin.open("student.dat");
    if (fin.fail())
    {
        cout<<"File error."<<endl;
        exit(1);
    }
    int count=0;
    string line;
    while(!fin.eof())
    {
        getline(fin, line);
        ++count;
    }
    fin.close();
    return(count);
}
=======
#include "euid_header.h"
int getNumber()
{
ifstream fin;
fin.open("student.dat");
if (fin.fail())
{
cout<<"File error."<<endl;
exit(1);
}
int count=0;
string line;
while(!fin.eof())
{
getline(fin, line);
++count;
}
fin.close();
return(count);
}
>>>>>>> fdb8f4acdc889b3392d2d0a381370d3e9252bf68
