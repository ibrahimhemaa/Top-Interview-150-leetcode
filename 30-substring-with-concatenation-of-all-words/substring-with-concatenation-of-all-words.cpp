class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wcount = words.size(), wlen = words[0].length();
        if (s.size() < wcount * wlen)
            return vector<int>();

        map<string, int> ws;
        for (string word : words) {
            if (ws.find(word) == ws.end())
                ws[word] = 0;
            ws[word]++;
        }

        vector<int> res;
        vector<map<string, int>> wss;
        for (int i = 0; i < wlen; i++) {
            if (i + wcount * wlen > s.size()) {
                break;
            }

            map<string, int> cws;
            for (int j = 0; j < wcount; j++) {
                string cw = s.substr(i + j * wlen, wlen);
                if(ws.find(cw) != ws.end()) {
                    if (cws.find(cw) == cws.end())
                        cws[cw] = 0;
                    cws[cw]++;
                }
            }

            wss.push_back(cws);
        }

        int l = 0, r = wcount * wlen;
        while (r <= s.length()) {
            map<string, int>& cws = wss[l % wlen];
            if (cws == ws) {
                res.push_back(l);
            }
            if (r + wlen <= s.length()) {
                string o = s.substr(l, wlen), n = s.substr(r, wlen);
                if(ws.find(o) != ws.end()) {
                    cws[o]--;
                    if (cws[o] == 0) {
                        cws.erase(o);
                    }
                }
                if(ws.find(n) != ws.end()) {
                    if (cws.find(s.substr(r, wlen)) == cws.end())
                        cws[s.substr(r, wlen)] = 0;
                    cws[s.substr(r, wlen)]++;
                }
            }
            l++;
            r++;
        }
        return res;
    }
};