#include "stdio.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <queue>

using namespace std;

const string EMPTY_GRID = ".";

struct Tile
{
	string tile = EMPTY_GRID;

	// top, bot, left, right
	int id[4] = { -1, -1, -1, -1 };
};

const vector<Tile> options =
{
	Tile { "┌", {0, 1, 0, 1} },
	Tile { "├", {1, 1, 0, 1} },
	Tile { "┤", {1, 1, 1, 0} },
	Tile { "└", {1, 0, 0, 1} },
	Tile { "│", {1, 1, 0, 0} },
	Tile { "┬", {0, 1, 1, 1} },
	Tile { "┴", {1, 0, 1, 1} },
	Tile { "─", {0, 0, 1, 1} },
	Tile { "┼", {1, 1, 1, 1} },
};

void render_grid(const vector<vector<Tile>>& grid)
{
	const int height = grid.size();
	const int width = grid[0].size();
	for (int i = 0; i < height; ++i)
	{
		printf("\n");
		for (int j = 0; j < width; ++j)
		{
			printf("%s", grid[i][j].tile.c_str());
		}
	}
}

vector<vector<int>> update_grid(int i, int j, vector<vector<Tile>>& grid)
{
	const int height = grid.size();
	const int width = grid[0].size();
	vector<vector<int>> children;

	if (i < 0 || i >= height || j < 0 || j >= width || grid[i][j].tile != EMPTY_GRID)
	{
		return children;
	}

	// get the neighbor's side attribute
	// @note. -1 means doesn't care
	const int get_top = i - 1 >= 0 ? grid[i - 1][j].id[1] : -1;
	const int get_bot = i + 1 < height ? grid[i + 1][j].id[0] : -1;
	const int get_left = j - 1 >= 0 ? grid[i][j - 1].id[3] : -1;
	const int get_right = j + 1 < width ? grid[i][j + 1].id[2] : -1;

	vector<Tile> possible; 
	for (const auto& option: options)
	{
		// filter possible options
		const bool check_top = get_top == -1 || option.id[0] == get_top;
		const bool check_bot = get_bot == -1 || option.id[1] == get_bot;
		const bool check_left = get_left == -1 || option.id[2] == get_left;
		const bool check_right = get_right == -1 || option.id[3] == get_right;

		if (check_top && check_bot && check_left && check_right)
		{
			possible.emplace_back(option);
		}
	}
		
	// pick one of them
	int rand_type = rand() % possible.size();
	grid[i][j] = possible[rand_type];

	if (i - 1 >= 0 && j >= 0 && j < width && grid[i - 1][j].tile == EMPTY_GRID)
	{
		children.push_back({ i - 1, j });
	}
	
	if (i + 1 < height && j >= 0 && j < width && grid[i + 1][j].tile == EMPTY_GRID)
	{
		children.push_back({ i + 1, j });
	}
	
	if (i >= 0 && i < height && j - 1 >= 0 && grid[i][j - 1].tile == EMPTY_GRID)
	{
		children.push_back({ i, j - 1 });
	}
	

	if (i >= 0 && i < height && j + 1 < width && grid[i][j + 1].tile == EMPTY_GRID)
	{
		children.push_back({ i, j + 1 });
	}

	return children;
}

int main()
{
	system("cls");
	printf("type in size of grid: ");
	int width = 0;
	int height = 0;
	cin >> width;
	cin >> height;

	srand(time(nullptr));

	vector<vector<Tile>> grid;
	for (int i = 0; i < height; ++i)
	{
		vector<Tile> row(width);
		grid.emplace_back(row);
	}

	auto queue = update_grid(0, 0, grid);
	system("cls");
	render_grid(grid);
	this_thread::sleep_for(chrono::milliseconds(50));

	while (queue.empty() == false)
	{
		vector<vector<int>> next_queue;
		for (const auto& child : queue)
		{
			vector<vector<int>> candidate = update_grid(child[0], child[1], grid);
			next_queue.insert(next_queue.end(), candidate.begin(), candidate.end());
		}

		queue.clear();
		queue = next_queue;

		system("cls");
		render_grid(grid);
		this_thread::sleep_for(chrono::milliseconds(50));
	}

	return 0;
}
