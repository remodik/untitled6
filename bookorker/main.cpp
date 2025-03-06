#include <iostream>
#include <format>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Worker.h"
using namespace std;
int main() {
    vector<Book> books = {
        Book("Достоевский", "Преступление и наказание", "Эксмо", 1866, 10, 550),
        Book("Толстой", "Война и мир", "АСТ", 1869, 15, 1225),
        Book("Булгаков", "Мастер и Маргарита", "Азбука", 1967, 12, 450),
        Book("Толстой", "Анна Каренина", "Эксмо", 1877, 8, 864)
    };

    vector<Worker> workers = {
        Worker("Иванов Иван", "Инженер", 2015, 50000),
        Worker("Петров Петр", "Менеджер", 2012, 70000),
        Worker("Сидоров Алексей", "Директор", 2005, 120000),
        Worker("Федорова Мария", "Бухгалтер", 2018, 45000)
    };

    int currentYear = 2024;

    printBooksByAuthor(books, "Толстой");
    printBooksByPublisher(books, "Эксмо");
    printBooksAfterYear(books, 1900);

    printWorkersByExperience(workers, 10, currentYear);
    printWorkersBySalary(workers, 60000);
    printWorkersByPosition(workers, "Инженер");
}