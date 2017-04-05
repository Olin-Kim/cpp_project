#include <iostream>

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

void showAccountList(Account (&accList)[100],int len){
	for(int i=0;i<len;i++){
		cout<<"===== "<<accList[i].name<<" ====="<<endl;
		cout<<"Account : "<<accList[i].account<<endl;
		cout<<"Balance : "<<accList[i].balance<<endl<<endl;

	}
}

void showMenu(){
	cout<<"========= Menu ========="<<endl;
	cout<<" Open Account      - 1"<<endl;
	cout<<" Deposit Money     - 2"<<endl;
	cout<<" Withdraw Money    - 3"<<endl;
	cout<<" Show Balance      - 4"<<endl;
	cout<<" Show Account List - 5"<<endl;
	cout<<"========================"<<endl;

}

int main(void){
	
	int selectNumber;
	Account accountList[100];
	int accountListLen=0;

	BANK_START:
	while(true){
		showMenu();
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
				accountList[accountListLen].balance=0;
				accountListLen++;
				break;
				case DEPOSIT:
				cout<<"DEPOSIT"<<endl;
				break;
				case WITHDRAW:
				cout<<"WITHDRAW"<<endl;
				break;
				case BALANCE:
				cout<<"BALANCE"<<endl;
				break;
				case SHOW_ACC_LIST:
				showAccountList(accountList,accountListLen);
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