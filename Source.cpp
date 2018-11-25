/*
Inhamul Hassan, HND Computing, Batch 75
ICBT Colombo City Campus
*/

#include <iostream>//standard input-output library
#include <string>//standard library containing string related functions
#include <conio.h>//
#include <time.h> //this is a standard library used to display time
#include <cwchar>//standard library for char related functions

using namespace std;

void Login();
void systemdatetime();
void AdminMenu();
void MainMenu();
void List_ProductOffers();
void Add_ProductOffers();
void Store_ProductOffers();
void Search_ProductOffers_Admin();
void Search_ProductOffers();
void HelpScreen();
void Billing();
void DisplayBill(string PrNameList, int Total);
void Exit();

struct Products {
	string ProductName;
	int ProductID;
	int Price;
	int Quantity;
}ProductArray[40]; //creating a struct to store all the information about the products

struct Offers {
	string OfferName;
	string OfferID;
	string Description;
}OfferArray[5]; //creating a struct to store all the information about different offers

void systemdatetime()//this function will be used to display the time as of running this program
{
	char date[26];
	time_t current = time(0);
	ctime_s(date, sizeof date, &current);
	cout << "   " << date << endl;
}

void main()
{
	Login();
}

void AdminMenu()
{
	system("CLS");
	// multiway selection
	int opt;

	cout << "\t __________________________________________________________________________________ " << endl;
	cout << "\t|                                Main Menu                                         |" << endl;
	cout << "\t|                               ***********                                        |" << endl;
	cout << "\t|                         1. Add Products & Offers                                 |" << endl;
	cout << "\t|                         2. Search Products & Offers                              |" << endl;
	cout << "\t|                         3. Logout                                                |" << endl;
	cout << "\t|                         4. Exit                                                  |" << endl;
	cout << "\t|__________________________________________________________________________________|" << endl;
	cout << "\t\t\t\tEnter Option : ";
	cin >> opt;

	switch (opt)
	{
	case 1:
		system("CLS");
		cout << "\t\t\tAdd New Products & Offers" << endl;
		Add_ProductOffers();
		break;

	case 2:
		system("CLS");
		cout << "\t\t\tSearch for Products & Offers";
		Search_ProductOffers_Admin();
		break;
	case 3:
		system("CLS");
		cout << "Logging out..." << endl;
		Login();
		break;
	case 4:
		system("CLS");
		cout << "You are exiting the system..." << endl;
		break;
	default:
		cout << "Please enter a correct option!" << endl;
		cout << "Accepted value are (1, 2, 3, 4)" << endl;
		cout << endl;
		system("PAUSE");
		AdminMenu();
		//break;
	}
	system("pause");
}

void MainMenu()
{
	system("CLS");
	system("color 0F");
	// multiway selection
	int opt;

	system("CLS");
	
	cout << "\t\t\t         @%@%@%@%@%@%@    " << endl;
	cout << "\t\t\t         { DELICOUS! }    " << endl;
	cout << "\t\t\t         {___CAKES___}    " << endl;
	cout << "\t\t\t      @%@%@%@%@%@%@%@%@%@ " << endl;
	cout << "\t\t\t      {                 } " << endl;
	cout << "\t\t\t      {  .............  } " << endl;
	cout << "\t\t\t      {_________________} " << endl;
	cout << "\t\t\t     @%@%@%@%@%@%@%@%@%@%@" << endl;
	cout << endl;


	cout << "\t\t\t ______________________________ " << endl;
	cout << "\t\t\t|          Main Menu           |" << endl;
	cout << "\t\t\t|         ***********          |" << endl;
	cout << "\t\t\t| 1. List Products & Offers    |" << endl;
	cout << "\t\t\t| 2. Search Products & Offers  |" << endl;
	cout << "\t\t\t| 3. Billing                   |" << endl;
	cout << "\t\t\t| 4. Help                      |" << endl;
	cout << "\t\t\t| 5. Exit                      |" << endl;
	cout << "\t\t\t|______________________________|" << endl;
	cout << "\t\t\t\tEnter Option : ";
	cin >> opt;

	switch (opt)
	{
	case 1:
		system("CLS");
		cout << "\t\t\tProducts & Offers" << endl;
		List_ProductOffers();
		break;

	case 2:
		cout << "\t\t\tSearch for Products & Offers";
		Search_ProductOffers();
		break;
	case 3:
		cout << "Billing";
		system("CLS");
		Billing();
		break;
	case 4:
		cout << "Help";
		system("CLS");
		HelpScreen();
		break;
	case 5:
		Exit();
		break;
	default:
		cout << "Please enter a correct option!" << endl;
		cout << "Accepted value are (1, 2, 3, 4, 5)" << endl;
		cout << endl;
		system("PAUSE");
		MainMenu();
		break;
	}
	system("pause");
}




