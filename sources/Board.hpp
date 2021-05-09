#pragma once
#include "City.hpp"
#include "Player.hpp"
#include <map>
#include <vector>

#include <iostream>

namespace pandemic{
    class Board{
        private:
        std::map< City, std::pair <Color, std::vector <City> > >board;
        void initialize_board();

        public:
          
            Board ();
            void remove_cures();
            bool is_clean();
            //operator []
            const int & operator[](City city) const;
            int& operator[](City city);
        
            //----------------------------------
            // friend global IO operators
            //----------------------------------
            friend std::ostream& operator<< (std::ostream& output, const Board & board);
    };
}