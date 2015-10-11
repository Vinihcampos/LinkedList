#include "list.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

	List<string> l;
	l.push_back("Vinicius");
	l.push_back("Vini");
	l.push_back("Ok");
	l.printList();
	/*cout<<l.front()<<endl;
	cout<<l.back()<<endl;
	l.pop_back();
	l.printList();
	cout<<l.front()<<endl;
	cout<<l.back()<<endl;
	l.pop_back();
	l.printList();
	cout<<l.front()<<endl;
	cout<<l.back()<<endl;
	l.pop_back();*/
	l.erase(l.begin()++, l.end());
	l.printList();
	cout<<l.front()<<endl;
	cout<<l.back()<<endl;

	return 0;
}