#include <iostream>
#include <locale>
#include <io.h>
#include <fcntl.h>
#include <string>
std::wstring alphabetUkr = L"абвгґдеєжзийіїйклмнопрстуфхцчшщьюя";

void visioner(std::wstring& alphabet){
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
int main(){
    setlocale(LC_ALL, "");
    _setmode(_fileno(stdout), _O_U8TEXT);
    visioner(alphabetUkr);
}