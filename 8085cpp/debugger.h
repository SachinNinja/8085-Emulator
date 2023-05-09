#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <bits/stdc++.h>
using namespace std;

bool ishex(string);
void Run(vector<string>& code,map<string,int>& registers,map<string,bool>& flags,map<int,int>& memory);
void Step(vector<string>& code,map<string,int>& registers,map<string,bool>& flags,map<int,int>& memory);  
void PrintRegistersOrMemory(map<string,int>&,map<string,bool>&,map<int,int>&);
void RunUntilBreakpoint(vector<string>& code,map<string,int>& registers,map<string,bool>& flags,map<int,int>& memory);
void PrintArchitecture(map<string,int>,map<string,bool>);
void PrintHelp();

#endif
