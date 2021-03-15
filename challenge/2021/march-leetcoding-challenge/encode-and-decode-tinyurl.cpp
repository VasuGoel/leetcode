class Solution {
    unordered_map<string, string> urls;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code;
        do  code = generateHash();
        while(urls.count(code));
        
        urls[code] = longUrl;
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urls[shortUrl.substr(shortUrl.size()-6)];
    }
    
    string generateHash() {
        string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", hash;
        while((int)hash.size() < 6)
            hash += s[rand() % s.size()];
        return hash;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
