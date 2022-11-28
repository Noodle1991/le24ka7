#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <sstream>

std::string read_file_from_path(const std::string &path) {
    std::ifstream f(path);
    std::string result;
    if (f) {
        std::stringstream ss;
        ss << f.rdbuf();
        return ss.str();
    }
}

void count_palindromes(std::string stroka) {
    int amount = 0, nope = 0, len0 = 0, len = 0;
    while (len < stroka.length()) {
        ///нахождение длины следоющего слова
        while (stroka[len] != '\n') {
            ++len;
        }

        ///проверка слова на палиндром
        for (int i = 0; len0 + i < len - i; ++i) {
            if (stroka[len0 + i] < 91 && stroka[len - i - 1] < 91) {
                if (stroka[len0 + i] != stroka[len - i - 1]) {
                    nope = 1;
                }
            } else if (stroka[len0 + i] < 91) {
                if (stroka[len0 + i] + 32 != stroka[len - i - 1]) {
                    nope = 1;
                }
            } else if (stroka[len - i - 1] < 91) {
                if (stroka[len0 + i] != stroka[len - i - 1] + 32) {
                    nope = 1;
                }
            } else if (stroka[len0 + i] != stroka[len - i - 1]) {
                nope = 1;
            }
        }

        ///если палиндром => +1
        if (nope == 0) {
            amount = amount + 1;
        } else nope = 0;

        ///нужно перескочить '\n'
        ++len;

        ///запаминание пройденного расстояния
        len0 = len;
    }
    std::cout << amount;
}

void palindromes(std::string stroka) {
    int nope = 0, len0 = 0, len = 0, comma = 0;
    while (len < stroka.length()) {

        ///нахождение длины следоющего слова
        while (stroka[len] != '\n') {
            ++len;
        }

        ///проверка слова на палиндром
        for (int i = 0; len0 + i < len - i; ++i) {
            if (stroka[len0 + i] < 91 && stroka[len - i - 1] < 91) {
                if (stroka[len0 + i] != stroka[len - i - 1]) {
                    nope = 1;
                }
            } else if (stroka[len0 + i] < 91) {
                if (stroka[len0 + i] + 32 != stroka[len - i - 1]) {
                    nope = 1;
                }
            } else if (stroka[len - i - 1] < 91) {
                if (stroka[len0 + i] != stroka[len - i - 1] + 32) {
                    nope = 1;
                }
            } else if (stroka[len0 + i] != stroka[len - i - 1]) {
                nope = 1;
            }
        }

        ///если палиндром => вывод
        if (nope == 0) {
            if (comma == 0) {
                std::cout << "\"";
                comma = 1;
            } else std::cout << ", " << "\"";
            for (int i = 0; len0 + i < len; i++) {
                std::cout << stroka[len0 + i];
            }
            std::cout << "\"";
        } else nope = 0;

        ///нужно перескочить '\n'
        ++len;

        ///запаминание пройденного расстояния
        len0 = len;
    }
}

int main(int argc, char *argv[]) {
    std::string file(read_file_from_path(argv[1]));
    std::cout << "{" << '\n' << "    " << "\"" << "count_palindromes" << "\"" << ": ";
    count_palindromes(file);
    std::cout << "," << '\n' << "    " << "\"" << "palindromes" << "\"" << ": " << "[";
    palindromes(file);
    std::cout << "]" << "\n" << "}";
    std::cout << "\n";
    return 0;
}
