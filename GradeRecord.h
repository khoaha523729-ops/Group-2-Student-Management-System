#pragma once
#include <string>

class GradeRecord
{
private:
    string studentId;  
    string classId;    
    double processScore;   
    double endCourseScore;  

public:
   
    //import file GradeRecord.txt
    GradeRecord(string sId, string cId, double pScore, double eScore)
        : studentId(sId), classId(cId), processScore(pScore), endCourseScore(eScore) {}
    
        double getFinalScore() const {
        return (processScore * 0.4) + (endCourseScore * 0.6);
    }
};