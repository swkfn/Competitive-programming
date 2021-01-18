#include <bits/stdc++.h>
#define ll long long
#define p pair<int, int>
using namespace std;

int main() {
    int h, w;
    int sy, sx, gy, gx;
    cin >> h >> w;
    cin >> sy >> sx >> gy >> gx;
    sy--, sx--, gy--, gx--;
    string grid[h];
    for (int i = 0; i < h; i++) cin >> grid[i];
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, -1, 0, 1};
    vector<vector<int> > dist(h, vector<int>(w, 1e9));
    queue<p> que, vis;
    que.push(p(sy, sx));
    dist[sy][sx] = 0;
    while (!que.empty() || !vis.empty()) {
        if (!que.empty()) {
            int cy = que.front().first;
            int cx = que.front().second;
            que.pop();
            vis.push(p(cy, cx));
            for (int i = 0; i < 4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (0 <= nx && nx < w && 0 <= ny && ny < h) {
                    if (grid[ny][nx] == '#') continue;
                    if (dist[ny][nx] > dist[cy][cx]) {
                        dist[ny][nx] = dist[cy][cx];
                        que.push(p(ny, nx));
                    }
                }
            }
        } else {
            int cy = vis.front().first;
            int cx = vis.front().second;
            vis.pop();
            for (int i = -2; i <= 2; i++) {
                for (int j = -2; j <= 2; j++) {
                    int ny = cy + i;
                    int nx = cx + j;
                    if (0 <= nx && nx < w && 0 <= ny && ny < h) {
                        if (grid[ny][nx] == '#') continue;
                        if (dist[ny][nx] > dist[cy][cx] + 1) {
                            dist[ny][nx] = dist[cy][cx] + 1;
                            que.push(p(ny, nx));
                        }
                    }
                }
            }
        }
    }
    cout << (dist[gy][gx] == 1e9 ? -1 : dist[gy][gx]) << endl;
    return 0;
}
