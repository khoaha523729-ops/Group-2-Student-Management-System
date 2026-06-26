#pragma once
#include <string>
#include <vector>
// #include "Admin.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "GradeRecord.h"
#include "Database.h"
using namespace std;


class Login
{
    public:
    void run(Database& db);
};

