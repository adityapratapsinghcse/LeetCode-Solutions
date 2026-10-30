class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // {distance, node, consecutive count}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [d, u, count] = pq.top();
            pq.pop();

            if (d != dist[u][count])
                continue;

            for (auto [v, w] : adj[u]) {

                int newCount;

                if (labels[u] == labels[v]) {
                    newCount = count + 1;
                } 
                else {
                    newCount = 1;
                }

                if (newCount > k)
                    continue;

                int newDist = d + w;

                if (newDist < dist[v][newCount]) {

                    dist[v][newCount] = newDist;

                    pq.push({
                        newDist,
                        v,
                        newCount
                    });
                }
            }
        }

        int ans = INF;

        for (int i = 1; i <= k; i++) {
            ans = min(ans, dist[n - 1][i]);
        }

        return ans == INF ? -1 : ans;
    }
};