#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

using namespace std;

void max_vector(const vector<int>& nums) {
    int maxElement = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > maxElement) {
            maxElement = nums[i];
        }
    }
    cout << "Максимальный элемент: " << maxElement << endl;
}

void chet_element(const vector<int>& nums) {
    for (const int num : nums) {
        if (num % 2 == 0) {
            cout << num << " ";
        }
    }
}

class Student {
    string name;
    string group;
    int age{};
public:
    Student(const string& name,const string& group, int age) : name(name), group(group), age(age) {}
    ~Student() = default;
    void printInfo() const {
        cout << format("----------\n"
                       "Имя студента: {0}\n"
                       "Группа: {1}\n"
                       "Возраст: {2}\n"
                       "----------", name, group, age);
    }
};

/*
int main() {
    vector nums = {3, 7, 2, 9, 1, 5, 8};
    max_vector(nums);
    chet_element(nums);
    cout << *ranges::max_element(nums);
    cout << endl;
    for (int i = 0; i < nums.size() / 2; i++) {
        swap(nums[i], nums[nums.size() - 1 - i]);
    }
    cout << endl;
    for (const int num : nums) {
        cout << num << " ";
    }
    const vector<Student> students = {
        Student("Никита", "РПО 23/2", 16),
            Student("Андрей", "ГД 24/1", 15)
    };
    for (const auto& student : students) {
        student.printInfo();
    }
}*/