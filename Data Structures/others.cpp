*************ROUNDOFF DOUBLE BY 2 digits*******************
		double value = 3.1474985;//
 		stringstream tmp;
		tmp << setprecision(2) << fixed << value;
		value = stod(tmp.str());//value is now precision with 2.


*******Generate binary numbers from 1 to N using a queue.*********
vector<string> generateBinaryStringFrom1ton(int n)
{
    queue<string> q;
    vector<string>v;
    q.push("1");
    while (n--) {
        string s1 = q.front();
        q.pop();
        v.push_back(s1);
        string s2 = s1; // Store s1 before changing it
        // Append "0" to s1 and enqueue it
        q.push(s1.append("0"));
        // Append "1" to s2 and enqueue it. Note that s2
        // contains the previous front
        q.push(s2.append("1"));
    }
    return v;
}


************Binary Exponentiation***********************
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;//divide by 2
    }
    return res;
}
int main()
{
	cout << binpow(2,6);
	return 0;
}


************Split String By Delimeter***********************
vector<string> split(string s,char delim)
{
	vector<string> result;
	int n=s.size(),len=0,b=0;
	for(int i=0 ; i<n ; i++)
	{
		len++;
		if(i==n-1)
		{
			result.push_back(s.substr(b,len));
		}
		else if(s.at(i)==delim)
		{
			result.push_back(s.substr(b,len-1));
			b=i+1;len=0;
		}
	}
	return result;
}


************Range Minimum Query*****************************
const int MAX_N = 500;
int lookup[MAX_N][MAX_N];
void buildSparseTable(vector<int>& arr, int& n)
{
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            if (lookup[i][j - 1] <
                        lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] =
                         lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
int query(int L, int R)
{
    int j = (int)log2(R - L + 1);
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];
    else
        return lookup[R - (1 << j) + 1][j];
}
int main()
{
	vector<int> arr = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
	int n = (int)arr.size();
	buildSparseTable(arr, n);
	cout << query(0, 4) << endl;
    cout << query(4, 7) << endl;
    cout << query(7, 8) << endl;
	return 0;
}


************Get All Subsets*********************************
vector<vector<int>> getAllSubsets(vector<int> sett)
{
    vector<vector<int>> ans;
    int size = (int)sett.size();
    int no_of_subs = (1 << size);//==2^n
    for(int j = 0; j < no_of_subs; ++j)
    {
        vector<int> subset;
        for(int i = 0; i < size; ++i)
        {
            if((j & (1 << i)) != 0)
            {
                subset.push_back(sett[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}


****************KMP Substring occurence find***************************
vector<int> prefix_function(string &s)
{
	int n = s.size();
	vector<int> pi(n);
	for(int i = 1; i < n; i++)
	{
		int j = pi[i - 1];
		while(j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}
vector<int> find_occurences(string &text, string &pattern)
{
	string cur = pattern + '#' + text;
	int sz1 = text.size(), sz2 = pattern.size();
	vector<int> v;
	vector<int> lps = prefix_function(cur);
	for(int i = sz2 + 1; i <= sz1 + sz2; i++)
	{
		if(lps[i] == sz2)
			v.push_back(i - 2 * sz2);
	}
	return v;
}
