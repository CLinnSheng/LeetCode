#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * recipes[i] can be create if you have all the needed ingredients from ingredients[i]
 * NOTE: An ingredient can also be an ingredient for other recipes
 * NOTE: ingredients[i] may contain a string that is in recipes
 *
 * Goal: Return a list of recipes that you can create in any order
 *
 * Intuition:
 * The naive way that straight come out of my mind is just storing all the supplies in a hash set
 * And then iterate through the recipes and ingredients, if all the ingredients is in the hash set
 * then we are able to make that food.
 * However due to the fact that, a recipe can also be an ingredient for other recipes.
 * So in some order it works, but some dont
 * eg:
 * recipes = ["bread","sandwich","burger"], ingredients =
[["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"] Output:
["bread","sandwich","burger"]
 * This work, what if the recipes is in this order? ["burger", "bread", "sandwich"]
 * then it dont work because burger need sandwich and bread which we dont have initially
 *
 * Then how?
 * We can treat this as a graph and solve it using dfs/bfs. (Choosing dfs over here)
 * We can say the ingredients is the prerequisite of making the recipes.
 * For eg: Burger --> (sandwich, bread, meat) --> [sandwich --> (bread, meat)] --> bread --> (yeast, flour)
 * So we will just traverse down to check the raw ingredient is available or not if yes the not raw ingredient can also
be make like bread and sandwich. We will keep a hash set to track of all the can cook recipe (include raw material as
well, so we can access it in O(1))
 * Also notice one thing the food is not cookable is either we dont have the raw material or it depends on another food
while the food also dependent on it.
 * Therefor, when this happen means there's a cycle in the graph
 * U might wonder why not use UnionFind because it is common to use for detecting cycle
 * Because unionFind is for undirected graph and for this question is directed graph
 *
 *
 * Time Complexity:
 * Populating the hashmap will be O(n) where n is the size of recipes
 * DFS will just simply be visiting all edges and nodes at worst case O(V+E)
 * Iterating through the recipe O(N)
 *
 * Hence, O(V+E+N)
 * */
class Solution
{
  public:
    std::vector<std::string> findAllRecipes(std::vector<std::string> &recipes,
                                            std::vector<std::vector<std::string>> &ingredients,
                                            std::vector<std::string> &supplies)
    {
        std::vector<std::string> answer;

        // Store the food is cookable or not
        std::unordered_map<std::string, bool> can_cook;
        for (const auto &supply : supplies)
            can_cook[supply] = true;

        // store the food index for easy accessing the array
        // to make sure the ingredients is either come from supplies or other food recipe
        std::unordered_map<std::string, int> food_index;
        for (int i{}; i < recipes.size(); i++)
            food_index[recipes[i]] = i;

        // for tracking cycles
        std::unordered_map<std::string, bool> in_progress;

        std::function<bool(const std::string &)> dfs = [&](const std::string &curr_food) {
            // check whether have we ever traverse through this food and check whether
            // is it cookable or not
            // either be raw ingredient or other recipes that can be cook
            if (can_cook.count(curr_food))
                return can_cook[curr_food];

            // detect cycles
            if (in_progress.count(curr_food) && in_progress[curr_food])
                return false;

            // handle if the ingredient is not available from supplies nor recipes
            // because is from supply will straight return from above condition
            if (!food_index.count(curr_food))
                return false;

            // assume the current food is not cookable first
            can_cook[curr_food] = false;
            in_progress[curr_food] = true;

            for (const auto &ingredient : ingredients[food_index[curr_food]])
                if (!dfs(ingredient))
                {
                    in_progress[curr_food] = false;
                    return false;
                }

            return can_cook[curr_food] = true;
        };

        for (const auto &recipe : recipes)
            if (dfs(recipe))
                answer.emplace_back(recipe);
        return answer;
    }
};
