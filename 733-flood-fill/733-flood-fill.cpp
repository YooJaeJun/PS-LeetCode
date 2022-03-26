#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int node) {
        for (int i = 0; i != 4; i++) {
            int nx = sr + dx[i];
            int ny = sc + dy[i];
            if (nx >= 0 && nx < image.size() &&
                ny >= 0 && ny < image[0].size() &&
                visited[nx][ny] == false &&
                image[nx][ny] == node) {

                image[nx][ny] = newColor;
                visited[nx][ny] = true;
                dfs(image, nx, ny, newColor, node);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        visited.resize(image.size());
        for (auto& elem : visited) {
            elem.resize(image[0].size());
        }

        dfs(image, sr, sc, newColor, image[sr][sc]);
        image[sr][sc] = newColor;
        return image;
    }
};