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
        cout << "\n===========================================" << endl;
        if(db.courseList.empty())
        {
            cout << "(Chua phan cong lop hoc nao)" << endl;
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
                             << " | Mon: " << course.getCourseName() << endl;
                    }
                }
            }
        }
        cout << "0. Thoat" << endl;
        cout << "Input Id of class: ";
        cin >> choiceClass;

        if (choiceClass == "0") {
            return;
        } else {
            // Chuyển sang hàm xử hiển học sinh
            viewStudentsInClass(choiceClass, db);
        }
    }
}


void Teacher::viewStudentsInClass(const string& targetClassId, Database& db) {
    cout << "\n===== DANH SACH HOC SINH LOP " << targetClassId << " =====" << endl;
    bool found = false;
    
    // Tạo một vector để lưu lại những MSSV thực sự học lớp này (phục vụ việc đối chiếu sau đó)
    vector<string> validStudentIds;

    for (const auto& grade : db.gradeList) {
        if (grade.getClassId() == targetClassId) {
            string studentIdInGrade = grade.getStudentId();
            
            //Đối chiếu lấy tên sinh viên
            for (const auto& student : db.studentList) {
                if (student.getID() == studentIdInGrade) {
                    cout << "MSV: " << student.getID() << " | Ho ten: " << student.getName() << endl;
                    
                    // Lưu MSSV
                    validStudentIds.push_back(student.getID());
                    found = true;
                    break; 
                }
            }
        }
    }

    if (!found) {
        cout << "Khong tim thay hoc sinh nao thuoc hoc phan nay hoặc ma lop khong ton tai." << endl;
        return; 
    }
    cout << "=========================================\n" << endl;

    string choiceStudentId;
    while (true) {
        cout << "0: Quay lai." << endl;
        cout << "Nhap MSSV muon chinh sua diem: ";
        cin >> choiceStudentId;

        if (choiceStudentId == "0") {
            return; 
        }

        // Kiểm tra xem MSSV trong danh sách validStudentIds 
        bool isValid = false;
        for (const string& id : validStudentIds) {
            if (id == choiceStudentId) {
                isValid = true;
                break;
            }
        }

        if (isValid) {
            editGrade(targetClassId, choiceStudentId, db); 
            return;
        } else {
            cout << "\n[Loi] MSSV khong hop le hoac khong co ten trong danh sach lop! Vui long nhap lai.\n" << endl;
        }
    }

    if (!found) {
        cout << "Khong tim thay hoc sinh nao thuoc hoc phan nay hoặc ma lop khong ton tai." << endl;
    }
    cout << "=========================================\n" << endl;
}

void Teacher::editGrade(const string& targetClassId, const string& studentId, Database& db) {
    cout << "\n======= CHINH SUA DIEM =======" << endl;

    //Tìm và hiển thị tên sinh viên đã chọn
    string studentName = "Unknown";
    for (const auto& student : db.studentList) {
        if (student.getID() == studentId) {
            studentName = student.getName();
            break;
        }
    }
    cout << "Sinh vien: " << studentName << " (MSSV: " << studentId << ")" << endl;

    //Tìm điểm cần sửa trong database
    GradeRecord* targetGrade = nullptr;
    for (auto& grade : db.gradeList) {
        if (grade.getClassId() == targetClassId && grade.getStudentId() == studentId) {
            targetGrade = &grade; 
            break;
        }
    }

    // Hiển thị điểm cũ
    cout << "Diem qua trinh: " << targetGrade->getProcessScore()
         << " | Diem cuoi ky: " << targetGrade->getEndCourseScore() 
         << " | Tong ket mon: " << targetGrade->getFinalScore() << endl;

    // nhập điểm
    double newProcess, newEnd;
    cout << "Diem qua trinh: ";
    cin >> newProcess;
    cout << "Diem cuoi ky: ";
    cin >> newEnd;

    // Lưu điểm
    targetGrade->processScore = newProcess;
    targetGrade->endCourseScore = newEnd;
    
    cout << "\nNhap diem thanh cong" << endl;

    // Đồng bộ ghi đè lại toàn bộ dữ liệu mới từ RAM xuống file txt
    db.exportGrades(); 
    cout << "===========================================\n" << endl;
}

string Teacher::getTeachingCourses() const{
        string result = "";
        for (size_t i = 0; i < classIds.size(); ++i) {
            result += classIds[i];
            if (i < classIds.size() - 1) {
                result += ","; // Thêm dấu phẩy giữa các mã lớp
            }
        }
        return result.empty() ? "None" : result; 
    }
