#include <bits/stdc++.h>
using namespace std;

bool visited[10];
int branches[10];
std::vector<int> arr[10];

void BFS(int start)
{
    std::queue<int> queue;
   
    queue.push(start);
    branches[start] = 0;
    visited[start] = true;
    cout << start << " -> " << branches[start] << endl;
   
    while (!queue.empty())
    {
        int x = queue.front();
       
        queue.pop();
       
        for (int i = 0; i < arr[x].size(); i++)
        {
            if (visited[arr[x][i]] == false)
            {
                branches[arr[x][i]] = branches[x] + 1;
                queue.push(arr[x][i]);
                cout << arr[x][i] << " -> " << branches[arr[x][i]] << endl;
                visited[arr[x][i]] = true;
            }
        }
    }
}

int main()
{
    int inpEdges;
    cout << "Enter Edges: ";
    cin >> inpEdges;
    while (inpEdges--)
    {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
    }
    BFS(1);
    return 0;
}
