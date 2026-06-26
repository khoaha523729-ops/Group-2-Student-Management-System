#include "Student.h"
#include "Database.h"
#include <iostream>
#include "Database.h"

using namespace std;

Student::Student(string _id, string _pass, string _name, string _gender, string _birthday, string _major)
    : User(_id, _pass, _name, _gender, _birthday), major(_major)
{
}

string Student::getMajor() const
{
    return major;
}

void Student::display(Database& db) {
    int choice;
    while (true) {
        cout << "\n===== STUDENT MENU =====" << endl;
        cout << "1. Xem danh sach mon hoc" << endl;
        cout << "2. Tra cuu diem mon hoc" << endl;
        cout << "3. Xem thong tin ca nhan" << endl;
        cout << "0. Logout" << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;

        if (choice == 0) break; // Thoát vòng lặp để đăng xuất

        switch (choice) {
            case 1:
                showAllCourses(db);
                break;
            case 2: {
                string cId = inputCourseID();
                showCourseGrade(db, cId);
                break;
            }
            case 3:
                showStudentRecord();
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    }
}

void Student::showAllCourses(const Database& db) const
{
    cout << "\n===== COURSE LIST =====\n";
    bool found = false;
    cout << "--- Danh sach hoc phan cua sinh vien " << id << " ---" << endl;

    // 1. Duyệt qua danh sách điểm để tìm các bản ghi có cùng studentId
    for (const auto& grade : db.gradeList) {
        if (grade.getStudentId() == id) {
            

            string classId = grade.getClassId(); 
            
            // 2. Tách 2 ký tự cuối của classId (Ví dụ: "C101" -> lấy "01")
            // Cắt từ vị trí độ dài chuỗi trừ đi 2 ký tự
            string courseIdTarget = "";
            if (classId.length() >= 2) {
                courseIdTarget = classId.substr(classId.length() - 2);
            }

            // 3. Tìm tên học phần tương ứng trong courseList dựa trên courseIdTarget vừa cắt
            string courseName = "Khong tim thay ten hoc phan";
            for (const auto& course : db.courseList) {
                if (course.getCourseID() == courseIdTarget) {
                    courseName = course.getCourseName();
                    break; // Tìm thấy rồi thì dừng vòng lặp courseList
                }
            }

            // 4. In kết quả định dạng: Mã lớp học phần + Tên học phần
            cout << classId << " " << courseName << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay du lieu hoc phan cho sinh vien nay." << endl;
    }
}

string Student::inputCourseID() const {
    string courseID;
    cout << "Nhap ma mon hoc: ";
    cin >> courseID;
    return courseID; 
}

void Student::showCourseGrade(const Database& db, const string& courseID) const
{
    for (size_t i = 0; i < db.gradeList.size(); i++)
    {
        if (db.gradeList[i].getStudentId() == id && db.gradeList[i].getClassId() == courseID)
        {
            cout << "\n===== GRADE =====\n";
            cout << "Process Score: " << db.gradeList[i].getProcessScore() << endl;
            cout << "End Course Score: " << db.gradeList[i].getEndCourseScore() << endl;
            cout << "Final Score: " << db.gradeList[i].getFinalScore() << endl;

            return;
        }
    }

    cout << "Khong tim thay diem cua mon hoc nay.\n";
}

void Student::showStudentRecord() const
{
    cout << "\n===== STUDENT RECORD =====\n";
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Birthday: " << birthday << endl;
    cout << "Major: " << major << endl;
}

