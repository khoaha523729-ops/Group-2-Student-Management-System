// #include "Admin.h"
// #include <iostream>
// #include <fstream>   
// #include <windows.h> 
// #include <string>


// using namespace std;

// Admin::Admin(string aId, string pass, string aName) 
// {
//     this->aId = aId;
//     this->aPass = pass;
//     this->aName = aName;
// }

// string Admin::getID() const
// {
//     return aId;
// }

// string Admin::getName() const
// {
//     return aName;
// }

// bool Admin::checkPassword(const string& inputPass) const
// {
//     return aPass == inputPass; 
// }

// // Hàm hủy lưu file
// // Admin::~Admin() {
// //     cout << "\n[He thong] Dang tu dong luu du lieu vao thu muc data..." << endl;

// //     if (managingCourses != nullptr) {
// //         ofstream f("data/course.txt"); 
// //         if (f.is_open()) {
// //             // Dung vong lap for binh thuong
// //             for (int i = 0; i < managingCourses->size(); i++) {
// //                 f << managingCourses->at(i).id << "," << managingCourses->at(i).name << "\n"; 
// //             }
// //             f.close();
// //         }
// //     }

// //     if (managingStudents != nullptr) {
// //         ofstream f("data/student.txt");
// //         if (f.is_open()) {
// //             for (int i = 0; i < managingStudents->size(); i++) {
// //                 f << managingStudents->at(i).id << "," 
// //                   << managingStudents->at(i).name << "," 
// //                   << managingStudents->at(i).dob << "," 
// //                   << managingStudents->at(i).sex << "," 
// //                   << managingStudents->at(i).field << "\n";
// //             }
// //             f.close();
// //         }
// //     }

// //     if (managingTeachers != nullptr) {
// //         ofstream f("data/teacher.txt");
// //         if (f.is_open()) {
// //             for (int i = 0; i < managingTeachers->size(); i++) {
// //                 f << managingTeachers->at(i).id << "," << managingTeachers->at(i).name << "\n";
// //             }
// //             f.close();
// //         }
// //     }
// //     cout << "[He thong] Da luu data thanh cong!" << endl;
// // }

// void Admin::setData(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers) {
//     this->managingCourses = &courses;
//     this->managingStudents = &students;
//     this->managingTeachers = &teachers;
// }

// void Admin::adminMenu(vector<Course>& courses, vector<Student>& students, vector<Teacher>& teachers) {
//     setData(courses, students, teachers); 
//     int choice;
//     while (true) {
//         cout << "\n===== ADMIN MAIN MENU =====" << endl;
//         cout << "1. Quan ly mon hoc (Course)" << endl;
//         cout << "2. Quan ly sinh vien (Student)" << endl;
//         cout << "3. Quan ly giao vien (Teacher)" << endl;
//         cout << "0. Dang xuat" << endl;
//         cout << "Chon: "; cin >> choice;

//         if (choice == 0) break;
//         switch (choice) {
//             case 1: courseSubMenu(); break;
//             case 2: studentSubMenu(); break;
//             case 3: teacherSubMenu(); break;
//             default: cout << "Lua chon sai!" << endl;
//         }
//     }
// }

// void Admin::courseSubMenu() {
//     int choice;
//     cout << "\n[COURSE MENU]\n1. Add Course\n2. Edit Course\n0. Return\nChoice: ";
//     cin >> choice;
//     if (choice == 1) addCourse();
//     else if (choice == 2) editCourse();
// }

// void Admin::studentSubMenu() {
//     int choice;
//     cout << "\n[STUDENT MENU]\n1. Add Student\n2. Edit Student\n0. Return\nChoice: ";
//     cin >> choice;
//     if (choice == 1) addStudent();
//     else if (choice == 2) editStudent();
// }

// void Admin::teacherSubMenu() {
//     int choice;
//     cout << "\n[TEACHER MENU]\n1. Add Teacher\n2. Edit Teacher\n0. Return\nChoice: ";
//     cin >> choice;
//     if (choice == 1) addTeacher();
//     else if (choice == 2) editTeacher();
// }

// void Admin::addCourse() {
//     string inputID;
//     string inputName;
//     cout << "\n----- THEM MON HOC MOI -----" << endl;
//     cout << "Nhap Ma mon hoc: "; cin >> inputID;
//     cin.ignore(1000, '\n');

//     // Kiem tra trung ma mon hoc
//     for (int i = 0; i < managingCourses->size(); i++) {
//         if (managingCourses->at(i).getCourseID() == inputID) {
//             cout << "[Loi] Ma mon hoc " << inputID << " da ton tai trong he thong!" << endl;
//             return; // Thoat ham neu trung ma
//         }
//     }

//     cout << "Nhap Ten mon hoc: "; getline(cin, inputName);

