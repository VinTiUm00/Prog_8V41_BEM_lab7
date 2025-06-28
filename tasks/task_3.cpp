#include <string>
//#include <iostream>

class Part_Of_Eq {
    public:
        Part_Of_Eq();
        Part_Of_Eq(std::string input){
            int cur_xs = 0, cur_number = 0, n = 0;
            bool minus = false, fig = false;
            for (int id = 0; id < input.length(); id++){
                if (input[id] == 'x'){
                    if (n == 0){
                        n++;
                    }
                    if (minus == true){
                        cur_xs -= n;
                        minus = false;
                    }
                    else {
                        cur_xs += n;
                    }
                    fig = false;
                    n = 0;
                }
                else if (input[id] == '-'){
                    if (minus == true){cur_number -= n;}
                    else {cur_number += n;}
                    n = 0;
                    minus = true;
                    fig = false;
                }
                else if (input[id] == '+'){
                    if (minus == true){cur_number -= n;}
                    else {cur_number += n;}
                    n = 0;
                    minus = false;
                    fig = false;
                }
                else {
                    if (fig == true){
                        n *= 10;
                    }
                    n += ((input[id]) - '0');
                    fig = true;
                }
            }
            if (minus){cur_number -= n;}
            else {cur_number += n;}
            xs = cur_xs;
            number = cur_number;
        }
        //~Part_Of_Eq();
        friend void operator ^ (Part_Of_Eq &lhs, Part_Of_Eq &rhs){
            lhs.xs -= rhs.xs;
            rhs.xs = 0;
            rhs.number -= lhs.number;
            lhs.number = 0;
        }

        int xs = 0;
        int number = 0;
};

std::string equation(std::string input){
    std::string answer = "", left = "", right = "";
    for (char sym : input) {
        if (sym == '='){
            left = right;
            right = "";
        }
        else {
            right += sym;
        }
    }
    Part_Of_Eq Left_Part(left), Right_Part(right);
    Left_Part ^ Right_Part;
    if (Left_Part.xs == 0){
        answer = "Infinite";
    }
    else if (Right_Part.number % Left_Part.xs){
        answer = "NO";
    }
    else {
        answer = "x=" + std::to_string(Right_Part.number / Left_Part.xs);
    }
    return answer;
}