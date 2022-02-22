#include "members.h"
using namespace std;

//Ethan Saftler, Ryan Tran, Cristian Torres Salazar, Matthew Marcellinus, Yuxin Sun, Chentao Ma

//CS300 Term Project 



int main()
{
	//variables
	char selection = '0';
	char quit = 'a';
	provider * temp_provider = new provider;
	provider * temp_provider2 = new provider;
	provider * temp_provider3 = new provider;
	providers * temp_providers = new providers;
	char temp_numb[NUMBERSIZE];

	//welcome message
	cout << "\n\nWelcome to the CS202 Contact and Device Manager\nCreated by Ethan Saftler\n\n\n";

	//while loop for main menu using switch statement for selection
	while (selection != '9')
	{
		cout << endl << endl;
		cout << "Chocoholics Anonymous Manager Terminal\n\n";
		cout << "*** Main Menu *** \n";
		cout << "(Make a selection)\n";
		cout << "	1 - Select member by number (Slide member card)\n";
		cout << "	2 - Add service for selected member (Bill ChocAn)\n";
		cout << "	3 - Request Provider Directory\n";
		cout << "	4 - Run weekly report\n";
		cout << "	5 - Add Member\n";
		cout << "	6 - Delete Member\n";
		cout << "	7 - Add Provider\n";
		cout << "	8 - Exit\n ";

		cin >> selection;
		cin.ignore(100, '\n');
		switch(selection)
		{
			case '1':
				//insert case for adding new member here
				//TODO - select current member 
				break;
			case '2':
				//TODO - add service
				break;
			case '3':	
				//TODO - uptdate to display entire providers class
				cout << "enter provider number to display";
				cin.get(temp_numb, NUMBERSIZE, '\n');
				cin.ignore(100, '\n');
				temp_providers->display(temp_numb);
				break;
			case '4':	
				//TODO - display weekly report
				break;
			case '5':
				//TODO - add member
				break;
			case '6':
				//TODO - delete member
				break;
			case '7':
				//TODO - update to providers class
				temp_provider->create();
				temp_providers->insert(*temp_provider);
				temp_provider2->create();
				temp_providers->insert(*temp_provider2);
				temp_provider3->create();
				temp_providers->insert(*temp_provider3);
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






		
