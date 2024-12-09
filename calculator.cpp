#include <iostream>
#include <limits>
using namespace std;
double operation(double res, bool &check2){
double c;
char op;
bool check3;
while (check3 == false){
    cout << "Enter a second number ";
    cin >> c;
    if (cin.fail()) // если предыдущее извлечение было неудачным, эквивалентно if (!cin)
{
    cin.clear(); // то возвращаем cin в 'обычный' режим работы
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "This is not number" << "\n ";
} else { check3 = true;}
    }
    check3 = false;
while (check3 == false){
    cout << "Enter operation +, -, *, /" << "\n ";
    cin >> op;
    switch (op){
        case '+':
            res = res + c;
            check3 = true;
            break;
        case '-':
            res = res - c;
            check3 = true;
            break;
        case '*':
            res = res * c;
            check3 = true;
            break;
        case '/':
            if (c == 0){
                cout << "Error can't divide by zero " << "\n";
                check3 = false;
                break;
            }
            res = res / c;
            check3 = true;
            break;
        default:
            cout<<"Error, wrong operation " << "\n";
            check3 = false;
    }
    }

    return res;
}
int main() {
    double a, b, res;
    char op;
    bool check1 = true, check2 = true, check3 = false;
    while (check3 == false){
    cout << "Enter a first number ";
    cin >> a;
    if (cin.fail()) // если предыдущее извлечение было неудачным, эквивалентно if (!cin)
{
    cin.clear(); // то возвращаем cin в 'обычный' режим работы
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // извлекаем и отбрасываем максимальное количество символов из входного потока до разделителя '\n' включительно
    cout << "This is not number" << "\n ";
} else { check3 = true;}
    }
    check3 = false;
    while (check3 == false){
    cout << "Enter a second number ";
    cin >> b;
    if (cin.fail()) // если предыдущее извлечение было неудачным, эквивалентно if (!cin)
{
    cin.clear(); // то возвращаем cin в 'обычный' режим работы
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "This is not number" << "\n ";
} else { check3 = true;}
    }
    check3 = false;
    while (check3 == false){
    cin.clear(); // то возвращаем cin в 'обычный' режим работы
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter operation +, -, *, /" << "\n ";
    cin >> op;
    switch (op){
        case '+':
            res = a+b;
            check3 = true;
            break;
        case '-':
            res = a-b;
            check3 = true;
            break;
        case '*':
            res = a * b;
            check3 = true;
            break;
        case '/':
            if (b == 0){
                cout << "Error can't divide by zero " << "\n";
                check3 = false;
            }
            res = a/b;
            check3 = true;
            break;
        default:
            cout<<"Error, wrong operation " << "\n";
            check3 = false;
    }
    }
    cout << res << " \n";
    do{
        int option;
        cout <<"Choose option:" << " \n" <<"1)New operation" << "\n" << "2)Quit" << "\n";
        cin >> option;
        if (!cin){
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Wrong option";
            continue;
        }
        switch (option){
            case 1:
                res = operation(res, check2);
                cout << res << "\n";
                break;
            case 2:
                cout << "Closing the programm";
                check1 = false;
                break;
            default:
                cout << "Wrong option" << "\n";   
                cin.clear(); // то возвращаем cin в 'обычный' режим работы
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                break;
        }
    } while (check1);
    return 0;
}