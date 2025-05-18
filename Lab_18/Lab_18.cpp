#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <io.h>
#include <fcntl.h>
#include <map>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <windows.h>
std::wstring ukrAlphabet = L"абвгґдеєжзиийклмнопрстуфхцчшщьюя";

void vegenerTable(std::wstring& alphabet){
    for (int i = 0; i < alphabet.size(); i++){
        wchar_t temp = alphabet[i];
        for (int j = 0; j < alphabet.size(); j++){
            std::wcout << alphabet[j];
        }
        std::wcout << L"\n";
        for (int i = 0; i < alphabet.size() - 1; i++){
            std::swap(alphabet[i], alphabet[i + 1]);
        }
    }
}

const wchar_t PolybiusSquare[6][6] = {
    {L'а', L'б', L'в', L'г', L'ґ', L'д'},
    {L'е', L'є', L'ж', L'з', L'и', L'і'},
    {L'й', L'к', L'л', L'м', L'н', L'о'},
    {L'п', L'р', L'с', L'т', L'у', L'ф'},
    {L'х', L'ц', L'ч', L'ш', L'щ', L'ь'},
    {L'ю', L'я', L' ', L'.', L',', L'!'}
};

std::map<wchar_t, wchar_t> simpleEncodings = {
    {L'о', L'а'}, {L'а', L'б'}, {L'е', L'в'}, {L'і', L'г'}, {L'н', L'ґ'},
    {L'т', L'д'}, {L'с', L'е'}, {L'р', L'є'}, {L'л', L'ж'}, {L'в', L'з'},
    {L'к', L'и'}, {L'м', L'й'}, {L'д', L'ї'}, {L'п', L'к'}, {L'у', L'л'},
    {L'з', L'м'}, {L'я', L'ь'}, {L'и', L'о'}, {L'б', L'п'}, {L'г', L'р'},
    {L'ї', L'с'}, {L'й', L'т'}, {L'х', L'у'}, {L'ж', L'ф'}, {L'є', L'х'},
    {L'ч', L'ц'}, {L'ю', L'ч'}, {L'ш', L'ш'}, {L'ц', L'щ'}, {L'щ', L'ю'},
    {L'ф', L'я'}, {L'ґ', L'н'}, {L'ь', L'ґ'}
};

std::map<wchar_t, double> ukrLetterFrequencies = {
    {L'о', 9.28}, {L'а', 8.34}, {L'е', 7.89}, {L'і', 7.56}, {L'н', 6.95},
    {L'т', 6.29}, {L'с', 5.62}, {L'р', 5.01}, {L'л', 4.70}, {L'в', 4.48},
    {L'к', 3.95}, {L'м', 3.78}, {L'д', 3.61}, {L'п', 3.42}, {L'у', 2.90},
    {L'з', 2.65}, {L'я', 2.47}, {L'и', 2.20}, {L'б', 1.85}, {L'г', 1.70},
    {L'ї', 1.49}, {L'й', 1.35}, {L'х', 1.11}, {L'ж', 0.95}, {L'є', 0.82},
    {L'ч', 0.77}, {L'ю', 0.64}, {L'ш', 0.59}, {L'ц', 0.52}, {L'щ', 0.43},
    {L'ф', 0.22}, {L'ґ', 0.15}, {L'ь', 0.13}
};

std::map<wchar_t, double> getLetterFrequencies(const std::wstring& text) {
    std::map<wchar_t, double> frequencies;
    int totalLetters = 0;

    for (wchar_t ch : text) {
        if (ukrLetterFrequencies.find(ch) != ukrLetterFrequencies.end()) {
            frequencies[ch]++;
            totalLetters++;
        }
    }

    for (auto& pair : frequencies) {
        pair.second = (pair.second / totalLetters) * 100;
    }

    return frequencies;
}

std::wstring decrypt(const std::wstring& text, int shift) {
    shift = (shift % 32 + 32) % 32;
    std::wstring result;
    for (wchar_t ch : text) {
        if (ch >= L'а' && ch <= L'я') {
            int index = (ch - L'а' - shift + 32) % 32;
            result += L'а' + index;
        } else if (ch >= L'А' && ch <= L'Я') {
            int index = (ch - L'А' - shift + 32) % 32;
            result += L'А' + index;
        } else {
            result += ch;
        }
    }
    return result;
}

