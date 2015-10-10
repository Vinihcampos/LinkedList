#include "list.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	
	List<string> l;
	l.push_front("Vinicius");
	l.push_front("Vini");
	l.push_front("Ok");
	l.printList();

	return 0;
}