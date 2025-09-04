#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Book {
    string name;
    string author;
    int age;
};
int main() {
    int n;
    int countBook = 0;
    Book* books = nullptr;
    do {
        cout << "\n=========== MENU ===========" << endl;
        cout << "1. Добавить книгу" << endl;
        cout << "2. Найти по автору" << endl;
        cout << "3. Сортировка по годам" << endl;
        cout << "4. Вывод всех книг" << endl;
        cout << "5. Выход" << endl;
        cout << ": ";
        cin >> n;
        cin.ignore(); 
        
        switch (n) {
            case 1: {
                Book* newBooks = new Book[countBook + 1];
            
                for (int i = 0; i < countBook; i++) {
                    newBooks[i] = books[i];
                }
            
                cout << "Введите название книги: ";
                cin >> newBooks[countBook].name;
            
                cout << "Введите автора книги: ";
                cin >> newBooks[countBook].author;
            
                cout << "Введите год выпуска книги: ";
                cin >> newBooks[countBook].age;
            
                delete[] books;
                books = newBooks;
                countBook++;
            
                cout << "Книга добавлена!" << endl;
                break;
            }            
        case 2: {
            string a;
            cout << "Введите автора книги для поиска: ";
            getline(cin, a);
            bool found = false;
            for (int i = 0; i < countBook; i++) {
                if (books[i].author == a) {
                    cout << "Книга найдена: " << endl;
                    cout << books[i].age << " — " << books[i].name << " (" << books[i].author << ")" << endl;
                    found = true;
                }
            }
            if (!found) cout << "❌ Книги этого автора не найдены." << endl;
            break;
        }
        case 3: {
            if (countBook > 1) {
                sort(books, books + countBook, [](const Book& a, const Book& b) {
                    return a.age < b.age;
                });
                cout << "✅ Книги отсортированы по годам." << endl;
            } else {
                cout << "Недостаточно книг для сортировки" << endl;
            }
            break;
        }
        case 4: {
            if (countBook == 0) {
                cout << "Библиотека пуста." << endl;
            } else {
                cout << "\nВсе книги в библиотеке:\n";
                for (int i = 0; i < countBook; i++) {
                    cout << books[i].age << " — " << books[i].name << " (" << books[i].author << ")" << endl;
                }
            }
            break;
        }
        default:
            cout << "Неверный пункт меню!";
            break;
        }
    } while(n != 5);
}