#include "String.h"


String::String() : str{
    nullptr
} {}

String::String(const char *str) {
    length = strlen(str) + 1;
    this->str = new char[length];
    strcpy_s(this->str, length, str);
}

String::String(const String& self) {
    length = self.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, self.str);
}

String::String(String&& self) noexcept {
    str = self.str;
    self.str = nullptr;
}

int String::getLength() const {
    return length;
}

char* String::getStr() const {
    return str;
}

String String::operator+(const String& self) const {
    const int newLength = length + self.length;
    const auto newStr = new char[newLength + 1];
    strcpy_s(newStr, newLength + 1, str);
    strcat_s(newStr, newLength + 1, self.str);
    String result(newStr);
    delete[] str;
    return result;
}

String String::operator-(const String& self) const {
    size_t new_length = 0;
    const auto temp = new char[length + 1];
    temp[0] = '\0';

    for (size_t i = 0; i < length; ++i) {
        bool found = false;
        for (size_t j = 0; j < length; ++j) {
            if (str[i] == self.str[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[new_length++] = str[i];
        }
    }
    temp[new_length] = '\0';

    String res;
    res.length = new_length;
    res.str = new char[new_length + 1];
    strcpy_s(res.str, new_length + 1, temp);

    delete[] temp;
    return res;
}

String String::operator*(const int scalar) const {
    if (scalar <= 0) {
        return String();
    }
    const size_t new_length = length * scalar;
    const auto temp = new char[new_length + 1];
    temp[0] = '\0';

    for (int i = 0; i < scalar; ++i) {
        strcat_s(temp, new_length + 1, str);
    }
    String res;
    res.length = new_length;
    res.str = new char[new_length + 1];
    strcpy_s(res.str, new_length + 1, temp);

    delete[] temp;
    return res;
}

String String::operator=(const String &self) {
    if (this != &self) {
        delete[] str;
        length = self.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, self.str);
    }
    return *this;
}

String String::operator=(String&& self) noexcept {
    if (this != &self) {
        delete[] str;
        str = self.str;
        self.str = nullptr;
    }
    return *this;
}

bool String::operator==(const String& self) const {
    return strcmp(this->str, self.str) == 0;
}

bool String::operator!=(const String& self) const {
    return !(*this == self);
}

bool String::operator>(const String& self) const {
    return strcmp(this->str, self.str) > 0;
}

bool String::operator<(const String& self) const {
    return strcmp(this->str, self.str) < 0;
}

bool String::operator>=(const String& self) const {
    return strcmp(this->str, self.str) >= 0;
}

bool String::operator<=(const String& self) const {
    return strcmp(this->str, self.str) <= 0;
}

bool String::operator()(const String& self) const {
    return strstr(this->str, self.str) == nullptr;
}

char& String::operator[](const size_t index) const {
    if (length >= index) {
        cerr << "Вы вышли за пределы" << endl;
    }
    return str[index];
}

String String::operator!() const {
    const auto temp = new char[length + 1];
    for (size_t i = 0; i < length; ++i) {
        if (isupper(str[i])) {
            temp[i] = tolower(str[i]);
        }
        else if (islower(str[i])) {
            temp[i] = toupper(str[i]);
        }
        else {
            temp[i] = str[i];
        }
    }
    temp[length] = '\0';

    String res;
    res.length = length;
    res.str = new char[length + 1];
    strcpy_s(res.str, length + 1, temp);

    delete[] temp;
    return res;
}

String::~String() {
    delete[] str;
}

ostream& operator<<(ostream& os, const String& s) {
    os << "Cтрока: " << s.str << endl;
    return os;
}

istream& operator>>(istream& is, String& s) {
    char buffer[1000];
    is >> buffer;
    s.length = strlen(buffer);
    s.str = new char[s.length + 1];
    strcpy_s(s.str, s.length + 1, buffer);
    return is;
}