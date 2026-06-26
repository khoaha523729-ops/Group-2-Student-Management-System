#include "Teacher.h"
#include <iostream>
#include "Database.h"

using namespace std;

Teacher::Teacher(string tId, string tPass, string tName, string tgender, string tBirthday, vector<string> tclassIds)
    : User(tId, tPass, tName, tgender, tBirthday),classIds(tclassIds){};

void Teacher::display(Database& db)
{
    cout << "Giao vien: " << name << " (ID: " << id << ")" << endl;
    string choiceClass;
    while (true) 
    {
        cout << "\n------------------------------------" << endl;
        cout << "(Show all class)" << endl;
        if(db.courseList.empty())
        {
            cout << "  (Chua phan cong lop hoc nao)" << endl;
        } 
        else 
        {
            for (const string& cid : classIds) 
            {
                string lastTwoDigits = cid.substr(cid.length() - 2, 2);
                for (const auto& course : db.courseList) 
                {
                    if (course.getCourseID() == lastTwoDigits) {
                        cout << "Ma hoc phan: " << cid 
                             << " | Ten mon hoc: " << course.getCourseName() << endl;
                    }
                }
            }
        }
        cout << "0. Return" << endl;
        cout << "Input Id of class: ";
        cin >> choiceClass;

        if (choiceClass == "0") {
            return;
        } else {
            // Chuyển tiếp sang hàm xử lý chức năng hiển thị học sinh
            viewStudentsInClass(choiceClass, db);
        }
    }
}


void Teacher::viewStudentsInClass(const string& targetClassId, const Database& db) {
    cout << "\n===== DANH SACH HOC SINH LOP " << targetClassId << " =====" << endl;
    bool found = false;

    // 1. Duyệt qua danh sách Điểm (Grade) trong database để tìm mã học phần trùng khớp
    for (const auto& grade : db.gradeList) {
        // Giả sử class Grade có hàm getCourseID() trả về mã học phần (vd: C101)
        if (grade.getClassId() == targetClassId) {
            
            // 2. Lấy mã sinh viên từ học phần này (Giả sử qua grade.getStudentID())
            string studentIdInGrade = grade.getStudentId();
            
            // 3. Đối chiếu mã sinh viên vừa tìm được với danh sách Học sinh (Student) toàn cục
            for (const auto& student : db.studentList) {
                // Giả sử class Student có hàm getID() và getName()
                if (student.getID() == studentIdInGrade) {
                    cout << "MSV: " << student.getID() << " | Ho ten: " << student.getName() << endl;
                    found = true;
                    break; // Đã tìm thấy học sinh này, nhảy sang dòng grade tiếp theo
                }
            }
        }
    }

    // int thoat;
    // cout << "0. Thoát";
    // cin >> thoat;
    // if(thoat == 0){return;}

    if (!found) {
        cout << "Khong tim thay hoc sinh nao thuoc hoc phan nay hoặc ma lop khong ton tai." << endl;
    }
    cout << "=========================================\n" << endl;
}