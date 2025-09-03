#include <iostream> 
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    float average;
};

int main() {
    int n;
    cout << "Введите количество студентов для записи: "; 
    cin >> n;
    cout << endl;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "Введите имя: ";
        cin >> students[i].name;
        cout << "Введите возраст: ";
        cin >> students[i].age;
        cout << "Введите рейтинг: ";
        cin >> students[i].average;
        cout << endl << endl;
    }

    int best = 0, worst = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].average > students[best].average) best = i;
        if (students[i].average < students[worst].average) worst = i;
    }
    cout << "Лучший студент: " << students[best].name << " Рейтинг: " << students[best].average << endl;
    cout << "Худший студент: " << students[worst].name << " Рейтинг: " << students[worst].average << endl;

    delete[] students;
    return 0;
}