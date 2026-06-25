#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Teacher {
private:
    string username;
    string password;
    string teacherId;
    string name;
    vector<string> classIds;

public:
    Teacher();
    Teacher(string user, string pass, string id, string teacherName);

    string getUsername() const;
    string getPassword() const;
    string getTeacherId() const;
    string getName() const;

    void addClassId(string classId);
    void display() const;
    void showTeacherMenu();
};

#endif
