/**
 * Demo program for Pandemic exercise - OperationsExpert role
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-04
 */

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
enum    Players{
    dispatcher=1,field_doctor,gene_splicer,medic,operation_expert,researcher,scientist,virologist
};
enum    operations{
/*נסיעה - */ drive=1, 
/*טיסה ישירה - */fly_direct,
/*טיסת זכיון -*/ fly_charter, 
/*טיסת שאטל - */fly_shuttle, 
/*בנייה - */build ,
/*גילוי תרופה - בנייה - */discover_cure ,
/*טיפול במחלה -*/ treat,
take_card ,
show_board
};//also exist: role
int main() {
    const int exit=0;
	Board board;
    Player * player=NULL;
    int option=-1;
    int city=-1;
    int color=-1;
    while((bool)option)
    {
        cout<<"which player would you like to be? enter:\n0- exit\n1- dispatcher\n2- field_doctor\n";
        cout<<"3- gene_splicer\n4- medic\n5- operation_expert\n6- researcher\n7- scientist\n8- virologist\n";
        cin>>option;
        cout<<"which city would you like to start in? enter number between 0-47:\n";
        cin>>city;
        switch(option)
        {
            case exit:
                return 0;
            case dispatcher:
                player=new Dispatcher(board,(City)city);
                option=0;
                break;
            case field_doctor:
                player=new FieldDoctor(board,(City)city);
                option=0;
                break;
            case gene_splicer:
                player=new GeneSplicer(board,(City)city);
                option=0;
                break;
            case medic:
                player=new Medic(board,(City)city);
                option=0;
                break;
            case operation_expert:
                player=new OperationsExpert(board,(City)city);
                option=0;
                break;
            case researcher:
                player=new Researcher(board,(City)city);
                option=0;
                break;
            case scientist:
                player=new Scientist(board,(City)city,3);
                option=0;
                break;
            case virologist:
                player=new Virologist(board,(City)city);
                option=0;
                break;
            
            default:
                cout<<"there isn't such option, please enter another one.\n";
                break;

        }
    }
    option=-1;
    for (int i=0;i<NUMBER_OF_CITIES;i++)
    {
        board[(City)i]=3;
    }//start the game with 3 sickness cubes in each city
    while((bool)option)
    {
        
        cout<<"hello player "<<player->role()<<" in city: "<<(int)player->get_city()<<" ,"<<string_for_city(player->get_city())<<endl;
        cout<<"choose operation, enter:\n1- drive\n2- fly_direct\n3- fly_charter\n4- fly_shuttle"; 
        cout<<"\n5- build \n6- discover_cure\n7- treat\n8- take_card\n9- show_board\n0- exit\n";
        cin>>option;
        try{
            switch(option)
            {
                case drive:
                    cout<<"please enter city, enter number between 0-47:\n";
                    cin>>city;
                    player->drive((City)city);
                    break;
                case fly_direct:
                    cout<<"please enter city, enter number between 0-47:\n";
                    cin>>city;
                    player->fly_direct((City)city);
                    break;
                case fly_charter:
                    cout<<"please enter city, enter number between 0-47:\n";
                    cin>>city;
                    player->fly_charter((City)city);
                    break;
                case fly_shuttle:
                    cout<<"please enter city, enter number between 0-47:\n";
                    cin>>city;
                    player->fly_shuttle((City)city);
                    break;
                case build:
                    player->build();
                    break;
                case discover_cure:
                    cout<<"please enter color, enter number between 0-3:\n";
                    color=-1;
                    cin>>color;
                    player->discover_cure((Color)color);
                    break;
                case treat:
                    city=player->get_city();
                    if (player->role()=="Virologist")
                    {
                        cout<<"please enter city, enter number between 0-47:\n";
                        cin>>city;
                    }
                    player->treat(City(city));
                    break;
                case take_card:
                    cout<<"please enter city, enter number between 0-47:\n";
                    cin>>city;
                    player->take_card(City(city));
                    break;
                case show_board:
                    cout<<board;
                    break;
                case exit:
                    cout<<"you chose to end the game. hope you enjoyed!\n";
                    delete player;
                    return 0;
                default:
                    cout<<"there isn't such option, please enter another one.\n";
                    break;

            }
        }
        catch (const exception& ex) 
        {
	 	    cout << "----caught exception: " << ex.what() << "----"<<endl;  // prints a meaningful error message.
	    }
    }
    

}