void Login()
{
	system("CLS");
	systemdatetime();


	int c = 1;
	while (c <= 4)
	{
		string username = "user";
		string password = "pass";
		string admin = "admin";
		string adminpass = "apass";
		string user;

		cout << "\t\t\n\n\n";
		cout << "\t\tEnter Username - ";
		cin >> user;
		cout << "\n";
		cout << "\t\tEnter Password - ";

		char PassChar[16];
		int i = 0;
		char a;

		for (i = 0;;) //if user typed any alphanumeric character, the _getch() will store it as password
		{
			a = _getch();
			if ((a >= 'a'&&a <= 'z') || (a >= 'A'&&a <= 'Z') || (a >= '0'&&a <= '9')) {
				PassChar[i] = a;
				++i;
				cout << "#";
			}
			if ((a == '\b') && (i >= 1)) //if user typed a backspace and the number of characters are greater than 1
			{
				cout << "\b \b";
				i--;
			}
			if (a == '\r') //if user pressed enter, then break the loop
			{
				PassChar[i] = '\0';
				break;
			}
		}
		string pass(PassChar);


		if ((user == username) && (pass != password))
		{

			cout << "\n\t\t\t\tIncorrect Password" << endl;


			system("PAUSE"); // pauses the console window, and waits for a character input
			system("CLS"); // clears the console window
		}

		else if ((user == admin) && (pass != adminpass))
		{

			cout << "\n\t\t\t\tIncorrect Password" << endl;


			system("PAUSE"); // pauses the console window, and waits for a character input
			system("CLS"); // clears the console window
		}

		else if ((user != username) && (pass == password))
		{

			cout << "\n\t\t\t\tIncorrect Username" << endl;


			system("PAUSE");
			system("CLS");
		}

		else if ((user != admin) && (pass == adminpass))
		{

			cout << "\n\t\t\t\tIncorrect Username" << endl;

			system("PAUSE");
			system("CLS");
		}

		else if ((user == username) && (pass == password))
		{

			cout << "\n\t\t\t\tLogin Successful!" << endl;

			system("PAUSE");
			MainMenu();
			break;
		}

		else if ((user == admin) && (pass == adminpass))
		{
			cout << "\n\t\t\t\tLogin Successful!" << endl;

			system("PAUSE");
			AdminMenu();
			break;
		}

		else if ((user != username) && (pass != password) && (c != 4))
		{

			cout << endl;
			cout << "\t\t\t\tLogin Failed!, Try again..." << endl;

		
			system("PAUSE");
			system("CLS");
		}

		else if ((user != admin) && (pass != adminpass) && (c != 4))
		{
			
			cout << endl;
			cout << "\t\t\t\tLogin Failed!, Try again..." << endl;

			system("PAUSE");
			system("CLS");
		}

		if (c == 4)
		{
	
			cout << endl;
			cout << "\t\t\t\tLogin Failed!" << endl;

			cout << "\t\t\t\tPlease Contact the Help Desk for further information" << endl;

			system("PAUSE");
			system("CLS");
		}
		c++;
	}//end of while statement
}

