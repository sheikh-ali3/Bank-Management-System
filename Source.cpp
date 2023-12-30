#include "Header.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>//to apply string elements 
#include <vector>// to deal with dynamic arrays
#include <cstring>
#include <stdlib.h>
using namespace std;

void admin::customer()
{
	admin a;
	char here, herre;

	ofstream file;

	cout << "  enter customers details:\n";
	cout << "\tenter first name : ";
	cin >> a.first_name;
	cout << "\tenter last name : ";
	cin >> a.last_name;
	cout << "\tenter cnic number : ";
herre:
	cin >> a.cnic;
	if (a.cnic.length() == 13)
	{
		cout << "\tenter password : ";
		int i = 0;
		// Read characters until Enter (ASCII code 13) is pressed
		while ((a.ch = _getch()) != 13) {
			if (a.ch == '\b') {
				// Handle backspace
				if (i > 0) {
					cout << "\b \b"; // Move the cursor back, overwrite the character with space, move back again
					i--;
				}
			}
			else {
				// Handle other characters (excluding Enter and backspace)
				a.password[i++] = a.ch;
				cout << '*'; // Display a star for each character
			}
		}
		a.password[i] = '\0'; // Null-terminate the password string
		cout << endl;
		//cout << password;
		cout << "\tconfirm password: ";
		int j = 0;
		// Read characters until Enter (ASCII code 13) is pressed
	here:
		while ((a.ch = _getch()) != 13) {
			if (a.ch == '\b') {
				// Handle backspace
				if (j > 0) {
					cout << "\b \b"; // Move the cursor back, overwrite the character with space, move back again
					j--;
				}
			}
			else {
				// Handle other characters (excluding Enter and backspace)
				a.password2[j++] = ch;
				cout << '*'; // Display a star for each character
			}
		}
		a.password2[j] = '\0'; // Null-terminate the password string
		cout << endl;

		do {
			if (strcmp(a.password, a.password2) != -1) {

				file.open(a.cnic + ".txt");

				file << a.first_name << endl;
				file << a.last_name << endl;
				file << a.cnic << endl;
				file << a.password << endl;
			}
			else {
				cout << "both passwords does not match.retry: ";
				goto here;
			}
		} while (strcmp(a.password, a.password2) == -1);
		cout << endl;

		cout << "\tenter first deposit: ";
		cin >> a.dep;
		file << a.dep << endl;
		cout << "\n\t congratulations!!!" << "  account made successfully\n";

		file.close();

		for (int i = 0; i <= 56; i++)
		{
			cout << "-";
		}

	heree:
		cout << "\n\tpress esc to exit \n" << "\t press 0 to return to menu\n";
		type = _getch();
		if (type == '0') {
			system("cls");
		}
		else if (type == 27) {
			exit(1);
		}
		else {
			cout << "invalid input!!!! . retry;\n";
			goto heree;
		}
	}
	else
	{
		cout << "invalid cnic!!. retry: ";
		goto herre;
	}

}

