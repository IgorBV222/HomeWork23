#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Заполнение массива случайными числами
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//Вывод массива в консоль
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

//Задача 23.1
//Вычисляет максимальную из трех переменных, после чего меняет значение остальных на значение максимальной
 void three_max(int &num1, int &num2, int &num3) {
	
	num1 = num1 > (num2 > num3 ? num2 : num3) ? num1 : (num2 > num3 ? num2 : num3);
	num2 = num1 > (num2 > num3 ? num2 : num3) ? num1 : (num2 > num3 ? num2 : num3);
	num3 = num1 > (num2 > num3 ? num2 : num3) ? num1 : (num2 > num3 ? num2 : num3);
}
 
 //Задача 23.2
 //Ссылка на первый отрицательный элемент массива.В его отсутствии первый элемент массива.
 template <typename T>
 T& link(T arr[], const int length) {
	 for (int i = 0; i < length; i++) {
		 if (arr[i] < 0) {
			 return arr[i];
			 break;
		 }		 	 
	 }		 
	 return arr[0];
 }

 //Задача 23.3.
 //Обнуляет все элементы второго массива, которые встречаются в первом.
 //Почему не срабатывает при разных длиннах массивов????

 template <typename T>
 void zeroing2(T &arr1, const int length1, T &arr2, const int length2) {
	 cout << "\nИтоговый массив 2:\n";
	 cout << '[';
	 for (int i = 0; i < length2; i++) {
		 for (int j = 0; j < length1; j++) {			
			 if (arr2[i] == arr1[j]) {
				 arr2[i] = 0;
			 }
		 }		
		 cout << arr2[i] << ", ";		 
	 }
	 cout << "\b\b]\n";	 
 }

 //Задача 23.3.
 //Обнуляет все элементы второго массива, которые встречаются в первом.
 template <typename T>
 void zeroing(T* arr1, const int length1, T* arr2, const int length2) {
	 cout << "\nИтоговый массив 2:\n";
	 cout << '[';
	 for (int i = 0; i < length2; i++) {
		 for (int j = 0; j < length1; j++) {
			 if (*(arr2 + i) == *(arr1 + j)) {
				 *(arr2 + i) = 0;
			 }					 
		 }
		 cout << *(arr2 + i) << ", ";		 
	 }
	 cout << "\b\b]\n";
 }

int main() {
	setlocale(LC_ALL, "Russian");

	// Задача 23.1.		
	cout << "Задача 23.1.\n";
	int A = 9, B = 5, C = 14;
	three_max(A, B, C);
	cout << A << ' ' << B << ' ' << C;
	cout << "\n\n";
	

	// Задача 23.2.	
	cout << "Задача 23.2.\nИзначальный массив: \n";
	const int size = 10;
	int mass[size];
	fill_arr(mass, size, -10, 11);
	show_arr(mass, size);
	cout << "Первый отрицательный элемент массива. В его отсутствии первый элемент массива:\n";
	cout << link(mass, size);
	cout << "\n\n";

	//Задача 23.3
	cout << "Задача 23.2.\nМассив 1: \n";
	const int size1 = 10;
	int mass1[size1];
	fill_arr(mass1, size1, 0, 10);
	show_arr(mass1, size1);
	
	cout << "\nМассив 2: \n";
	const int size2 = 8;
	int mass2[size2];
	fill_arr(mass2, size2, 0, 7);
	show_arr(mass2, size2);
	
	zeroing(mass1, size1, mass2, size2);
	cout << "\n\n";

	return 0;
}