#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 10;
int pancakes[SIZE]{ 12,6,10,23,41,1,19,26,45,37 };
int count2 = 0,count1=0;
int temp1,temp3, counter1 = 0;
int max_pan, max_index = 0;

void findMaxPancake(int i) {
	max_pan = pancakes[i];
	for (int j = i; j < SIZE; j++) {
		if (max_pan < pancakes[j]) {
			max_pan = pancakes[j];
			max_index = j;
		}
	}
}
void sortPancake() {
	for (int j = max_index, h = SIZE - 1; j < h; j++, h--) {
		temp1 = pancakes[j];
		pancakes[j] = pancakes[h];
		pancakes[h] = temp1;
	}
	counter1++;
}
void maxPancakeDown(int i) {
	for (int j = i, h = SIZE - 1; j < h; j++, h--) {
		temp1 = pancakes[j];
		pancakes[j] = pancakes[h];
		pancakes[h] = temp1;
	}
	counter1++;
}
int selectionSort(int array[]);
int selectionSort2(int array[]);
void createArray(int array[]);
int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	/*cout << "Home task #9.2.1\n\n";
	//Написать программу «справочник».Создать два одномерных
	//массива.Один массив хранит номера мобильных телефонов,
	//второй — домашние телефонные номера.
	//Реализовать меню для пользователя :
	//■ Отсортировать по номерам мобильных
	//■ Отсортировать по домашним номерам телефонов;
	//■ Вывести пользовательский данные;
	//■ Выход.
	enum menu { ENTER_DATA = 1, OUTPUT_DATA, SORT_BY_MOBILE_NUM, SORT_BY_TEL_NUM, QUIT };
	const int n = 5;
	int userChoice, mobTel[n], tel[n], temp;
	bool isDataEntered = false;
	do {
		cout << "Выберете пункт:\n";
		cout << "1 - ввести данные\n";
		cout << "2 - отобразить данные\n";
		cout << "3 - сортировать по номеру мобильного\n";
		cout << "4 - сортировать по домашним номерам телефонов\n";
		cout << "5 - выход\n";
		cin >> userChoice;
		switch (userChoice) {
		case ENTER_DATA:
		{
			cout << "Пожалуйста, введите данные для каждого клиента\n";
			isDataEntered = true;
			for (int i = 0; i < n; i++) {
				cout << "Введите номер мобильного телефона для ";
				cout << i + 1 << " клиента:\n";
				cin >> mobTel[i];
				cout << "Введите номер домашнего телефона для ";
				cout << i + 1 << " клиента:\n";
				cin >> tel[i];
			}
			break;
		}
		case OUTPUT_DATA:
		{
			if (isDataEntered) {
				cout << "Данные клиента:\n";
				cout << "ID|Мобильный номер|Домашний номер\n";
				for (int i = 0; i < n; i++) {
					cout << i + 1 << "|     " << mobTel[i];
					cout << " \t\t" << tel[i] << "\n";
				}
			}
			else {
				cout << "Нет данных!" << "\n";
				cout << "Пожалуйста, введите данные для каждого клиента заного\n";
			}
			break;
		}
		case SORT_BY_MOBILE_NUM:
		{
			if (isDataEntered) {
				cout << "Сортировка данных по мобильному телефону\n";
				for (int i = 1; i < n; ++i) {
					for (int r = 0; r < n - i; r++) {
						if (mobTel[r] < mobTel[r + 1]) {
							temp = mobTel[r];
							mobTel[r] = mobTel[r + 1];
							mobTel[r + 1] = temp; temp = tel[r];
							tel[r] = tel[r + 1];
							tel[r + 1] = temp;
						}
					}
				}
			}
			else {
				cout << "Нет данных!" << "\n";
				cout << "Пожалуйста, введите данные для каждого клиента заного\n";
			}
			break;
		}
		case SORT_BY_TEL_NUM:
		{
			if (isDataEntered) {
				cout << "Сортировка по домашним номерам\n";
				for (int i = 1; i < n; ++i) {
					for (int r = 0; r < n - i; r++) {
						if (tel[r] < tel[r + 1]) {
							temp = tel[r];
							tel[r] = tel[r + 1];
							tel[r + 1] = temp;
							temp = mobTel[r];
							mobTel[r] = mobTel[r + 1];
							mobTel[r + 1] = temp;
						}
					}
				}
			}
			else {
				cout << "Нет данных!" << "\n";
				cout << "Пожалуйста, введите данные для каждого клиента заного\n";
			}
			break;
		}
		case QUIT: {
			cout << "Досвидания)";
			break;
		}
		default:
			cout << "Неверный пункт меню!";
		}
	} while (userChoice != 5);
	cout << "\n\nHome task #9.2.2\n\n";
	//Написать программу, реализующую сортировку массива с
	//помощью усовершенствованной сортировки пузырьковым методом.Усовершенствование состоит в том, чтобы анализировать
	//количество перестановок на каждом шагу, если это количество
	//равно нулю, то продолжать сортировку нет смысла — массив
	//отсортирован.
	const int SIZE1 = 10;
	int arr[SIZE1], temp2, counter;
	cout << "Введите элементы массива:\n";
	for (int i = 0; i < SIZE1; i++) {
		cin >> arr[i];
	}
	cout << endl;
	for (int i = 1; i < SIZE1; ++i) {
		counter = 0;
		for (int r = 0; r < SIZE1 - i; r++) {
			if (arr[r] > arr[r + 1]) {
				temp2 = arr[r];
				arr[r] = arr[r + 1];
				arr[r + 1] = temp2;
				counter++;
			}
		}
		if (counter == 0) {
			cout << "Cортировкa завершилась на ";
			cout << i - 1 << " шаге\n";
			break;
		}
	}
	for (int i = 0; i < SIZE1; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n\nHome task #9.2.3\n\n";
	//Есть стопка оладий различного радиуса. Единственная
	//операция, проводимая с ними — между любыми двумя суем
	//лопатку и меняем порядок оладий над лопаткой на обратный.
	//Необходимо за минимальное количество операций таких
	//отсортировать снизу вверх по убыванию радиуса.
	for (int i = 0; i < SIZE; i++) {
		findMaxPancake(i);

		if (pancakes[i] == max_pan && i >= max_index) continue;
		else {
			sortPancake();
			for (int i = 0; i < SIZE; i++) {
				cout << pancakes[i] << " ";
			}
			cout << endl << endl;
			maxPancakeDown(i);
		}
	}

	for (int i = 0; i < SIZE; i++) {
		cout << pancakes[i] << " ";
	}
	cout << "\n\nПотребовалось перевернуть " << counter1 << " раз\n";
	cout << "\n\nHome task #9.2.4\n\n";*/
	//Написать программу, которая сравнивает число перестановок элементов 
	//при использовании сортировки «пузырьком» (усовершенствованная версия задани я 2) 
	//и методом выбора.Выполнить ее тестирование на разных 10 массивах,
	//содержащих 1000 случайных элементов, вычислить среднее
	//число перестановок для каждого метода после тестирования
	int count1 = 0;
	int count2 = 0;
	int array[1000];

	for (int i = 0; i < 10; i++){
		createArray(array);
		count1 += selectionSort2 (array);
		count2 += selectionSort (array);
	}
	cout << count1 << " - Пузырьком, среднее значение - " << count1 / 10<<endl;
	cout << count2 << " - Выбором среднее значение - " << count2 / 10 << endl;
	
}
void createArray(int array[]) {
	const int a = 10;
	for (int i = 0; i < a; i++) {
		array[i] = rand() % 100;
	}
	for (int i = 0; i < a; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
int selectionSort2 (int array[]) {
	int temp;
	int count1 = 0;
	int sum = 0;
	for (int i = 0; i < 1000; i++) {
		sum = 0;
		for (int j = 0; j < 1000 - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				count1++;
			}
			if (count1 == 0) {
				sum += i;
				break;
			}
		}
	}
	cout << endl;
	return sum;
}
int selectionSort(int array[]) {
	int i, j, k;
	int temp;
	int count = 0;
	int sum1 = 0;
	for (i = 0; i < 1000; i++) {
		k = i;
		temp = array[i];
		count = 0;
		for (j = 1 + i; j < 1000; j++) {
			if (array[j] < temp) {
				k = j;
				temp = array[j];
				count++;
			}
		}
		if (k != i) {
			array[k] = array[i];
			array[i] = temp;
		}
		if (count == 0) {
			sum1 += i;
			break;
		}
	}
	return sum1;
}