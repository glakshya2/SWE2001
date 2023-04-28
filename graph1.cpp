#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

void breadthFirst(vector<list<int>> arr, int start, int n)
{
    queue<int> q1;
    bool visited[n];
    for (int i = 0; i < n + 1; i++)
    {
        visited[i] = false;
    }
    q1.push(start);
    while (!q1.empty())
    {
        visited[q1.front()] = true;
        int a = q1.front();
        for (auto i : arr[a])
        {
            int x = i;
            if (!visited[i])
            {
                q1.push(i);
                visited[i] = true;
            }
        }
        cout << q1.front() << " ";
        q1.pop();
    }
}

void depthFirst(vector<list<int>> arr, int start, int n)
{
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty())
    {
        int a = s.top();
        for (auto i : arr[a])
        {
            if (!visited[i])
            {
                s.push(i);
                visited[i] = true;
                cout << i << " ";
                s.pop();
            }
            else
            {
                s.pop();
            }
        }
    }
}

int main(void)
{
    int n;
    cout << "Enter number of nodes\n";
    cin >> n;
    vector<list<int>> arr(n);
    int m;
    cout << "Enter number of edges\n";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter nodes of edge " << i << "\n";
        int j, k;
        cin >> j >> k;
        arr[j].push_back(k);
        arr[k].push_back(j);
    }
    cout << "Enter start node: \n";
    int s;
    cin >> s;
    cout << "BreadthFirst: \n";
    breadthFirst(arr, s, n);
    cout << "\n Enter for depth: \n";
    cin >> s;
    depthFirst(arr, s, n);
}