void admin::edit()
{
	admin a;

	vector<string> lines;
	ifstream file;

	cout << "\t enter cnic number of customer whose\n" << "\t data had to be edited: ";
	cin >> a.cnic;

	file.open(a.cnic + ".txt");

	if (!file.is_open()) {
		cout << "\t data not found \n";
	}
	else {
		cout << "\tchoose data to edit: \n" << "\t 1 for first name\n" << "\t 2 for last name\n" << "\t 3 for cnic number\n";
		cout << "\t 4 for password\n" << "\t 5 for deposit\n" << "\t enter now: ";
	there3:
		cin >> a.type;
		while (!file.eof()) {
			getline(file, a.line);
			lines.push_back(a.line);
		}

		file.close();

		switch (a.type) {
		case '1':
			cout << "\t previous first name: " << lines[0] << endl;
			cout << "\t new first name: ";
			cin >> a.first_name;
			lines[0] = a.first_name;
			break;

		case '2':
			cout << "\t previous last name: " << lines[1] << endl;
			cout << "\t new last name: ";
			cin >> a.last_name;
			lines[1] = a.last_name;
			break;

		case '3':
			cout << "\t previous cnic number: " << lines[2] << endl;
			cout << "\t new cnic number: ";
			cin >> a.c;
			lines[2] = a.c;
			break;

		case '4':
		{
			cout << "\t previous password: " << lines[3] << endl;
			cout << "\t new password: ";
			int i = 0, j = 0;
			// Read characters until Enter (ASCII code 13) is pressed
			while ((a.ch = _getch()) != 13) {
				if (a.ch == '\b') {
					// Handle backspace
					if (i > 0) {
						cout << "\b \b"; // Move the cursor back, overwrite the character with space, move back again
						i--;
					}
				}
				else {
					// Handle other characters (excluding Enter and backspace)
					a.password[i++] = ch;
					cout << '*'; // Display a star for each character
				}
			}
			a.password[i] = '\0'; // Null-terminate the password string
			cout << endl;

			cout << "\t confirm new password: ";
		here4:
			//int j = 0;
			// Read characters until Enter (ASCII code 13) is pressed
			while ((a.ch = _getch()) != 13) {
				if (a.ch == '\b') {
					// Handle backspace
					if (j > 0) {
						cout << "\b \b"; // Move the cursor back, overwrite the character with space, move back again
						j--;
					}
				}
				else {
					// Handle other characters (excluding Enter and backspace)
					a.password2[j++] = ch;
					cout << '*'; // Display a star for each character
				}
			}
			a.password2[j] = '\0'; // Null-terminate the password string
			cout << endl;

			if (a.password != a.password2) {
				cout << "\t passwords doesnot match.retry: ";
				goto here4;
			}
			else {
				lines[3] = a.password;
			}
			break;
		}
		case '5':
			cout << "\t previous balance: " << lines[4] << endl;
			cout << "\t new balance: ";
			cin >> a.bal;
			lines[4] = a.bal;
			break;

		default:
			cout << "\t invalid choice.retry: ";
			goto there3;
		}

		ofstream ofile;
		if (a.type != 3) {
			ofile.open(a.cnic + ".txt");

			if (!ofile.is_open()) {
				cout << "\t error while editing file\n";
			}
			else {
				cout << "\n\t congratulations!!!" << "  account updated successfully\n";
				for (int i = 0; i < 5; i++) {
					ofile << lines[i] << endl;
				}
				ofile.close();
			}
		}
		else {
			ofile.open(a.c + ".txt");
			if (!ofile.is_open()) {
				cout << "\t error while editing file\n";
			}
			else {
				cout << "\n\t congratulations!!!" << "  account updated successfully\n";
				for (int i = 0; i < 5; i++) {
					ofile << lines[i] << endl;
				}
				ofile.close();
			}
		}

	}

	for (int i = 0; i <= 56; i++)
	{
		cout << "-";
	}

here:
	cout << "\n\tpress esc to exit \n" << "\t press 0 to return to menu\n";
	type = _getch();
	if (type == '0') {
		system("cls");
	}
	else if (type == 27) {
		exit(1);
	}
	else {
		cout << "invalid input!!!! . retry;\n";
		goto here;
	}
}

