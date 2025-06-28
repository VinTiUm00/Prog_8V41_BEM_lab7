#include <vector>
#include <string>

int min_dif(std::vector<std::string> & times){
    int size_times = times.size(), minimum = 1440, time_1, time_2;

    for (int i = 0; i < size_times - 1; i++){
        time_1 = ((times[i][0] - '0') * 10 + (times[i][1] - '0')) * 60 + (times[i][3] - '0') * 10 + (times[i][4] - '0');
        for (int j = i + 1; j < size_times; j++){
            time_2 = ((times[j][0] - '0') * 10 + (times[j][1] - '0')) * 60 + (times[j][3] - '0') * 10 + (times[j][4] - '0');

            if (abs(time_1 - time_2) < minimum){
                minimum = abs(time_1 - time_2);
            }
            if (1440 - abs(time_1 - time_2) < minimum){
                minimum = 1440 - abs(time_1 - time_2);
            }
        }
    }
    
    return minimum;
}