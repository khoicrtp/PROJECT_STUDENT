#include "Caro.h"

bool isFileOpen(ifstream& fin, const char* filename) {
	fin.open(filename);
	if (!fin.is_open()) {
		cout << "Can not open " << filename << endl;
		return false;
	}
	return true;
}

void importStudentsFromCSV(Student*& students, int& nStudent) {
	ifstream fin;
	if (isFileOpen(fin, "Students.csv") == false)
		return;

	ofstream fout;
	fout.open("Students.txt");
	if (!fout.is_open()) {
		cout << "Can not open Students.txt" << endl;
		return;
	}

	nStudent = 0;
	string ignore = "";
	while (!fin.eof()) {
		getline(fin, ignore, '\n');
		++nStudent;
	}
	students = new Student[nStudent];

	fin.seekg(0, fin.beg);
	ignore = "";
	int i = 0;

	fout << nStudent << endl;
	while (!fin.eof()) {
		//Read each line in csv 
		getline(fin, ignore, ',');
		getline(fin, students[i].ID, ',');
		getline(fin, students[i].fullName, ',');
		getline(fin, students[i].gender, ',');
		getline(fin, students[i].DoB, ',');
		getline(fin, students[i].classID, '\n');
		//Export to Students.txt
		fout << endl << students[i].ID << endl << students[i].fullName << endl << students[i].gender << endl << students[i].DoB << endl << students[i].classID << endl;
		i++;
	}
	fin.close();
	fout.close();
}

void filterStudentToClass(string filename)
{
	ifstream in(filename);
	int nStudents;
	if (!in.is_open())
	{
		cout << "Cant open file" << endl;
		return;
	}

	in >> nStudents;

	Student* a = new Student[nStudents];

	importStudentsFromCSV(a, nStudents);

	for (int i = 0; i < nStudents; i++)
	{
		string classFile=a[i].classID+"-Students.txt";
		ofstream fout(classFile,ofstream::app);
		if (!fout.is_open())
		{
			cout << "Cant create file" << endl;
			return;
		}
		fout << a[i].ID << endl << a[i].fullName << endl << a[i].DoB << endl << a[i].gender << endl;
		fout.close();
	}
}

void createCourse(Course& course) {
	cout << "Input course's ID: ";
	cin >> course.ID;

	cout << "Input course's name: ";
	cin >> course.name;

	cout << "Input course's classID: ";
	cin >> course.classID;

	cout << "Input course's lecturer's account: ";
	cin >> course.lecAccount;

	cout << "Input course's start day: ";
	course.startDate.inputDay();

	cout << "Input course's end day: ";
	course.endDate.inputDay();

	cout << "Input course's time: ";
	course.courseTime.inputTime();

	cout << "Input course's room: ";
	cin >> course.room;
}

void createSemester(Semester& temp)
{
	//semester temp;
	cout << "Input the number of courses: ";
	cin >> temp.numberOfCourses;
	temp.coursesArray = new Course[temp.numberOfCourses];
	for (int i = 0; i < temp.numberOfCourses; i++)
	{
		createCourse(temp.coursesArray[i]);
	}
}

void createAcademicYear(academicYear& year) 
{
	cout << "Input starting year: ";
	cin >> year.startYear;
	for (int i = 0; i < 3; i++)
	{
		cout << "INPUT SEMESTER " << i + 1 << " " << endl;
		createSemester(year.semesterArray[i]);
	}
}

void deleteCourses(Course& course)
{
	course.ID="";

	course.name = "";

	course.classID = "";

	course.lecAccount = "";

	course.startDate.deleteDay();

	course.endDate.deleteDay();

	course.classID = "";

	course.courseTime.deleteTime();

	course.room = "";
}

void deleteSemester(Semester& semester)
{
	semester.numberOfCourses = 0;
	semester.coursesArray = nullptr;
}

void deleteYear(academicYear& year)
{
	year.startYear = 0;
	for (int i = 0; i < 3; i++)
	{
		deleteSemester(year.semesterArray[i]);
	}
}


