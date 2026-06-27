#pragma once
#include <string>

using namespace std;
class Teacher;

class GradeRecord
{
    friend class Teacher;
private:
    string studentId;
    string classId;
    double processScore;
    double endCourseScore;
public:
    GradeRecord(string sId, string cId, double pScore, double eScore);
    string getStudentId() const;
    string getClassId() const;
    double getProcessScore() const;
    double getEndCourseScore() const;
    double getFinalScore() const;
};
