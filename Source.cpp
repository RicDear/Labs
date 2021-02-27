/*В начальный момент времени на экране выводится массив из NxM звездочек.
С каждым шагом одна случайная звездочка заменяется на “#”.
Пользователю необходимо ввести координаты измененного символа.
За каждую ошибку снимается одна жизнь.
Пользователь выигрывает, если угадал все замены, и проигрывает, если у него закончились все жизни.
Очищать экран после каждого хода
*/
#include <iostream>
#include <ctime>
#include <windows.h>


using namespace std;

#define N 100 //Строки
#define M 100 //Столбцы

void clear()
{
	Sleep(5000); // 5 секунд ничего не происходит
	system("cls"); //Очищает консоль
}
void input(char a[N][M], int n, int m)
{
	//Ввод массива со *
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			   a[i][j] = '*';
	}
} 

void output(char a[N][M], int n, int m)
{
	//Вывод массива пользователю
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void random(char a[N][M], int n, int m,int Chek, int Chek2)
{
	int nrandom, mrandom;
	int K;
	do
	{
		K = 0;
		nrandom = rand() % n;
		mrandom = rand() % m;
		if (a[nrandom][mrandom] == '#')
			continue;
		else
		{
			a[nrandom][mrandom] = '#';
			K = 1;
		}
		if (Chek == Chek2)
			break;
	} while (K!=1);
}

int main()	
{
	srand(time(NULL));
	setlocale(0, "rus");

	char rep;
	     do
		 {

		   char a[N][M];//Основной массив
		   int n = 0, m = 0, HP, Chek, Chek2 = 0, answerN, answerM;// n - строки, m - столбцы, Chek,Chek2 - проверка для того, чтобы не было бесконечного цикла замены #;
		//Инициализирую, так как при проверке ввода я могу не ввести m и программа падает.
		   int prov[N][M] = {};
		
		
			
			cout << "Правила игры" << endl;
			cout << "В начальный момент времени на экране выводится массив из NxM звездочек." << endl << "С каждым шагом одна случайная звездочка заменяется на “#”." << endl;
			cout << "Вам необходимо ввести координаты измененного символа." << endl << "За каждую ошибку снимается одна жизнь." << endl;
			cout << "Вы победите, если угадаете все замены, и проиграете, если у Вас закончатся все жизни" << endl << endl;
			do
			{
				cout << "Введите количество строк от 1 до 100" << endl;
				cin >> n;
				if (n < 0 || n>100)
				{
					cout << "Некорректный ввод строк" << endl;
					continue;
				}
				cout << "Введите количество столбцов от 1 до 100" << endl;
				cin >> m;
				if (m < 0 || m>100)
				{
					cout << "Некорректный ввод столбцов" << endl;
					continue;
				}
			} while ((n < 0 || n>100) && (m < 0 || m>100));

			Chek = n * m;

			do
			{
				cout << "Выберите количество жизней, 1, 2 или 3" << endl;
				cin >> HP;
			} while (HP < 1 || HP>3);

			input(a, n, m);
			do

			{
				system("cls");
			    Sleep(1000); //Не использую clear(), чтобы засыпать не на 5 секунд, а на 2
				cout << "Текущее расположение элементов" << endl;
				output(a, n, m);

				clear();

				cout << "Измененное расположение элементов" << endl;

				random(a, n, m, Chek, Chek2);
				output(a, n, m);

				cout << "Запомните расположение измененного элемента!!!" << endl;

				clear();

				cout << "Введите координаты измененного элемента" << endl;
				cout << endl << "Введите строку" << endl;
				cin >> answerN;
				cout << endl << "Введите столбец" << endl;
				cin >> answerM;
				Chek2++;
				if (a[answerN - 1][answerM - 1] == '#' && prov[answerN - 1][answerM - 1] == 0)
				{
					cout << "Правильный ответ!" << endl;
					prov[answerN - 1][answerM - 1] = 1;
					Sleep(1000);
				}
				else
				{
					cout << "Неправильный ответ, вы не угадали измененный на этом ходу элемент и теряете одну жизнь" << endl;
					HP -= 1;
					cout << "Ваше количество жизней стало равно: " << HP << endl;
					Sleep(1000);
					if (HP == 0)
					{
						cout << "К сожалению, вы проиграли" << endl<<endl;
						break;
					}
				}
				if (Chek2 == Chek && HP != 0)
				{
					cout << "Поздравляю, Вы победили!!!";
					break;
				}

			} while (HP != 0 || Chek2 != Chek);
			cout << "Введите любую цифру, если хотите сыграть ещё" << endl;
			cout << "Введите 0, если хотите выйти" << endl;
			cin >> rep;
		} while (rep != '0');
	return 1;
}