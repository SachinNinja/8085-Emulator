#include "instructions.h"

#include<bits/stdc++.h>
using namespace std;

//for checking whether a given number is hexadecimal or not
bool ishex(string val) {
    for(int i = 0; i < val.length(); i++) {
        if(val[i] < '0' || (val[i] > '9' && val[i] < 'A') || val[i] > 'F')
            return false;
    }
    return true;
}

//for setting value at some register
int set_(vector<string>& words,map<int,int>& memory){
    string arg = words[1];
    string delimiter = ",";
    size_t pos = arg.find(delimiter);
    if(pos == string::npos || arg.length() !=7) {
        cout << "Error while Using SET" << endl;
        return 0;
    }
    string mem = arg.substr(0, pos);
    string val = arg.substr(pos + 1);
    int memo=stoi(mem);
    memory[memo]=stoi(val);
    return 4;
}

//move immediate
int mvi(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr) {
    
    if(words.size()!=3){
    	cout << "Error while Using MVI" << endl;
        return 0;
    }
    string reg = words[1];
    string val = words[2];
    if(reg.length() != 1 || val.length() != 2 || !ishex(val)) {
        cout << "Error while Using MVI" << endl;
        return 0;
    } else {
        int vall = stoi(val);
        r[reg] = vall;
        return 2;
    }
}

//move value from one register to the other
int mov(vector<string>& words,map<string,int>& r,map<string,bool>& f) {
    string arg = words[1];
    string delimiter = ",";
    size_t pos = arg.find(delimiter);
    if(pos == string::npos || arg.length() < 3 || arg[pos - 1] == arg[pos + 1] || arg[pos - 1] < 'A' || arg[pos - 1] > 'Z' || arg[pos + 1] < 'A' || arg[pos + 1] > 'Z') {
        cout << "Error while Using MOV" << endl;
        return 0;
    }
    string reg1 = arg.substr(0, pos);
    string reg2 = arg.substr(pos + 1);
    r[reg1] = r[reg2];
    return 1;
}

//store value of accumulator at memory location
int sta(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr) {
    string addr = words[1];
    if(addr.length() != 4 || !ishex(addr)) { 
        cout << "Error while Using STA" << endl;
        return 0;
    }
    int addval = stoi(addr);
    adr[addval]= r["A"];
    return 3;
}


//load value of memory location to accumulator
int lda(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr) {
    string addr = words[1];
    if (addr.length() != 4 || !ishex(addr)) {
        cout << "Error while using LDA\n";
        return 0;
    }
    int addval = stoi(addr);
    if (adr.find(addval) != adr.end()) {
        r["A"] = adr[addval];
    }else{
    	r["A"]=0;
    }
    return 3;
}

int add(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr) {
    string op2 = words[1];
    if(op2.length()!=1){
        cout << "Error while using ADD\n";
        return 0; 
    }
    int val = r["A"] + r[op2];
    r["A"] = val & 0xFF;
    f["C"] = (val > 0xFF);
    f["Z"] = (r["A"] == 0);
    f["S"] = (r["A"] & 0x80);
    return 1;
}

int sub(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr) {
    string op2 = words[1];
    if(op2.length()!=1){
        cout << "Error while using SUB\n";
        return 0;
    }
    int val = r["A"] - r[op2];
    r["A"] = val & 0xFF;
    f["C"] = (val >= 0);
    f["Z"] = (r["A"] == 0);
    f["S"] = (r["A"] & 0x80);
    return 1;
}

int adi(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr) {
    string op2 = words[1];
    if(op2.length()!=2 || !ishex(op2)){
        cout << "Error while using ADI\n";
        return 0;
    }
    int val = r["A"] + stoi(op2, nullptr, 16);
    r["A"] = val & 0xFF;
    f["C"] = (val > 0xFF);
    f["Z"] = (r["A"] == 0);
    f["S"] = (r["A"] & 0x80);
    return 2;
}

int inr(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr) {
    string op2 = words[1];
    if(op2.length()!=1){
        cout << "Error while using INR\n";
        return 0;
    }
    int val = r[op2] + 1;
    r[op2] = val & 0xFF;
    f["Z"] = (r[op2] == 0);
    f["S"] = (r[op2] & 0x80);
    f["AC"] = ((val & 0x0F) == 0);
    return 1;
}

