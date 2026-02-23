#include <iostream>

const int MAX_NAME_LENGTH = 50;
const int MAX_STUDENTS = 100;

enum class Major {
	SWE,
	CS,
	AM,
	M,
	I,
	IS,
	DA
};

struct Student {
	char name[MAX_NAME_LENGTH];
	int facultyNumber;
	int year;
	Major major;
};

struct Participant {
	Student* student;
	double grade;
};

struct Course {
	char name[MAX_NAME_LENGTH];
	int credits;
	Major major;
	Participant participants[MAX_STUDENTS];
	int participantCount;
};

int findParticipantIndex(const Course& course, int facultyNumber) {
	for (int i = 0; i < course.participantCount; ++i)
		if (course.participants[i].student->facultyNumber
			== facultyNumber)
			return i;

	return -1;
}

bool isEnrolled(const Course& course, int facultyNumber) {
	return findParticipantIndex(course, facultyNumber) != -1;
}

bool enrollStudent(Course& course, Student& student) {
	if (course.participantCount >= MAX_STUDENTS)
		return false;

	if (isEnrolled(course, student.facultyNumber))
		return false;

	course.participants[course.participantCount].student = &student;
	course.participants[course.participantCount].grade = 2.0;
	course.participantCount++;
	return true;
}

void printStudents(const Course& course) {
	for (int i = 0; i < course.participantCount; ++i)
		std::cout 
		<< course.participants[i].student->name
		<< ' '
		<< course.participants[i].student->facultyNumber
		<< '\n';
}

double averageGrade(const Course& course) {
	if (course.participantCount == 0)
		return 0;

	double sum = 0;

	for (int i = 0; i < course.participantCount; i++)
		sum += course.participants[i].grade;

	return sum / course.participantCount;
}

