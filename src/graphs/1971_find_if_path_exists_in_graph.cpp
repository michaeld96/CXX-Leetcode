#include <cassert>
#include <stack>
#include <vector>

using std::vector;

[[nodiscard]] vector<vector<int>> create_adjacency_list(vector<vector<int>> &edges, int n)
{
    vector<vector<int>> adj(n);
    for (const vector<int>& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    return adj;
}

[[nodiscard]] bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
{
    vector<vector<int>> adj = create_adjacency_list(edges, n);   

    // DFS
    std::stack<int> stack;
    vector<bool> visited(n, false);
    stack.push(source);
    visited[source] = true;


    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        
        if (current == destination) {
            return true;
        }

        for (const int neighbor: adj[current]) {
            if (visited[neighbor]) {
                continue;
            }
            stack.push(neighbor);
            visited[neighbor] = true;
        }

    }

    return false;
}

int main(int argc, char *argv[])
{

    int n = 3;
    vector<vector<int>> edges{
        {0, 1}, 
        {1, 2},
        {2, 0}
    };

    bool result = validPath(n, edges, 0, 2);

    assert(result == true);

    return 0;
}

