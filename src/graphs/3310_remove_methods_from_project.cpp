#include <algorithm>
#include <set>
#include <stack>
#include <vector>

// build adj.

// From adj do a dfs from problem node to the end. Make this a vector (lets call this a problem group).

// for the remaining group, see if u is NOT part of the group and points to something in the group the 
// removal is impossible.

[[nodiscard]] std::vector<std::vector<int>> create_adj_list(const int n, std::vector<std::vector<int>>& v)
{
  std::vector<std::vector<int>> adj_list(n);
  for (const std::vector<int> edge : v) {
    int u = edge[0], v = edge[1];
    adj_list[u].push_back(v);
  }

  return adj_list;
}

[[nodiscard]] std::vector<bool> group_dfs(const int n, const int k, std::vector<std::vector<int>>& adj_list)
{
  std::stack<int> s;
  // true at index if suspicious.
  std::vector<bool> group(n, false);
  s.push(k);
  group[k] = true;
  // since this graph can be cyclic there must be a visted list to curb adding the same node twice.
  std::vector<bool> visited(n, false);
  visited[k] = true;
  while (!s.empty()) {
    int curr_node = s.top();
    s.pop();
    std::vector<int> edges = adj_list[curr_node];
    for (const int edge : edges) {
      if (!visited[edge]) {
        visited[edge] = true;
        group[edge] = true;
        s.push(edge);
      }
    }
  } 
  return group;
}

std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) 
{
    std::vector<int> methods{};
    methods.reserve(n);
    std::vector<std::vector<int>> adj_list = create_adj_list(n, invocations);
    std::vector<bool> group = group_dfs(n, k, adj_list);
    bool can_remove = true;
    for (const auto& edge : invocations) {
      int u = edge[0], v = edge[1];
      if (!group[u] && group[v]) {
        can_remove = false;
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (can_remove && group[i]) {
        continue;
      }
      methods.push_back(i);
    }
    return methods;
}

int main()
{
  using std::vector;

  // Test 1
    vector<vector<int>> invocations = {
    {1, 2 },
    {0, 1 },
    {3, 2 },
  };
  int n = 4, k = 1;

  // Test 2
  //   vector<vector<int>> invocations = {
  //   {1, 2 },
  //   {0, 2 },
  //   {0, 1 },
  //   {3, 4 },
  // };
  // int n = 5, k = 0;
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