#include "Board.hpp"

using namespace std;
namespace pandemic {

    void Board::initialize_board() {
        board_city_map[Algiers] = make_pair(Black, vector{Madrid, Paris, Istanbul, Cairo});
        board_city_map[Atlanta] = make_pair(Blue, vector{Chicago, Miami, Washington});
        board_city_map[Baghdad] = make_pair(Black, vector{Tehran, Istanbul, Cairo, Riyadh, Karachi});
        board_city_map[Bangkok] = make_pair(Red, vector{Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong});
        board_city_map[Beijing] = make_pair(Red, vector{Shanghai, Seoul});
        board_city_map[Bogota] = make_pair(Yellow, vector{MexicoCity, Lima, Miami, SaoPaulo, BuenosAires});
        board_city_map[BuenosAires] = make_pair(Yellow, vector{Bogota, SaoPaulo});
        board_city_map[Cairo] = make_pair(Black, vector{Algiers, Istanbul, Baghdad, Khartoum, Riyadh});
        board_city_map[Chennai] = make_pair(Black, vector{Mumbai, Delhi, Kolkata, Bangkok, Jakarta});
        board_city_map[Chicago] = make_pair(Blue, vector{SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal});
        board_city_map[Delhi] = make_pair(Black, vector{Tehran, Karachi, Mumbai, Chennai, Kolkata});
        board_city_map[Essen] = make_pair(Blue, vector{London, Paris, Milan, StPetersburg});
        board_city_map[HoChiMinhCity] = make_pair(Red, vector{Jakarta, Bangkok, HongKong, Manila});
        board_city_map[HongKong] = make_pair(Red, vector{Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei});
        board_city_map[Istanbul] = make_pair(Black, vector{Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow});
        board_city_map[Jakarta] = make_pair(Red, vector{Chennai, Bangkok, HoChiMinhCity, Sydney});
        board_city_map[Johannesburg] = make_pair(Yellow, vector{Kinshasa, Khartoum});
        board_city_map[Karachi] = make_pair(Black, vector{Tehran, Baghdad, Riyadh, Mumbai, Delhi});
        board_city_map[Khartoum] = make_pair(Yellow, vector{Cairo, Lagos, Kinshasa, Johannesburg});
        board_city_map[Kinshasa] = make_pair(Yellow, vector{Lagos, Khartoum, Johannesburg});
        board_city_map[Kolkata] = make_pair(Black, vector{Delhi, Chennai, Bangkok, HongKong});
        board_city_map[Lagos] = make_pair(Yellow, vector{SaoPaulo, Khartoum, Kinshasa});
        board_city_map[Lima] = make_pair(Yellow, vector{MexicoCity, Bogota, Santiago});
        board_city_map[London] = make_pair(Blue, vector{NewYork, Madrid, Essen, Paris});
        board_city_map[LosAngeles] = make_pair(Yellow, vector{SanFrancisco, Chicago, MexicoCity, Sydney});
        board_city_map[Madrid] = make_pair(Blue, vector{London, NewYork, Paris, SaoPaulo, Algiers});
        board_city_map[Manila] = make_pair(Red, vector{Taipei, SanFrancisco, HoChiMinhCity, Sydney});
        board_city_map[MexicoCity] = make_pair(Yellow, vector{LosAngeles, Chicago, Miami, Lima, Bogota});
        board_city_map[Miami] = make_pair(Yellow, vector{Atlanta, MexicoCity, Washington, Bogota});
        board_city_map[Milan] = make_pair(Blue, vector{Essen, Paris, Istanbul};
        board_city_map[Montreal] = make_pair(Blue, vector{Chicago, Washington, NewYork};
        board_city_map[Moscow] = make_pair(Black, vector{StPetersburg, Istanbul, Tehran};
        board_city_map[Mumbai] = make_pair(Black, vector{Karachi, Delhi, Chennai});
        board_city_map[NewYork] = make_pair(Blue, vector{Montreal, Washington, London, Madrid};
        board_city_map[Osaka] = make_pair(Red, vector{Taipei, Tokyo});
        board_city_map[Paris] = make_pair(Blue, vector{Algiers, Essen, Madrid, Milan, London});
        board_city_map[Riyadh] = make_pair(Black, vector{Baghdad, Cairo, Karachi});
        board_city_map[SanFrancisco] = make_pair(Blue, vector{LosAngeles, Chicago, Tokyo, Manila});
        board_city_map[Santiago] = make_pair(Yellow, vector{Lima});
        board_city_map[SaoPaulo] = make_pair(Yellow, vector{Bogota, BuenosAires, Lagos, Madrid});
        board_city_map[Seoul] = make_pair(Red, vector{Beijing, Shanghai, Tokyo});
        board_city_map[Shanghai] = make_pair(Red, vector{Beijing, HongKong, Taipei, Seoul, Tokyo});
        board_city_map[StPetersburg] = make_pair(Blue, vector{Essen, Istanbul, Moscow});
        board_city_map[Sydney] = make_pair(Red, vector{Jakarta, Manila, LosAngeles});
        board_city_map[Taipei] = make_pair(Red, vector{Shanghai, HongKong, Osaka, Manila});
        board_city_map[Tehran] = make_pair(Black, vector{Baghdad, Moscow, Karachi, Delhi});
        board_city_map[Tokyo] = make_pair(Red, vector{Seoul, Shanghai, Osaka, SanFrancisco});
        board_city_map[Washington] = make_pair(Blue, vector{Atlanta, NewYork, Montreal, Miami});
    }

    Board::Board():sickness_cubes_num(0) {
        initialize_board();
    }

    bool Board::is_clean() {
        for(auto city :city_attributes)
        {
            if (get<0>(city.second)!=0)
            {
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures() {
        for(auto city :city_attributes)
        {
            get<1>(city.second)=0;
        }
    }
    Color Board::color_for_city(City city){
        
        return board_city_map[city].first;
    }

    // const int &Board::operator[](City city) const {
    //     return get<0>(city_attributes[city]);
    // }

    int &Board::operator[](City city) {
        return get<0>(city_attributes[city]);
    }

    //----------------------------------
    // friend global IO operators
    //----------------------------------
    std::ostream &operator<<(std::ostream &output, const Board &board) {
        return (output << "hello");
    }

}