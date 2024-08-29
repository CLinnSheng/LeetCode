#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
Goal: Return most stones removed
Constraint: The stone can only be removed if it shares either the same row or the same column as another stone that has not been removed

Intuition: 
In a connected component, we can always remove all stones except one
Moves in one connected component doesnt affect other connected component
Each stones belonged to 1 component only
So this lead to the formula for finding the number of stoned removed = total stones - total number of connected component 

Since involved with connected component, we can use Union Find Data Structure
If the stone shared the same row or col will unify them together also means that connected them together into a single one component
But this method will be very tedious because we will be looping twice --> time complexity O(n2)
Instead of that we break down each stone into 2 entities: row index & column index
By doing so all stones that share the same row or column index become implicitly connected (eliminating the need of connecting the stones within the same row or column)
We will only need to connect the row and column indices of a stone. Time Complexity is reduced to O(n)

eg: [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
  0 1 2
0 x x
1 x   x
2   x x
Seperate each stones into 2 entitties (row & col)
row: group0, 1, 2
col: group0, 1, 2
for i in 0 to n
then we union(stone[i].row, stone[i].col) trying to connect the stones together through union the row & col
in the end will only left 1 group means we got 1 connected component
*/  
class UnionFind {
  
    private:
        std::vector<int> parent; // Track the parent of each node
        std::unordered_set<int> Node; // Set to track nodes
        
    public:
        int component_cnt; // Track the number of component

        UnionFind(int x) {
            parent.resize(x, -1); // Initialize all node is their own parent
            component_cnt = 0;
        }
        
        int find(int node) {
            
            if (Node.count(node) == 0) {
                Node.insert(node);
                component_cnt++;
            }
            
            if (parent[node] == -1) return node;
            
            return parent[node] = find(parent[node]);
        }
        
        void unionNodes(int node1, int node2) {
            int parent1 = find(node1);
            int parent2 = find(node2);
            
            // if they are already connected can skip
            if (parent1 == parent2) return;
            
            // Connect the whole structure of node1 to under node2
            parent[parent1] = parent2;
            component_cnt--; // Since we connect it, the number of individual count will be decrease
        }
        
};
class Solution {
public:
    int removeStones(std::vector<std::vector<int>>& stones) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);


        UnionFind u(20001); // To ensure it can hold for all coordinates
        
        for (const std::vector<int>& stone : stones)
            u.unionNodes(stone[0], stone[1] + 10001); // Add offset to deal with the same x & y value
            
        return stones.size() - u.component_cnt;
    }
};