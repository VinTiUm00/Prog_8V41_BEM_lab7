#include <string>
#include <vector>
#include <numeric>

int calculator(std::string exp){
    bool minus = false, figure = false;
    std::string extra = "";
    std::vector<int> numbers {};
    unsigned int opened = 0;
    int num = 0;
    
    for (char symb : exp){
        if (opened){
            if (symb == '('){
                opened++;
            }
            else if (symb == ')'){
                opened--;
            }

            if (opened){
                extra += symb;
            }
            else {
                if (minus){
                    numbers.push_back(-calculator(extra));
                }
                else {
                    numbers.push_back(calculator(extra));
                }
            
                extra = "";
                minus = false;
            }
        }
        else if (symb == '('){
            opened++;
        }
        else if (symb == '-'){
            if (minus and figure){
                numbers.push_back(-num);
            }
            else if (figure){
                numbers.push_back(num);
            }

            minus = true;
            num = 0;
            figure = false;
        }
        else if (symb == '+'){
            if (minus){
                numbers.push_back(-num);
            }
            else {
                numbers.push_back(num);
            }

            minus = false;
            num = 0;
            figure = false;
        }
        else if (not (symb == ' ' or symb == ')')){
            figure = true;
            num = num * 10 + (symb - '0');
        }
    }

    if (figure){
        if (minus){
            numbers.push_back(-num);
        }
        else {
            numbers.push_back(num);
        }
    }

    return std::accumulate(numbers.begin(), numbers.end(), 0);
}

int calc_expression(std::string expression){
    return calculator(expression);
}