void Store_ProductOffers()
{
	ProductArray[0].ProductName = "Rainbow Cake";
	ProductArray[0].ProductID = 108;
	ProductArray[0].Price = 300;
	ProductArray[0].Quantity = 14;

	ProductArray[1].ProductName = "Chocolate Cake";
	ProductArray[1].ProductID = 112;
	ProductArray[1].Price = 1250;
	ProductArray[1].Quantity = 11;

	ProductArray[2].ProductName = "Butter Cake";
	ProductArray[2].ProductID = 126;
	ProductArray[2].Price = 980;
	ProductArray[2].Quantity = 8;

	ProductArray[3].ProductName = "Date Cake";
	ProductArray[3].ProductID = 129;
	ProductArray[3].Price = 1200;
	ProductArray[3].Quantity = 6;

	ProductArray[4].ProductName = "Fruit Gateau";
	ProductArray[4].ProductID = 134;
	ProductArray[4].Price = 2900;
	ProductArray[4].Quantity = 3;

	ProductArray[5].ProductName = "Black Forest Gateau";
	ProductArray[5].ProductID = 135;
	ProductArray[5].Price = 3420;
	ProductArray[5].Quantity = 3;

	ProductArray[6].ProductName = "Chocolate Brownie";
	ProductArray[6].ProductID = 141;
	ProductArray[6].Price = 120;
	ProductArray[6].Quantity = 27;

	ProductArray[7].ProductName = "Chocolate Eclairs";
	ProductArray[7].ProductID = 145;
	ProductArray[7].Price = 60;
	ProductArray[7].Quantity = 16;

	ProductArray[8].ProductName = "Chocolate Doughnut";
	ProductArray[8].ProductID = 149;
	ProductArray[8].Price = 60;
	ProductArray[8].Quantity = 21;

	ProductArray[9].ProductName = "Cheese Cake";
	ProductArray[9].ProductID = 153;
	ProductArray[9].Price = 760;
	ProductArray[9].Quantity = 5;

	ProductArray[10].ProductName = "Coffee Cake";
	ProductArray[10].ProductID = 157;
	ProductArray[10].Price = 1420;
	ProductArray[10].Quantity = 2;

	ProductArray[11].ProductName = "Mini-Cupcakes";
	ProductArray[11].ProductID = 160;
	ProductArray[11].Price = 30;
	ProductArray[11].Quantity = 31;

	ProductArray[12].ProductName = "Fruitcake";
	ProductArray[12].ProductID = 172;
	ProductArray[12].Price = 1430;
	ProductArray[12].Quantity = 2;

	ProductArray[13].ProductName = "Ice Cream Cake";
	ProductArray[13].ProductID = 174;
	ProductArray[13].Price = 3500;
	ProductArray[13].Quantity = 3;

	ProductArray[14].ProductName = "Madeira Cake";
	ProductArray[14].ProductID = 176;
	ProductArray[14].Price = 830;
	ProductArray[14].Quantity = 9;

	ProductArray[15].ProductName = "Lemon Cake";
	ProductArray[15].ProductID = 181;
	ProductArray[15].Price = 1200;
	ProductArray[15].Quantity = 4;

	ProductArray[16].ProductName = "Ice Coffee";
	ProductArray[16].ProductID = 101;
	ProductArray[16].Price = 60;
	ProductArray[16].Quantity = 24;

	ProductArray[17].ProductName = "Lemon Juice";
	ProductArray[17].ProductID = 103;
	ProductArray[17].Price = 40;
	ProductArray[17].Quantity = 21;

	ProductArray[18].ProductName = "Orange Juice";
	ProductArray[18].ProductID = 105;
	ProductArray[18].Price = 40;
	ProductArray[18].Quantity = 14;

	ProductArray[19].ProductName = "Americano";
	ProductArray[19].ProductID = 106;
	ProductArray[19].Price = 120;
	ProductArray[19].Quantity = 11;

	ProductArray[20].ProductName = "Espresso";
	ProductArray[20].ProductID = 109;
	ProductArray[20].Price = 130;
	ProductArray[20].Quantity = 8;

	ProductArray[21].ProductName = "Garlic Bread";
	ProductArray[21].ProductID = 110;
	ProductArray[21].Price = 80;
	ProductArray[21].Quantity = 12;

	ProductArray[22].ProductName = "Cumin Bread";
	ProductArray[22].ProductID = 113;
	ProductArray[22].Price = 95;
	ProductArray[22].Quantity = 8;

	ProductArray[23].ProductName = "Whole Wheat Bread";
	ProductArray[23].ProductID = 115;
	ProductArray[23].Price = 110;
	ProductArray[23].Quantity = 35;

	ProductArray[24].ProductName = "Chocolate Cookies";
	ProductArray[24].ProductID = 116;
	ProductArray[24].Price = 20;
	ProductArray[24].Quantity = 26;

	ProductArray[25].ProductName = "Creamy Cookies";
	ProductArray[25].ProductID = 117;
	ProductArray[25].Price = 24;
	ProductArray[25].Quantity = 25;

	ProductArray[26].ProductName = "Marshmellow Cookies";
	ProductArray[26].ProductID = 118;
	ProductArray[26].Price = 25;
	ProductArray[26].Quantity = 20;

	ProductArray[27].ProductName = "Chocolate Chip Cookies";
	ProductArray[27].ProductID = 119;
	ProductArray[27].Price = 30;
	ProductArray[27].Quantity = 25;

	ProductArray[28].ProductName = "White Chocolate Pudding";
	ProductArray[28].ProductID = 121;
	ProductArray[28].Price = 60;
	ProductArray[28].Quantity = 12;

	ProductArray[29].ProductName = "Strawberry Truffle";
	ProductArray[29].ProductID = 122;
	ProductArray[29].Price = 75;
	ProductArray[29].Quantity = 15;

	ProductArray[30].ProductName = "Blueberry Pancake";
	ProductArray[30].ProductID = 124;
	ProductArray[30].Price = 70;
	ProductArray[30].Quantity = 12;


	OfferArray[0].OfferName = "Get 20% discount";
	OfferArray[0].OfferID = "001";
	OfferArray[0].Description = "Get 20% discount from the total bill, if you purchase for more than LKR 6500";

	OfferArray[1].OfferName = "Buy 3, Get 1";
	OfferArray[1].OfferID = "002";
	OfferArray[1].Description = "Buy 3 Chocolate Brownies and get 1 more for free.";

	OfferArray[2].OfferName = "Get 5% discount";
	OfferArray[2].OfferID = "003";
	OfferArray[2].Description = "Get 5% discount from the total bill, if you purchase for more than LKR 3000";
}