void admin::view()
{
	admin a;

	string c, st[5];
	ifstream file;
	cout << "\tenter your cnic: ";
	cin >> c;

	file.open(c + ".txt");

	if (!file.is_open()) {
		cout << "\tdata not found\n";
	}
	else {
		cout << "\tenter password: ";
	there:
		int i = 0;
		// Read characters until Enter (ASCII code 13) is pressed
		while ((a.ch = _getch()) != 13) {
			if (a.ch == '\b') {
				// Handle backspace
				if (i > 0) {
					cout << "\b \b"; // Move the cursor back, overwrite the character with space, move back again
					i--;
				}
			}
			else {
				// Handle other characters (excluding Enter and backspace)
				a.password2[i++] = ch;
				cout << '*'; // Display a star for each character
			}
		}
		a.password2[i] = '\0'; // Null-terminate the password string
		cout << endl;

		while (!file.eof()) {
			for (int i = 0; i < 5; i++) {
				getline(file, st[i]);
			}
			file.close();

			if (a.password2 == st[3]) {
				cout << "\tfirst name: " << st[0] << endl;
				cout << "\tlast name: " << st[1] << endl;
				cout << "\tcnic number: " << st[2] << endl;
				cout << "\tpassword: " << st[3] << endl;
				cout << "\taccount balance: " << st[4] << endl;

				for (int i = 0; i <= 56; i++)
				{
					cout << "-";
				}

			here:
				cout << "\n\tpress esc to exit \n" << "\t press 0 to return to menu\n";
				a.type = _getch();
				if (a.type == '0') {
					system("cls");
				}
				else if (type == 27) {
					exit(1);
				}
				else {
					cout << "invalid input!!!! . retry;\n";
					goto here;
				}
			}
			else {
				cout << "password incorrect.retry: ";
				goto there;
			}
		}
	}

}

void admin::del()
{
	admin a;

	char filename[17];

	cout << "\t enter cnic number of customer\n" << "\t to  delete account: ";
	for (int i = 0; i < 13; i++) {
		cin >> filename[i];
	}
	filename[13] = '.';
	filename[14] = 't';
	filename[15] = 'x';
	filename[16] = 't';

	if (remove(filename) == 0) {
		cout << "\t account deleted successfully\n";
	}
	else {
		cout << "\t error while deleting account\n";
	}

	for (int i = 0; i <= 56; i++)
	{
		cout << "-";
	}

here:
	cout << "\n\tpress esc to exit \n" << "\t press 0 to return to menu\n";
	a.type = _getch();
	if (a.type == '0') {
		system("cls");
	}
	else if (a.type == 27) {
		exit(1);
	}
	else {
		cout << "invalid input!!!! . retry;\n";
		goto here;
	}
}

void admin::review(string& c)
{
	admin a;

	string st[5];

	ifstream file;
	file.open(c + ".txt");

	while (!file.eof()) {
		for (int i = 0; i < 5; i++) {
			getline(file, st[i]);
		}
		cout << "\tfirst name: " << st[0] << endl;
		cout << "\tlast name: " << st[1] << endl;
		cout << "\tcnic number: " << st[2] << endl;
		cout << "\tpassword: " << st[3] << endl;
		cout << "\taccount balance: " << st[4] << endl;
	}
	file.close();
}

void admin::search() {
	string c;
	char ch;
	ifstream file;

	cout << "\tenter cnic of user to find: ";
	cin >> c;

	file.open(c + ".txt");

	if (!file.is_open()) {
		cout << "\n\t sorry!!!" << "  data not found\n";
	}
	else {
		cout << "\n\t congratulations!!!" << "  data found \n";
		cout << "\n\t do you want to view data:\n y for yes\t n for no\n";
		cin >> ch;
		if (ch == 'y' || ch == 'Y') {
			review(c);
		}
		file.close();
	}
}

