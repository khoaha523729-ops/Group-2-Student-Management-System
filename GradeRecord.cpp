#include "GradeRecord.h"

GradeRecord::GradeRecord(string sId, string cId, double pScore, double eScore)
    : studentId(sId), classId(cId), processScore(pScore), endCourseScore(eScore)
{
}

string GradeRecord::getStudentId() const
{
    return studentId;
}

string GradeRecord::getClassId() const
{
    return classId;
}

double GradeRecord::getProcessScore() const
{
    return processScore;
}

double GradeRecord::getEndCourseScore() const
{
    return endCourseScore;
}

double GradeRecord::getFinalScore() const
{
    return processScore * 0.4 + endCourseScore * 0.6;
}
