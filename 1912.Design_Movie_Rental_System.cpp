#include <algorithm>
#include <cstdint>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;

/*
 * Search ->  Find the cheapest 5 shops that have an unrented copy. -> Priority Queue
 * Rent -> Rents an unrented copy
 * Drop -> Drop a previously rented copy
 * Report -> Return the cheapest 5 rented movie -> Priority Queue
 * Intuition:
 * need to maintain a map of movies to shops that have unrented copies. map from movie to a minHeap
 * then another minHeap that hold the rented 5 movies
 * */
using int2 = std::pair<int, int>;
using int3 = std::tuple<int, int, int>;
class MovieRentingSystem
{
  public:
    std::unordered_map<std::uint64_t, int> Shop; // (shop,movie)->price
    std::set<int3> rented;                       // rented->set (price,shop,movie)
    std::set<int2> Movie[10001];                 // movie

    static inline std::uint64_t key(int shop, int movie)
    {
        return (std::uint64_t)shop << 32 | movie;
    }
    int mm = 10001, MM = 0;
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (auto &e : entries)
        {
            int shop = e[0], movie = e[1], price = e[2];
            Shop[key(shop, movie)] = price;
            Movie[movie].insert({price, shop});
            mm = std::min(mm, movie);
            MM = std::max(MM, movie);
        }
    }
    ~MovieRentingSystem()
    {
        fill(Movie + mm, Movie + MM + 1, std::set<int2>());
    }
    vector<int> search(int movie)
    {
        vector<int> ans;
        auto &S = Movie[movie];
        int i = 0;
        for (auto it = S.begin(); it != S.end() && i < 5; it++, i++)
        {
            ans.push_back(it->second); // shop
        }
        return ans;
    }

    void rent(int shop, int movie)
    {
        int price = Shop[key(shop, movie)];
        Movie[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int price = Shop[key(shop, movie)];
        Movie[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> ans;
        int i = 0;
        for (auto it = rented.begin(); it != rented.end() && i < 5; it++, i++)
        {
            auto [price, shop, movie] = *it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
