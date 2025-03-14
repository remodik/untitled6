#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>

using namespace std;

class String {
    char* str;
    int length{};
public:
    String();

    explicit String(const char* str);
    String(const String& self);
    String(String&& self) noexcept;
    int getLength() const;
    char* getStr() const;
    String operator+(const String& self) const;
    String operator-(const String& self) const;
    String operator*(int scalar) const;
    String operator=(const String& self);
    String operator=(String&& self) noexcept;
    bool operator==(const String& self) const;
    bool operator!=(const String& self) const;
    bool operator>(const String& self) const;
    bool operator<(const String& self) const;
    bool operator>=(const String& self) const;
    bool operator<=(const String& self) const;
    bool operator()(const String& self) const;
    char& operator[](size_t index) const;
    String operator!() const;
    friend ostream& operator <<(ostream& os, const String& s);
    friend istream& operator >>(istream& is, String& s);
    ~String();


};

#endif