#ifndef RUNMODE_H 
#define RUNMODE_H

#include<bits/stdc++.h>
using namespace std;

void executeTillEnd(vector<string>& ,map<string,int>& ,map<string,bool>& ,map<int,int>&,int);
void stepExecution(vector<string>& code,map<string,int>& registers,map<string,bool>& flags,map<int,int>& memory,int breakpoint);

#endif