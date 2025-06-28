#include <gtest/gtest.h>
#include "../headers/task_3.hpp"
#include "../headers/task_4.hpp"
#include "../headers/task_5.hpp"
#include "../headers/task_6.hpp"
#include "../headers/task_7.hpp"
#include "../headers/task_8.hpp"


TEST(Task_3, SimpleEquation) {
    EXPECT_EQ(equation("x+2x+1-2=6+x-1"), "x=3");
}
TEST(Task_3, NoSolution) {
    EXPECT_EQ(equation("1+x=5+6-2x"), "NO");
}
TEST(Task_3, InfiniteSolutions) {
    EXPECT_EQ(equation("x=x"), "Infinite");
}


TEST(Task_4, Basic) {
    std::vector<std::string> times = {"00:00", "06:00", "11:30"};
    EXPECT_EQ(min_dif(times), 330);
}
TEST(Task_4, Harder) {
    std::vector<std::string> times = {"23:34", "01:23", "03:15"};
    EXPECT_EQ(min_dif(times), 109);
}
TEST(Task_4, MaxDiff) {
    std::vector<std::string> times = {"00:00", "23:02"};
    EXPECT_EQ(min_dif(times), 58);
}


TEST(Task_5, Basic){
    EXPECT_EQ(path_finder(671088640, 939524096), true);
}
TEST(Task_5, Second){
    EXPECT_EQ(path_finder(7339, 25), true);
}
TEST(Task_5, Third){
    EXPECT_EQ(path_finder(3, 900'000'000), false);
}


TEST(Task_6, Basic){
    EXPECT_EQ(calc_expression("(2)"), 2);
}
TEST(Task_6, Harder){
    EXPECT_EQ(calc_expression("(2+6)-1"), 7);
}
TEST(Task_6, Hardest){
    EXPECT_EQ(calc_expression("-7+ ( ( 10 - 19) -9 )+5 -(3 + 1)  "), -24);
}


TEST(Task_7, small){
    EXPECT_EQ(numbers_from_range(2), 3);
}
TEST(Task_7, big){
    EXPECT_EQ(numbers_from_range(10), 8);
}
TEST(Task_7, bigger){
    EXPECT_EQ(numbers_from_range(16), 9);
}


TEST(Task_8, Plus){
    std::vector<std::vector<int>> all_bushes = {{1,0},{2,1},{1,2},{0,1},{1,1}};
    std::vector<std::vector<int>> expected = {{0,1},{1,0},{1,2},{2,1}};
    EXPECT_EQ(bushes(all_bushes), expected);
}
TEST(Task_8, FullSquare){
    std::vector<std::vector<int>> all_bushes = {{1,3},{2,3},{3,3},{3,2},{3,1},{2,1},{1,1},{1,2},{2,2}};
    std::vector<std::vector<int>> expected = {{1,1},{1,2},{1,3},{2,1},{2,3},{3,1},{3,2},{3,3}};
    EXPECT_EQ(bushes(all_bushes), expected);
}
TEST(Task_8, Square){
    std::vector<std::vector<int>> all_bushes = {{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0}};
    std::vector<std::vector<int>> expected = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    EXPECT_EQ(bushes(all_bushes), expected);
    system("pause");
}