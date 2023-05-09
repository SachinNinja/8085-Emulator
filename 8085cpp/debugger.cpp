#include<bits/stdc++.h>
#include "debugger.h"
#include "instructions.h"
#include "RunMode.h"

using namespace std;

void RunUntilBreakpoint(vector<string>& code,map<string,int>& registers,map<string,bool>& flags,map<int,int>& memory) {
    int breakpoint;
    cout<<"Enter the Address of breakpoint: ";
    cin>>breakpoint;
    executeTillEnd(code,registers,flags,memory,breakpoint);
}

void PrintHelp(){

cout << "\nCommands:\n";

cout<<"********************************************************\n";
cout << " run (r) - Run until breakpoint or end of program.\n";
cout << " step (s) - Execute one instruction.\n";
cout << " print(p) - Print value of register or memory location.\n";
cout << " print architecture(pa) - printing the 8085 architecture\n";
cout << " quit (q) - Quit the debugger.\n";
cout << " help (h) - Help Message \n";
cout<<"********************************************************\n";

}

void PrintArchitecture(map<string,int> registers,map<string,bool> flags){
 
    cout << "\n***********Microprocessor Architecture***************\n"<< endl;
    cout << "+---------------+---------------+" << endl;
    cout << "| Register      | Value         |" << endl;
    cout << "+---------------+---------------+" << endl;
    cout << "| Accumulator   | " << setw(13) << registers["A"] << " |" << endl;
    cout << "| B             | " << setw(13) << registers["B"] << " |" << endl;
    cout << "| C             | " << setw(13) << registers["C"] << " |" << endl;
    cout << "| D             | " << setw(13) << registers["D"] << " |" << endl;
    cout << "| E             | " << setw(13) << registers["E"] << " |" << endl;
    cout << "| H             | " << setw(13) << registers["H"] << " |" << endl;
    cout << "| L             | " << setw(13) << registers["L"] << " |" << endl;
    cout << "+---------------+---------------+" << endl;
    cout << endl;
    cout << "+-------+-------+-------+-------+-------+-------+" << endl;
    cout << "| Flags |  S    |  Z    | AC    |  P    | CY    |" << endl;
    cout << "+-------+-------+-------+-------+-------+-------+" << endl;
    cout << "| Value | " << setw(2) << flags["S"] << "    | " << setw(2) << flags["Z"] << "    | " << setw(2) << flags["AC"] << "    | " << setw(2) << flags["P"] << "    | " << setw(2) << flags["CY"] << "    |" << endl;
    cout << "+-------+-------+-------+-------+-------+-------+" << endl;
  
}

void PrintMemoryOrAddress(map<string,int>& registers, map<string,bool>& flags, map<int,int>& memory) {

    string command;
    cout << "Enter the Command for Printing >> ";
    getline(cin>>ws,command);

    if (command[0] == 'p' && command[1] == ' ') {
        if (command.size() == 3 && (command[2] == 'A' || command[2] == 'B' || command[2] == 'C' || command[2] == 'D'
                || command[2] == 'E' || command[2] == 'G' || command[2] == 'H')) {
                string reg = "";
                reg += command[2];

    cout<<"\nValue stored At Register "<<reg<<" : "<<registers[reg] << endl;
   } else if (command.size() == 6 && ishex(command.substr(2, 5))) {
            int addr = stoi(command.substr(2, 4));
            if (memory.find(addr) != memory.end()) {
                cout <<"\nValue stored At Memory Addrress "<<addr<<" : "<<memory[addr] << endl;
            } else {
                cout << "No value Stored at this Address.\n";
            }
        } else {
            cout << "Error1: Invalid format.\n";
        }
    } else {
        cout << "Error2: Invalid format.\n";
    }
}



void Step(vector<string>& code,map<string,int>& registers,map<string,bool>& flags,map<int,int>& memory) {
    stepExecution(code,registers,flags,memory,1e6);
}

 void Run(vector<string>& code,map<string,int>& registers,map<string,bool>& flags,map<int,int>& memory){
    
    cout << "Commands:\n";
    cout<<"********************************************************\n";
    cout << " run (r) - Run until breakpoint or end of program.\n";
    cout << " step (s) - Execute one instruction.\n";
    cout << " print(p) - Print value of register or memory location.\n";
    cout << " print architecture(pa) - printing the 8085 architecture\n";
    cout << " quit (q) - Quit the debugger.\n";
    cout << " help (h) - Help Message \n";
    cout<<"********************************************************\n";

   
    while (true) {
        string cmd;
        cout << "\n> ";
        cin>>cmd;
        if (cmd == "run" || cmd == "r") {
            RunUntilBreakpoint(code,registers,flags,memory);
        } else if (cmd == "step" || cmd == "s") {
            Step(code,registers,flags,memory);
        } else if (cmd == "quit" || cmd == "q") {
            cout << "Debugger terminated.\n";
            break;
        } else if (cmd == "help" || cmd == "h") {
            PrintHelp();
        }else if(cmd == "print"||cmd=="p"){
            PrintMemoryOrAddress(registers,flags,memory);
        }
        else if(cmd=="pa"){
            PrintArchitecture(registers,flags);
        } 
        else {
            cout << "Invalid command. Type 'help' for a list of commands.\n";
        }
    }
}

