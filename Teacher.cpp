#include "Teacher.h"
#include <iostream>

using namespace std;

// Teacher::Teacher() : username(""), password(""), teacherId(""), name("") {}

// Teacher::Teacher(string user, string pass, string id, string teacherName) {
//     username = user;
//     password = pass;
//     teacherId = id;
//     name = teacherName;
// }

string Teacher::getUsername() const { return username; }
string Teacher::getPassword() const { return password; }
string Teacher::getTeacherId() const { return teacherId; }
string Teacher::getName() const { return name; }

void Teacher::addClassId(string classId) {
    this->classIds.push_back(classId);
}

void Teacher::display(Database& db)
{
    cout << "Giao vien: " << name << " (ID: " << teacherId << ")" << endl;
    string choiceClass;
    while (true) {
        cout << "\n------------------------------------" << endl;
        cout << "(Show all class)" << endl;
        if (classIds.empty()) {
            cout << "  (Chua phan cong lop hoc nao)" << endl;
        } else {
            for (const string& cid : classIds) {
                cout << "  " << cid << " database" << endl;
            }
        }
        cout << "  0. Return" << endl;
        cout << "Input Id of class: ";
        cin >> choiceClass;

        if (choiceClass == "0") {
            return;
        }

        bool hasClass = false;
        for (const string& cid : classIds) {
            if (cid == choiceClass) {
                hasClass = true;
                break;
            }
        }

        if (!hasClass) {
            cout << "Ban khong day lop nay hoac ma lop khong ton tai!" << endl;
            continue;
        }

        string studentId;
        while (true) {
            cout << "\n------------------------------------" << endl;
            cout << "(Show all student in class)" << endl;
            cout << "  (Ex: S01 Nguyen van a)" << endl; 
            cout << "  0. Return" << endl;
            cout << "Input student Id: ";
            cin >> studentId;

            if (studentId == "0") {
                break;
            }

            int gradeChoice;
            while (true) {
                cout << "\n------------------------------------" << endl;
                cout << "(Show all grades of student)" << endl;
                cout << "  (Ex: Process grade: 5.6 - End of course grade: 7.5 - Total: 6.17)" << endl;
                cout << "  1. Edit grade" << endl;
                cout << "  0. Return" << endl;
                cout << "Input: ";
                cin >> gradeChoice;

                if (gradeChoice == 0) {
                    break;
                } else if (gradeChoice == 1) {
                    double processG, endG;
                    cout << "Enter new Process grade: ";
                    cin >> processG;
                    cout << "Enter new End of course grade: ";
                    cin >> endG;
                    cout << "=> Cap nhat diem thanh cong! (Total: " << (processG * 0.3 + endG * 0.7) << ")" << endl;
                } else {
                    cout << "Lua chon khong hop le!" << endl;
                }
            }
        }
    }
}
