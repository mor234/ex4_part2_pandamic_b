#include "Board.hpp"
#include<iostream>
using namespace std;
namespace pandemic {
    //
    bool Board::is_first_time = true; 
    std::map< City, std::pair <Color, std::set <City> > >Board::board_city_map;
    /**
     * @brief Construct a new Board:: Board object, initialize cures to be false, 
     * and if this it the first time object from type Board is created,
     * initialize the map ot the connection between cities. 
     */
    Board::Board() :cures({false}){
        if(is_first_time)
        {
            initialize_board();
            is_first_time=false;
        }
        //initialize city_attributes
        for(const auto &city_info:board_city_map)
        {
            city_attributes[city_info.first]=make_pair(0,false);
        }
    }
    /**
     * @brief initialize the map ot the connection between cities.
     */
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
            //sickness cubes not equal 0
            if (get<0>(city.second)!=0)
            {
                return false;
            }
        }
        return true;
    }
    /**
     * @brief remove all cures from the board by changing the flag to false
     */
    void Board::remove_cures() {
        for(bool & cure:cures)
        {
            cure=false;
        }
    }
    /**
     * @brief  remove all study stations from the board by changing the flag to false
     */
    void Board::remove_stations()
    {
         for(auto & atr:city_attributes)
        {
            auto & pair_cube_station=atr.second;
            pair_cube_station.second=false;
        }
    }
    
    /**
     * @brief [] operator const, return number of sickness cubes in given city
     * 
     * @param city 
     * @return const int& 
     */
    const int &Board::operator[](const City & city) const {
         return get<0>(city_attributes.at(city));
    }
    /**
     * @brief mutable [] operator , return number of sickness cubes in given city
     * and allows to change it.
     * @param city 
     * @return int& 
     */
    int &Board::operator[](const City & city) {
        return get<0>(city_attributes[city]);
    }
    

    //----------------------------------
    // friend global IO operators
    //----------------------------------
    /**
     * @brief output operator for board' contains information about:
     * city, color, sickness level and study station
     */
    std::ostream &operator<<(std::ostream &output, const Board &board) {//need fix!!!
        string str_out;
        for(const auto & city:Board::board_city_map)
        {  
            str_out+="city: "+to_string(city.first)+" color: "+to_string(city.second.first);
            str_out+=" sickness level: "+to_string(board[city.first]);
            str_out+=" study stations: "+to_string(int(board.has_study_station(city.first)));
            str_out+="\n";
        }
        return (output << str_out);
    }
    /**
     * @brief return immutable bool if a given city has a study station
     * 
     * @param city 
     * @return true if has a study station
     * @return false if not
     */
    const bool & Board::has_study_station(City city) const
    {
        return get<1>(city_attributes.at(city));
    }
    /**
     * @brief return mutable bool if a given city has a study station
     * 
     * @param city 
     * @return true if has a study station
     * @return false if not
     */
    bool & Board::has_study_station(const City & city)
    {
        return get<1>(city_attributes[city]);
    }
    /**
     * @brief static, return the matching color for a given city
     * @param city 
     * @return const Color& 
     */
    const Color & Board::color_for_city(const City & city)
    {
        return board_city_map[city].first;
    }
    /**
     * @brief return true if cities are directly connected, false if not.
     * 
     * @param city1 
     * @param city2 
     * @return true 
     * @return false 
     */
    bool Board::are_cities_connected(const City & city1,const City & city2)
    {
        return (board_city_map[city1].second).find(city2)!=(board_city_map[city1].second).end();
    }
    /**
     * @brief return mutable bool. if the given color has cure return true' otherwise false, 
     * allow to change the ansewer
     * 
     * @param color 
     * @return true 
     * @return false 
     */
    bool & Board::color_has_cure(const Color & color)
    {
        return(cures.at(array<bool,COLOR_NUMBER>::size_type (color)));
    }
    /**
     * @brief return set of all the cities directly connected to a given city.
     * 
     * @param city 
     * @return set <City> 
     */
   set <City> Board::near_cities(const City & city)
   {
       return (board_city_map[city]).second;
   }


}