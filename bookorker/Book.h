#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <format>
#include <vector>
using namespace std;
class Book {
    string author;
    string title;
    string publisher;
    int year;
    int quantity;
    int pages;

public:
    Book(const string& author,const string& title,const string& publisher, int year, int quantity, int pages)
        : author(author), title(title), publisher(publisher), year(year), quantity(quantity), pages(pages) {}

    string getAuthor() const;
    string getPublisher() const;
    int getYear() const;

    void printBooksByAuthor(const vector<Book>& books, const string& author);
    void printBooksByPublisher(const vector<Book>& books, const string& publisher);
    void printBooksAfterYear(const vector<Book>& books, int year);

    void display() const;
};

#endif