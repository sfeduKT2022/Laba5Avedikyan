#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

struct buyer
{
	char surname[20];
	char name[20];
	char patronymic[20];
	struct {  char city[20]; char street[20]; int home; int kv; } address;
	int code;
	int credit;
};

void Sort(buyer** q, int k)
{
	for (int i = 1; i < k + 1; i++)
		for (int j = 1; j < k - i + 1; i++)
			if (q[j]->code > q[j + 1]->code)
			{
				buyer* temp = q[j];
				q[j] = q[j + 1];
				q[j + 1] = temp;
			}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	setlocale(LC_ALL, "ru");

	const int n = 10; 
	char otvet;
	int k = 0, poisk;

	ofstream file("buyer.txt");

	buyer* h = new buyer[n];

	// Ввод

	for (int i = 1; i < n + 1; i++) 
	{
		cout << endl;
		cout << "Введите фамилию " << i << " покупателя: ";
		cin >> h[i].surname;
		file << h[i].surname << "	";
		cout << "Введите имя " << i << " покупателя: ";
		cin >> h[i].name;
		file << h[i].name << "	";
		cout << "Введите отчество " << i << " покупателя: ";
		cin >> h[i].patronymic;
		file << h[i].patronymic << "	";
		cout << "Введите город " << i << " покупателя: ";
		cin >> h[i].address.city;
		file << h[i].address.city << "	";
		cout << "Введите улицу " << i << " покупателя: ";
		cin >> h[i].address.street;
		file << h[i].address.street << "	";
		cout << "Введите номер дома " << i << " покупателя: ";
		cin >> h[i].address.home;
		file << h[i].address.home << "	";
		cout << "Введите номер квартиры " << i << " покупателя: ";
		cin >> h[i].address.kv;
		file << h[i].address.kv;
		cout << "Введите номер кридитной карты " << i << " покупателя: ";
		cin >> h[i].credit;
		file << h[i].credit << "	";
		cout << "Введите код покупки " << i << " покупателя: ";
		cin >> h[i].code;
		file << h[i].code << "	";

		k++;

		cout << endl << "Чтобы прекратить заполнение структур, введите '1'. Чтобы продолжить, любое другое значение.";
		cin >> otvet;
		if (otvet == '1') break;

		file << (char)13; 
	}

	file.close();

	buyer** q = new buyer * [n];
	for (int i = 1; i < k + 1; i++)
		q[i] = &h[i];


	// Поиск 

	cout << endl << endl << "Если вы хотите выполнить поиск структуры с заданным зачением, ВВЕДИТЕ '1'" << endl;
	cout << "Чтобы пропустить, введите любое другое значение ";
	cin >> otvet;
	if (otvet == '1')
	{
		cout << endl << "Введите значение, соответствующее нужному полю" << endl;
		cout << "Поиск по фамилии - 1" << endl;
		cout << "Поиск по имени - 2" << endl;
		cout << "Поиск по отчеству - 3" << endl;			
		cout << "Поиск по городу - 4" << endl;
		cout << "Поиск по улице - 5" << endl;
		cout << "Поиск по номеру дома - 6" << endl;
		cout << "Поиск по номеру квартиры - 7" << endl;
		cout << "Поиск по номеру кредитной карты - 8" << endl;
		cout << "Поиск по коду покупки - 9" << endl;;

		cout << "Введите значение: ";
		cin >> poisk;

		if (poisk == 1)
		{
			string znachenie;
			cout << endl << "Введите фамилию: ";
			cin >> znachenie;
			for (int i = 1; i < k + 1; i++)
			{
				if (znachenie == h[i].surname)
				{
					cout << endl;
					cout << i << " Покупатель: ";
					cout << h[i].surname << "	" << h[i].name << "	  " << h[i].patronymic << "   "
						<< h[i].address.city << "	" << h[i].address.street << "	"
						<< h[i].address.home << "	" << h[i].address.kv << "   " << h[i].credit << "	"
						<< h[i].code << "	";
				}
			}
		}
		if (poisk == 2)
		{
			string znachenie;
			cout << "Введите имя: ";
			cin >> znachenie;
			for (int i = 1; i < k + 1; i++)
			{
				if (znachenie == h[i].name)
				{
					cout << endl;
					cout << i << " Покупатель: ";
					cout << h[i].surname << "	" << h[i].name << "	  " << h[i].patronymic << "   "
						<< h[i].address.city << "	" << h[i].address.street << "	"
						<< h[i].address.home << "	" << h[i].address.kv << "   " << h[i].credit << "	"
						<< h[i].code << "	";
				}
			}
		}
		if (poisk == 3)
		{
			string znachenie;
			cout << "Введите отчество: ";
			cin >> znachenie;
			for (int i = 1; i < k + 1; i++)
			{
				if (znachenie == h[i].patronymic)
				{
					cout << endl;
					cout << i << " Покупатель: ";
					cout << h[i].surname << "	" << h[i].name << "	  " << h[i].patronymic << "   "
						<< h[i].address.city << "	" << h[i].address.street << "	"
						<< h[i].address.home << "	" << h[i].address.kv << "   " << h[i].credit << "	"
						<< h[i].code << "	";
				}
			}
		}
		
		
		if (poisk == 4)
		{
			string znachenie;
			cout << "Введите город: ";
			cin >> znachenie;
			for (int i = 1; i < k + 1; i++)
			{
				if (znachenie == h[i].address.city)
				{
					cout << endl;
					cout << i << " Покупатель: ";
					cout << h[i].surname << "	" << h[i].name << "	  " << h[i].patronymic << "   "
						<< h[i].address.city << "	" << h[i].address.street << "	"
						<< h[i].address.home << "	" << h[i].address.kv << "   " << h[i].credit << "	"
						<< h[i].code << "	";
				}
			}
		}
		if (poisk == 5)
		{
			string znachenie;
			cout << "Введите улицу: ";
			cin >> znachenie;
			for (int i = 1; i < k + 1; i++)
			{
				if (znachenie == h[i].address.street)
				{
					cout << endl;
					cout << i << " Покупатель: ";
					cout << h[i].surname << "	" << h[i].name << "	  " << h[i].patronymic << "   "
						<< h[i].address.city << "	" << h[i].address.street << "	"
						<< h[i].address.home << "	" << h[i].address.kv << "   " << h[i].credit << "	"
						<< h[i].code << "	";
				}
			}
		}
		if (poisk == 6)
		{
			int znachenie;
			cout << "Введите номер дома: ";
			cin >> znachenie;
			for (int i = 1; i < k + 1; i++)
			{
				if (znachenie == h[i].address.home)
				{
					cout << endl;
					cout << i << " Покупатель: ";
					cout << h[i].surname << "	" << h[i].name << "	  " << h[i].patronymic << "   "
						<< h[i].address.city << "	" << h[i].address.street << "	"
						<< h[i].address.home << "	" << h[i].address.kv << "   " << h[i].credit << "	"
						<< h[i].code << "	";
				}
			}
		}
		if (poisk == 7)
		{
			int znachenie;
			cout << "Введите номер квартиры: ";
			cin >> znachenie;
			for (int i = 1; i < k + 1; i++)
			{
				if (znachenie == h[i].address.kv)
				{
					cout << endl;
					cout << i << " Покупатель: ";
					cout << h[i].surname << "	" << h[i].name << "	  " << h[i].patronymic << "   "
						<< h[i].address.city << "	" << h[i].address.street << "	"
						<< h[i].address.home << "	" << h[i].address.kv << "   " << h[i].credit << "	"
						<< h[i].code << "	";
				}
			}
		}
		if (poisk == 8)
		{
			int znachenie;
			cout << "Введите номер кредитной карты: ";
			cin >> znachenie;
			for (int i = 1; i < k + 1; i++)
			{
				if (znachenie == h[i].credit)
				{
					cout << endl;
					cout << i << " Покупатель: ";
					cout << h[i].surname << "	" << h[i].name << "	  " << h[i].patronymic << "   "
						<< h[i].address.city << "	" << h[i].address.street << "	"
						<< h[i].address.home << "	" << h[i].address.kv << "   " << h[i].credit << "	"
						<< h[i].code << "	";
				}
			}
		}
		if (poisk == 9)
		{
			int znachenie;
			cout << "Введите код покупки: ";
			cin >> znachenie;
			for (int i = 1; i < k + 1; i++)
			{
				if (znachenie == h[i].code)
				{
					cout << endl;
					cout << i << " Покупатель: ";
					cout << h[i].surname << "	" << h[i].name << "	  " << h[i].patronymic << "   "
						<< h[i].address.city << "	" << h[i].address.street << "	"
						<< h[i].address.home << "	" << h[i].address.kv << "   " << h[i].credit << "	"
						<< h[i].code << "	";
				}
			}
		}
	}

	// Вывод массива структур

	cout << endl << endl << "Если вы хотите вывести на экран содержимое массива структур, ВВЕДИТЕ '1'";
	cout << endl << "Чтобы пропустить, введите любое другое значение ";
	cin >> otvet;
	if (otvet == '1')
	{
		for (int i = 1; i < k + 1; i++)
		{
			cout << endl;
			cout << i << " Покупатель: ";
			cout << h[i].surname << "	" << h[i].name << "	  " << h[i].patronymic << "   "
				<< h[i].address.city << "	" << h[i].address.street << "	"
				<< h[i].address.home << "	" << h[i].address.kv << "   " << h[i].credit << "	"
				<< h[i].code << "	";
		}
	}



	// Сортировка
	

	cout << endl << endl << "Если вы хотите отсортировать структуры по коду и вывести результат на экран, ВВЕДИТЕ '1'";
	cout << endl <<"Чтобы пропустить, введите любое другое значение" << endl;
	cin >> otvet;
	if (otvet == '1')
	{
		Sort(q, k);
		for (int i = 1; i < k + 1; i++)
		{
			cout << i << " Покупатель: ";
			cout << q[i]->surname << "	" << q[i]->name << "	"
				<< q[i]->patronymic << "	" << q[i]->address.city << "	"
				<< q[i]->address.street << "	" << q[i]->address.home << "	" 
				<< q[i]->address.kv << q[i]->credit << "	" << q[i]->code << "	";
			cout << "\n";
		};
	}
	return 0;
}
