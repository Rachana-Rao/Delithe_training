#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

    vector<int> leftnearer(vector<int> &heights)
    {
     vector<int> v;
        stack<pair<int,int>> s;

        for(int i=0;i<heights.size();i++)
        {
            if(s.size()==0)
            {
               v.push_back(-1);
            }else if(s.size()>0 && s.top().first<heights[i])
            {
                v.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=heights[i])
            {
                while(s.size()>0 && s.top().first>=heights[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                {
                    v.push_back(-1);
                }else
                {
                    v.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }

        return v;

    }

    vector<int> rightnearer(vector<int> &heights)
    {
       vector<int> v;
        stack<pair<int,int>> s;

        for(int i=heights.size()-1;i>=0;i--)
        {
            if(s.size()==0)
            {
               v.push_back(heights.size());
            }else if(s.size()>0 && s.top().first<heights[i])
            {
                v.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=heights[i])
            {
                while(s.size()>0 && s.top().first>=heights[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                {
                    v.push_back(heights.size());
                }else
                {
                    v.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        reverse(v.begin(),v.end());
        return v;

    }



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

