#include "myBank.h"
#include <stdio.h>
int leagalInput(){
        char a;
        int ans=1;
        do{
            scanf("%c",&a);
            if(a!='\n')ans=0;
        }while(a!='\n');
        if(ans==0)printf("ilegal input\n");
        return ans;
    }
int main(){
    init();
    int accountId;
    double amount;
    for (char c; c!='E' ;)
    {
        printf("Transaction type?\n");
        scanf("%c",&c);
        if(!leagalInput()) continue;
        
        if(c=='P'){ 
            if(!printBank()) printf("no open accounts\n");
            continue;
        }
        if(c=='E'){ init(); continue;}//will end for
        
        if(c=='O'){
            accountId=openAccount();//-1 is returned if not able to open
            if(!(accountId+1)){
                printf("sorry bank is at capacity.\n");
                continue;
            }
            printf("Initial deposit?\n");
        }
        else{
            if(c=='I') printf("Interest rate?\n");
            else{// not O nor I    
                if(c=='D'||c=='W'||c=='B'||c=='C'){
                    printf("Account number?\n");
                    scanf("%int",&accountId);
                    if(!leagalInput()){
                        continue;
                    }
                    accountId=isOpen(accountId);//returns the place in bank array -1 otherwise 
                    
                    if(accountId==-1){
                        printf("Wrong Account number.\n");
                        continue;
                    }
                    if(c=='B'){printBalance(accountId);
                        continue;
                    }
                    if(c=='C'){close(accountId);
                        continue;
                    }
                }
                else{//also not D,W,B,C
                    printf("ilegal input action.\n");
                    continue;
                }
            printf("Amount?\n");// W , D    
            }
            scanf("%lf",&amount);//for I,W,D
            if(!leagalInput())continue;
        }
        switch (c)
        {
        case 'I':interst(amount);
            break;
        case 'O':
            scanf("%lf",&amount);
            if(!leagalInput()){
                close(accountId);
                break;
            }
        case 'D'://maybe O    
            if(!(add(accountId, amount))){
                printf("ilegal negativ amount\n");
                if(c=='O') close(accountId);
            }
            break;
        case 'W':
            if(!withdrawal(accountId, amount)){
                if(amount<0)printf("ilegal negativ amount\n");
                else{ printf("no seficiant funds\n"); }
            }
        }   
    }
}