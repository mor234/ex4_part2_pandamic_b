#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>
#include <string>
namespace pandemic{
    class Player{
        private:
            City rand_city();

        protected:
            Board _board;
            City _current_city;
            std::set<City> cards;

        public:
            Player(const Board & board,const City & current_city);
            Player & take_card(City city);

            //movements options
            Player & drive(City city);
            Player & fly_direct(City city);
            Player & fly_charter(City city);
            Player & fly_shuttle(City city);

            Player & treat(City city);



            Player & discover_cure(Color color);
            Player & build();
            virtual std::string role()=0;
    };



}