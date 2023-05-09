#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include<bits/stdc++.h>
using namespace std;

//All the Instructions ...

bool ishex(string);
int mvi(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr);
int mov(vector<string>& words,map<string,int>& r,map<string,bool>& f);
int sta(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr);
int lda(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr);
int add(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr);
int sub(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr);
int adi(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr);
int inr(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr);
int  dcr(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr);
int set_(vector<string>& words,map<int,int>& memory);
int lhld(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr);
int shld(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr);
int cmp(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr);
int cma(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr);
int stax(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr);
int xchg(vector<string>& words, map<string,int>& r, map<string,bool>& f, map<int,int>& adr);
int jmp(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr);
int jc(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr);
int jnc(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr);
int jz(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr);
int jnz(vector<string>& words,map<string,int>& r,map<string,bool>& f,map<int,int>& adr);

#endif