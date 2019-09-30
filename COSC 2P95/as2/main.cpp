#include<iostream>
#include<queue>
#include<list>
#include"main.h"
#include<string>
#include<iterator>
using namespace std;
int menu();
int main(){
	int choice=-1;
	string first,second,third,fourth;
	ConcretePoolQueue<string> *queue=new ConcretePoolQueue<string>();
	list<string> names;
	do{
			choice=menu();
			switch(choice){
				case 1:
				cout<<"Enter Name: ";
				cin>>first;
				cout<<endl;
				queue->addSingle(first);
				cout<<":-\tAdded ["<<first<<"]"<<endl;
				break;
				case 2:
				cout<<"First: ";
				cin>>first;
				cout<<endl;
				cout<<"Second: ";
				cin>>second;
				cout<<endl;
				queue->addPair(first,second);
				cout<<":-\tAdded ["<<first<<","<<second<<"]"<<endl;
				break;
				case 3:
				cout<<"First: ";
				cin>>first;
				cout<<endl;
				cout<<"Second: ";
				cin>>second;
				cout<<endl;
				cout<<"Third: ";
				cin>>third;
				cout<<endl;
				queue->addTriple(first,second,third);
				cout<<":-\tAdded ["<<first<<","<<second<<","<<third<<"]"<<endl;
				break;
				case 4:
				cout<<"First: ";
				cin>>first;
				cout<<endl;
				cout<<"Second: ";
				cin>>second;
				cout<<endl;
				cout<<"Third: ";
				cin>>third;
				cout<<endl;
				cout<<"Fourth: ";
				cin>>fourth;
				cout<<endl;
				queue->addQuartet(first,second,third,fourth);
				cout<<":-\tAdded ["<<first<<","<<second<<","<<third<<","<<fourth<<"]"<<endl;
				break;
				case 5:
				cout<<":>\t"<<queue->removeSingle(0)<<""<<endl;
				break;
				case 6:
				cout<<":>\t"<<queue->removePair(0)<<","<<queue->removePair(1)<<""<<endl;
				break;
				case 7:
				cout<<":>\t"<<queue->removeTriple(0)<<","<<queue->removeTriple(1)<<","<<queue->removeTriple(2)<<""<<endl;
				break;
				case 8:
				cout<<":>\t"<<queue->removeQuartet(0)<<","<<queue->removeQuartet(1)<<","<<queue->removeQuartet(2)<<","<<queue->removeQuartet(3)<<""<<endl;
				case 9:
				cout<<"One:\t"<<queue->hasSingle(0)<<""<<endl;
				cout<<"Two:\t"<<queue->hasPair(0)<<""<<endl;
				cout<<"Third:\t"<<queue->hasTriple(0)<<""<<endl;
				cout<<"Four:\t"<<queue->hasQuartet(0)<<""<<endl;
				cout<<"Count:\t"<<queue->count()<<""<<endl;
				cout<<endl;
				break;
				case 0:
				break;
				default:
				cout<<"Unrecognized Option"<<endl;
			}
	}while(choice!=0);
}
int menu(){
	int choice;
	cout<<"1. Add One"<<endl;
	cout<<"\t2. Add Two"<<endl;
	cout<<"\t3. Add Three"<<endl;
	cout<<"\t4. Add Four"<<endl;
	cout<<"5. Remove One"<<endl;
	cout<<"\t6. Remove Two"<<endl;
	cout<<"\t7. Remove Three"<<endl;
	cout<<"\t8. Remove Four"<<endl;
	cout<<"\t\t9. Test Options"<<endl;
	cout<<"\t0. Quit"<<endl;
	cin>>choice;
	return	choice;
}