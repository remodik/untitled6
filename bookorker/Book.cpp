#include "Book.h"

string Book::getAuthor() const {
    return author;
}

string Book::getPublisher() const {
    return publisher;
}

int Book::getYear() const {
    return year;
}

void Book::display() const {
    cout << "Автор: " << author << "\n"
         << "Название: " << title << "\n"
         << "Издательство: " << publisher << "\n"
         << "Количество: " << quantity << "\n"
         << "Страниц: " << pages << "\n" << endl;
}

void Book::printBooksAfterYear(const vector<Book> &books, const int year) {
    cout << "\nКниги, выпущенные после " << year << ": \n";
    for (const auto &book : books) {
        if (book.getYear() > year) {
            book.display();
        }
    }
}

void Book::printBooksByAuthor(const vector<Book> &books, const string &author) {
    cout << "\nКниги автора " << author << ": \n";
    for (const auto &book : books) {
        if (book.getAuthor() == author) {
            book.display();
        }
    }
}

void Book::printBooksByPublisher(const vector<Book> &books, const string &publisher) {
    cout << "\nКниги издательства " << publisher << ": \n";
    for (const auto &book : books) {
        if (book.getPublisher() == publisher) {
            book.display();
        }
    }
}
