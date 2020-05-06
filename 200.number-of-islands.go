/*
 * @lc app=leetcode id=200 lang=golang
 *
 * [200] Number of Islands
 */

// @lc code=start
func numIslands(grid [][]byte) int {
	if grid == nil || len(grid) == 0 {
		return 0
	}
	answer := 0
	rowLength := len(grid)
	colLength := len(grid[0])
	for i := 0; i < rowLength; i++ {
		for j := 0; j < colLength; j++ {
			answer += bfs(i, j, grid)
		}
	}
	return answer
}

func bfs(x int, y int, grid [][]byte) int {
	if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[0]) || string(grid[x][y]) != "1" {
		return 0
	}
	grid[x][y] = byte('0')
	bfs(x+1, y, grid)
	bfs(x-1, y, grid)
	bfs(x, y+1, grid)
	bfs(x, y-1, grid)
	return 1
}

// @lc code=end
