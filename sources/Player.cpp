#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"//check if have to
using namespace std;
namespace pandemic{
        Player::Player(Board board,City current_city){
            _board=board;
            _current_city-current_city;
        }
        // City Player::rand_city()
        // {
        //     return (City)rand()%board.NUMBER_OF_CITIES;
        // }
       Player & Player::take_card(City city)
       {
           cards.insert(city);
       }

        //movements options
        Player & Player::drive(City city){
            if(_board.are_cities_connected(_current_city,city))
            {
                _current_city=city;
            }
            else{
                throw invalid_argument{"Error. can't drive to an un connected city."};
            }
            return *this;

        }
        
        Player & Player::fly_direct(City city){
            return *this;

        }
        Player & Player::fly_charter(City city){
            return *this;

        }
        Player & Player::fly_shuttle(City city){
            return *this;

        }

        Player & Player::treat(City city){
            return *this;

        }



        Player & Player::discover_cure(Color color){
            return *this;            
        }
        Player & Player::build(){
            return *this;
        }

}