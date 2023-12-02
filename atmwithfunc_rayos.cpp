#include <iostream>
using namespace std;
//---functions---//
bool loginfunction(string username, string password)
{
	if (username == "Mysti" && password == "101263")
	{
		cout << "Account logged in!" << endl;
		return true;
	}
	cout << "[The username or the password does not match\n Please try again.]" <<
	endl << endl;
	return false;
}
void exitfunction()
{
	cout << "Thank you for using the S1mple ATM! have a wonderful rest of your day/night." << endl;
	exit(0);
}
void invalidfunction()
{
	cout << "You have entered an invalid input, please only press the numbers stated." << endl;
}
void mainmenufunction()
{
	cout << "-------------------------[Welcome to S1mple ATM! PRESS [1] to PROCEED and PRESS[2] to EXIT.]-------------------------- - " << endl;
}
int withdrawfunction(double balance)
{
	double withdraw = 0;
	cout << " withdraw Amount : $";
	cin >> withdraw;
	balance = balance - withdraw;
	cout << " You have withdrawn $" << withdraw << " from your account " << endl;
	return balance;
}
int depositfunction(double balance)
{
	double deposit = 0;
	cout << " Deposit Amount : $";
	cin >> deposit;
	balance = balance + deposit;
	cout << " You have deposited $" << deposit << " to your account " << endl;
	return balance;
}
//-----------------------------------------//
int main()
{
	//Declaration//
	system("Color 6");
	double balance, withdraw, deposit;
	balance = 1000;
	string username = "", password = "";
	int optionselect, optionselect2, optionselect3;
	bool loginverified = false;
	//start//
	mainmenufunction();
	do
	{
		cin >> optionselect;
		system("cls");
		switch (optionselect) //first switch//
		{
		case 1:
			cout << "[S1mple ATM]\n [Choose upon the following: ]\n [1] LOGIN\n [2] RETURN" << endl;
				do
				{
					cin >> optionselect2;
					system("cls");
					switch (optionselect2) //second switch//
					{
					case 1:
						do
						{
							cout << "[Type in the following credentials: ]\n [Username: ]\n[Password:]" << endl;
								cin >> username >> password;
							system("cls");
							loginverified = loginfunction(username, password);
						} while (!loginverified);
						cout << " Welcome " << username << "," << " what would you like	to do today ? " << endl;
							cout <<
							"==========================================================" << endl;
						cout << "" << endl;
						cout << "\n [1 ------ Balance]\n [2 ------ Withdraw]\n [3------Deposit]\n[4 ------Exit]\n" << endl;
							cin >> optionselect3;
						system("cls");
						while (optionselect3 != 4)
						{
							switch (optionselect3)//third switch//
							{
							case 1:
								cout << " Your current Balance is : $" << balance <<
									endl;
								break;
							case 2:
								balance = withdrawfunction(balance);
								break;
							case 3:
								balance = depositfunction(balance);
								break;
							default:
								invalidfunction();
								break;
							}
							cout << "[Enter another operation -]\n [1 ------ Balance]\n[2 ------Withdraw]\n[3 ------Deposit]\n[4 ------Exit]\n"; //loop of case
								cin >> optionselect3;
						}
						if (optionselect3 == 4)
						{
							exitfunction();
						}
						if (optionselect3 == 2)
						{
							exitfunction();
						}
						else
						{
							invalidfunction();
						}
						break;
					case 2:
						system("cls");
						return main();
					default:
						invalidfunction();
						optionselect = 0;
						break;
					}
				} while (optionselect != 1);
				break;
		case 2:
			exitfunction();
			break;
		default:
			invalidfunction();
			break;
		}
	} while (optionselect != 1);
}
