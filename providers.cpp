#include "providers.h"
using namespace std;

//check if array of chars is digits
bool check_if_digit(char * to_check)
{
    int i = 0;
    int len = strlen(to_check);
    while (i <= len)
    {
        if (isdigit(to_check[i]) == false) return false;
        i++;
    }
    return true;
}

//check if array of chars is letters
bool check_if_letter(char * to_check)
{
    int i = 0;
    int len = strlen(to_check);
    while (i <= len)
    {
        if (isdigit(to_check[i]) == false) return false;
        i++;
    }
    return true;
}

void uppercaser(char * to_upper)
{
    int i = 0;
    int len = strlen(to_upper);
    while (i < len){
        to_upper[i] = toupper(to_upper[i]);
        i++;
    }
    return;
}

service_node::service_node()
{
    next = NULL;
}
service_node::~service_node()
{
    next = NULL;
}

provider::provider()
{
    name = NULL;
    address = NULL;
    city = NULL;
    state = NULL;
    number = NULL;
    zip = NULL;
    total_consults = 0;
    weekly_fee = 0;
    services = NULL;
}

provider::~provider()
{
    delete name;
    delete address;
    delete city;
    delete state;
    delete number;
    delete zip;
    delete services;
    services = NULL;
}

int provider::create()
{
    char temp_name[NAMESIZE];
    char temp_number[NUMBERSIZE];
    char temp_address[ADDRESSSIZE];
    char temp_city[CITYSIZE];
    char temp_state[STATESIZE];
    char temp_zip[ZIPSIZE];
    cout << "\n\nPlease enter the provider information below\n";
    cout << "name: ";
    cin.get(temp_name, NAMESIZE, '\n');
    cin.ignore(100, '\n');
    cout << "number (9digit): ";
    cin.get(temp_number, NUMBERSIZE, '\n');
    cin.ignore(100, '\n');
    cout << "address: ";
    cin.get(temp_address, ADDRESSSIZE, '\n');
    cin.ignore(100, '\n');
    cout << "city: ";
    cin.get(temp_city, CITYSIZE, '\n');
    cin.ignore(100, '\n');
    cout << "state: ";
    cin.get(temp_state, STATESIZE, '\n');
    cin.ignore(100, '\n');
    cout << "zip: ";
    cin.get(temp_zip, ZIPSIZE, '\n');
    cin.ignore(100, '\n');
    name = new char[strlen(temp_name)+1];
    strcpy(name, temp_name);
    number = new char[strlen(temp_number)+1];
    strcpy(number, temp_number);
    address = new char[strlen(temp_address)+1];
    strcpy(address, temp_address);
    city = new char[strlen(temp_city)+1];
    strcpy(city, temp_city);
    state = new char[strlen(temp_state)+1];
    strcpy(state, temp_state);
    uppercaser(state);
    zip = new char[strlen(temp_zip)+1];
    strcpy(zip, temp_zip);
    return 0;

}

//copies input to current provider
int provider::copy_provider(const provider & to_copy)
{
    name = new char[strlen(to_copy.name)+1];
    address = new char[strlen(to_copy.address)+1];
    city = new char[strlen(to_copy.city)+1];
    state = new char[strlen(to_copy.state)+1];
    zip = new char[strlen(to_copy.zip)+1];
    number = new char[strlen(to_copy.number)+1];
    strcpy(name, to_copy.name);
    strcpy(address, to_copy.address);
    strcpy(city, to_copy.city);
    strcpy(state, to_copy.state);
    strcpy(zip, to_copy.zip);
    strcpy(number, to_copy.number);
    //TODO add copy services function
    if (to_copy.services == NULL){
        services = NULL;
    }else{
    //services = to_copy.services;
    }
    return 0;
}

//display current provider and all service events
int provider::display() const{
    cout << "\n\nProvider name: " << name << endl;
    cout << "Provider address: " << address << "\n\t\t" << city << ", " << state << " " << zip << endl;
    cout << "Total consults: " << total_consults << endl;
    cout << "Weekly fee: " << weekly_fee << endl;
    cout << "Service Record:";
    service_node * cur = services;
    int i = 1;
    while (cur != NULL)
    {
        cout << "\n" << i << ".";
        cout << "\nService date: " << cur->service_date;
        cout << "\nTime of entry: " << cur->current_date;
        cout << "\nProvider number: " << cur->provider_number;
        cout << "\nMember number: " << cur->member_number;
        cout << "\nService code: " << cur->service_code;
        i++;
        cur = cur->next;
    }
    return 0;
}

//each object member as an associated prime number.
//function returns the associated prime number if the input is bad.
//take the mod of the returned value and check against associated prime number to see fail state 
//display set to true by default
int provider::check_format(bool display)
{
    int i = 1;
    if (name != NULL){
        if (check_if_letter(this->name) == false){
            i *= 3;
        }
    }
    if (address != NULL){
        if (check_if_letter(this->address) == false){
            i *= 5;
        }
    }
    if (city != NULL){
        if (check_if_letter(this->city) == false){
            i *= 7;
        }
    }
    if (state != NULL){
        if (check_if_letter(this->state) == false){
            i *= 11;
        }
    }
    if (zip != NULL){
        if (check_if_digit(this->zip) == false){
            i *= 13;
        }
    }
    if (display == true){
        display_invalidity(i);
    }
    return i;
}

//displayed associated error code. use in tandem with check_format
void display_invalidity(int check)
{
    int temp = 0;
    if (check == 0){
        return;
    }else{
        temp = (check % 3);
        if (temp == 0) cerr << "\ninvalid name. ";
        temp = (check % 5);
        if (temp == 0) cerr << "\ninvalid address. ";
        temp = (check % 7);
        if (temp == 0) cerr << "\ninvalid city. ";
        temp = (check % 11);
        if (temp == 0) cerr << "\ninvalid state. ";
        temp = (check % 13);
        if (temp == 0) cerr << "\ninvalid zip. ";
    }
}