#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <ios>
#include <queue>
#include <utility>

/*
Given that vector<vector<int>>& edges where edges[i] = [ai, bi, wi] indicates there is an edge between nodes a & b with weight w
Some edges have weight of -1 & others might have weights of > 1
Goal: Modify all edges with a weight of -1 by assigning them positive integers in the range of [1, 2*10^9], so that the shortest distance between the nodes source & distance beceoms equal to an integer target

Intuition: Since we want to find the 'shortest path' ---> Obviously we can use Djikstra algorithm as this algorithm is use to find the shortest path
However, we need to tweak the algorithm a little bit because not every edges is weighted properly

1. We try to see is it possible to reach destination from source
2. We compute the distance from source to destination & ignoring the -1 edges at the same time if the distance is lesser than target and thus it is impossible to travel from source to destiantion with target distance
    -> Because it is impossible to increase the path length
3. Compute the distance from source to destination & temporary assign 1 to all -1 edges if greater than target then it is impossible
    -> Because smallest number can be assigned is 1 and already exceed the target already
4. When we try to modify the weight, we just assign all to 1 first except the last 1 we assigned it by target - shortest_distance

Time Complexity: O(E * (V + E)lgV) first part is iterating through the edges & the second part is Djikstra Algo
*/
class Solution {

    const int INF = 2e9;

public:
    std::vector<std::vector<int>> modifiedGraphEdges(int n, std::vector<std::vector<int>>& edges, int source, int destination, int target) {

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        // Construct an adjList by ignoring the edges with -1
        std::vector<std::vector<std::pair<int, int>>> adjList(n);
        for (const auto& edge : edges) 
            if (edge[2] != -1) {
            adjList[edge[0]].emplace_back(edge[1], edge[2]);
            adjList[edge[1]].emplace_back(edge[0], edge[2]); 
        }  
        
        // Checking the first criteria
        int ShortestDistance = Djikstra(adjList, n, source, destination);
        
        // if the current shortest distance is already smaller than the target is impossible to achieve already
        if (ShortestDistance < target) return { };
 
        // Check whether to see is current edges already the shortest distance or not
        bool Matches = ShortestDistance == target;
        
        // Modify the edges weighted -1
        for (auto& edge : edges) {
            
            if (edge[2] != -1) continue;
            
            // if already found the shortest path, we just simply set any value to it, because we wont be using this node already
            edge[2] = Matches ? INF : 1;
            adjList[edge[0]].emplace_back(edge[1], edge[2]);
            adjList[edge[1]].emplace_back(edge[0], edge[2]);
            
            // if already found we not need to compute to find the shortest distance equal to target
            if (!Matches) {
                
                // Compute the shortest distance with newly update edges
                ShortestDistance = Djikstra(adjList, n, source, destination);
                
                if (ShortestDistance == target) Matches = true;
                
                // if we couldnt find the shortest path the ShortestDistance will be INT_MAX
                // if we find it it will be within the target range
                if (ShortestDistance <= target) {
                    Matches = true;
                    edge[2] += target - ShortestDistance;
                }
            } 
        }
        
        return Matches ? edges : std::vector<std::vector<int>>();
    }

        int Djikstra(const std::vector<std::vector<std::pair<int, int>>>& adjList, int n, int source, int destination) {
            
            // Using minHeap data structure for Djikstra Algo
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
            
            // Array to keep track the shortest distnace to every single Node
            std::vector<int> Distance_To_Node(n, INF);
            // A array to keep track the visited nodes
            std::vector<bool> visited(n, false);
            
            Distance_To_Node[source] = 0;
            minHeap.emplace(0, source);
            
            while (!minHeap.empty()) {
                
                auto [currDistance, currNode] = minHeap.top();
                minHeap.pop();
                
                // if the distnace to this node is exceeded the min distance to this node traverse by other path we just skip it
                // because there is no reason to serach from this path
                if (currDistance > Distance_To_Node[currNode]) continue;
                
                for (const auto& [neighNode, weight] : adjList[currNode]) 
                    if (weight + currDistance < Distance_To_Node[neighNode]) {
                        Distance_To_Node[neighNode] = weight + currDistance;
                        minHeap.emplace(Distance_To_Node[neighNode], neighNode);
                    }
                
            }
            
            return Distance_To_Node[destination];
        }
};
