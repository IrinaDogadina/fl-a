#include <iostream>
#include <cstdio>
using namespace std;

class Symbols {
char* Term;
char* Un_Term;
int Term_Q;
int Un_Term_Q;

public:
void init_term();
void init_un_term();
};

void Symbols::init_term() {
        cout << "Count of terminal symbols: " << endl;
        cin >> Term_Q;
        Term = new char [Term_Q];
        cout << "Terminal symbols: " << endl;
        for (int i = 0; i < Term_Q; i++) {
                cin >> Term[i];
        }
}

void Symbols::init_un_term() {
        cout << "Count of not terminal symbols: " << endl;
        cin >> Un_Term_Q;
        Un_Term = new char [Un_Term_Q];
        cout << "Not terminal symbols: " << endl;
        for (int i = 0; i < Un_Term_Q; i++) {
                cin >> Un_Term[i];
        }
}

class Rules : public Symbols {
char left_symb;
char* right_symb;

public:
void init_left_symb();
void init_right_symb();
};

void Rules::init_left_symb(){
        cout << "Left symbol: " << endl;
        cin >> left_symb;
        //я предполагаю где-то здесь должна быть проверка
}

int main()
{
        Symbols laba;
        laba.init_term();
        laba.init_un_term();
        return 0;
}
