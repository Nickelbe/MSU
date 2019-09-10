#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Function(string a, float b)
{
    ifstream file(a);
    float c;
    if (file)
    {
    while (!file.eof()) {
    file >> c;
    if (c == b) {
      return 1;
      }
    }
    file.close();
    }
    else cout <<"Файл не существует"<< endl;
    return 0;
}



int main()
{
    float a;
    cout << "Введите имя файла ";
    string str;
    cin >> str;
    cout << "Элемент Х = ";
    cin >> a;
    int k;
    k = Function(str, a);
    if (k == 1) {
    cout << "Yes";
    }
    else {
    cout << "No";
    }
    return 0;
}
