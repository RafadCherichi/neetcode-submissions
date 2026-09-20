class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // ---------------------------------------------------------
        // STEP 1: Build the Adjacency List (The Graph)
        // ---------------------------------------------------------
        // We need a structure where each node points to its neighbors and the travel time.
        // graph[u] will store a list of pairs: {neighbor_node, travel_time}
        // Size is n + 1 because nodes are 1-indexed (from 1 to n).
        vector<vector<pair<int, int>>> graph(n + 1);
        
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0]; // From node
            int v = times[i][1]; // To node
            int w = times[i][2]; // Travel time weight
            
            graph[u].push_back({v, w}); // Add directed edge
        }
        
        // ---------------------------------------------------------
        // STEP 2: Initialize Distances and the Min-Heap
        // ---------------------------------------------------------
        // dist[i] stores the shortest time found so far from start node 'k' to node 'i'.
        // We initialize all of them to infinity (INT_MAX) meaning "not reached yet".
        vector<int> dist(n + 1, INT_MAX);
        
        // Min-heap (priority queue) ensures we always pick the path with the smallest time first.
        // It stores pairs of: {accumulated_time, current_node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Base case: The time to reach the starting node 'k' from itself is 0.
        dist[k] = 0;
        pq.push({0, k}); // Push the starting point into our min-heap
        
        // ---------------------------------------------------------
        // STEP 3: The Dijkstra Loop (Exploring the network)
        // ---------------------------------------------------------
        while (!pq.empty()) {
            
            // Pull out the node that currently has the smallest accumulated time
            int current_time = pq.top().first;
            int current_node = pq.top().second;
            pq.pop(); // Remove it from the heap so we don't process it again
            
            // Optimization check: 
            // If we already found a faster way to this node previously, ignore this outdated entry.
            if (current_time > dist[current_node]) {
                continue;
            }
            
            // Look at all neighboring nodes connected to our current node
            for (int i = 0; i < graph[current_node].size(); i++) {
                int neighbor_node = graph[current_node][i].first;
                int travel_time = graph[current_node][i].second;
                
                // Calculate the total time it takes to reach this neighbor through our current path
                int total_time = current_time + travel_time;
                
                // If this new path is faster than any previously recorded path to this neighbor...
                if (total_time < dist[neighbor_node]) {
                    dist[neighbor_node] = total_time;         // Update with the new, shorter time
                    pq.push({total_time, neighbor_node});     // Push it into the heap to explore its neighbors later
                }
            }
        }
        
        // ---------------------------------------------------------
        // STEP 4: Find the maximum time required to reach everyone
        // ---------------------------------------------------------
        int max_time = 0;
        
        for (int i = 1; i <= n; i++) {
            // If any node still has INT_MAX, it means it was never reached by the signal!
            if (dist[i] == INT_MAX) {
                return -1; 
            }
            
            // The signal is fully done spreading when the *last* node receives it.
            // Therefore, we want the maximum value out of all shortest times.
            max_time = max(max_time, dist[i]);
        }
        
        return max_time;
    }
};