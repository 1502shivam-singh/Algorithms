#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int32_t bfs_multisource(vector<vector<int32_t>> grid)
{
	queue<pair<int32_t, int32_t>> cache;
	bool hasWater = 0;
	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j= 0; j < grid[i].size(); j++)
		{
			if(grid[i][j] == 1) 
			{
				cache.push(make_pair(i, j));
				grid[i][j] = -1;
			}
			else 
			{
				hasWater = 1;
			}
		}
	}

	if (!hasWater || cache.empty()) { return -1; }

	vector<pair<int32_t, int32_t>> dir = { {-1,0},{0,1},{1,0},{0,-1} };
	
	int32_t distance = 0;
	
	while(!cache.empty()) 
	{
		pair<int32_t, int32_t> index = cache.front();
		cache.pop();
		for (size_t i = 0; i < dir.size(); i++)
		{
			pair<int32_t, int32_t> node = make_pair(index.first + dir[i].first, index.second + dir[i].second);
			if((node.first >= 0 && node.first < grid.size()) && (node.second >= 0 && node.second < grid[0].size()))
			{
				if(grid[node.first][node.second] == 0) 
				{
					if(grid[index.first][index.second] == -1) 
					{
						grid[node.first][node.second]++;
						if (grid[node.first][node.second] > distance) { distance = grid[node.first][node.second]; }
					}
					else 
					{
						grid[node.first][node.second] = grid[index.first][index.second] + 1;
						if (grid[node.first][node.second] > distance) { distance = grid[node.first][node.second]; }
					}
					cache.push(node);
				}
			}
		}
	}
	return distance;
}

int main() 
{
	int32_t value = bfs_multisource(routes);
	cin.get();
}