void user::login()
{
	user u;

	string c, st[5], pw;
	char herre;

	ifstream file;

	cout << "\tenter your cnic: ";
herre:
	cin >> c;

	if (c.length() == 13)
	{
		file.open(c + ".txt");
		if (!file.is_open()) {
			cout << "\tdata not found\n" << "\t retry: ";
			goto herre;
		}
		else {
			cout << "\tenter password: ";
		there:
			int i = 0;
			// Read characters until Enter (ASCII code 13) is pressed
			while ((u.ch = _getch()) != 13) {
				if (u.ch == '\b') {
					// Handle backspace
					if (i > 0) {
						std::cout << "\b \b"; // Move the cursor back, overwrite the character with space, move back again
						i--;
					}
				}
				else {
					// Handle other characters (excluding Enter and backspace)
					u.password[i++] = u.ch;
					cout << '*'; // Display a star for each character
				}
			}
			u.password[i] = '\0'; // Null-terminate the password string
			cout << endl;
			cout << endl;
			while (!file.eof()) {
				file.seekg(0);
				for (int i = 0; i < 5; i++) {
					getline(file, st[i]);
				}
				/*cout << u.password;
				cout << st[3];*/
				if (u.password == st[3]) {
					cout << "\n\t congratulations!!!" << "  login successfull\n";
					cout << "\n\tfirst name: " << st[0] << endl;
					cout << "\tlast name: " << st[1] << endl;
					cout << "\tcnic number: " << st[2] << endl;
					cout << "\tpassword: " << st[3] << endl;
					cout << "\tdeposit: " << st[4] << endl;

					for (int i = 0; i <= 56; i++)
					{
						cout << "-";
					}
					cout << endl;

				here:
					cout << "\n\tpress esc to exit \n" << "\t press 0 to return to menu\n";
					u.type = _getch();
					if (u.type == '0') {
						system("cls");
					}
					else if (u.type == 27) {
						exit(1);
					}
					else {
						cout << "invalid input!!!! . retry;\n";
						goto here;
					}
				}
				else {
					cout << "password incorrect.retry: ";
					goto there;
				}

			}
		}
	}
	else
	{
		cout << "invalid cnic!!. retry: ";
		goto herre;
	}

}

void user::deposit()
{
	user u;

	long long dep2;//local variables : cnic2 to store cnic entered for deposit & dep2 to store deposit amount 
	string pw, cnic2, st[5];//to store password

	cout << "  provide following details to deposit funds:\n";
	cout << "\tenter cnic: ";
	cin >> cnic2;

	ifstream ofile;
	ofile.open(cnic2 + ".txt");

	if (!ofile.is_open()) {
		cout << "\tdata not found\n";
	}
	else {
		cout << "\tenter password: ";
		int i = 0;
		// Read characters until Enter (ASCII code 13) is pressed
		while ((u.ch = _getch()) != 13) {
			if (u.ch == '\b') {
				// Handle backspace
				if (i > 0) {
					cout << "\b \b"; // Move the cursor back, overwrite the character with space, move back again
					i--;
				}
			}
			else {
				// Handle other characters (excluding Enter and backspace)
				u.password[i++] = u.ch;
				cout << '*'; // Display a star for each character
			}
		}
		u.password[i] = '\0'; // Null-terminate the password string
		cout << endl;
	there:
		cout << endl;
		while (!ofile.eof()) {
			for (int i = 0; i < 5; i++) {
				getline(ofile, st[i]);
			}
			if (u.password == st[3]) {
				cout << "\twelcome " << st[0] << " " << st[1] << endl;
				cout << "\tcurrent balance: " << st[4] << endl;
				char* ch = new char[5];
				strcpy_s(ch, sizeof(ch), st[4].c_str());
				u.dep = atoi(ch);
				break;
			}
			else {
				cout << "password incorrect.retry: ";
				goto there;
			}
		}
	}

	ofile.close();

	cout << "\tenter amount to deposit: ";
	cin >> dep2;
	u.dep += dep2;
	st[4] = to_string(u.dep);
	cout << "\n\t amount deposited successfully\n\n";
	cout << "\tnew balance: " << st[4] << endl;

	ofstream ifile;

	ifile.open(cnic2 + ".txt");
	ifile << st[0] << endl;
	ifile << st[1] << endl;
	ifile << st[2] << endl;
	ifile << st[3] << endl;
	ifile << st[4] << endl;
	ifile.close();

	for (int i = 0; i <= 56; i++)
	{
		cout << "-";
	}
	cout << endl;

here:
	cout << "\n\tpress esc to exit \n" << "\t press 0 to return to menu\n";
	u.type = _getch();
	if (u.type == '0') {
		system("cls");
	}
	else if (u.type == 27) {
		exit(1);
	}
	else {
		cout << "invalid input!!!! . retry;\n";
		goto here;
	}
}

