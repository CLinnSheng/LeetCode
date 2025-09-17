#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

/*
 * foods[i] -> name of the ith food
 * cuisines[i] -> type of cuisine of the ith food
 * ratings[i] -> initial rating of the ith food
 *
 * changeRating -> Changes the rating of the food item
 * highestRate -> Return the name of the food item that has the highest rating iven the type of cuisine. If theres a tie
 * then return the 1 with lexicographically smaller name
 *
 * Intuition:
 * Since we want to easily access the rating of a food, and the cuisine for the food.
 * We can easily access it by using a hash map
 * Brute force way will need to check the food all under the key cuisine, instead of straight away get the highest
 * rating
 * To overcome the issues of finding lexicographically, we just simply has another hash map that map the cuisine to list
 * of food sorted according to rating then food string
 * Time Complexity: O(nlgn)
 * */
struct Comparator
{

    bool operator()(const std::pair<int, std::string> &A, const std::pair<int, std::string> &B) const
    {
        if (A.first != B.first)
            return A.first > B.first;

        return A.second < B.second;
    }
};
class FoodRatings
{
  public:
    std::unordered_map<std::string, int> foodRatingsMap;
    std::unordered_map<std::string, std::string> foodCuisinesMap;
    std::unordered_map<std::string, std::set<std::pair<int, std::string>, Comparator>> cuisineFoodListMap;
    FoodRatings(std::vector<std::string> &foods, std::vector<std::string> &cuisines, std::vector<int> &ratings)
    {
        int n(foods.size());

        for (int i{}; i < n; i++)
        {
            std::string &foodName{foods[i]};

            foodRatingsMap[foodName] = ratings[i];
            foodCuisinesMap[foodName] = cuisines[i];
            cuisineFoodListMap[cuisines[i]].emplace(std::make_pair(ratings[i], foodName));
        }
    }

    void changeRating(std::string food, int newRating)
    {
        // Delete it from the cuisineFoodListMap & update with the new 1
        auto it = cuisineFoodListMap[foodCuisinesMap[food]].find({foodRatingsMap[food], food});
        cuisineFoodListMap[foodCuisinesMap[food]].erase(it);

        foodRatingsMap[food] = newRating;

        cuisineFoodListMap[foodCuisinesMap[food]].emplace(std::make_pair(newRating, food));
    }

    std::string highestRated(std::string cuisine)
    {
        return cuisineFoodListMap[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
