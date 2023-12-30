// Bank Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Source.cpp"
#include <iostream>
#include <conio.h>
#include <fstream>//to use file handeling
#include <string>//to apply string elements 
#include <vector>// to deal with dynamic arrays
#include <cstring>
#include <stdlib.h>// exit() function
using namespace std;

int main()
{
	char here, heree, heere, hrre;
	int count = 0;
	for (int i = 0; i <= 56; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "|\t banking\t management\t  system\t|";//display project name
	cout << endl;
	for (int i = 0; i <= 56; i++) {
		cout << "-";
	}
	cout << endl;
here:
	cout << "|\t* how do you want to continue\t * \t\t|\n";
	cout << "|\t* 1 for loging in as a user \t * \t\t|\n";
	cout << "|\t* 2 for loging in as a manager\t * \t\t|\n";
	cout << "|\t* esc for exit\t\t\t *\t\t|\n";
	for (int i = 0; i <= 56; i++) {
		cout << "-";
	}
	cout << endl;
	char choice, choice2;
	cout << "\t make your choice : ";
	choice2 = _getch();
	system("cls");
	switch (choice2) {
	case '1': //user

		do {
			for (int i = 0; i <= 56; i++) {
				cout << "-";
			}
			user obj;
			cout << endl;

			cout << "\n|\tyou had proceeded towards user interface\t|\n";
			cout << "|\t* press 1 to login to your account\t*\t|\n";//display choices available
			/*cout << "|\t* press 2 to generate OTP\t\t*\t|\n";
			cout << "|\t* press 3 to withdraw cash\t\t*\t|\n";*/
			cout << "|\t* press 2 to transfer cash\t\t*\t|\n";
			cout << "|\t* press 3 to check balance\t\t*\t|\n";
			cout << "|\t* press 0 to return to main menu\t*\t|\n";

			for (int i = 0; i <= 56; i++) {
				cout << "-";
			}
			cout << endl;

			cout << "\n\tmake your choice now : ";
		heere:
			choice = _getch();
			system("cls");
			cout << "\t";
			for (int i = 0; i <= 43; i++) {
				cout << "-";
			}
			cout << endl;

			switch (choice) {
			case '1':
				obj.login();
				break;
				/*case '2':
					obj.OTP();
					break;
				case '3':
					obj.withdraw();
					break;*/
			case '2':
				obj.transfer();
				break;
			case '3':
				obj.balance();
				break;
			case '0':
				goto here;
				break;
			default:
				cout << "\tinvalid input\n" << "\t retry:";
				goto heere;
			}
		} while (choice != '0');
		break;

	case '2': //admin
	{
		for (int i = 0; i <= 56; i++) {
			cout << "-";
		}
		cout << endl;

		cout << "\t enter password : ";

	heree:

		char password[50];
		char ch;
		int i = 0;

		// Read characters until Enter (ASCII code 13) is pressed
		while ((ch = _getch()) != 13) {
			if (ch == '\b') {
				// Handle backspace
				if (i > 0) {
					cout << "\b \b"; // Move the cursor back, overwrite the character with space, move back again
					i--;
				}
			}
			else {
				// Handle other characters (excluding Enter and backspace)
				password[i++] = ch;
				cout << '*'; // Display a star for each character
			}
		}

		password[i] = '\0'; // Null-terminate the password string
		cout << endl;
		//std::cout << "Password entered: " << password << std::endl;

		cout << endl;
		for (int i = 0; i <= 56; i++) {
			cout << "-";
		}
		cout << endl;

		//cout << strcmp(password, "admin123");
		if (strcmp(password, "admin123") != -1)
		{
			do {
				admin obj2;
				user o;

				cout << "|   *  you had proceeded to manager interface    *\t|\n";
				cout << "|\tchoose what you want to do: \t\t\t|\n";
				cout << "|   *  1 for create a new customer account\t * \t|\n";
				cout << "|   *  2 for deposit cash\t\t\t *\t|\n";
				cout << "|   *  3 for withdraw cash\t\t\t *\t|\n";
				cout << "|   *  4 for edit a pre-existing account\t * \t|\n";
				cout << "|   *  5 for view customer account details\t * \t|\n";
				cout << "|   *  6 for searching among the list\t\t * \t|\n";
				cout << "|   *  7 for deleting an account\t\t * \t|\n";
				cout << "|   *  0 for returning to main menu\t\t * \t|\n";

				for (int i = 0; i <= 56; i++)
				{
					cout << "-";
				}
				cout << endl;

				cout << "\tmake your choice now : \t";
			hrre:
				choice = _getch();
				system("cls");

				for (int i = 0; i <= 43; i++)
				{
					cout << "-";
				}
				cout << endl;

				switch (choice) {
				case '1':
					obj2.customer();
					break;
				case '2':
					o.deposit();
					break;
				case '3':
					o.withdraw();
					break;
				case '4':
					obj2.edit();
					break;
				case '5':
					obj2.view();
					break;
				case '6':
					obj2.search();
					break;
				case '7':
					obj2.del();
					break;
				case '0':
					goto here;
					break;
				default:
					cout << "\t invalid choice \t\n" << "\t retry : ";
					goto hrre;
				}
			} while (choice != '0');
			break;
		}
		else
		{
			cout << "invalid password!!!\n \t retry : ";
			goto heree;
		}
	}

	case 27:
		exit(1);
		break;

	default:
		cout << "\t invalid choice \t\n" << "\t retry:\n";
		goto here;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
