#include "Login.h"
#include <iostream>
using namespace std;





void Login::run(Database& db)
{
    string inputId;
    string inputPass;

    while(true)
    {

        cout << "Id: "; 
        cin >> inputId;

        cout << "Password: "; 
        cin >> inputPass;

        bool isFound = false;

        for (const auto& student : db.studentList) 
        {
            if (student.getID() == inputId) 
            { 
                if (student.checkPassword(inputPass)) 
                {
                    cout << "\n[HỆ THỐNG]: Đăng nhập thành công! Xin chào " << student.getName() << ".\n";
                    isFound = true;
                    return;
                }
            }
        }
        if (!isFound) 
        {
            cout << "[THẤT BẠI]: Sai mã số sinh viên hoặc mật khẩu. Vui lòng thử lại!\n";
            cout << "=================================================================\n";
        }
    }
}