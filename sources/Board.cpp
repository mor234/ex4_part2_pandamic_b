#include "Board.hpp"

using namespace std;
namespace pandemic {

    void Board::initialize_board() {
        board[Algiers] = make_pair(Black, vector{Madrid, Paris, Istanbul, Cairo});
        board[Atlanta] = make_pair(Blue, vector{Chicago, Miami, Washington});
        board[Baghdad] = make_pair(Black, vector{Tehran, Istanbul, Cairo, Riyadh, Karachi});
        board[Bangkok] = make_pair(Red, vector{Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong});
        board[Beijing] = make_pair(Red, vector{Shanghai, Seoul});
        board[Bogota] = make_pair(Yellow, vector{MexicoCity, Lima, Miami, SaoPaulo, BuenosAires});
        board[BuenosAires] = make_pair(Yellow, vector{Bogota, SaoPaulo});
        board[Cairo] = make_pair(Black, vector{Algiers, Istanbul, Baghdad, Khartoum, Riyadh});
        board[Chennai] = make_pair(Black, vector{Mumbai, Delhi, Kolkata, Bangkok, Jakarta});
        board[Chicago] = make_pair(Blue, vector{SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal});
        board[Delhi] = make_pair(Black, vector{Tehran, Karachi, Mumbai, Chennai, Kolkata});
        board[Essen] = make_pair(Blue, vector{London, Paris, Milan, StPetersburg});
        board[HoChiMinhCity] = make_pair(Red, vector{Jakarta, Bangkok, HongKong, Manila});
        board[HongKong] = make_pair(Red, vector{Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei});
        board[Istanbul] = make_pair(Black, vector{Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow});
        board[Jakarta] = make_pair(Red, vector{Chennai, Bangkok, HoChiMinhCity, Sydney});
        board[Johannesburg] = make_pair(Yellow, vector{Kinshasa, Khartoum});
        board[Karachi] = make_pair(Black, vector{Tehran, Baghdad, Riyadh, Mumbai, Delhi});
        board[Khartoum] = make_pair(Yellow, vector{Cairo, Lagos, Kinshasa, Johannesburg});
        board[Kinshasa] = make_pair(Yellow, vector{Lagos, Khartoum, Johannesburg});
        board[Kolkata] = make_pair(Black, vector{Delhi, Chennai, Bangkok, HongKong});
        board[Lagos] = make_pair(Yellow, vector{SaoPaulo, Khartoum, Kinshasa});
        board[Lima] = make_pair(Yellow, vector{MexicoCity, Bogota, Santiago});
        board[London] = make_pair(Blue, vector{NewYork, Madrid, Essen, Paris});
        board[LosAngeles] = make_pair(Yellow, vector{SanFrancisco, Chicago, MexicoCity, Sydney});
        board[Madrid] = make_pair(Blue, vector{London, NewYork, Paris, SaoPaulo, Algiers});
        board[Manila] = make_pair(Red, vector{Taipei, SanFrancisco, HoChiMinhCity, Sydney});
        board[MexicoCity] = make_pair(Yellow, vector{LosAngeles, Chicago, Miami, Lima, Bogota});
        board[Miami] = make_pair(Yellow, vector{Atlanta, MexicoCity, Washington, Bogota});
        board[Milan] = make_pair(Blue, vector{Essen, Paris, Istanbul};
        board[Montreal] = make_pair(Blue, vector{Chicago, Washington, NewYork};
        board[Moscow] = make_pair(Black, vector{StPetersburg, Istanbul, Tehran};
        board[Mumbai] = make_pair(Black, vector{Karachi, Delhi, Chennai});
        board[NewYork] = make_pair(Blue, vector{Montreal, Washington, London, Madrid};
        board[Osaka] = make_pair(Red, vector{Taipei, Tokyo});
        board[Paris] = make_pair(Blue, vector{Algiers, Essen, Madrid, Milan, London});
        board[Riyadh] = make_pair(Black, vector{Baghdad, Cairo, Karachi});
        board[SanFrancisco] = make_pair(Blue, vector{LosAngeles, Chicago, Tokyo, Manila});
        board[Santiago] = make_pair(Yellow, vector{Lima});
        board[SaoPaulo] = make_pair(Yellow, vector{Bogota, BuenosAires, Lagos, Madrid});
        board[Seoul] = make_pair(Red, vector{Beijing, Shanghai, Tokyo});
        board[Shanghai] = make_pair(Red, vector{Beijing, HongKong, Taipei, Seoul, Tokyo});
        board[StPetersburg] = make_pair(Blue, vector{Essen, Istanbul, Moscow});
        board[Sydney] = make_pair(Red, vector{Jakarta, Manila, LosAngeles});
        board[Taipei] = make_pair(Red, vector{Shanghai, HongKong, Osaka, Manila});
        board[Tehran] = make_pair(Black, vector{Baghdad, Moscow, Karachi, Delhi});
        board[Tokyo] = make_pair(Red, vector{Seoul, Shanghai, Osaka, SanFrancisco});
        board[Washington] = make_pair(Blue, vector{Atlanta, NewYork, Montreal, Miami});
    }

    Board::Board() {
        initialize_board();
    }

    bool Board::is_clean() {
        return true;
    }

    void Board::remove_cures() {

    }

    const int &Board::operator[](City city) const {
        return *(new int(5));
    }

    int &Board::operator[](City city) {
        return *(new int(5));
    }

    //----------------------------------
    // friend global IO operators
    //----------------------------------
    std::ostream &operator<<(std::ostream &output, const Board &board) {
        return (output << "hello");
    }

}