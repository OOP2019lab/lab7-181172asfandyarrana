// l181172_q1.cpp : Defines the entry point for the console application.

#include <iostream>
using namespace std;
#include "bankAccount.h"
#include <fstream>;
#include <string>;
bankAccount** read(string filename)
{
	int a=0;
	int id=0, balance=0, balancelimit=0, nooftrans=0, trans=0;
	
	ifstream fin(filename);
	
	while(!fin.eof())
	{
		fin>>a;
		cout<<"The number of bank accounts are"<<a<<endl;
		bankAccount **arr2=new bankAccount*[a];
		for(int j=0;j<a;j++)
		{
			fin>>id;
			fin>>balance;
			fin>>balancelimit;
			fin>>nooftrans;
			float *arr3=new float[nooftrans];
			for(int k=0;k<nooftrans;k++)
			{
				fin>>trans;
			    arr3[k]=trans;

			}
			arr2[j]=new bankAccount(id,balance,arr3,nooftrans,balancelimit);
			
		}
		return arr2;
	}
	
}
void printacc(bankAccount** arr,int size)
{
	for(int i=0;i<size;i++)
	{
		arr[i]->print();
		cout<<endl<<endl;
	}

}
bool check(bankAccount** b2, int id, int trans, string type)
{
	int counter=0;
	for(int i=0;i<4;i++)
	{
		if(b2[i]->getID()==id)
		{
			counter++;
            if(type=="withdraw")
			{
				if(b2[i]->withdraw(trans)==true)
				{
					return true;

				}
				else
					return false;
			}
			if(type=="deposit")
			{
				if(b2[i]->deposit(trans)==true)
				{
					return true;
				}
				else
					return false;
			}
		
		}
	}
		if(counter == 0)
			{
		 		cout<<"Id not found";
		      return false;
		}
	
}


void main()
{
	string data="data.txt";
	bankAccount *ptridentifier;
	ptridentifier=new bankAccount(10,13000,15000);
	bankAccount *b1=new bankAccount(10,13000,15000);

	b1->print();
	b1->deposit(1000);
	b1->deposit(3000);
	b1->withdraw(10000);
	b1->withdraw(6000);

	bankAccount *arr[2];

	float temp[3]={3000,5000,60000};
	float temp2[2]={5000,-5000};
	arr[0]=new bankAccount(30,2000,temp,3,15000);
    arr[1]=new bankAccount(40,255000,400000);
	arr[0]->print();
	arr[1]->print();

		bankAccount **dyarrayIdentifier= new bankAccount*[2];
		dyarrayIdentifier[0]= new bankAccount(50,2000,temp2,2,15000);
		dyarrayIdentifier[0]->withdraw(1000);
		dyarrayIdentifier[1]= new bankAccount(60,6000,400000);
		dyarrayIdentifier[0]->print();
		dyarrayIdentifier[1]->print();


		delete ptridentifier;
		delete b1;
		delete arr[0];
		arr[0]=nullptr;
		delete arr[1];
		arr[1]=nullptr;
		
		delete dyarrayIdentifier[0];
		dyarrayIdentifier[0]=nullptr;
		delete dyarrayIdentifier[1];
		dyarrayIdentifier[1]=nullptr;
		delete []dyarrayIdentifier;
		/////////
		bankAccount** b2;
		b2=read(data);
		printacc(b2,4);
		int id=0;
		int trans=0;
		string type;
		cout<<"Enter the id"<<endl;
		cin>>id;
		cout<<"Enter the transaction amount"<<endl;
		cin>>trans;
		cout<<"Enter the transaction type:withdraw or deposit(case sensitive)"<<endl;
		cin>>type;

		check(b2,id,trans,type);






}