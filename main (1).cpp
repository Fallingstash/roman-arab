#include <iostream>
#include <string>
#include <map>
using namespace std;
string toRoman(int num) {
    map<int, string> romanNumerals = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
        {1, "I"}
    };

    string result;
    for (auto pair : romanNumerals) {
        while (num >= pair.first) {
            result += pair.second;
            num -= pair.first;
        }
    }
    return result;
}

int fromRoman(const string roman) {
    map<char, int> romanValues = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int value = 0;
    for (size_t i = 0; i < roman.size(); ++i) {
        if (i + 1 < roman.size() && romanValues[roman[i]] < romanValues[roman[i + 1]]) {
            value -= romanValues[roman[i]];
        } else {
            value += romanValues[roman[i]];
        }
    }
    return value;
}

int main() {
    int choice;
    cout << "Выберите действие:\n1. Арабское в римское\n2. Римское в арабское\n";
    cin >> choice;

    if (choice == 1) {
        int arabic;
        cout << "Введите арабское число: ";
        cin >> arabic;
        cout << "Римское: " << toRoman(arabic) << endl;
    } else if (choice == 2) {
        string roman;
        cout << "Введите римское число: ";
        cin >> roman;
        cout << "Арабское: " << fromRoman(roman) << endl;
    } else {
        cout << "Неверный выбор." << endl;
    }

    return 0;
}