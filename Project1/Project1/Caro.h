#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
	void inputDay(){
		cout << "Day: ";
		cin >> day;
		cout << "Month: ";
		cin >> month;
		cout << "year: ";
		cin >> year;
	}
	void deleteDay() {
		day = 0; month = 0; year = 0;
	}
	void printDay() {
		cout << day << "/" << month << "/" << year << endl;
	}
};

struct User {
	string username;
	string password;
	string name;
};

struct Staff {
	User user;
	string name;
};

struct Lecturer {
	User user;
	string name;
};

struct Student_User {
	User user;
	string name;
};

struct Student {
	string ID;
	string fullName;
	string gender;
	string DoB;
	string classID;
};

struct Time
{
	string dayOfWeek;
	string startHour;
	string startMin;
	string endHour;
	string endMin;
	void inputTime() 
	{
		cout << "day of week: ";
		cin >> dayOfWeek;

		cout << "start hour: ";
		cin >> startHour;

		cout << "start min: ";
		cin >> startMin;

		cout << "end hour: ";
		cin >> endHour;

		cout << "end min: ";
		cin >> endMin;
	}
	void deleteTime() 
	{
		dayOfWeek = "";
		startHour = "";
		endHour = "";
		startMin = "";
		endMin = "";
	}
	void printTime()
	{
		cout << "Day of week: " << dayOfWeek << endl;
		cout << startHour << ":" << endHour << endl;
		cout << startMin << ":" << endMin << endl;
	}
};

struct Course
{
	string ID;
	string name;
	string classID;
	string lecAccount;
	Date startDate;
	Date endDate;
	Time courseTime;
	string room;
};

struct Semester {
	int numberOfCourses;
	Course *coursesArray;
};

struct academicYear {
	int startYear;
	Semester semesterArray[3];
};
bool isFileOpen(ifstream& fin, const char* filename);
void importStudentsFromCSV(Student*& students, int& nStudent);
void filterStudentToClass(string filename);
void createCourse(Course& course);
void createSemester(Semester& temp);
void createAcademicYear(academicYear& year);
void deleteCourses(Course& course);


#endif