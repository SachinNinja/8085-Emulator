#include<bits/stdc++.h>
#include "RunMode.h"
#include "instructions.h"

using namespace std;

void executeTillEnd(vector<string>& code,map<string,int>& registers,map<string,bool>& flags,map<int,int>& memory,int breakpoint){
     
      int start=0;
      cout<<"Enter the Starting Address or Default is 0\n";
      cin>>start;
  
      cout<<"Code >>\n\n";

      for (size_t i = 0; i < code.size(); i++) {
        stringstream ss(code[i]);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        int f=0;
        
        cout<<start<<" > "<<code[i]<<endl; 

        if(words[0]=="MVI"){
            f=mvi(words,registers,flags,memory);
        }else if(words[0]=="MOV"){
            f=mov(words,registers,flags);
        }else if(words[0]=="LDA"){
            f=lda(words,registers,flags,memory);
        }else if(words[0]=="STA"){
            f=sta(words,registers,flags,memory);
        }else if(words[0]=="ADD"){
            f=add(words,registers,flags,memory);
        }else if(words[0]=="SUB"){
            f=sub(words,registers,flags,memory);
        }else if(words[0]=="DCR"){
            f=dcr(words,registers,flags,memory);
        }else if(words[0]=="ADI"){
            f=adi(words,registers,flags,memory);
        }else if(words[0]=="INR"){
            f=inr(words,registers,flags,memory);
        }else if(words[0]=="SET"){
            f=set_(words,memory);
        }else if(words[0]=="LHLD"){
            f=lhld(words,registers,flags,memory);
        }else if(words[0]=="SHLD"){
            f=shld(words,registers,flags,memory);
        }else if(words[0]=="XCHG"){
            f=xchg(words,registers,flags,memory);
        }else if(words[0]=="CMA"){
            f=cma(words,registers,flags,memory);
        }else if(words[0]=="CMP"){
            f=cmp(words,registers,flags,memory);
        }else if(words[0]=="JMP"){
            f=jmp(words,registers,flags,memory);
        }else if(words[0]=="JC"){
            f=jc(words,registers,flags,memory);
        }else if(words[0]=="JNC"){
            f=jnc(words,registers,flags,memory);
        }else if(words[0]=="JZ"){
            f=jz(words,registers,flags,memory);
        }else if(words[0]=="JNZ"){
            f=jnz(words,registers,flags,memory);
        }else if(words[0]=="HLT"){
            break;
        }

        if(f) start+=f;
        if(start>= breakpoint){ cout<<"BreakPoint Reached !! Terminating\n"; return;}  

        if(!f) {cout<<"Error Occurred in Line - "<<i+1<<endl; return;}
    }

    cout<<"Code Run Successfull !!!\n";

}

void stepExecution(vector<string>& code,map<string,int>& registers,map<string,bool>& flags,map<int,int>& memory,int breakpoint){
     
     int start=0;
      cout<<"Enter the Starting Address or Default is 0\n";
      cin>>start;
  
      cout<<"Code >>\n\n";

      for (size_t i = 0; i < code.size(); i++) {
        stringstream ss(code[i]);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        int f=0;
        
        cout<<start<<" > "<<code[i]<<endl; 

         if(words[0]=="MVI"){
            f=mvi(words,registers,flags,memory);
        }else if(words[0]=="MOV"){
            f=mov(words,registers,flags);
        }else if(words[0]=="LDA"){
            f=lda(words,registers,flags,memory);
        }else if(words[0]=="STA"){
            f=sta(words,registers,flags,memory);
        }else if(words[0]=="ADD"){
            f=add(words,registers,flags,memory);
        }else if(words[0]=="SUB"){
            f=sub(words,registers,flags,memory);
        }else if(words[0]=="DCR"){
            f=dcr(words,registers,flags,memory);
        }else if(words[0]=="ADI"){
            f=adi(words,registers,flags,memory);
        }else if(words[0]=="INR"){
            f=inr(words,registers,flags,memory);
        }else if(words[0]=="SET"){
            f=set_(words,memory);
        }else if(words[0]=="LHLD"){
            f=lhld(words,registers,flags,memory);
        }else if(words[0]=="SHLD"){
            f=shld(words,registers,flags,memory);
        }else if(words[0]=="XCHG"){
            f=xchg(words,registers,flags,memory);
        }else if(words[0]=="CMA"){
            f=cma(words,registers,flags,memory);
        }else if(words[0]=="CMP"){
            f=cmp(words,registers,flags,memory);
        }else if(words[0]=="JMP"){
            f=jmp(words,registers,flags,memory);
        }else if(words[0]=="JC"){
            f=jc(words,registers,flags,memory);
        }else if(words[0]=="JNC"){
            f=jnc(words,registers,flags,memory);
        }else if(words[0]=="JZ"){
            f=jz(words,registers,flags,memory);
        }else if(words[0]=="JNZ"){
            f=jnz(words,registers,flags,memory);
        }else if(words[0]=="HLT"){
            break;
        }

        if(f) { cout<<"No Error in following line\n"; start+=f;}
        if(start>= breakpoint){ cout<<"BreakPoint Reached !! Terminating\n"; return;}  

    }

}