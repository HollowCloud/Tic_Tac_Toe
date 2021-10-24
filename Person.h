//
// Created by asus on 24.10.2021.
//

#ifndef TIC_PERSON_H
#define TIC_PERSON_H


class Person {
public:

    bool Tic_Tac_Toe_Master();

    bool check_duplicates();
    void Lines();

    void set_numbers();

    void assigning_board();

    void change_player();

    void define_turn();

    void exit();

    friend std::ostream &operator<<( std::ostream &output, const Person &p) {
        output <<"\n";

        output<<"\n";
        output<<"***********\n";
        output<<"Tic-Tac-Toe\n";
        output<<"***********\n";

        output<<"Player 1) X\n";
        output<<"Player 2) O\n";

        output << "     |     |      \n";
        output << "  1  |  2  |  3   \n";
        output << "_____|_____|_____ \n";
        output << "     |     |      \n";
        output << "  4  |  5  |  6   \n";
        output << "_____|_____|_____ \n";
        output << "     |     |      \n";
        output << "  7  |  8  |  9   \n";
        output << "     |     |      \n\n";;
        return output;
    }

    void set_position_bot();

};

#endif //TIC_PERSON_H
