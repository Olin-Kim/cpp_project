#include <iostream>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;

typedef enum BankReqType{

	OPEN_ACC=1,
	DEPOSIT,
	WITHDRAW,
	BALANCE,
	SHOW_ACC_LIST,
	EXIT
}BankReqType;

typedef struct Account{
	int balance;
	char name[100];
	char account[100];

}Account;

void ShowAccountList(Account (&accList)[100],int len){
	for(int i=0;i<len;i++){
		cout<<"===== "<<accList[i].name<<" ====="<<endl;
		cout<<"Account : "<<accList[i].account<<endl;
		cout<<"Balance : "<<accList[i].balance<<endl<<endl;

	}
}

Account* SearchAccountId(Account (& accountList)[100],char (&accountId)[50], int accountListLen){
	for(int i=0;i<accountListLen;i++){
		if(strcmp(accountList[i].account,accountId)==0){
			return &(accountList[i]);
		}
	}
	return NULL;
}

void ShowMenu(){
	cout<<"========= Menu ========="<<endl;
	cout<<" Open Account      - 1"<<endl;
	cout<<" Deposit Money     - 2"<<endl;
	cout<<" Withdraw Money    - 3"<<endl;
	cout<<" Show Balance      - 4"<<endl;
	cout<<" Show Account List - 5"<<endl;
	cout<<" EXIT              - 6"<<endl;
	cout<<"========================"<<endl;

}



int main(void){
	
	int selectNumber;
	Account accountList[100];
	int accountListLen=0;

	BANK_START:
	while(true){
		ShowMenu();
		cout<< "input menu>> ";
		cin>>selectNumber;

		

		if(cin.fail()){
			cout<<"cin Failure!!!"<<endl;
			// cin.clear();
			cin.ignore(256,'\n');
		}
		else{
			switch(selectNumber){
				case OPEN_ACC:
				cout<<"Input your account: ";
				cin>>accountList[accountListLen].account;
				cout<<"Input your name: ";
				cin>>accountList[accountListLen].name;
				cout<<"Input your money: ";
				cin>>accountList[accountListLen].balance;
				accountListLen++;
				break;

				case DEPOSIT:
				{
					char accountId[50];
					int money=0;
					Account* searchedAccount=NULL;
					
					cout<<"DEPOSIT"<<endl;
					cout<<"Input your account: ";
					cin>>accountId;
					cout<<"Deposit your money: ";
					cin>>money;

					searchedAccount=SearchAccountId(accountList, accountId, accountListLen);
					if(searchedAccount!=NULL){
						(*searchedAccount).balance+=money;
						cout<<"Deposit Success!!!"<<endl;
					}else{
						cout<<"No Account!!!"<<endl;
					}
				}

				break;

				case WITHDRAW:
				cout<<"WITHDRAW"<<endl;
				{
					char accountId[50];
					int money=0;
					Account* searchedAccount=NULL;
					
					cout<<"Input your account: ";
					cin>>accountId;
					cout<<"Withdraw your money: ";
					cin>>money;

					searchedAccount=SearchAccountId(accountList, accountId, accountListLen);
					if(searchedAccount!=NULL){
						(*searchedAccount).balance-=money;
						cout<<"Withdraw Success!!!"<<endl;
					}else{
						cout<<"No Account!!!"<<endl;
					}
				}				
				break;

				case BALANCE:
				cout<<"BALANCE"<<endl;
				{
					char accountId[50];
					int money=0;
					Account* searchedAccount=NULL;
					
					cout<<"Input your account: ";
					cin>>accountId;
					cout<<"Withdraw your money: ";
					cin>>money;

					searchedAccount=SearchAccountId(accountList, accountId, accountListLen);
					if(searchedAccount!=NULL){
						cout<<"My balance: "<<(*searchedAccount).balance<<endl;
					}else{
						cout<<"No Account!!!"<<endl;
					}
				}
				break;

				case SHOW_ACC_LIST:
				ShowAccountList(accountList,accountListLen);
				break;
				
				case EXIT:
				cout<<"EXIT"<<endl;
				return 0;
				break;
				default:
				cout<<"DEFAULT"<<endl;
				break;

			}
		}
	}

	return 0;
}