void Add_ProductOffers()
{
	char option;
START:
	cout << "Do you want to add a new Product or Offer ?" << endl;
	cout << "Press [P/p] to add a new Product, or press [O/o] to add a new Offer, \nand press [X/x] to exit to the Main Menu - ";
	option = _getch();
	cout << endl;
	if (option == 'O' || option == 'o')
	{
		for (int i = 3;i <= 6;i++)
		{
			cout << "\nEnter the Offer details below" << endl;
			cout << "Offer ID : ";
			cin >> OfferArray[i].OfferID;
			cout << "Name : ";
			cin.ignore();
			getline(cin, OfferArray[i].OfferName);
			cout << "Description : ";
			getline(cin, OfferArray[i].Description);
			cout << "Offer ID : " << OfferArray[i].OfferID << "\t" << "Name : " << OfferArray[i].OfferName << endl;
			cout << "Description : " << OfferArray[i].Description << endl;
			cout << "Press any key to continue, or press [N/n] to stop : ";
			option = _getch();
			if (option == 'N' || option == 'n')
			{
				system("CLS");
				goto START;
			}
		} //end for
	}//end if

	else if (option == 'P' || option == 'p')
	{
		for (int i = 31;i <= 40;i++)
		{
			cout << "\nEnter the details below" << endl;
			cout << "Product ID : ";
			cin >> ProductArray[i].ProductID;
			cout << "Name : ";
			cin.ignore();
			getline(cin, ProductArray[i].ProductName);
			cout << "Price : ";
			cin >> ProductArray[i].Price;
			cout << "Available Quantity : ";
			cin >> ProductArray[i].Quantity;
			cout << "Product ID : " << ProductArray[i].ProductID << "\t" << "Name : " << ProductArray[i].ProductName << endl;
			cout << "Price : " << ProductArray[i].Price << "\t" << "Available Quantity : " << ProductArray[i].Quantity << endl;
			cout << "Press any key to continue, or press [N/n] to stop : ";
			option = _getch();
			if (option == 'N' || option == 'n')
			{
				system("CLS");
				goto START;
			}
		}//end for
	}//end if

	else if (option == 'X' || option == 'x')
	{
		cout << "Exiting to the Main Menu..." << endl;
		AdminMenu();
	}
}

