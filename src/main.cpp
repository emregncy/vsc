#include <iostream>
using namespace std;

class Student {
public:
    char name[30], clas[10];
    int age, rol;

    void Enter(){
    cout<<"Please enter your name: "<<endl;
    cin.getline(name, 30);
    cout<<"Please enter student age: "<<endl;
    cin>>age;
    cout<<"Please enter the class of the student: "<<endl;
    cin.getline(clas, 10);
    cout<<"Please enter the roll of the student: "<<endl;
    cin>>rol;
    }

    void display(){
        cout<<"\n Age \t Name \t Rol \t Class";
        cout<<"\n"<<age<<"\t"<<name<<"\t"<<rol<<"\t"<<clas;
    }
};

int main(){
    Student obj1;

    obj1.Enter();
    obj1.display();
    return 0;
}