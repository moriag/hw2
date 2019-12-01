#define baseId 901
#define bankSize 50
#include <stdio.h>
enum{status,balance,next};
int addNext=0;
double bank[bankSize][3];
void init(){
    for (int i = 0; i < bankSize; i++)
        {
        bank[i][next]=i+1;
        bank[i][balance]=0;
        bank[i][status]=0;
        }
}
int isOpen(int account){
    account-=baseId;

    if( (account>bankSize-1) || (0>account) || (bank[account][status]==0) )return -1;
    return account;
}
int openAccount(){
    if(addNext==bankSize) return -1;
    bank[addNext][status]=1;
    int account=addNext;
    addNext=bank[addNext][next];
    return account;
}
void changeBalance(int account,double amount){
    amount=(int)(amount*100);
    amount/=100;
    bank[account][balance]+=amount;
}
int add(int account,double amount){
    if(amount<0)return 0;
    changeBalance(account,amount);
    return 1;
}
int withdrawal(int account, double amount){
    if(bank[account][balance]<amount||amount<0) return 0;
    changeBalance(account,-amount);
    return 1;
}
void interst(double amount){

    for (size_t i = 0; i < bankSize; i++)
        { 
            bank[i][balance]=(int)(100*(bank[i][balance]*(1+(amount/100))));
            bank[i][balance]/=100;
        }
}
void close(int account){
    bank[account][status]=0;
    bank[account][balance]=0;
    bank[account][next]=addNext;
    addNext=account;
}

int printBank(){
    if(addNext==0)return 0;
    printf("account number\t:\tbalance\n\n");
    for (int i = 0; i < bankSize; i++)
        {
            if(bank[i][status]==0)continue;
            printf("\t%d\t:\t%lf\n",i+baseId,bank[i][balance]);
        }
    return 1;    
}
void printBalance(int account){
            printf("the balance for acount number %i is: %.2f\n",account+baseId, bank[account][balance]);
}