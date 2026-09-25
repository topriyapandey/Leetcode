class Solution {
public:
    int i = 0;
    string expr;
    
    vector<string> braceExpansionII(string expression) {
        expr = expression;
        i = 0;
        set<string> result = parse();
        return vector<string>(result.begin(), result.end());
    }
    
private:
    set<string> parse() {
        set<string> result;
        result.insert("");  
        
        while (i < expr.size() && expr[i] != '}' && expr[i] != ',') {
            set<string> current;
            
            if (expr[i] == '{') {
                i++;  
                current = parseUnion();
                i++;  
            } else {

                current.insert(string(1, expr[i]));
                i++;
            }

            result = concatenate(result, current);
        }
        
        return result;
    }
    set<string> parseUnion() {
        set<string> result = parse();
        
        while (i < expr.size() && expr[i] == ',') {
            i++;
            set<string> next = parse();
            result.insert(next.begin(), next.end());
        }
        
        return result;
    }
    set<string> concatenate(const set<string>& a, const set<string>& b) {
        set<string> result;
        for (const string& s1 : a) {
            for (const string& s2 : b) {
                result.insert(s1 + s2);
            }
        }
        return result;
    }
};