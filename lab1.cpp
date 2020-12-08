#include <iostream>
#include <cstdio>
using namespace std;

class Symbols {
public:

char* Term;
char* Un_Term;
int Term_Q;
int Un_Term_Q;

Symbols() {
        Term = {};
        Un_Term = {};
        Term_Q = 0;
        Un_Term_Q = 0;
}
void init_term();
void init_un_term();
};

void Symbols::init_term() {
        cout << "Count of terminal symbols: " << endl;
        cin >> Term_Q;
        Term = new char [Term_Q];
        cout << "Terminal symbols: " << endl;
        for (int i = 0; i < Term_Q; i++) {
                cout << i << ". ";
                cin >> Term[i];
        }
}

void Symbols::init_un_term() {
        cout << "Count of not terminal symbols: " << endl;
        cin >> Un_Term_Q;
        Un_Term = new char [Un_Term_Q];
        cout << "Not terminal symbols: " << endl;
        for (int i = 0; i < Un_Term_Q; i++) {
                cout << i << ". ";
                cin >> Un_Term[i];
        }
}

class Rules {
public:
char left_symb;
char* right_symb;
int right_symb_Q;

void init_left_symb(Symbols& symb);
void init_right_symb(Symbols& symb);
bool Check_left(Symbols& symb);
bool Check_right(Symbols& symb);

friend ostream& operator<<(ostream&, Rules);
};

void Rules::init_left_symb(Symbols& symb){
        do {
                cout << "Left symbol: " << endl;
                cin >> left_symb;
        }
        while (!Check_left(symb));
}

//проверка что в левой части только нетерминальный символ
bool Rules::Check_left(Symbols& symb) {
        for (int i = 0; i < symb.Un_Term_Q; i++) {
                if (symb.Un_Term[i] == left_symb) {
                        return true;
                }
        }
        return false;
}


void Rules::init_right_symb(Symbols& symb) {
        do {
                cout << "Count Right symbols: " << endl;
                cin >> right_symb_Q;
                right_symb = new char [right_symb_Q];
                for (int i = 0; i < right_symb_Q; i++) {
                        cout << i << ". ";
                        cin >> right_symb[i];
                }
        }
        while (!Check_right(symb));
}

//проверка что в правой части символы принадлежат алфавиту
bool Rules::Check_right(Symbols& symb) {
        int i = 0;
        int w = 0;
        while (i < right_symb_Q) {
                w = i;
                for (int j = 0; j < symb.Un_Term_Q; j++) {
                        if (symb.Un_Term[j] == right_symb[i]) {
                                i++;
                                break;
                        }
                        else {
                                continue;
                        }

                }
                for (int k = 0; k < symb.Term_Q; k++) {
                        if (symb.Term[k] == right_symb[i]) {
                                i++;
                                break;
                        }
                        else {
                                continue;
                        }
                }
                if (w == i) {
                        cout << "Symbol "<< right_symb[i] << "does not belong to the alphabet " << endl;
                        return false;
                }
        }
        return true;
}

ostream& operator<<(ostream& stream, Rules rul) {
        stream << rul.left_symb << "-> ";
        for (int i = 0; i < rul.right_symb_Q; i++) {
                stream << rul.right_symb[i];
        }
        stream << endl;
        return stream;
}

int main()
{
        int Rules_Q = 0;
        Symbols laba;
        laba.init_term();
        laba.init_un_term();

        cout << "Count quantity rules" << endl;
        cin >> Rules_Q;
        Rules* rul =  new Rules[Rules_Q];
        for(int i = 0; i < Rules_Q; i++)
        {
                rul[i].init_left_symb(laba);
                rul[i].init_right_symb(laba);
        }
        for(int i = 0; i < Rules_Q; i++)
        {
                cout << rul[i];
        }
        return 0;
}
