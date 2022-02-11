#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <time.h>


//nodes for service events (used by provider and member class)/
//provider class
struct service_node
{
    service_node();
    ~service_node();
    service_node * current;
    char * current_date;
    char * service_date;
    char * provider_number;
    char * member_number;
    char * service_code;
    char * comments;

};

class provider
{
    public:
        provider();
        ~provider();
        int create_provider(char * name, char * address, char * city, char * state, int * number, int * zip, int total_consults, int weekly_fee);
        int copy_provider(const provider & provider_to_copy);
        int retrieve_name(char * & name_to_ret);
        int display() const;
        int delete_all();
    private:
        char * name;
        char * address;
        char * city;
        char * state;
        int * number;
        int * zip;
        int total_consults;
        int weekly_fee;
        service_node * services; //LLL of services provider has provided
};


//nodes for BST	(used by providers and members class)
struct node
{
    node();
    ~node();
    node * left;
    node * right;
    provider current;
};

//BST providers class
class providers
{
        public:
                providers();
                ~providers();

                int delete_all();
                int delete_all(node * & root);

                int insert (provider & provider_to_insert);
                int insert (node * & root, provider & provider_to_insert);

                int retrieve (char * name_to_get, provider & provider_to_return);
                int retrieve(node * root, char * name, provider & provider_to_return);

                int display(char * prodiver_todisplay);
                int display(node * root, char * provider_todisplay);

                int remove(char * name_to_remove);
                int remove(node * & root, node * & prev, char * prodiver_to_remove);
                int remove(node * & root, char * prodiver_to_remove);

                int remove_provider(char * provider_to_remove);//, char * & found_match_name);
                int remove_provider(node * & root, char * provider_to_remove, char * & found_match_name);

                int height();
                int height(node * root);
        private:
                node * root;

};
