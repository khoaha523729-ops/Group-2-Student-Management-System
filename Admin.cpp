#include <iostream>
#include <fstream>   
#include <string>
#include <algorithm>
#include "Database.h"
#include "Admin.h"
#include "Course.h"

using namespace std;

Admin::Admin(string aId, string pass, string aName) 
{
    this->aId = aId;
    this->aPass = pass;
    this->aName = aName;
}

string Admin::getID() const { return aId; }
string Admin::getName() const { return aName; }
bool Admin::checkPassword(const string& inputPass) const { return aPass == inputPass; }

string formatSpace(string str) {
    replace(str.begin(), str.end(), ' ', '_');
    return str;
}

void Admin::editInfo() {
    //Xử lý khóa học (Course)
    if (managingCourses != nullptr) {
        ofstream f("data/course.txt");
        if (f.is_open()) {
            for (size_t i = 0; i < managingCourses->size(); i++) {
                f << managingCourses->at(i).getCourseID() << " " 
                  << formatSpace(managingCourses->at(i).getCourseName()) << "\n";
            }
            f.close();
        }
    }

//Xử lý sinh viên (Student)
    if (managingStudents != nullptr) {
        ofstream f("data/student.txt");
        if (f.is_open()) {
            for (size_t i = 0; i < managingStudents->size(); i++) {
                // Format : S01 1001 Nguyen_An_Binh Male 12/03/2007 Khoa_hoc_may_tinh
                f << managingStudents->at(i).getID() << " "
                  << managingStudents->at(i).getPass() << " " 
                  << formatSpace(managingStudents->at(i).getName()) << " "
                  << managingStudents->at(i).getGender() << " "
                  << managingStudents->at(i).getBirthday() << " "
                  << formatSpace(managingStudents->at(i).getMajor()) << "\n";
            }
            f.close();
        }
    }

    // Xử lý giáo viên (Teacher)
    if (managingTeachers != nullptr) {
        ofstream f("data/teacher.txt");
        if (f.is_open()) {
            for (size_t i = 0; i < managingTeachers->size(); i++) {
                f << managingTeachers->at(i).getID() << " "
                  << managingTeachers->at(i).getPass() << " " 
                  << formatSpace(managingTeachers->at(i).getName()) << " "
                  << managingTeachers->at(i).getGender() << " "
                  << managingTeachers->at(i).getBirthday() << " "
                  << managingTeachers->at(i).getTeachingCourses() << "\n"; 
            }
            f.close();
        }
    }
    cout << "[He thong] Da luu data thanh cong!" << endl;
}

void Admin::setData(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers) {
    this->managingCourses = &courses;
    this->managingStudents = &students;
    this->managingTeachers = &teachers;
}

void Admin::adminMenu(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers, Database& db) {
    setData(courses, students, teachers); 
    int choice;
    while (true) {
        cout << "\n===== ADMIN MAIN MENU =====" << endl;
        cout << "1. Quan ly mon hoc (Course)" << endl;
        cout << "2. Quan ly sinh vien (Student)" << endl;
        cout << "3. Quan ly giao vien (Teacher)" << endl;
        cout << "0. Dang xuat va luu du lieu" << endl;
        cout << "Chon: "; cin >> choice;

        if (choice == 0) break;
        switch (choice) {
            case 1: courseSubMenu(db); break;
            case 2: studentSubMenu(db); break;
            case 3: teacherSubMenu(db); break;
            default: cout << "Lua chon sai!" << endl;
        }
    }
    editInfo();
}

void Admin::courseSubMenu(Database& db) {
    int choice;
    cout << "\n=== DANH SACH MON HOC HIEN TAI ===\n";
    if (db.courseList.empty()) {
        cout << "(Chua co mon hoc nao)\n";
    } else {
        for (const auto& c : db.courseList) {
            cout << " - Ma mon: " << c.getCourseID() << " | Ten mon: " << c.getCourseName() << endl;
        }
    }
    cout << "======================================\n";

    cout << "\n[COURSE MENU]\n1. Add Course\n2. Edit Course\n0. Return\nChoice: ";
    cin >> choice;
    if (choice == 1) addCourse();
    else if (choice == 2) editCourse();
}

void Admin::studentSubMenu(Database& db) {
    int choice;
    cout << "\n=== DANH SACH SINH VIEN HIEN TAI ===\n";
    if (db.studentList.empty()) {
        cout << "(Chua co danh sach sinh cien)\n";
    } else {
        for (const auto& s : db.studentList) {
            cout << " - MSSV: " << s.getID() << " | Ho ten: " << s.getName() << " | Nganh: " << s.getMajor() << endl;
        }
    }
    cout << "======================================\n";
    
    cout << "\n[STUDENT MENU]\n1. Add Student\n2. Edit Student\n0. Return\nChoice: ";
    cin >> choice;
    if (choice == 1) addStudent();
    else if (choice == 2) editStudent();
}

void Admin::teacherSubMenu(Database& db) {
    int choice;
    cout << "\n=== DANH SACH GIAO VIEN HIEN TAI ===\n";
    if (db.teacherList.empty()) {
        cout << "(Chua co danh sach giao vien)\n";
    } else {
        for (const auto& t : db.teacherList) {
            cout << " - Ma giao vien: " << t.getID() << " | Ho ten: " << t.getName() << endl;
        }
    }
    cout << "======================================\n";
    cout << "\n[TEACHER MENU]\n1. Add Teacher\n2. Edit Teacher\n0. Return\nChoice: ";
    cin >> choice;
    if (choice == 1) addTeacher();
    else if (choice == 2) editTeacher();
}

