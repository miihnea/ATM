#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void logare();
void meniu();
void interogareSold(float sold);
float depunereNumerar(float sold);
float retragereNumerar(float sold);
void iesire();
void eroare_pin();
void eroare();

int main()
{
	int pin = 1234;
	int operatiune;
	float sold = 20000.00;
	int optiune;

	printf("Introduceti cod PIN: \n");
	scanf_s("%d", &pin);

	if (pin == 1234)
	{
		system("CLS");
		bool again = true;

		while (again)
		{
			meniu();

			printf("Operatiunea dvs:\t");
			scanf_s("%d", &operatiune);

			switch (operatiune)
			{
			case 1:
				system("CLS");
				interogareSold(sold);
				break;
			case 2:
				system("CLS");
				sold = depunereNumerar(sold);
				break;
			case 3:
				system("CLS");
				sold = retragereNumerar(sold);
				break;
			case 0:
				system("CLS");
				iesire();
				break;
			default:
				eroare();
				break;
			}

			printf("\n\n Doriti sa efectuati o alta tranzactie? \n");
			printf(" 1.Da \n");
			printf(" 2.Nu \n");
			scanf_s("%d", &optiune);

			system("CLS");

			if (optiune == 2)
			{
				again = false;
				iesire();
			}
	     }
	

	
	}
	else
	{
		eroare_pin();
	}
	return 0;
}

void meniu()
{
	printf("                      Buna ziua!          \n");
	printf("               Bine ati venit la Lefter Bank!       \n  ");
	printf("       Ce operaiune doriti sa efectuati?       \n\n");
	printf(" 1.Interogare sold \n");
	printf(" 2.Depunere numerar \n");
	printf(" 3.Extragere numerar \n\n\n");
	printf(" 0.Iesire \n\n "); 
}

void interogareSold(float sold)
{
	printf("Soldul dumneavoastra este de:  %.2f ron", sold);
}

float depunereNumerar(float sold)
{
	float depozit;
	printf("introduceti suma pe care doriti sa o depuneti in cont: \n\n");
	scanf_s("%f", &depozit);

	sold += depozit;

	printf(" \nNoul dumneavoastra sold este: %.2f  ron", sold);
	return sold;
}

float retragereNumerar(float sold)
{
	float retragere;
	bool ok = true;

	while (ok)
	{
		printf("Introduceti suma pe care doriti sa o retrageti: \n");
		scanf_s("%f", &retragere);

		if (retragere < sold)
		{
			ok = false;
			sold -= retragere;
			printf("Noul dvs sold este de %2.f  ron", sold);
		}
		else
		{
			printf("Eroare! Sold insuficient pentru aceasta retragere!");
		}
	}
	return sold;
}

void iesire()
{
	printf("Va rugam ridicati chitanta! \n\n Va multumim ca ati apelat la serviciile Lefter Bank!");
}

void eroare()
{
	printf("Eroare!Ati introdus un numar invalid!");
}

void eroare_pin()
{
	printf("PIN incorect! Mai aveti 2 incercari!");
}