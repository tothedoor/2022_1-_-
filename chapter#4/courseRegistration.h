#ifndef COURSEREGISTRATION
#define COURSEREGISTRATION

class CourseRegistration {
public:
	// data memberµé
	int courseId;
	int studentId;
	int NumberOfCreditHourse;
	char grade[5];

	CourseRegistration();
	CourseRegistration& operator = (const CourseRegistration& cr);

	void setCourseId(int courseId);
	void setStudentId(int studentId);
	void setNumberOfCreditHourse(int numOfCredit);
	void setGrade(char grade[]);
};
#endif // ! COURSEREGISTRATION
