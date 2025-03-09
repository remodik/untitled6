#ifndef BOOK_H
#define BOOK_H
#include <format>
#include <iostream>
#include <utility>
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
    Book(
        string  author,
        string  title,
        string  publisher,
        const int year,
        const int quantity,
        const int pages
        )
    : author(move(author)),
    title(move(title)),
    publisher(move(publisher)),
    year(year), quantity(quantity),
    pages(pages) {}

    string getAuthor() const;
    string getPublisher() const;
    int getYear() const;

    static void printBooksByAuthor(const vector<Book>& books, const string& author);

    static void printBooksByPublisher(const vector<Book>& books, const string& publisher);

    static void printBooksAfterYear(const vector<Book>& books, int year);

    void display() const;
};

#endif