void decryptFrequencyAnalysis(const std::wstring& text) {
    auto cipherFrequencies = getLetterFrequencies(text);

    std::vector<std::pair<wchar_t, double>> cipherSorted(cipherFrequencies.begin(), cipherFrequencies.end());
    std::vector<std::pair<wchar_t, double>> ukrSorted(ukrLetterFrequencies.begin(), ukrLetterFrequencies.end());

    std::sort(cipherSorted.begin(), cipherSorted.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    std::sort(ukrSorted.begin(), ukrSorted.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    int userInput = 1, counter = 0;

    while (userInput == 1 && counter < cipherSorted.size()) {
        wchar_t cipherChar = cipherSorted[counter].first;

        double minDiff = std::numeric_limits<double>::max();
        wchar_t bestMatch = L' ';
        for (auto& pair : ukrSorted) {
            double diff = std::abs(pair.second - cipherSorted[counter].second);
            if (diff < minDiff) {
                minDiff = diff;
                bestMatch = pair.first;
            }
        }

        int shift = (cipherChar - bestMatch + 32) % 32;
        std::wstring decrypted = decrypt(text, shift);

        std::wcout << L"\nsymbols: '" << cipherChar << L"' → '" << bestMatch << L"' (зсув " << shift << L")\n";
        std::wcout << L"Dexrypted text:\n" << decrypted << L"\n";
        std::wcout << L"Continue? (1 - так, 0 - ні): ";
        std::wcin >> userInput;

        counter++;
    }
}

std::wstring ceasar(const std::wstring& text, int shift) {
    shift = (shift % 32 + 32) % 32;
    std::wstring result;
    for (wchar_t ch : text) {
        if (ch >= L'а' && ch <= L'я') {
            int index = (ch - L'а' + shift) % 32;
            result += L'а' + index;
        } else if (ch >= L'А' && ch <= L'Я') {
            int index = (ch - L'А' + shift) % 32;
            result += L'А' + index;
        } else {
            result += ch;
        }
    }
    return result;
}

std::wstring enterText() {
    std::wstring text;
    std::wcout << L"Enter text: ";
    std::wcin.ignore();
    std::getline(std::wcin, text);
    return text;
}

std::wstring readFile(const std::string& filename) {
    std::wifstream file(filename);
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));
    if (!file) {
        std::wcerr << L"Failed to open file.\n";
        return L"";
    }
    std::wstringstream buffer;
    std::wstring line;
    while (std::getline(file, line)) {
        buffer << line << L'\n';
    }
    return buffer.str();
}

std::wstring simpleEncoding(const std::wstring& text) {
    std::wstring result;
    for (wchar_t ch : text) {
        if (simpleEncodings.find(ch) != simpleEncodings.end()) {
            result += simpleEncodings[ch];
        } else {
            result += ch;
        }
    }
    return result;
}

std::wstring simpleDecoding(const std::wstring& text) {
    std::wstring result;
    for (wchar_t ch : text) {
        auto it = std::find_if(simpleEncodings.begin(), simpleEncodings.end(),
                               [ch](const std::pair<wchar_t, wchar_t>& pair) { return pair.second == ch; });
        if (it != simpleEncodings.end()) {
            result += it->first;
        } else {
            result += ch;
        }
    }
    return result;
}

std::wstring squareEncoding(const std::wstring& text) {
    std::wstring result;
    for (wchar_t ch : text) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (PolybiusSquare[i][j] == ch) {
                    result += std::to_wstring(i + 1) + std::to_wstring(j + 1);
                    break;
                }
            }
        }
    }
    return result;
}
std::wstring squareDecoding(const std::wstring& text) {
    std::wstring result;
    for (size_t i = 0; i < text.length(); i += 2) {
        int row = text[i] - L'0' - 1;
        int col = text[i + 1] - L'0' - 1;
        if (row >= 0 && row < 6 && col >= 0 && col < 6) {
            result += PolybiusSquare[row][col];
        }
    }
    return result;
}
std::wstring vegenere(const std::wstring& text, const std::wstring& key){
    std::wstring result = text;
    int keyLength = sizeof(key);
    int index = 0;
    for (int i = 0; i < text.length(); i++){
        if (index >= keyLength){
            index = 0;
        }
        result[i] = text[i] + key[index];
        index++;
    }
    return result;
}

