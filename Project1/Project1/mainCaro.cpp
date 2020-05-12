#include "Caro.h"

int main()
{
	Course tempCourse;
	createCourse(tempCourse);
	cout << tempCourse.ID<<endl;
	cout << tempCourse.courseTime.dayOfWeek<< endl;
	tempCourse.startDate.printDay();
	tempCourse.endDate.printDay();
	cout << tempCourse.lecAccount << endl;
	cout << tempCourse.classID << endl;


	return 0;
}