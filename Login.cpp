#include "Login.h"
#include <iostream>
using namespace std;

void Login::run(Database& db) {
    string inputId, inputPass;
    while (true) {
        cout << "Id: ";
        cin >> inputId;
        cout << "Password: ";
        cin >> inputPass;

        bool isFound = false;
        for (const auto& student : db.studentList) {
            if (student.getID() == inputId && student.checkPassword(inputPass)) {
                cout << "\n[HỆ THỐNG]: Đăng nhập thành công! Xin chào Sinh viên " << student.getName() << ".\n";
                isFound = true;
                return;
            }
        }
        for (const auto& teacher : db.teacherList) {
            if (teacher.getID() == inputId && teacher.checkPassword(inputPass)) {
                cout << "\n[HỆ THỐNG]: Đăng nhập thành công! Xin chào Giáo viên " << teacher.getName() << ".\n";
                isFound = true;
                return;
            }
        }

        for (const auto& admin : db.adminList) {
            if (admin.getID() == inputId && admin.checkPassword(inputPass)) {
                cout << "\n[HỆ THỐNG]: Đăng nhập thành công! Xin chào Quản trị viên " << admin.getName() << ".\n";
                isFound = true;
                return;
            }
        }

        if (!isFound) {
            cout << "[THẤT BẠI]: Sai mã số hoặc mật khẩu. Vui lòng thử lại!\n";
            cout << "=================================================================\n";
        }
    }
}