void Admin::addCourse() {
    string inputID, inputName;
    cout << "\n====== THEM MON HOC MOI ======" << endl;
    cout << "Nhap Ma mon hoc: "; cin >> inputID;
    cin.ignore(1000, '\n');

    for (size_t i = 0; i < managingCourses->size(); i++) {
        if (managingCourses->at(i).getCourseID() == inputID) {
            cout << "[Loi] Ma mon hoc " << inputID << " da ton tai trong he thong!" << endl;
            return; 
        }
    }

    cout << "Nhap Ten mon hoc: "; getline(cin, inputName);
    managingCourses->emplace_back(inputID, inputName);
    cout << "=> Them mon hoc thanh cong!" << endl;
}

void Admin::editCourse() {
    string id;
    cout << "\n===== SUA THONG TIN MON HOC =====" << endl;
    cout << "Nhap Ma mon hoc can sua: "; cin >> id;
    cin.ignore(1000, '\n');

    bool found = false;
    for (size_t i = 0; i < managingCourses->size(); i++) {
        if (managingCourses->at(i).getCourseID() == id) {
            string newName;
            cout << "Mon hoc hien tai: " << managingCourses->at(i).getCourseName() << endl;
            cout << "Nhap Ten moi: "; getline(cin, newName);

            managingCourses->at(i).setName(newName);
            cout << "=> Cap nhat ten mon hoc thanh cong!" << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "[Loi] Khong tim thay mon hoc co ma: " << id << endl;
}

void Admin::addStudent() {
    string inputId, inputName, inputGender, inputBirthday, inputMajor;
    string defaultPass = "123";
    
    cout << "\n===== THEM SINH VIEN MOI =====" << endl;
    cout << "Nhap ID: "; cin >> inputId; 
    cin.ignore(1000, '\n'); 

    for (size_t i = 0; i < managingStudents->size(); i++) {
        if (managingStudents->at(i).getID() == inputId) {
            cout << "[Loi] Ma sinh vien " << inputId << " da ton tai trong he thong!" << endl;
            return;
        }
    }

    cout << "Nhap ten: "; getline(cin, inputName);
    cout << "Gioi tinh: "; cin >> inputGender;
    cout << "Ngay sinh (dd/mm/yyyy): "; cin >> inputBirthday;
    cin.ignore(1000, '\n');
    cout << "Chuyen nganh: "; getline(cin, inputMajor);

    managingStudents->push_back(Student(inputId, defaultPass, inputName, inputGender, inputBirthday, inputMajor));
    cout << "=> Them sinh vien thanh cong!" << endl;
}

void Admin::editStudent() {
    string id;
    cout << "\n===== SUA THONG TIN SINH VIEN =====" << endl;
    cout << "Nhap Student ID can sua: "; cin >> id;
    cin.ignore(1000, '\n');
    bool found = false;
    for (size_t i = 0; i < managingStudents->size(); i++) {
        if (managingStudents->at(i).getID() == id) {
            string newName;
            cout << "Sinh vien hien tai: " << managingStudents->at(i).getName() << endl;
            cout << "Nhap ten moi: "; getline(cin, newName);
            
            User* userPtr = &(managingStudents->at(i));
            userPtr->setName(newName); 
            
            cout << "=> Cap nhat ten thanh cong!" << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "[Loi] Khong tim thay sinh vien ID: " << id << endl;
}

void Admin::addTeacher() {
    string inputId, inputName, inputGender, inputBirthday;
    vector<string> inputClassId;
    string defaultPass = "123"; 

    cout << "\n===== THEM GIAO VIEN MOI =====" << endl;
    cout << "Nhap ID Giao vien: "; cin >> inputId;
    cin.ignore(1000, '\n'); 
    cout << "Nhap Ho ten: "; getline(cin, inputName);
    cout << "Nhap Gioi tinh: "; cin >> inputGender;
    cout << "Nhap Ngay sinh (dd/mm/yyyy): "; cin >> inputBirthday;

    managingTeachers->push_back(Teacher(inputId, defaultPass, inputName, inputGender, inputBirthday, inputClassId));

    cout << "=> Them giao vien thanh cong!" << endl;
}

void Admin::editTeacher() {
    string id;
    cout << "\n===== SUA THONG TIN GIAO VIEN =====" << endl;
    cout << "Nhap Teacher ID can sua: "; cin >> id;
    cin.ignore(1000, '\n'); 

    bool found = false;
    for (size_t i = 0; i < managingTeachers->size(); i++) {
        if (managingTeachers->at(i).getID() == id) {
            string newName, newGender, newBirthday;
            cout << "Tim thay giao vien: " << managingTeachers->at(i).getName() << endl;
            
            cout << "Nhap Ten moi: "; getline(cin, newName);
            cout << "Nhap Gioi tinh moi: "; cin >> newGender;
            cin.ignore(1000, '\n');
            cout << "Nhap Ngay sinh moi: "; cin >> newBirthday;

            User* userPtr = &(managingTeachers->at(i));
            userPtr->setName(newName);
            userPtr->setGender(newGender);
            userPtr->setBirthday(newBirthday);

            cout << "=> Cap nhat thong tin giao vien thanh cong!" << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "[Loi] Khong tim thay giao vien co ID: " << id << endl;
}