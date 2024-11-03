#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	ofstream ofile("Testing.txt", ios::app);
	vector <int> a={2,3,4,5,6,7,8,9,-1,-2,4,-5,-6,-7};
	int a;
	ofile<<a;
	ofile.close();
	ifstream ifile("Testing..txt", ios::app);
	for(int i=0;i<a.size();i++){
		if(a[i] < 0)
			a[i] = 0;	
	}
	ofstream ofile("Testing.txt", ios::app);
	for(int i=0;i<a.size();i++){
		ofile<< a[i] <<" ";
	}
	ofile.close();
	
	cout<<"Code Successfully executed"<<endl;
		return 0;
}
