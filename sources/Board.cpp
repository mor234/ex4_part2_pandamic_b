#include "Board.hpp"
#include<iostream>
using namespace std;
namespace pandemic {
 
    std::map< City, std::pair <Color, std::set <City> > >Board::board_city_map;

    Board::Board() {
        initialize_board();//fix
        cures.fill(false);
        //initialize city_attributes
        for(const auto &city_info:board_city_map)
        {
            city_attributes[city_info.first]=make_pair(0,false);
        }
    }
    // Board::Board(const Board  & board) {
    //     city_attributes=board.city_attributes;
    //     cures=board.cures;
    // }
    // Board& Board::operator=(const Board  & board) 
    // {
    //     if (this!=&board) 
    //     { // preventing problems in a=a
    //         city_attributes=board.city_attributes;
    //         cures=board.cures;
    //     } 
    //     return *this; 
    // } 
    
    void Board::initialize_board() {
    
        board_city_map[Algiers] = make_pair(Black, set{Madrid, Paris, Istanbul, Cairo});
        board_city_map[Atlanta] = make_pair(Blue, set{Chicago, Miami, Washington});
        board_city_map[Baghdad] = make_pair(Black, set{Tehran, Istanbul, Cairo, Riyadh, Karachi});
        board_city_map[Bangkok] = make_pair(Red, set{Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong});
        board_city_map[Beijing] = make_pair(Red, set{Shanghai, Seoul});
        board_city_map[Bogota] = make_pair(Yellow, set{MexicoCity, Lima, Miami, SaoPaulo, BuenosAires});
        board_city_map[BuenosAires] = make_pair(Yellow, set{Bogota, SaoPaulo});
        board_city_map[Cairo] = make_pair(Black, set{Algiers, Istanbul, Baghdad, Khartoum, Riyadh});
        board_city_map[Chennai] = make_pair(Black, set{Mumbai, Delhi, Kolkata, Bangkok, Jakarta});
        board_city_map[Chicago] = make_pair(Blue, set{SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal});
        board_city_map[Delhi] = make_pair(Black, set{Tehran, Karachi, Mumbai, Chennai, Kolkata});
        board_city_map[Essen] = make_pair(Blue, set{London, Paris, Milan, StPetersburg});
        board_city_map[HoChiMinhCity] = make_pair(Red, set{Jakarta, Bangkok, HongKong, Manila});
        board_city_map[HongKong] = make_pair(Red, set{Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei});
        board_city_map[Istanbul] = make_pair(Black, set{Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow});
        board_city_map[Jakarta] = make_pair(Red, set{Chennai, Bangkok, HoChiMinhCity, Sydney});
        board_city_map[Johannesburg] = make_pair(Yellow, set{Kinshasa, Khartoum});
        board_city_map[Karachi] = make_pair(Black, set{Tehran, Baghdad, Riyadh, Mumbai, Delhi});
        board_city_map[Khartoum] = make_pair(Yellow, set{Cairo, Lagos, Kinshasa, Johannesburg});
        board_city_map[Kinshasa] = make_pair(Yellow, set{Lagos, Khartoum, Johannesburg});
        board_city_map[Kolkata] = make_pair(Black, set{Delhi, Chennai, Bangkok, HongKong});
        board_city_map[Lagos] = make_pair(Yellow, set{SaoPaulo, Khartoum, Kinshasa});
        board_city_map[Lima] = make_pair(Yellow, set{MexicoCity, Bogota, Santiago});
        board_city_map[London] = make_pair(Blue, set{NewYork, Madrid, Essen, Paris});
        board_city_map[LosAngeles] = make_pair(Yellow, set{SanFrancisco, Chicago, MexicoCity, Sydney});
        board_city_map[Madrid] = make_pair(Blue, set{London, NewYork, Paris, SaoPaulo, Algiers});
        board_city_map[Manila] = make_pair(Red, set{HongKong,Taipei, SanFrancisco, HoChiMinhCity, Sydney});
        board_city_map[MexicoCity] = make_pair(Yellow, set{LosAngeles, Chicago, Miami, Lima, Bogota});
        board_city_map[Miami] = make_pair(Yellow, set{Atlanta, MexicoCity, Washington, Bogota});
        board_city_map[Milan] = make_pair(Blue, set{Essen, Paris, Istanbul});
        board_city_map[Montreal] = make_pair(Blue, set{Chicago, Washington, NewYork});
        board_city_map[Moscow] = make_pair(Black, set{StPetersburg, Istanbul, Tehran});
        board_city_map[Mumbai] = make_pair(Black, set{Karachi, Delhi, Chennai});
        board_city_map[NewYork] = make_pair(Blue, set{Montreal, Washington, London, Madrid});
        board_city_map[Osaka] = make_pair(Red, set{Taipei, Tokyo});
        board_city_map[Paris] = make_pair(Blue, set{Algiers, Essen, Madrid, Milan, London});
        board_city_map[Riyadh] = make_pair(Black, set{Baghdad, Cairo, Karachi});
        board_city_map[SanFrancisco] = make_pair(Blue, set{LosAngeles, Chicago, Tokyo, Manila});
        board_city_map[Santiago] = make_pair(Yellow, set{Lima});
        board_city_map[SaoPaulo] = make_pair(Yellow, set{Bogota, BuenosAires, Lagos, Madrid});
        board_city_map[Seoul] = make_pair(Red, set{Beijing, Shanghai, Tokyo});
        board_city_map[Shanghai] = make_pair(Red, set{Beijing, HongKong, Taipei, Seoul, Tokyo});
        board_city_map[StPetersburg] = make_pair(Blue, set{Essen, Istanbul, Moscow});
        board_city_map[Sydney] = make_pair(Red, set{Jakarta, Manila, LosAngeles});
        board_city_map[Taipei] = make_pair(Red, set{Shanghai, HongKong, Osaka, Manila});
        board_city_map[Tehran] = make_pair(Black, set{Baghdad, Moscow, Karachi, Delhi});
        board_city_map[Tokyo] = make_pair(Red, set{Seoul, Shanghai, Osaka, SanFrancisco});
        board_city_map[Washington] = make_pair(Blue, set{Atlanta, NewYork, Montreal, Miami});
    }
/**
 * @brief check if there are no sickness cubes on the board
 * 
 * @return true 
 * @return false 
 */
    bool Board::is_clean() {
        for(auto city :city_attributes)
        {
            //sickness cubes equal 0
            if (get<0>(city.second)!=0)
            {
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures() {
        for(bool & cure:cures)
        {
            cure=false;
        }
    }


    const int &Board::operator[](City city) const {
         return get<0>(city_attributes.at(city));
     }

    int &Board::operator[](City city) {
        return get<0>(city_attributes[city]);
    }
    

    //----------------------------------
    // friend global IO operators
    //----------------------------------
    std::ostream &operator<<(std::ostream &output, /*const Board &board*/Board board) {
        string str_out;

        for(auto city:board.board_city_map)
        {
          
            str_out+="city: "+to_string(city.first)+" color: "+to_string(city.second.first);
            str_out+=" sickness level: "+to_string(board.sickness_cubes(city.first));
            str_out+=" study stations: "+to_string(board.has_study_station(city.first));
            str_out+="\n";
        }

        return (output << str_out);
    }
    int Board::sickness_cubes ( City city) {//fix!!!!!
        return get<0>(city_attributes[city]);
    }

    bool & Board::has_study_station(City city)
    {
        return get<1>(city_attributes[city]);
    }
    const Color & Board::color_for_city(City city)
    {
        return board_city_map[city].first;
    }
    bool Board::are_cities_connected(City city1,City city2)
    {
        return (board_city_map[city1].second).find(city2)!=(board_city_map[city1].second).end();
    }
    bool & Board::color_has_cure(Color color)
    {
        return(cures.at(array<bool,COLOR_NUMBER>::size_type (color)));
    }
   set <City> Board::near_cities(City city)
   {
       return (board_city_map[city]).second;
   }


}