#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
        int Term_Q, Un_Term_Q;

        cout << "Count of terminal symbols: " << endl;
        cin >> Term_Q;
        char* Term = new char [Term_Q];
        cout << "Terminal symbols: " << endl;
        for (int i = 0; i < Term_Q; i++) {
                cin >> Term[i];
        }

        cout << "Count of not terminal symbols: " << endl;
        cin >> Un_Term_Q;
        char* Un_Term = new char [Un_Term_Q];
        cout << "Not terminal symbols: " << endl;
        for (int i = 0; i < Un_Term_Q; i++) {
                cin >> Un_Term[i];
        }

        return 0;
}
