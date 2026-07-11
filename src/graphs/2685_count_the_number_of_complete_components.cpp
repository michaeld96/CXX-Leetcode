#include <algorithm>
#include <cassert>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

[[nodiscard]] vector<vector<int>> build_adjacency_list(vector<vector<int>>& edges, int vertices)
{
    vector<vector<int>> adj_list(vertices);
    for (const vector<int>& edge : edges) {
        const int u = edge[0], v = edge[1];
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    return adj_list;
}

// Returns true if the connected component containing node is complete.
[[nodiscard]] bool dfs(int node, vector<int>& visited, const vector<vector<int>>& adj_list) 
{
    stack<int> s;
    s.push(node);
    visited[node] = true;
    vector<int> degrees;

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        const auto& edge = adj_list[current];
        degrees.push_back(0);
        for (const int v : edge) {
            if (!visited[v]) {
                s.push(v);    
            }
            visited[v] = true;
            degrees.back()++;
        }
    }

    bool all_same =  degrees.empty() 
        || std::all_of(degrees.begin(), degrees.end(), [first = degrees[0]](int x) {
            return x == first;
        });
    
        if (all_same) {
            // check to see if it's complete. We have the number of vertices, so a complete graph
            // will have a vertex tired to every other vertex. Formula: n - 1 where n is the number
            // of vertices, if a graph has n - 1 vertices then it's complete.
            int complete_degree = degrees.size() - 1;
            return degrees.back() == complete_degree;
        } else {
            return false;
        }
}

[[nodiscard]] int countCompleteComponents(int n, vector<vector<int>>& edges)
{
    int complete_components = 0;

    const auto adj_list = build_adjacency_list(edges, n);
    vector<int> visited(n, 0);

    for (int v = 0; v < n; ++v) {
        if (!visited[v] && dfs(v, visited, adj_list)) {
            complete_components++;
        }
    }

    return complete_components;
}

int main()
{
    // test case 1:
    // vector<vector<int>> edges = {
    //     {0, 1},
    //     {0, 2},
    //     {1, 2},
    //     {3, 4}
    // };
    // int n = 6;
    // result == 3;

    // test case 2:
    vector<vector<int>> edges = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };
    int n = 4;

    int result = countCompleteComponents(n, edges);
    assert(result == 3);
    return 0;
}

