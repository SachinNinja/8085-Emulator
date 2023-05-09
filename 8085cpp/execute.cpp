#include "execute.h"


int mvi(std::vector<std::string> words, Microprocessor obj, int currAddress) {
    cout << currAddress << endl;
    cout << "MVI is going to execute" << endl;
    string reg = words[1];
    string val = words[2];
    if (reg.length() != 1 || val.length() != 2 || !ishex(val)) {
        cout << "Error while Using MVI , Please correct to continue" << endl;
        return 0;
    }
    else {
        currAddress += 2;
        int vall = stoi(val, nullptr, 16);
        obj.A = vall;
        return currAddress;
    }
}



