// Queue с приоритетным входом tail на последний элемент в очереди 

#include <iostream>
#include "ClassQueue.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Queue q1(10);
	Queue q2(7);

	//четные по возр
	cout << "четн по возр\n";
	for (int i = 0; i < 9; i++) {
		q1.Add_Q(2*(i%8));
			
	}
	cout << q1;
	cout << "\n";

	//удалить
	for (int i = 0; i < 4; i++) {
		q1.Pop_Q();
		
	}
	cout << q1;
	cout << "GHBCDFBDFYBT \n";

	q2 = q1;
	
	cout << q2;
	cout << "\n";
	//нечетные по возр
	cout << "нечет по возр\n";
	for (int i = 0; i < 11; i++) {
		q1.Add_Q(2*i+1);
		
	}
	cout << q1;cout << "\n";


	q2 = q1;

	cout << q2;
	cout << "\n";

}