std::wstring vegenereDecrypt(const std::wstring& text, const std::wstring& key){
    std::wstring result = text;
    int keyLength = sizeof(key);
    int index = 0;
    for (int i = 0; i < text.length(); i++){
        if (index >= keyLength){
            index = 0;
        }
        result[i] = text[i] - key[index];
        index++;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    while (true) {
        std::wcout << L"\nChoose a task (1-6, 0 for exit)): ";
        int task;
        std::wcin >> task;
        if (task == 0) break;
        switch (task) {
            case 1:{
                std::wcout << L"Select input method (1 - console, 2 - file): ";
                int choice;
                std::wcin >> choice;
                std::wstring text;
                if (choice == 1) {
                    text = enterText();
                } else if (choice == 2) {
                    text = readFile("text.txt");
                } else {
                    std::wcerr << L"Invalid input method.\n";
                    continue;
                }

                std::wcout << L"Enter shift value (positive or negative): ";
                int shift;
                std::wcin >> shift;

                std::wstring encrypted = ceasar(text, shift);
                std::wstring decrypted = decrypt(encrypted, shift);

                std::wcout << L"\nEncrypted text: " << encrypted;
                std::wcout << L"\nDecrypted text: " << decrypted << L"\n";
                std::wcout << L"\nFrequency analysis:\n";
                decryptFrequencyAnalysis(encrypted);
            }
                break;
            case 2:
                {
                    std::wcout << L"Select input method (1 - console, 2 - file): \n";
                    int choice;
                    std::wcin >> choice;
                    std::wstring text;
                    if (choice == 1) {
                        text = enterText();
                    } else if (choice == 2) {
                        text = readFile("text.txt");
                    } else {
                        std::wcerr << L"Invalid input method.\n";
                        continue;
                    }
                    std::wcout << L"Simple encoding:\n";
                    std::wcout << L"Original text: " << text << L"\n";
                    std::wstring encoded = simpleEncoding(text);
                    std::wcout << L"Encoded text: " << encoded << L"\n";
                    std::wcout << L"Decoded text: " << simpleDecoding(encoded) << L"\n";
                }
                break;
            case 3:
                {
                    std::wcout << L"Select input method (1 - console, 2 - file): ";
                    int choice;
                    std::wcin >> choice;
                    std::wstring text;
                    if (choice == 1) {
                        text = enterText();
                    } else if (choice == 2) {
                        text = readFile("text.txt");
                    } else {
                        std::wcerr << L"Invalid input method.\n";
                        continue;
                    }
                    std::wcout << L"Enter key\n";
                    std::wstring key;
                    std::wcin >> key;
                    std::wcout << L"Original text: " << text << L"\n";
                    std::wcout << L"Key: " << key << L"\n";
                    std::wstring encoded = vegenere(text, key);
                    std::wcout << L"Encoded text: " << encoded << L"\n";
                    std::wcout << L"Decoded text: " << vegenereDecrypt(encoded, key) << L"\n";
                    vegenerTable(ukrAlphabet);
                }
                break;
            case 4:
                {
                    std::wcout << L"Select input method (1 - console, 2 - file): \n";
                    int choice;
                    std::wcin >> choice;
                    std::wstring text;
                    if (choice == 1) {
                        text = enterText();
                    } else if (choice == 2) {
                        text = readFile("text.txt");
                    } else {
                        std::wcerr << L"Invalid input method.\n";
                        continue;
                    }
                    std::wcout << L"Original: " << text << L"\n";
                    std::wcout << L"Encoded: " << squareEncoding(text) << L"\n";
                    std::wcout << L"Decoded: " << squareDecoding(squareEncoding(text)) << L"\n";
                }
                break;
            case 5:
                std::wcout << L"Task 5 selected.\n";
                break;
            case 6:
                {
                    std::wcout << L"Select input method (1 - console, 2 - file): \n";
                    int choice;
                    std::wcin >> choice;
                    std::wstring text;
                    if (choice == 1) {
                        text = enterText();
                    } else if (choice == 2) {
                        text = readFile("morse.txt");
                    } else {
                        std::wcerr << L"Invalid input method.\n";
                        continue;
                    }
                }
                break;
            default:
                std::wcerr << L"Invalid task number.\n";
        }
    }
    return 0;
}
