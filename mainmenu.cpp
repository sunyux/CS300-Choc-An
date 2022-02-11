#include "providers.h"
#include "members.h"
using namespace std;

//Ethan Saftler, Ryan Tran, Cristian Torres Salazar, Matthew Marcellinus, Yuxin Sun, Chentao Ma

//CS300 Term Project 



int main()
{
	//variables
	char selection = '0';
	char quit = 'a';

	//welcome message
	cout << "\n\nWelcome to the CS202 Contact and Device Manager\nCreated by Ethan Saftler\n\n\n";

	//while loop for main menu using switch statement for selection
	while (selection != '9')
	{
		cout << endl << endl;
		cout << "Chocoholics Anonymous Manager Terminal\n\n";
		cout << "*** Main Menu *** \n";
		cout << "(Make a selection)\n";
		cout << "	1 - Slide new member number (select member)\n";
		cout << "	2 - Bill ChocAn for currently selected member (add service)\n";
		cout << "	3 - Request Provider Directory\n";
		cout << "	4 - Run weekly report\n";
		cout << "	5 - Add Member\n";
		cout << "	6 - Delete Member\n"
		cout << "	7 - Add Provider\n";
		cout << "	8 - Exit\n ";

		cin >> selection;
		cin.ignore(100, '\n');
		switch(selection)
		{
			case '1':
				//insert case for adding new member here
				break;
			case '2':
				//insert case for adding a service here
				break;
			case '3':	
				//insert case for adding a service here
				break;
			case '4':	
				//insert case for adding a service here
				break;
			case '5':
				//insert case for adding a service here
				break;
			case '6':
				//insert case for adding a service here
				break;
			case '7':
				//insert case for adding a service here
				break;
			case '8':		
				cout << endl << "Are you sure you would like to quit?" << endl;
				cout << "Enter 'Y' to quit or any other key to return to the main menu." << endl;
				cin >> quit;
				cin.ignore(100, '\n');
				if ( quit == 'Y' || quit == 'y' )
				{
					selection = '9';
				}
				break;
			case '9':
				cerr << "Invalid response.";
				selection = '0';
				break;
			default:
				cerr << "Invalid response.";
				break;
		}


	}




	return 0;
}






		
