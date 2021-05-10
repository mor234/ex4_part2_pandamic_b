#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"//check if have to
using namespace std;
namespace pandemic{
        Player::Player(Board board,City current_city){
            _board=board;
            _current_city-current_city;
        }
        bool Player::has_card(City city)
        {
            return cards.find(city)!=cards.end();
        }
        void Player::throw_card(City city)
        {
            cards.erase(city);
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
            if(has_card(city)){
                throw_card(city);
                _current_city=city;
            }
            else{
                throw invalid_argument{"Error. can't fly directly to a city without maching card."};
            }
            return *this;
        }
        Player & Player::fly_charter(City city){
            if(has_card(_current_city)){
                throw_card(_current_city);
                _current_city=city;
            }
            else{
                throw invalid_argument{"Error. can't fly charter from a city without maching card."};
            }
            return *this;
        }
        Player & Player::fly_shuttle(City city){
            //if the destination city doesn't have study station 
            if(!board.has_study_station(_current_city))
            {
                throw invalid_argument{"Error. can't fly shuttle from a city without study station."};
            }
            //if the destination city doesn't have study station 
            else if(!board.has_study_station(city))
            {
                throw invalid_argument{"Error. can't fly shuttle to a city without study station."};
            }
            else//both has study stations
            {
                _current_city=city;
            }
            return *this;
        }

        Player & Player::treat(City city){
            return *this;

        }


        bool Player::has_5_color_cards(Color color)
        {
            int counter=0;
            for(card::cards)
            {
                if(_board.color_for_city(card)==color)
                {
                    counter++;
                }
            }
            return counter>=CARDS_FOR_CURE;
        }
        void Player::throw_5_color_cards(Color color)
        {
            int counter=CARDS_FOR_CURE;
            for(int i=0;i<cards.size();i++)
            {
                if(_board.color_for_city(cards[i])==color)
                {
                    throw_card(cards[i]);
                    counter--;
                    if(counter==0)
                    {
                        break;
                    }
                }
            }
        }
        Player & Player::discover_cure(Color color){
            if(_board.has_study_station(_current_city)
            {
                \            &&!_board.cure_for_color(color))

                if(has_5_color_cards(color)){
                    throw_5_color_cards(color);
                    _board.cure_for_color(color)=true;
                }
                else{
                    throw invalid_argument{"Error. can't discover cures without enough cards in the maching color"};
                }

            }
            else{
                throw invalid_argument{"Error. can't discover cures without study station in the city"};
  
            }
            
            return *this;            
        }
        Player & Player::build(){
            if(has_card(_current_city))
            {    
                if(!board.has_study_station(_current_city))
                {
                    throw_card(_current_city); 
                    _board.has_study_station(_current_city)=true;
                }
            }
            else{
                throw invalid_argument{"Error. can't build study station without matching card."};
            }
            return *this;
        }

}