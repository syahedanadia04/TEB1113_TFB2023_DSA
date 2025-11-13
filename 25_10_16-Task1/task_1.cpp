#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    int id;
    string name;
    string email;
};

// get the students data 
void inputStudents(vector<Student>& students, int count){
    cin.ignore();
    for (int i=0; i< count; i++){
        Student s;
        cout << "\n---- Enter details for Student " << i+1 << "---\n";
        
        cout << "Name : ";
        getline (cin, s.name);
        
        cout << "ID :";
        cin >> s.id;
        
        cout << "Email :";
        cin >> s.email;
        cin.ignore();
        
        students.push_back(s);
    }
}

void displayStudents (const vector<Student>& students){
    cout << "\n=====================================\n";
    cout << "           STUDENTS RECORD           \n";
    cout << "=======================================\n";
    
    for (int i=0; i< students.size(); i++){
        cout << "\nStudent #" << i+1 << '\n'
             << "Name : " << students[i].name << '\n'
             << "ID : " << students[i].id << '\n'
             << "Email : " << students[i].email << '\n';
    }
}

int main (){
    int n;
    cout << "How many students?";
    cin >> n;
    
    vector <Student> students;
    inputStudents(students, n);
    
    displayStudents(students);
    
    return 0;
}