void Search_ProductOffers()
{
	Store_ProductOffers();
	system("CLS");
	string matchString;

	cout << "Search for a Product, by either entering the Product ID or by typing \nin the Product Name (Product Name search is case-sensitive)\nSearch for an Offer by entering the Offer ID\nPress [M/m] to exit the Main Menu." << endl;
START: //defining a START label, in order to create a loop within the search menu
	string found = "false"; //a string value to display an error message if the entered search value is wrong
	cout << "\nSearch - ";
	cin >> matchString;


	if (matchString == "M" || matchString == "m")
	{
		found = "true";
		MainMenu();
		exit(0);
	}

	for (int x = 0; x < 31; x++) //for loop in order to loop through the array to find the correct serach reference 
	{
		if (ProductArray[x].ProductName.find(matchString, 0) != std::string::npos) //if the matchstring value matches the product name
		{
			cout << "Product ID - " << ProductArray[x].ProductID << "\tName - " << ProductArray[x].ProductName << endl;
			found = "true";//this value tells the program that the search criteria returned a correct value
		}

		string ID = to_string(ProductArray[x].ProductID); //converting the Product ID (which is an integer) using to_string, into a string in order to use string.find 

		if (ID.find(matchString, 0) != std::string::npos)
		{
			cout << "Product ID - " << ProductArray[x].ProductID << "\tName - " << ProductArray[x].ProductName << endl;
			found = "true";
		}

	} //end for loop

	for (int i = 0; i < 3; i++)
	{
		if (matchString == OfferArray[i].OfferID) //seraching the array to find the value that matches the entered value
		{
			cout << "Offer ID - " << OfferArray[i].OfferID << "\t " << OfferArray[i].OfferName << endl;
			cout << "Description - " << OfferArray[i].Description << "\n" << endl;
			found = "true";
		}
	}//end for


	if (found == "false")//this error message will be displayed if the search criteria is wrong
	{
		cout << "Please enter a valid search criteria.\nThe accepted values are Product Name, Product ID and Offer ID." << endl;
		goto START;
	}


	else
	{
		cout << "\n" << endl;
		goto START;
	}

}//end function Search_ProductOffers




void Search_ProductOffers_Admin()
{
	Store_ProductOffers();
	system("CLS");
	string matchString;

	cout << "Search for a Product, by either entering the Product ID or by typing \nin the Product Name (Product Name search is case-sensitive)\nSearch for an Offer by entering the Offer ID\nPress [M/m] to exit the Main Menu." << endl;
START: //defining a START label, in order to create a loop within the search menu
	string found = "false"; //a string value to display an error message if the entered search value is wrong
	cout << "\nSearch - ";
	cin >> matchString;

	if (matchString == "M" || matchString == "m")
	{
		found = "true";
		AdminMenu();
		exit(0);
	}

	for (int x = 0; x < 31; x++) //for loop in order to loop through the array to find the correct serach reference 
	{
		if (ProductArray[x].ProductName.find(matchString, 0) != std::string::npos) //if the matchstring value matches the product name
		{
			cout << "Product ID - " << ProductArray[x].ProductID << "\tName - " << ProductArray[x].ProductName << endl;
			found = "true";//this value tells the program that the search criteria returned a correct value
		}

		string ID = to_string(ProductArray[x].ProductID); //converting the Product ID (which is an integer) using to_string, into a string in order to use string.find 

		if (ID.find(matchString, 0) != std::string::npos)
		{
			cout << "Product ID - " << ProductArray[x].ProductID << "\tName - " << ProductArray[x].ProductName << endl;
			found = "true";
		}

	} //end for loop

	for (int i = 0; i < 3; i++)
	{
		if (matchString == OfferArray[i].OfferID) //seraching the array to find the value that matches the entered value
		{
			cout << "Offer ID - " << OfferArray[i].OfferID << "\t " << OfferArray[i].OfferName << endl;
			cout << "Description - " << OfferArray[i].Description << "\n" << endl;
			found = "true";
		}
	}//end for


	if (found == "false")//this error message will be displayed if the search criteria is wrong
	{
		cout << "Please enter a valid search criteria.\nThe accepted values are Product Name, Product ID and Offer ID." << endl;
		goto START;
	}


	else
	{
		cout << "\n" << endl;
		goto START;
	}

}//end function Search_ProductOffers


void List_ProductOffers()
{
	Store_ProductOffers();

	cout << "\nProducts\n" << endl;
	cout << endl;

	for (int c = 0;c < 32;c++)
	{
		cout << ProductArray[c].ProductID << " - " << ProductArray[c].ProductName << endl;
		cout << "\t\t\t\tLKR " << ProductArray[c].Price;
		if (ProductArray[c].Price>1000) { cout << "\tStocks Available " << ProductArray[c].Quantity << endl; }
		if (ProductArray[c].Price<1000) { cout << "\t\tStocks Available " << ProductArray[c].Quantity << endl; }
	}

	cout << "\n\n\nOffers\n\n" << endl;

	for (int c = 0;c < 4;c++)
	{
		cout << OfferArray[c].OfferID << " - " << OfferArray[c].OfferName << endl;
		cout << "\t\t\t" << OfferArray[c].Description << endl;
	}

	string letter;
	cout << "\nPress M to go to the Main Menu.\nPress X to exit the system." << endl;
	cin >> letter;
	if (letter == "m" || letter == "M") { MainMenu(); }
	else if (letter == "x" || letter == "X") { Exit(); }
}

