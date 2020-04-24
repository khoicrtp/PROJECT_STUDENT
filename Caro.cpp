#include "Caro.h"

void importStudentsFromCSV(ifstream& in, Student students[], int& nStudents)
{

	char tempData[100];
	for(int i=0;i<nStudents;i++)
	{
		in.getline(tempData, 100);
		char* temp;
		//access first member
		temp = strtok(tempData, ",");
		students[i].name = temp;
		//access another member
		temp = strtok(NULL, ",");
		students[i].ID = temp;

		temp = strtok(NULL, ",");
		strcpy(students[i].DoB,temp);

		//test read
		cout << students[i].name << endl;
		cout << students[i].ID   <<endl;
		cout << students[i].DoB << endl;
	}

}

void createUserPassword(Student a[], int nStudents)
{
	
	for (int i = 0; i < nStudents; i++) {	

		a[i].password = new char[9];
		a[i].password[9] = '\0';

		strcpy_s(a[i].password,9, a[i].DoB);

		//test created password
		cout << "PASSWORD: "<<a[i].password<<endl;
	}
}