#include "Login.h"
#include <iostream>
using namespace std;

void Login::run(Database& db) {
    string inputId, inputPass;
    while (true) {
        cout << "Id: "; cin >> inputId;
        cout << "Password: "; cin >> inputPass;

        // 1. Kiểm tra Sinh viên
        for (auto& student : db.studentList) {
            if (student.getID() == inputId && student.checkPassword(inputPass)) {
                cout << "\n[HỆ THỐNG]: Xin chào Sinh viên " << student.getName() << ".\n";
                student.display(); // Chuyển hướng sang menu sinh viên
                return; 
            }
        }

        // 2. Kiểm tra Giáo viên
        for (auto& teacher : db.teacherList) {
            if (teacher.getID() == inputId && teacher.checkPassword(inputPass)) {
                cout << "\n[HỆ THỐNG]: Xin chào Giáo viên " << teacher.getName() << ".\n";
                teacher.display(); // Chuyển hướng sang menu giáo viên
                return;
            }
        }

        // 3. Kiểm tra Admin
        for (auto& admin : db.adminList) {
            if (admin.getID() == inputId && admin.checkPassword(inputPass)) {
                cout << "\n[HỆ THỐNG]: Xin chào Quản trị viên " << admin.getName() << ".\n";
                admin.display(); // Chuyển hướng sang menu admin
                return;
            }
        }

        cout << "[THẤT BẠI]: Sai mã số hoặc mật khẩu!\n";
    }
}