int dcr(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr) {  
    string op2 = words[1];
    if(op2.length()!=1){
        cout << "Error while using DCR\n";
        return 0;
    }
    int val = r[op2] - 1;
    r[op2] = val & 0xFF;
    f["Z"] = (r[op2] == 0);
    f["S"] = (r[op2] & 0x80);
    f["AC"] = ((val & 0x0F) == 0x0F);
    return 1;
}

int lhld(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr) {
    if (words.size() != 2 || words[1].length() != 4 || !ishex(words[1])) {
        cout << "Error while Using LHLD" << endl;
        return 0;
    } else {
        int addr = stoi(words[1]);
        r["L"] = adr[addr];
        r["H"] = adr[addr+1];
        return 3;
    }
}

// Store HL direct
int shld(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr) {
    if (words.size() != 2 || words[1].length() != 4 || !ishex(words[1])) {
        cout << "Error while Using SHLD" << endl;
        return 0;
    } else {
        int addr = stoi(words[1]);
        adr[addr] = r["L"];
        adr[addr+1] = r["H"];
        return 3;
    }
}

// Compare with accumulator
int cmp(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr) {
    if (words.size() != 2 || words[1].length() != 1) {
        cout << "Error while Using CMP" << endl;
        return 0;
    } else {
        char reg = words[1][0];
        int diff = r["A"] - r[string(1,reg)];
        f["Z"] = (diff == 0);
        f["S"] = (diff < 0);
        f["P"] = 1;
        f["CY"] = (r["A"] < r[string(1,reg)]);
        return 1;
    }
}

// Complement accumulator
int cma(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr) {
    r["A"] = ~r["A"];
    return 1;
}

// Store accumulator indirect
int stax(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr) {
    if (words.size() != 2 || (words[1] != "B" && words[1] != "D")) {
        cout << "Error while Using STAX" << endl;
        return 0;
    } else {
        if (words[1] == "B") {
            adr[(r["B"] << 8) | r["C"]] = r["A"];
        } else { // words[1] == "D"
            adr[(r["D"] << 8) | r["E"]] = r["A"];
        }
        return 1;
    }
}

// Exchange H and L with D and E
int xchg(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr) {
    int temp = r["H"];
    r["H"] = r["D"];
    r["D"] = temp;
    temp = r["L"];
    r["L"] = r["E"];
    r["E"] = temp;
    return 1;
}

int jmp(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr) {
    
    if(words.size()!=2){
    	cout << "Error while Using JMP" << endl;
        return 0;
    }
    string l = words[1];
    int label=stoi(l);
    if(adr.find(label) == adr.end()){
        cout << "Error: Label Not Found!" << endl;
        return 0;
    } else {
        int address = adr[label];
        return 3;
    }
}

int jc(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr) {
    
    if(words.size()!=2){
    	cout << "Error while Using JC" << endl;
        return 0;
    }
    if(f["CY"] == true) {
        string l= words[1];
        int label=stoi(l);
        if(adr.find(label) == adr.end()){
            cout << "Error: Label Not Found!" << endl;
            return 0;
        } else {
            int address = adr[label];
            return 3;
        }
    } else {
        return 1;
    }
}

int jnc(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr) {
    
    if(words.size()!=2){
    	cout << "Error while Using JNC" << endl;
        return 0;
    }
    if(f["CY"] == false) {
        string l = words[1];
        int label=stoi(l);
        if(adr.find(label) == adr.end()){
            cout << "Error: Label Not Found!" << endl;
            return 0;
        } else {
            int address = adr[label];
            return 3;
        }
    } else {
        return 1;
    }
}

int jz(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr) {
    
    if(words.size()!=2){
    	cout << "Error while Using JZ" << endl;
        return 0;
    }
    if(f["Z"] == true) {
        string l = words[1];
        int label=stoi(l);
        if(adr.find(label) == adr.end()){
            cout << "Error: Label Not Found!" << endl;
            return 0;
        } else {
            int address = adr[label];
            return 3;
        }
    } else {
        return 1;
    }
}

int jnz(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr) {
    
    if(words.size()!=2){
    	cout << "Error while Using JNZ" << endl;
        return 0;
    }
    if(f["Z"] == false) {
        string l = words[1];
        int label=stoi(l);
        if(adr.find(label) == adr.end()){
            cout << "Error: Label Not Found!" << endl;
            return 0;
        } else {
            int address = adr[label];
            return 3;
        }
    } else {
        return 1;
    }
}