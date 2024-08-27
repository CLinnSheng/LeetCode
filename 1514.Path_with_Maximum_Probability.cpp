#include <bits/stdc++.h>
using namespace std;
using v = pair<double, int>;

/*
Goal: Return the maximum probability from start to end
Intuition: Probability is getting smaller & smaller everytimes we multiply it
Therefore, we try to always select the path with higher probability first
The path with higher probability that reach the end will be the answer (Mathematically)
We can make use of Djikstra Algorithm which return the shortest path, we modify
it to become return the highest probability by using maxheap
*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Create an adjacent List
        vector<vector<v>> adjList(n);
        for (int i = 0; i < edges.size(); i++) {
            int v0 = edges[i][0], v1 = edges[i][1];

            adjList[v0].emplace_back(succProb[i], v1);
            adjList[v1].emplace_back(succProb[i], v0);
        }
        
        // Storing the probability of reaching every single node from start
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;

        // MaxHeap
        priority_queue<v, vector<v>> maxHeap;
        maxHeap.push(make_pair(1, start_node));

        while (!maxHeap.empty()) {

            auto [curr_prob, curr_node] = maxHeap.top();
            maxHeap.pop();

            if (curr_node == end_node)
                return curr_prob;

            for (const auto& [neigh_prob, neigh_node] : adjList[curr_node])
            // Check it whether the probability from start to neigh_node is the highest because we might visit this node before
                if (curr_prob * neigh_prob > prob[neigh_node]) {
                    prob[neigh_node] = curr_prob * neigh_prob;
                    maxHeap.push(make_pair(prob[neigh_node], neigh_node));
                }
        
        }

        return 0;
    }
};