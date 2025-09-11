/*
    Number of Islands

    Problem Statement:
    Given an m x n 2D binary grid `grid` which represents a map of '1's (land) and '0's (water),
    return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands
    horizontally or vertically. You may assume all four edges of the grid are all
    surrounded by water.

    Example 1:
    Input: grid = [
      ["1","1","1","1","0"],
      ["1","1","0","1","0"],
      ["1","1","0","0","0"],
      ["0","0","0","0","0"]
    ]
    Output: 1

    Example 2:
    Input: grid = [
      ["1","1","0","0","0"],
      ["1","1","0","0","0"],
      ["0","0","1","0","0"],
      ["0","0","0","1","1"]
    ]
    Output: 3
*/

#include <iostream>
#include <vector>

/**
 * @brief Performs a Depth-First Search (DFS) to find and "sink" an island.
 *
 * This function is a helper for `numIslands`. It explores a grid from a starting
 * land cell (i, j). It marks the current cell as visited (by changing '1' to '0')
 * and then recursively calls itself for all 4 adjacent cells (horizontally and vertically).
 * This process effectively finds all parts of a single island and marks them as visited
 * so they are not counted again.
 *
 * @param grid The 2D grid representing the map of islands. It is passed by reference
 *             as the function modifies it.
 * @param i The current row index.
 * @param j The current column index.
 */
void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
    // Boundary and water checks
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
        return;
    }
    // Mark the current cell as visited by sinking it
    grid[i][j] = '0';
    // Explore neighbors
    dfs(grid, i + 1, j); // down
    dfs(grid, i - 1, j); // up
    dfs(grid, i, j + 1); // right
    dfs(grid, i, j - 1); // left
}

/**
 * @brief Counts the number of islands in a 2D grid.
 *
 * This function iterates through each cell of the grid. If a cell contains '1' (land),
 * it increments the island counter and then calls a DFS helper function to find and
 * "sink" all parts of that island. This ensures that each island is counted only once.
 *
 * @param grid The 2D grid of characters ('1' for land, '0' for water). The grid will
 *             be modified by the function.
 * @return The total number of islands.
 */
int numIslands(std::vector<std::vector<char>>& grid) {
    if (grid.empty()) {
        return 0;
    }
    int num_islands = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                num_islands++;
                dfs(grid, i, j);
            }
        }
    }
    return num_islands;
}

/**
 * @brief Main function to test the numIslands function.
 * @return 0 on successful execution.
 */
int main() {
    // Example 1
    std::vector<std::vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    std::cout << "Grid 1:" << std::endl;
    std::cout << "Number of islands is: " << numIslands(grid1) << " (Expected: 1)" << std::endl;
    std::cout << "--------------------" << std::endl;

    // Example 2
    std::vector<std::vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    std::cout << "Grid 2:" << std::endl;
    std::cout << "Number of islands is: " << numIslands(grid2) << " (Expected: 3)" << std::endl;
    return 0;
}
