#include <cassert>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

void dfs(vector<int>& visited, vector<vector<int>>& adj_matrix, int city)
{

    stack<int> s;
    s.push(city);
    visited[city] = true;

    while (!s.empty()) {
        int current = s.top();
        s.pop();
        const vector<int>& adj_list = adj_matrix[current];
        for (int neighbor = 0; neighbor < adj_list.size(); ++neighbor) {
            if (visited[neighbor]) {
                continue;
            }
            if (adj_list[neighbor] == 1) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }

    return;
}

[[nodiscard]] int findCircleNum(vector<vector<int>>& isConnected)
{
    int providences = 0;
    vector<int> visited(isConnected.size());

    for (std::size_t city = 0; city < isConnected.size(); ++city) {
        if (visited[city]) {
            continue;
        }
        dfs(visited, isConnected, city);
        ++providences;
    }

    return providences;
}

int main()
{
    // example 1:
    // vector<vector<int>> is_connected = {
    //     {1, 1, 0},
    //     {1, 1, 0},
    //     {0, 0, 1},
    // };
    // result == 2

    // example 2:
    // vector<vector<int>> is_connected = {
    //     {1, 0, 0},
    //     {0, 1, 0},
    //     {0, 0, 1},
    // };
    // result == 1

    // example 3:
    vector<vector<int>> is_connected = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1},
    };
    // result == 1

    int result = findCircleNum(is_connected);

    assert(result == 1);

    return 0;
}