void Exit()
{
START: //creating a label point
	char exit;
	cout << "Do you want to exit the program (press 'n' to return to the main menu)? y/n:";
	cin >> exit;
	if (exit == 'Y' || exit == 'y') {
		cout << "You are exiting the system..." << endl;
	}
	else if (exit == 'N' || exit == 'n') {
		MainMenu();
	}
	else {
		cout << "Please provide a correct value. Press 'y'to exit the system, press 'n' to return back to the main menu." << endl;
		goto START; //telling the program to go to the labelling point called START
	}
}

void HelpScreen()
{
	system("color F0");

	cout << "\nWelcome to the Help Screen\n";
	cout << "The Main Menu screen has 5 options : " << endl;
	cout << "1. List Products & Offers" << endl;
	cout << "\t\tThis window displays all the Products and Offers currently available in the bakery. All the Product\n"
		<< "\t\tdetails are outlined here (Product ID, Product Name, Product Price and the number of stocks available).\n"
		<< "\t\tThis window also shows the current offers available at the Bakery, the details include (Offer ID, \n"
		<< "\t\tOffer Name, Description of the Offer). The user will then be prompted to type a command, typing [M/m]\n"
		<< "\t\twill redirect the user to the Main Menu and typing [X/x] will initialize the system termination.\n" << endl;

	cout << "2. Search Products & Offers" << endl;
	cout << "\t\tThis option would allow the user to search for information about the Products and Offers offered at\n"
		<< "\t\tDelicous Bakers. In order to complete a succesfull search query and get the desired search results,\n"
		<< "\t\tensure that you type in the correct values without any spelling errors. The accepted search values\n"
		<< "\t\tto search for products are Product ID and Product Name.\n"
		<< "\t\tProduct ID : A numeric value with three integers (the first integer value being '1' in all the IDs).\n"
		<< "\t\t\t\tEx : '126', '157', '176'. \n"
		<< "\t\tProduct Name : An alphabetic value that stores the product's name, in order for the user to identify\n"
		<< "\t\tit properly. The user is required to enter the first few letters of the product's name, in order for\n"
		<< "\t\tthe search query to succesfully identify and display the most relevant product's Product Details.\n"
		<< "\t\tThe search query is case-sensitive.\n"
		<< "\t\t\t\tEx : If you want to search for a product called 'Butter Cake', then the search query\n"
		<< "\t\t\t\t     should be 'Butter' or try typing in the first few letters of the\n";
	cout << "\t\t\t\t     the name (such as 'Bu', 'But' or 'Butte').\n"
		<< "\t\tIn order to search for the available offers, the accepted search value is the Offer ID. \n"
		<< "\t\tOffer ID : A numeric value with three integers (the first two integer values being '0' in all the IDs).\n"
		<< "\t\t\t\tEx : '001', '002', '003'\n" << endl;

	cout << "3. Billing" << endl;
	cout << "\t\tThis window allows the user to buy the products, and initiates the billing process. All you have to\n"
		<< "\t\tdo is type in the Product ID of the product you wish to buy, followed by the quantity you wish to buy.\n"
		<< "\t\tThis two step procedure would add that product to your cart, then you can follow the same procedure\n"
		<< "\t\tto add the next product to your cart. In order to print the total bill information on to the screen,\n"
		<< "\t\tyou have to press [N/n], ending the Checkout process. The system would automatically add up the total,\n"
		<< "\t\tand would apply the appropriate discounts (5% for purchases above LKR 3000, 20% for purchases above\n"
		<< "\t\tLKR 6500). The bill would then be printed onto the screen." << endl;
	cout << "\n" << endl;

	cout << "4. Help" << endl;
	cout << "\t\tThis is the window you are currently in, this is the Help window.\n" << endl;

	cout << "5. Exit" << endl;
	cout << "\t\tThis option is the exit option. Upon choosing this you will be exited from the system\n"
		<< "\t\tand the program terminates." << endl;

	string letter;
	cout << "\nPress M to go to the Main Menu.\nPress X to exit the system." << endl;
	cin >> letter;
	if (letter == "m" || letter == "M")
	{
		MainMenu();
	}

	else if (letter == "x" || letter == "X")
	{
		Exit();
	}
}

