#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	PriorityQueue<int> i;
	i.enqueue(10);
	i.enqueue(20);
	i.enqueue(30);
	i.enqueue(40);
	//Lägger till 4 element i objektet i av typen INT

	cout << i.front() << endl;
	while (!i.isEmpty()) { //Sålänge det finns element i objektet "i" ska det skrivas ut och tas bort i prioritetsordning.
		try {
			cout << i.dequeue() << endl;
		}
		catch (string e) {
			cout << e << endl;
		}
	}
	//Försöker skriva ut fast det inte finns element kvar för att testa så att throw fungerar som tänkt.
	try {
		cout << i.dequeue() << endl;   
	}
	catch (string e) {
		cout << e << endl;
	}
	try {
		cout << i.front() << endl;
	}
	catch (string e) {
		cout << e << endl;
	}

	PriorityQueue<int> i2; //skapar nytt objekt "i2" och fyller den med element.
	i2.enqueue(5);
	i2.enqueue(10);
	i2.enqueue(15);
	i2.enqueue(20);
	PriorityQueue<int> i3(i2); //Skapar en kopia av "i2" och ger det till objektet "i3".
	i = i3; //tilldelar "i3" till "i" med tilldelningsoperatorn

	while (!i.isEmpty()) { //Sålänge det finns element i objektet "i" ska det skrivas ut och tas bort i prioritetsordning.
		try {
			cout << i.dequeue() << endl;
		}
		catch (string e) {
			cout << e << endl;
		}
	}

	PriorityQueue<string>s;
	s.enqueue("Detta");
	s.enqueue("Går");
	s.enqueue("Ju");
	s.enqueue("Bra");

	cout << s.front() << endl;
	while (!s.isEmpty()) { //Sålänge det finns element i objektet "i" ska det skrivas ut och tas bort i prioritetsordning.
		try {
			cout << s.dequeue() << endl;
		}
		catch (string e) {
			cout << e << endl;
		}
	}
	//Försöker skriva ut fast det inte finns element kvar för att testa så att throw fungerar som tänkt.
	try {
		cout << s.dequeue() << endl;
	}
	catch (string e) {
		cout << e << endl;
	}
	try {
		cout << s.front() << endl;
	}
	catch (string e) {
		cout << e << endl;
	}

	PriorityQueue<string> s2; //skapar nytt objekt "s2" och fyller den med element.
	s2.enqueue("Nej");
	s2.enqueue("Eller");
	s2.enqueue("Gjorde");
	s2.enqueue("Det");
	PriorityQueue<string> s3(s2); //Skapar en kopia av "s2" och ger det till objektet "s3".
	s = s3; //tilldelar "s3" till "s" med tilldelningsoperatorn

	while (!s.isEmpty()) { //Sålänge det finns element i objektet "i" ska det skrivas ut och tas bort i prioritetsordning.
		try {
			cout << s.dequeue() << endl;
		}
		catch (string e) {
			cout << e << endl;
		}
	}

	system("pause");
	return 0;
}