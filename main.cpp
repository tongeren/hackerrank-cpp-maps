#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Query {
    public:
    int type;
    int marks;
    Query();
    Query(int type, int marks=0);
};

Query::Query() {
    type = 0;
    marks = 0;
}

Query::Query(int type, int marks) {
    Query::type = type;
    Query::marks = marks;
}

template <typename T, typename S>
bool key_exists(map<T,S>& mp, T& key) {
    typename map<T,S>::iterator it = mp.find(key);
    return it==mp.end() ? false : true;
}

void execute_queries(vector<pair<string, Query>>& v) {
    int n = v.size();
    map<string, int> mp;
    Query qry;
    string name;
    int type, marks = 0;
    for (int i=0; i<n; i++) {
        name = v[i].first;
        qry = v[i].second;
        if (key_exists(mp, name)) {
            marks = mp[name];
        } else {
            marks = 0;
            // insert in map
            mp.insert(make_pair(name, marks));
        }
        type = qry.type;
        switch (type) {
            case 1: 
               marks += qry.marks;
               // update marks
               mp[name] = marks;
               break;
            case 2:
               // reset marks
               mp[name] = 0;
               break; 
            case 3:
               // print marks
               cout << marks << endl;
               break;
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long q;
    
    cin >> q;
    
    int type, marks;
    string name;    
    vector<pair<string, Query>> vp;
    Query qry;

    // Since 1<=marks<=1000 we can take marks=0 in case of type 2 or 3
    for (int i=0; i<q; i++) {
        cin >> type >> name;

        if (type==1) { 
            cin >> marks; 
            qry = Query(type, marks);
        } else {
            qry = Query(type);
        }

        vp.push_back(make_pair(name, qry));
    }

    execute_queries(vp);

    return 0;
}