void Billing()
{
	Store_ProductOffers();

	string PID; //used to read the Product ID entered by the user
	string PrNameList; //This string will be used to list all the purchased item in the final bill.
	int Quantity; //used to read the quantity of the products that the user wishes to buy
	int Offer002 = 0; //will be used to check whether the customer is eligible for offer 002
	int Total = 0; //a value that adds on the product's price to produce a total




	int Stocks; //a value used to track the amount of product stocks available currently
	system("CLS");
	cout << "Enter the Product ID, followed by the item quantity to add the item/s to the Checkout List : " << endl;
	cout << "Press [N/n] to checkout the item/s and produce the total bill.\n\n";


	while (1) //creates an infinite while loop till there is a break inside the loop
	{
	START:
		string found = "false";
		cout << " - ";
		cin >> PID;
		if (PID == "N" || PID == "n")
		{
			DisplayBill(PrNameList, Total);
			break; //break the loop and exit
		}

		for (int i = 0; i < 31; i++)
		{
			string ID = to_string(ProductArray[i].ProductID); //converting the Product ID (which is an integer) using to_string, into a string in order for the cin to identify it
			if (PID == ID)
			{
				found = "true";
				cout << "Total Stocks of " << ProductArray[i].ProductName << " available : " << ProductArray[i].Quantity << endl;
			}
		}//end for


		if (found == "false")//checking whether the entered ID is correct
		{
			cout << "Invalid Product ID, please provide a valid ID" << endl;
			cout << endl;
			goto START;
		}

		cout << "Quantity - ";
		cin >> Quantity;

		for (int i = 0; i < 31; i++)
		{
			string ID = to_string(ProductArray[i].ProductID); //converting the Product ID (which is an integer) using to_string, into a string in order for the cin to identify it
			if (PID == ID)
			{
				cout << "Item : " << ProductArray[i].ProductName << " added to the Checkout List." << endl;
				Total = Total + (ProductArray[i].Price * Quantity); //adding the product's price to the total
				cout << "Gross Total : LKR " << Total << endl;
				ProductArray[i].Quantity = ProductArray[i].Quantity - Quantity; //reducing the product's available stocks value, in order to track the product quantity that is available at the bakery
				Stocks = ProductArray[i].Quantity;
				cout << "Stocks left : " << Stocks << endl;

				string Qty = to_string(Quantity); //converting the Quantity (which is an integer) using to_string, into a string in order to include in the PrNameList so that the bought quantity can be displayed in the bill
				PrNameList = PrNameList + "   " + ProductArray[i].ProductName + " \t" + Qty + " pcs\n";

				if ((ID == "141") && (Quantity >= 3))
				{
					Offer002 = 1;
					ProductArray[6].Quantity = ProductArray[6].Quantity - 1;
					cout << "You get an extra Chocolate Brownie with your purchase of three Chocolate Brownies" << endl;
				}
				cout << "\n" << endl;
			}
		}//end for

		goto START; //this would result in an endless loop, until [N/n] is pressed

	}//end while
}//end function Billing

void DisplayBill(string PrNameList, int Total)
{
	system("CLS");
	system("color 0B");
	cout << " _______________________________________________" << endl;
	cout << "|\t   DELICIOUS CAKES" << endl;
	systemdatetime();
	cout << "   Items Purchased :\n" << PrNameList << endl;

	if ((Total >= 3000) && (Total <6500))
	{
		Total = (Total - (Total * 0.05));
		cout << "\tTotal (with 5% Discount) : LKR " << Total << endl;
	}
	else if (Total >= 6500)
	{
		Total = (Total - (Total * 0.2));
		cout << "\tTotal (with 20% Discount) : LKR " << Total << endl;
	}

	else
	{
		cout << "\tTotal : LKR " << Total << endl;
	}

	cout << "_______________________________________________|" << endl;
	cout << "\n" << endl;

	string letter;
	cout << "\nPress M to go to the Main Menu.\nPress X to exit the system." << endl;
	cin >> letter;
	if (letter == "m" || letter == "M") { MainMenu(); }
	else if (letter == "x" || letter == "X") { Exit(); }
}