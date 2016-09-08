class Solution {
public:
    string decodeString(string s) {
		stack<pair<int,string>> st;
		pair<int,string> u;
		int k=0;
		string res = "";
		int len = s.length();
		for( int i = 0 ; i < len ; i++ ) {
			if(isdigit(s[i])) {
				k = k*10+s[i]-'0';
			} else if(s[i]=='[') {
				st.push({k,""});
				k = 0;
			} else if(s[i]==']') {
				u = st.top();
				st.pop();
				while(u.first) {
					if(st.empty()) res += u.second;
					else st.top().second += u.second;
					u.first--;
				}
			} else {
				if(st.empty()) res += s[i];
				else st.top().second += s[i];
			}
		}
		while(!st.empty()) {
			u = st.top();
			st.pop();
			while(u.first) {
				res += u.second;
				u.first--;
			}
		}
		return res;
    }
};
