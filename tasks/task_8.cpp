#include <vector>

class Field{
public:
    Field(int x_1, int y_1){
        this->x = x_1;
        this->y = y_1;
    }

    int x, y;
    bool is_bush = false, is_opened = false;
};

void area_opening(std::vector<std::vector<Field>> & field, int x_c = 0, int y_c = 0){
    // Up
    if (y_c + 1 < field[x_c].size()){
        if (!field[x_c][y_c + 1].is_opened){
            field[x_c][y_c + 1].is_opened = true;
            if (!field[x_c][y_c + 1].is_bush){
                area_opening(field, x_c, y_c + 1);
            }
        }
    }

    // Right
    if (x_c + 1 < field.size()){
        if (!field[x_c + 1][y_c].is_opened){
            field[x_c + 1][y_c].is_opened = true;
            if (!field[x_c + 1][y_c].is_bush){
                area_opening(field, x_c + 1, y_c);
            }
        }
    }

    // Down
    if (y_c - 1 >= 0){
        if (!field[x_c][y_c - 1].is_opened){
            field[x_c][y_c - 1].is_opened = true;
            if (!field[x_c][y_c - 1].is_bush){
                area_opening(field, x_c, y_c - 1);
            }
        }
    }

    // Left
    if (x_c - 1 >= 0){
        if (!field[x_c - 1][y_c].is_opened){
            field[x_c - 1][y_c].is_opened = true;
            if (!field[x_c - 1][y_c].is_bush){
                area_opening(field, x_c - 1, y_c);
            }
        }
    }
}

std::vector<std::vector<int>> bushes(std::vector<std::vector<int>> all_bushes){
    int max_x = 1<<31, max_y = 1<<31, min_x = ~(1<<31), min_y = ~(1<<31);

    for (int i = 0; i < all_bushes.size(); i++){
        if (all_bushes[i][0] > max_x){
            max_x = all_bushes[i][0];
        }
        if (all_bushes[i][0] < min_x){
            min_x = all_bushes[i][0];
        }
        if (all_bushes[i][1] > max_y){
            max_y = all_bushes[i][1];
        }
        if (all_bushes[i][1] < min_y){
            min_y = all_bushes[i][1];
        }
    }

    min_x--; min_y--; max_x++; max_y++;
    int dx = max_x - min_x, dy = max_y - min_y;

    // Create field x0y
    std::vector<std::vector<Field>> x0y{};
    for (int i = 0; i < dx + 1; i++){
        x0y.push_back(std::vector<Field>{});

        for (int j = 0; j < dy + 1; j++){
            x0y[i].push_back(Field(i+min_x, j+min_y));
        }
    }

    // Add bushes
    for (int i = 0; i < all_bushes.size(); i++){
        x0y[all_bushes[i][0] - min_x][all_bushes[i][1] - min_y].is_bush = true; 
    }

    // Create opened area
    x0y[0][0].is_opened = true;
    area_opening(x0y);

    // Find opened bushes
    std::vector<std::vector<int>> opened_bushes{};
    for (int i = 0; i < x0y.size(); i++){
        for (int j = 0; j < x0y[i].size(); j++){
            if (x0y[i][j].is_bush and x0y[i][j].is_opened){
                opened_bushes.push_back(std::vector<int>{});
                opened_bushes[opened_bushes.size()-1].push_back(x0y[i][j].x);
                opened_bushes[opened_bushes.size()-1].push_back(x0y[i][j].y);
            }
        }
    }

    return opened_bushes;
}