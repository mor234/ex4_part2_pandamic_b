#pragma once
#include "City.hpp"
#include "Player.hpp"
#include <map>
#include <vector>
#include<tuple> // for tuple


#include <iostream>

namespace pandemic{
    class Board{
        private:
            static std::map< City, std::pair <Color, std::vector <City> > >board_city_map;
            void initialize_board();
            int sickness_cubes_num;
            std::map<City,std::tuple<int /*sickness_cubes*/,int /*cures*/,int /*study_station*/>> city_attributes;
        public:
          
            Board ();
            void remove_cures();
            bool is_clean();
            Color color_for_city(City city);

            //operator []
            const int & operator[](City city) const;
            int& operator[](City city);
            //----------------------------------
            // friend global IO operators
            //----------------------------------
            friend std::ostream& operator<< (std::ostream& output, const Board & board);
    };
}