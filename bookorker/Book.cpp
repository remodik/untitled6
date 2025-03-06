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
    cout << format("Автор: {0}\n"
                   "Название: {1}\n"
                   "Издательство: {2}\n"
                   "Количество: {3}\n"
                   "Страниц: {4}\n", author, title, publisher, year, quantity, pages) << endl;
}

void Book::printBooksAfterYear(const vector<Book> &books, int year) {
    cout << format("\nКниги автора {0}: \n", author);
    for (const auto &book : books) {
        if (book.getAuthor() == author) {
            book.display();
        }
    }
}

void Book::printBooksByAuthor(const vector<Book> &books, const string &author) {
    cout << format("\n Книги выпущенные после {0}: \n", year);
    for (const auto &book : books) {
        if (book.getYear() == year) {
            book.display();
        }
    }
}

void Book::printBooksByPublisher(const vector<Book> &books, const string &publisher) {
    cout << format("\nКниги издательства {0}: \n");
    for (const auto &book : books) {
        if (book.getPublisher() == publisher) {
            book.display();
        }
    }
}
