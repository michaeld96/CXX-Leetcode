#include <set>
#include <stack>
#include <vector>

[[nodiscard]] std::vector<std::vector<int>> build_adj(const int n, const std::vector<std::vector<int>> &v)
{
  std::vector<std::vector<int>> adj(n);
  for (const std::vector<int> edges : v) {
    const int u = edges[0], v = edges[1];
    adj[u].push_back(v);
  }
  return adj;
}

std::set<int> group_dfs(const int n, const int k, const std::vector<std::vector<int>>& adj_list) {
  std::set<int> group{};
  std::stack<int> s{};
  s.push(k);
  group.insert(k);
  std::vector<bool> visited(n, false);
  while (!s.empty()) {
    int curr_node = s.top();
    s.pop();
    const std::vector<int> edges = adj_list[curr_node];
    for (const int edge : edges) {
      if (!visited[edge]) {
        s.push(edge);
        group.insert(edge);
        visited[edge] = true;
      }
    }
  }
  return group;
}

void dfs(int n, int node, std::vector<std::vector<int>>& adj_list, std::set<int>& group) {
    std::stack<int> s{};
    s.push(node);
    int curr_node = -1;
    std::vector<bool> visited(n, false);
    while(!s.empty()) {
        curr_node = s.top();
        s.pop();
        std::vector<int>& edges = adj_list[curr_node];
        bool not_in_group = group.find(curr_node) == group.end();
        for (const int edge : edges) {
            if (not_in_group 
                && group.find(edge) != group.end()) {
                    group.clear();
            }
            if (!visited[edge]) {
              s.push(edge);
              visited[edge] = true;
            }
        }
    }
}

using std::vector;
vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) 
{
    std::vector<int> methods{};
    auto adj_list = build_adj(n, invocations);
    const auto v = adj_list[k];
    std::set<int> group = group_dfs(n, k, adj_list);
    for (int i = 0; i < n; ++i) {
        dfs(n, i, adj_list, group);
    }
    std::vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (group.find(i) == group.end()) {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
  using std::vector;

  // Test 1
  //   vector<vector<int>> invocations = {
  //   {1, 2 },
  //   {0, 1 },
  //   {3, 2 },
  // };
  // int n = 4, k = 1;

  // Test 2
    vector<vector<int>> invocations = {
    {1, 2 },
    {0, 2 },
    {0, 1 },
    {3, 4 },
  };
  int n = 5, k = 0;
  // Test 3
  //   vector<vector<int>> invocations = {
  //   {1, 2 },
  //   {0, 1 },
  //   {2, 0 },
  // };
  // int n = 3, k = 2;
  remainingMethods(n, k, invocations);

  return 0;
}