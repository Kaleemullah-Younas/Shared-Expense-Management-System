#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h> 
#include <limits>
#include <sstream>

using namespace std;

struct Member {
    string name;
    double expense;
    double balance;
};

vector<Member> members;

void header(){
	cout<<"\n\n\n\n\t\t\t\t\t ________________________________ \t\t\t\t\t" <<endl;
     cout << "\n\t\t\t\t\t SHARED EXPENSE MANAGEMENT SYSTEM \t\t\t\t\t" <<endl;
	cout<<"\t\t\t\t\t ________________________________ \t\t\t\t\t" <<endl;
	return;
}

void loading(){
	cout<< "\n\t\t\t\t PlEASE WAIT";
	 for(int i=0;i<3;i++){
    		  cout<<".";
    		  Sleep(100);
		}
		return;
}

void addMember() {
    int count;
    	cout<<"\n\t\t HOW MANY MEMBERS DO YOU WANT TO ENTER: ";
   	 cin>>count;
    	 if(cin.fail()) {
       	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	     system ("CLS");
       	cout<<"\n\n\t\t\t\t\t ERROR: NOT AN INTEGER...\n";
       	cout<<"\n\t\t\t\t\t\t PLEASE, TRY AGAIN :x ";
        return;
    		}
    		cin.ignore();
    	 for (int i = 0; i < count; i++) {
        	Member member;
        	cout << "\n\t\t ENTER NAME OF MEMBER " << i+1 << ": ";
        	string nameInput;
        	getline(cin, nameInput); 
        	stringstream ss(nameInput);
       	 ss >> member.name;
       	 if (ss.fail()) {
            system("CLS");
            cout << "\n\n\t\t\t\t\t ERROR: INVALID NAME...\n";
            cout << "\n\t\t\t\t\t\t PLEASE, TRY AGAIN :x ";
            return;
          }
        		member.expense = 0;
        		member.balance = 0;
        	for (int j = 0; j < members.size(); j++) {
            if (members[j].name == member.name) {
       			cout<<"\n\n\t\t\t\t\t ERROR: NAME ALREADY EXIST...\n";
       			cout<<"\n\t\t\t\t\t\t PLEASE, ADD ANOTHER NAME :x ";
       			return;
		   	}
		   }
        		members.push_back(member);
        		ofstream outfile("Result.txt", ios::app);     
    			   	loading();
    				cout << "\n\n\t\t\t\t MEMBER ADDED SUCCESSFULLY." << endl;
        			outfile << member.name << "\n";
        			outfile.close();
			}
			system("CLS");
				cout<< "\n\n\t\t\t\t\t ALL MEMBERS ADDED SUCCESSFULLY :] " << endl;
	 }	


void addExpense() {
    string name;
    double expense;
     if(members.empty()){
     	system("CLS");
   			  cout << "\n\n\t\t\t\t\t ERROR: MEMBER NOT ADDED YET...";
   			  cout<< "\n\t\t\t\t\t PLEASE, ADD MEMBER FIRST :x \n";
	}else{
    	cout << "\n\t\t ENTER PAYER'S NAME: ";
    	cin >> name;
     cout << "\n\t\t ENTER EXPENSE AMOUNT: ";
     cin >> expense;
    	  for (int i = 0; i < members.size(); i++) {
       	 if (members[i].name == name) {
        	  	  loading();
                 members[i].expense += expense;
          	  ofstream outfile("Result.txt", ios::app);
          	  outfile << members[i].expense << "\n";
          	  outfile.close();
          	  system("CLS");
          	  header;
    			  cout << "\n\n\t\t\t\t\t EXPENSE ADDED SUCCESSFULLY :} " << endl;
		  return;
        	}
        	  else{
        		  system("CLS");
   			  cout << "\n\n\t\t\t\t\t ERROR: MEMBER NOT FOUND..\n";
   			  cout<< "\n\t\t\t\t\t\t PLEASE, TRY AGAIN :x ";
	   }
	}
  }
	
}

    		
void calculateBalance() {
	if (members.size() == 0) {
		system("CLS");
        cout << "\n\n\t\t\t\t\t\t NO DATA ENTERED YET.\n";
         cout<< "\n\t\t\t\t\t PLEASE, ENTER DATA FIRST. :x ";
        return;
    }
    double totalExpense = 0;
    		for (int i = 0; i < members.size(); i++) {
        		totalExpense += members[i].expense;
    }
    double perPersonExpense = totalExpense / members.size();
    		for (int i = 0; i < members.size(); i++) {
       		 members[i].balance = perPersonExpense - members[i].expense;
       		 ofstream outfile("Result.txt", ios::app);
       		 outfile << members[i].balance << "\n";
       		 outfile.close();
   		}
    		loading();
		system("CLS");
    			cout << "\n\n\t\t\t\t\t NET BALANCE CALCULATED SUCCESSFULLY :) ";
}

void printData() {
    ifstream infile("Result.txt");
    int i = 0;
    string line;
    if (!infile) {
    	  system("CLS");
        cout << "\n\n\t\t\t\t\t\t NO DATA STORED YET.\n";
         cout<< "\n\t\t\t\t\t PLEASE, ENTER DATA FIRST :x ";
        return;
    }
	cout <<setw(15) <<"MEMBER" <<setw(10) <<" EXPENSE " <<setw(10) <<" BALANCE\n";
    while (getline(infile, line)) {
        cout <<setw(15) << members[i].name <<setw(10) << members[i].expense <<setw(10) << members[i].balance << "\n";
        i++;
    }
    infile.close();
}


int main() {
	system("Color F1");
    		while (true) {
       		 int option;
       		 header();
       		 cout << "\n\t\t PRESS 1 TO ADD MEMBERS" << endl;
                cout << "\n\t\t PRESS 2 TO ADD EXPENSE" << endl;
       		 cout << "\n\t\t PRESS 3 TO CALCULATE NET BALANCE" <<endl;
      		 cout << "\n\t\t PRESS 4 TO SHOW HISTORY" << endl;
                cout << "\n\t\t PRESS 5 TO EXIT" << endl;
                cout << "\n\n\t ENTER YOUR CHOICE: ";
        			cin >> option;
       	switch (option) {
            case 1:
            	system("CLS");
            		header();
                	addMember();
                break;
            case 2:
            	system("CLS");
            	 	header();
                	addExpense();
                break;
            case 3:
            	system("CLS");
            		header();
                	calculateBalance();
                break;
            case 4:
            	system("CLS");
            		header();
                	printData();
                break;
            case 5:
            	system("CLS");
            		header();
				cout << "\n\n\n\n\n\t\t\t\t\t   GOODBYE! THANKS FOR USING :) \n\n\n\n\n" << endl;
                return 0;
            default:
            	system("CLS");
            		header();
                	cout << "\n\n\t INVALID CHOICE, PLEASE TRY AGAIN.\n" << endl;
        }
    }
}