void user::withdraw()
{
	user u;

	long long dep2;//local variables : cnic2 to store cnic entered for deposit & dep2 to store deposit amount 
	string pw, cnic2, st[5];//to store password

	cout << "  provide following details to withdraw funds:\n";
	cout << "\tenter cnic: ";
	cin >> cnic2;

	if (cnic2.length() == 13)
	{
		ifstream ofile;
		ofile.open(cnic2 + ".txt");

		if (!ofile.is_open()) {
			cout << "\tdata not found\n";
		}
		else {
			cout << "\tenter password: ";
			int i = 0;
			// Read characters until Enter (ASCII code 13) is pressed
			while ((u.ch = _getch()) != 13) {
				if (u.ch == '\b') {
					// Handle backspace
					if (i > 0) {
						cout << "\b \b"; // Move the cursor back, overwrite the character with space, move back again
						i--;
					}
				}
				else {
					// Handle other characters (excluding Enter and backspace)
					u.password[i++] = u.ch;
					cout << '*'; // Display a star for each character
				}
			}
			u.password[i] = '\0'; // Null-terminate the password string
			cout << endl;
		there:
			cout << endl;
			while (!ofile.eof()) {
				for (int i = 0; i < 5; i++) {
					getline(ofile, st[i]);
				}
				if (u.password == st[3]) {
					cout << "\twelconme " << st[0] << " " << st[1] << endl;
					cout << "\tcurrent balance: " << st[4] << endl;
					char* ch = new char[5];
					strcpy_s(ch, sizeof(ch), st[4].c_str());
					u.dep = atoi(ch);
					break;
				}
				else {
					cout << "password incorrect.retry: ";
					goto there;
				}
			}
		}
		ofile.close();

	}

	cout << "\tenter amount to withdraw: ";
	cin >> dep2;
	u.dep -= dep2;
	st[4] = to_string(u.dep);
	cout << "\n\n\t congratulations!!!" << "  amount wuthdrawn successfully\n";
	cout << "\tnew balance: " << st[4] << endl;

	ofstream ifile;
	ifile.open(cnic2 + ".txt");

	ifile << st[0] << endl;
	ifile << st[1] << endl;
	ifile << st[2] << endl;
	ifile << st[3] << endl;
	ifile << st[4] << endl;

	ifile.close();

	for (int i = 0; i <= 56; i++)
	{
		cout << "-";
	}
	cout << endl;

here:
	cout << "\n\tpress esc to exit \n" << "\t press 0 to return to menu\n";
	u.type = _getch();
	if (u.type == '0') {
		system("cls");
	}
	else if (u.type == 27) {
		exit(1);
	}
	else {
		cout << "invalid input!!!! . retry;\n";
		goto here;
	}
}

