#include "Login.h"
#include <iostream>

using namespace std;

void Login::run(Database& db) {
    string inputId, inputPass;
    while (true) {
        cout << "Nhap Id dang nhap: "; cin >> inputId;
        cout << "Nhap Password: "; cin >> inputPass; 
        cin.ignore(1000, '\n');

        // 1. Kiểm tra Sinh viên
        for (auto& student : db.studentList) {
            if (student.getID() == inputId && student.checkPassword(inputPass)) {
                cout << "\nXin chao sinh vien " << student.getName() << ".\n";
                student.display(db); // Chuyển hướng sang menu sinh viên
                return; 
            }
        }

        //2. Kiểm tra Giáo viên
        for (auto& teacher : db.teacherList) {
            if (teacher.getID() == inputId && teacher.checkPassword(inputPass)) {
                cout << "\nXin chao giao vien " << teacher.getName() << ".\n";
                teacher.display(db); // Chuyển hướng sang menu giáo viên
                return;
            }
        }

        //3. Kiểm tra Admin
        for (auto& admin : db.adminList) {
            if (admin.getID() == inputId && admin.checkPassword(inputPass)) {
                cout << "\nXin chao quan tri vien " << admin.getName() << ".\n";
                admin.adminMenu(db.courseList, db.studentList, db.teacherList, db); // Chuyển hướng sang menu admin
                return;
            }
        }

        cout << "SAI THONG TIN DANG NHAP\n";
    }
}