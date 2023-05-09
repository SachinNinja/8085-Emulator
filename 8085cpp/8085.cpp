#include <bits/stdc++.h>
#include "debugger.h"
#include "RunMode.h"


using namespace std;

    // Register Pairs
    map<string, int > registers;
    // Flag register
    map<string, bool> flags;
    // Memory Locations
    map<int, int> memory;

int main() {
    cout << "Welcome to the 8085 Emulator!" << endl;
    // Initialize the microprocessor
    
     registers["A"] = 0;
     registers["B"] = 0;
     registers["C"] = 0;
     registers["D"] = 0;
     registers["E"] = 0;
     registers["H"] = 0;
     registers["L"] = 0;
     flags["S"]  = false;
     flags["Z"]  = false;
     flags["AC"] = false;
     flags["P"]  = false;
     flags["CY"] = false;


    ifstream input("input.txt");

    if (!input.is_open()) {
        cout << "Error: Could not open file." << endl;
        return 1;
    }

    string line;
    vector<string> code;
    while (getline(input, line)) {
        code.push_back(line);
    }

    // Close input file
    input.close();
    // Run the code
    int currAddress = 0;
   
    cout<<"+----------------------------------------------------------------------+\n";
    cout<<"|**************Welcome to 8085 Emulator By Sachin Upadhyay*************|\n";
    cout<<"+----------------------------------------------------------------------+\n\n\n";

    int choice;
    
   while(true){
    cout<<"\nSelect the Mode for Running the Code- \n\nPress 1 For Run Mode\nPress 2 For Debugger Mode\nAny other key to Exit\n";
    cin>>choice;

    if(choice == 1){
        cout<<"\n*****Run Mode Activated****\n\n";
        executeTillEnd(code,registers,flags,memory,1e6);

        PrintArchitecture(registers,flags);
    }else if(choice==2){
        cout<<"\n*****Debugger Mode Activated****\n\n";
        Run(code,registers,flags,memory);
    }else{
        cout<<"\n\nThanks for Using the Processor\n\n";
        cout<<"\n**********Exiting the Processor***********";
        return 0;
    }
   }
}