void user::transfer()
{
	user u;

	long long dep2, dep3;//local variables : cnic2 to store cnic entered for deposit & dep2 to store deposit amount 
	string pw, cnic2, cn, st[5], at[5], paw;
	char here, herre;

	cout << "  provide following details to deposit funds:\n";
	cout << "\tenter cnic: ";
here:
	cin >> cnic2;

	if (cnic2.length() == 13)
	{
		ifstream ofile;
		ofile.open(cnic2 + ".txt");

		if (!ofile.is_open()) {
			cout << "\tdata not found\n";
		}
		else {
			cout << "\tenter password: ";
		there:
			int i = 0;
			// Read characters until Enter (ASCII code 13) is pressed
			while ((u.ch = _getch()) != 13) {
				if (u.ch == '\b') {
					// Handle backspace
					if (i > 0) {
						cout << "\b \b"; // Move the cursor back, overwrite the character with space, move back again
						i--;
					}
				}
				else {
					// Handle other characters (excluding Enter and backspace)
					u.password[i++] = u.ch;
					cout << '*'; // Display a star for each character
				}
			}
			u.password[i] = '\0'; // Null-terminate the password string
			cout << endl;
			cout << endl;
			while (!ofile.eof()) {
				for (int i = 0; i < 5; i++) {
					getline(ofile, st[i]);
				}
			}
			ofile.close();

			if (pw == st[3]) {
				cout << "\twelcome " << st[0] << " " << st[1] << endl;
				cout << "\tcurrent balance: " << st[4] << endl;
				char* ch = new char[5];
				strcpy_s(ch, sizeof(ch), st[4].c_str());
				u.dep = atoi(ch);

				cout << "\tenter amount to transfer: ";
				cin >> dep2;
				u.dep -= dep2;
				st[4] = to_string(u.dep);
				cout << "enter cnic of reciever: ";
			here2:
				cin >> cn;
				if (cn != cnic && cn.length() == 13) {
					ifstream ofile2;
					ofile2.open(cn + ".txt");

					if (!ofile2.is_open())
					{
						cout << "\t error while finding the receiver!!! \n";
						cout << "\t retry : ";
						goto here2;
					}
					else
					{
						cout << endl;
						while (!ofile2.eof()) {
							for (int i = 0; i < 5; i++) {
								getline(ofile2, at[i]);
							}
						}

						ofile2.close();

						cout << "\t receiver name = " << at[0] << " " << at[1] << endl;
						cout << "\t re-enter password to continue: ";
					herre:
						cin >> paw;
						if (paw == u.password)
						{
							char* ch = new char[5];
							strcpy_s(ch, sizeof(ch), at[4].c_str());
							dep3 = atoi(ch);
							dep3 += dep2;

							at[4] = to_string(dep3);

							ofstream ifile;
							ifile.open(cnic2 + ".txt");

							ifile << st[0] << endl;
							ifile << st[1] << endl;
							ifile << st[2] << endl;
							ifile << st[3] << endl;
							ifile << st[4] << endl;

							ifile.close();

							ofstream ifile2;
							ifile2.open(cn + ".txt");

							ifile2 << at[0] << endl;
							ifile2 << at[1] << endl;
							ifile2 << at[2] << endl;
							ifile2 << at[3] << endl;
							ifile2 << at[4] << endl;

							ifile2.close();
						}
						else
						{
							cout << "\t password doesnot match!!! \n" << "\t retry : ";
							goto herre;
						}
					}
				}
				else {
					cout << "\n\t transaction failed due to invalid cnic\n" << "\t retry: ";
					goto here2;
				}
			}
			else
			{
				cout << "\t incorrect password!!! \n" << "\t retry : ";
				goto there;
			}


		}
	}
	else
	{
		cout << "\t invalid cnic!!! \n" << "\t retry : ";
		goto here;
	}
}

void user::balance()
{
	user u;

	long long dep2;//local variables : cnic2 to store cnic entered for deposit & dep2 to store deposit amount 
	string pw, cnic2, st[5];//to store password
	cout << "  provide following details to check balance:\n";
	cout << "\tenter cnic: ";
	cin >> cnic2;

	ifstream ofile;
	ofile.open(cnic2 + ".txt");

	if (!ofile.is_open()) {
		cout << "\tdata not found\n";
	}
	else {
		cout << "\tenter password: ";
		int i = 0;
		// Read characters until Enter (ASCII code 13) is pressed
		while ((u.ch = _getch()) != 13) {
			if (u.ch == '\b') {
				// Handle backspace
				if (i > 0) {
					cout << "\b \b"; // Move the cursor back, overwrite the character with space, move back again
					i--;
				}
			}
			else {
				// Handle other characters (excluding Enter and backspace)
				u.password[i++] = u.ch;
				cout << '*'; // Display a star for each character
			}
		}
		u.password[i] = '\0'; // Null-terminate the password string
		cout << endl;
	there:
		cout << endl;
		while (!ofile.eof()) {
			for (int i = 0; i < 5; i++) {
				getline(ofile, st[i]);
			}
			if (u.password == st[3]) {
				cout << "\twelcome " << st[0] << " " << st[1] << endl;
				cout << "\tcurrent balance: " << st[4] << endl;
				char* ch = new char[5];
				strcpy_s(ch, sizeof(ch), st[4].c_str());
				u.dep = atoi(ch);
				break;
			}
			else {
				cout << "password incorrect.retry: ";
				goto there;
			}
		}
	}

	ofile.close();
}