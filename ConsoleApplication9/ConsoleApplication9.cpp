#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

class Person {
public:
    Person(const string& name, int age) : name(name), age(age) {}

    void printType() {
        cout << "Type of this object (Person): " << typeid(*this).name() << endl;
    }

    void printTypeUsingTypeid() {
        cout << "Type of this object using typeid (Person): " << typeid(*this).name() << endl;
    }

    void printTypeUsingTypeidWithAuto() {
        auto& obj = *this;
        cout << "Type of this object using typeid with auto (Person): " << typeid(obj).name() << endl;
    }

    void printTypeUsingTypeidWithDecltype() {
        decltype(*this) obj = *this;
        cout << "Type of this object using typeid with decltype (Person): " << typeid(obj).name() << endl;
    }

    virtual void printDerivedType() {
        cout << "Type of this object (Derived - Person): " << typeid(*this).name() << endl;
    }

    virtual void printDerivedTypeUsingTypeid() {
        cout << "Type of this object using typeid (Derived - Person): " << typeid(*this).name() << endl;
    }

    virtual void printDerivedTypeUsingTypeidWithAuto() {
        auto& obj = *this;
        cout << "Type of this object using typeid with auto (Derived - Person): " << typeid(obj).name() << endl;
    }

    virtual void printDerivedTypeUsingTypeidWithDecltype() {
        decltype(*this) obj = *this;
        cout << "Type of this object using typeid with decltype (Derived - Person): " << typeid(obj).name() << endl;
    }

private:
    string name;
    int age;
};

class Student : public Person {
public:
    Student(const string& name, int age, const string& university) : Person(name, age), university(university) {}

    void printDerivedType() override {
        cout << "Type of this object (Derived - Student): " << typeid(*this).name() << endl;
    }

    void printDerivedTypeUsingTypeid() override {
        cout << "Type of this object using typeid (Derived - Student): " << typeid(*this).name() << endl;
    }

    void printDerivedTypeUsingTypeidWithAuto() override {
        auto& obj = *this;
        cout << "Type of this object using typeid with auto (Derived - Student): " << typeid(obj).name() << endl;
    }

    void printDerivedTypeUsingTypeidWithDecltype() override {
        decltype(*this) obj = *this;
        cout << "Type of this object using typeid with decltype (Derived - Student): " << typeid(obj).name() << endl;
    }

private:
    string university;
};

int main() {
    Person person("Alice", 30);
    Student student("Bob", 20, "XYZ University");

    person.printType();
    person.printTypeUsingTypeid();
    person.printTypeUsingTypeidWithAuto();
    person.printTypeUsingTypeidWithDecltype();
    person.printDerivedType();
    person.printDerivedTypeUsingTypeid();
    person.printDerivedTypeUsingTypeidWithAuto();
    person.printDerivedTypeUsingTypeidWithDecltype();

    student.printType();
    student.printTypeUsingTypeid();
    student.printTypeUsingTypeidWithAuto();
    student.printTypeUsingTypeidWithDecltype();
    student.printDerivedType();
    student.printDerivedTypeUsingTypeid();
    student.printDerivedTypeUsingTypeidWithAuto();
    student.printDerivedTypeUsingTypeidWithDecltype();

    return 0;
}