//     // Them vao vector thong qua con tro [1]
//     managingCourses->emplace_back(inputID, inputName);
//     cout << "=> Them mon hoc thanh cong!" << endl;
// }
// void Admin::editCourse() {
//     string id;
//     cout << "\n----- SUA THONG TIN MON HOC -----" << endl;
//     cout << "Nhap Ma mon hoc can sua: "; cin >> id;
//     cin.ignore(1000, '\n');

//     bool found = false;
//     for (int i = 0; i < managingCourses->size(); i++) {
//         // Su dung getCourseID() de kiem tra [1, 2]
//         if (managingCourses->at(i).getCourseID() == id) {
//             string newName;
//             cout << "Mon hoc hien tai: " << managingCourses->at(i).getCourseName() << endl;
//             cout << "Nhap Ten moi: "; 
//             getline(cin, newName);

//             // Goi ham setName tu lop Course de cap nhat [2]
//             managingCourses->at(i).setName(newName);
            
//             cout << "=> Cap nhat ten mon hoc thanh cong!" << endl;
//             found = true;
//             break;
//         }
//     }

//     if (!found) {
//         cout << "[Loi] Khong tim thay mon hoc co ma: " << id << endl;
//     }
// }

// void Admin::addStudent() {
//     string inputId, inputName, inputGender, inputBirthday, inputMajor;
//     string defaultPass = "123";
    
//     cout << "Nhap ID: "; cin >> inputId; cin.ignore();
//     cout << "Nhap ten: "; getline(cin, inputName);
//     cout << "Gioi tinh: "; cin >> inputGender;
//     cout << "Ngay sinh: "; cin >> inputBirthday;
//     cout << "Chuyen nganh: "; cin >> inputMajor;

//     managingStudents->push_back(Student(inputId, defaultPass, inputName, inputGender, inputBirthday, inputMajor));
//     cout << "Them sinh vien thanh cong!" << endl;
// }

// void Admin::editStudent() {
//     string id;
//     cout << "Nhap Student ID can sua: "; cin >> id;
//     cin.ignore(1000, '\n'); 
    
//     bool found = false;
//     for (int i = 0; i < managingStudents->size(); i++) {
//         if (managingStudents->at(i).getID() == id) {
//             string newName, newMajor;
//             cout << "Nhap ten moi: "; getline(cin, newName);
//             cout << "Nhap nganh moi: "; getline(cin, newMajor);
            
//             managingStudents->at(i).setName(newName); // Sử dụng hàm từ User/Student [5, 6]
//             managingStudents->at(i).setMajor(newMajor);
//             cout << "Cap nhat thanh cong!" << endl;
//             found = true;
//             break;
//         }
//     }
//     if (!found) cout << "Khong tim thay sinh vien ID: " << id << endl;
// }
// void Admin::addTeacher() {
//     string inputId, inputName, inputGender, inputBirthday;
//     string defaultPass = "123"; // Mật khẩu mặc định [1]

//     cout << "\n----- THEM GIAO VIEN MOI -----" << endl;
//     cout << "Nhap ID Giao vien: "; cin >> inputId;
//     cin.ignore(1000, '\n'); // Xoa bo nho dem
//     cout << "Nhap Ho ten: "; getline(cin, inputName);
//     cout << "Nhap Gioi tinh: "; cin >> inputGender;
//     cout << "Nhap Ngay sinh (dd/mm/yyyy): "; cin >> inputBirthday;

//     // Khoi tao doi tuong Teacher va day vao vector quan ly
//     // Dung con tro managingTeachers da ket noi voi Database
//     Teacher newTeacher(inputId, defaultPass, inputName, inputBirthday);
//     newTeacher.setGender(inputGender); // Thiet lap gioi tinh qua ham set tu lop User [4]
    
//     managingTeachers->push_back(newTeacher);
//     cout << "=> Them giao vien thanh cong!" << endl;
// }

// void Admin::editTeacher() {
//     string id;
//     cout << "Nhap Teacher ID can sua: "; cin >> id;
//     cin.ignore(1000, '\n'); 

//     bool found = false;
//     for (int i = 0; i < managingTeachers->size(); i++) {
//         // Lay thong tin qua ham get tu lop User [5]
//         if (managingTeachers->at(i).getID() == id) {
//             string newName, newGender, newBirthday;
//             cout << "Tim thay giao vien: " << managingTeachers->at(i).getName() << endl;
            
//             cout << "Nhap Ten moi: "; getline(cin, newName);
//             cout << "Nhap Gioi tinh moi: "; cin >> newGender;
//             cout << "Nhap Ngay sinh moi: "; cin >> newBirthday;

//             // Cap nhat thong tin
//             managingTeachers->at(i).setName(newName);
//             managingTeachers->at(i).setGender(newGender);
//             managingTeachers->at(i).setBirthday(newBirthday);

//             cout << "=> Cap nhat thong tin giao vien thanh cong!" << endl;
//             found = true;
//             break;
//         }
//     }

//     if (!found) {
//         cout << "[Loi] Khong tim thay giao vien co ID: " << id << endl;
//     }
// }
