/**********************************************************************
                C++ STL CHEATSHEET (Striver + Interview Ready)
                Save as: STL_Cheatsheet.cpp
**********************************************************************/

#include <bits/stdc++.h>
using namespace std;

/**********************************************************************
1. PAIR
**********************************************************************/

pair<int,int> p = {1,2};
pair<int,pair<int,int>> nested = {1,{2,3}};
pair<int,int> arr[] = {{1,2},{3,4},{5,6}};

// access
p.first;
p.second;


/**********************************************************************
2. VECTOR  (Most Important)
Dynamic Array
Time Complexity:
push_back()        O(1) amortized
pop_back()         O(1)
size()             O(1)
**********************************************************************/

vector<int> v;

v.push_back(10);
v.emplace_back(20);          // Faster than push_back

vector<pair<int,int>> vp;
vp.push_back({1,2});
vp.emplace_back(3,4);

vector<int> a(5);            // {0,0,0,0,0}
vector<int> b(5,100);        // {100,100,...}
vector<int> c(b);            // copy

v.front();
v.back();

v.size();
v.empty();

v.pop_back();

v.clear();

v.begin();
v.end();

v.rbegin();
v.rend();


// Iteration

for(auto it=v.begin();it!=v.end();it++)
    cout<<*it<<" ";

for(auto x:v)
    cout<<x<<" ";


/**********************************************************************
3. ITERATORS
**********************************************************************/

begin()
end()

rbegin()
rend()

auto it = v.begin();

next(it);
prev(it);


/**********************************************************************
4. LIST
Doubly Linked List
Insertion/Deletion O(1)
**********************************************************************/

list<int> ls;

ls.push_back(1);
ls.push_front(2);

ls.emplace_back(3);
ls.emplace_front(4);

ls.pop_back();
ls.pop_front();


/**********************************************************************
5. DEQUE
Double Ended Queue
**********************************************************************/

deque<int> dq;

dq.push_back(10);
dq.push_front(5);

dq.pop_back();
dq.pop_front();

dq.front();
dq.back();


/**********************************************************************
6. STACK
LIFO
**********************************************************************/

stack<int> st;

st.push(10);
st.emplace(20);

st.top();

st.pop();

st.empty();
st.size();


/**********************************************************************
7. QUEUE
FIFO
**********************************************************************/

queue<int> q;

q.push(10);
q.emplace(20);

q.front();
q.back();

q.pop();

q.empty();


/**********************************************************************
8. PRIORITY QUEUE (Heap)

Default -> Max Heap

Operations:
push()      O(logN)
pop()       O(logN)
top()       O(1)
**********************************************************************/

priority_queue<int> pq;

pq.push(5);
pq.push(10);
pq.push(2);

pq.top();

pq.pop();


// Min Heap

priority_queue<int,
vector<int>,
greater<int>> minHeap;


/**********************************************************************
9. SET
Sorted Unique Elements

insert/find/erase
O(logN)
**********************************************************************/

set<int> s;

s.insert(5);
s.emplace(10);
s.insert(2);
s.insert(5);      // ignored

s.find(10);

s.erase(5);

s.count(10);

s.lower_bound(6);

s.upper_bound(6);


/**********************************************************************
10. MULTISET
Sorted
Duplicates Allowed
**********************************************************************/

multiset<int> ms;

ms.insert(1);
ms.insert(1);
ms.insert(1);

ms.erase(ms.find(1));     // erase one occurrence

ms.count(1);


/**********************************************************************
11. UNORDERED_SET
Hash Table

Average O(1)

Worst O(N)
**********************************************************************/

unordered_set<int> us;

us.insert(5);

us.find(5);

us.erase(5);


/**********************************************************************
12. MAP
Sorted Key-Value

O(logN)
**********************************************************************/

map<int,string> mp;

mp[1]="One";

mp.insert({2,"Two"});

mp.emplace(3,"Three");

cout<<mp[2];

mp.find(1);

mp.erase(2);

mp.count(1);

for(auto x:mp)
    cout<<x.first<<" "<<x.second;


/**********************************************************************
13. MULTIMAP
Duplicate Keys Allowed
**********************************************************************/

multimap<int,int> mm;

mm.insert({1,100});
mm.insert({1,200});


/**********************************************************************
14. UNORDERED_MAP

Average O(1)

Most used in Leetcode
**********************************************************************/

unordered_map<int,int> ump;

ump[10]=20;

ump[30]++;

ump.find(10);

ump.erase(10);


/**********************************************************************
15. ALGORITHMS
**********************************************************************/

vector<int> arr={5,2,7,1,9};

/******** Sorting ********/

sort(arr.begin(),arr.end());

sort(arr.rbegin(),arr.rend()); // descending

sort(arr.begin(),arr.end(),greater<int>());


/******** Reverse ********/

reverse(arr.begin(),arr.end());


/******** Maximum Minimum ********/

*max_element(arr.begin(),arr.end());

*min_element(arr.begin(),arr.end());


/******** Sum ********/

accumulate(arr.begin(),arr.end(),0);


/******** Count ********/

count(arr.begin(),arr.end(),5);


/******** Find ********/

find(arr.begin(),arr.end(),7);


/******** Binary Search ********/

binary_search(arr.begin(),arr.end(),5);


/******** Lower Bound ********/
// first >= x

lower_bound(arr.begin(),arr.end(),5);


/******** Upper Bound ********/
// first > x

upper_bound(arr.begin(),arr.end(),5);


/******** Unique ********/

sort(arr.begin(),arr.end());

arr.erase(unique(arr.begin(),arr.end()),arr.end());


/******** Rotate ********/

rotate(arr.begin(),arr.begin()+2,arr.end());


/******** Next Permutation ********/

next_permutation(arr.begin(),arr.end());


/******** Previous Permutation ********/

prev_permutation(arr.begin(),arr.end());


/******** Fill ********/

fill(arr.begin(),arr.end(),100);


/******** Swap ********/

swap(arr[0],arr[1]);


/**********************************************************************
16. STRING FUNCTIONS
**********************************************************************/

string s="hello";

s.size();

s.length();

s.substr(1,3);

reverse(s.begin(),s.end());

sort(s.begin(),s.end());

getline(cin,s);

stoi("123");

to_string(123);

s.push_back('a');

s.pop_back();


/**********************************************************************
17. NUMERIC FUNCTIONS
**********************************************************************/

__gcd(12,18);          // gcd

lcm(12,18);            // C++17

pow(2,10);

sqrt(49);

abs(-10);

ceil(2.3);

floor(2.9);


/**********************************************************************
18. BIT FUNCTIONS
**********************************************************************/

__builtin_popcount(x);

__builtin_popcountll(x);

__builtin_parity(x);

__builtin_clz(x);

__builtin_ctz(x);


/**********************************************************************
19. LAMBDA FUNCTIONS
**********************************************************************/

sort(arr.begin(),arr.end(),
[](int a,int b){
    return a>b;
});


/**********************************************************************
20. COMPARATORS
**********************************************************************/

bool comp(pair<int,int>a,pair<int,int>b)
{
    if(a.second==b.second)
        return a.first<b.first;

    return a.second>b.second;
}

sort(vp.begin(),vp.end(),comp);


/**********************************************************************
21. IMPORTANT HEADERS

<bits/stdc++.h>

algorithm
vector
queue
stack
set
map
unordered_map
unordered_set
deque
list
numeric
string

**********************************************************************/


/**********************************************************************
22. TIME COMPLEXITIES TO REMEMBER

Vector
------
push_back      O(1)
pop_back       O(1)
access         O(1)

Stack
------
push           O(1)
pop            O(1)

Queue
------
push           O(1)
pop            O(1)

Priority Queue
--------------
push           O(logN)
pop            O(logN)
top            O(1)

Set/Map
-------
insert         O(logN)
erase          O(logN)
find           O(logN)

Unordered Map/Set
-----------------
insert         O(1) average
erase          O(1) average
find           O(1) average

Sort
----
sort()         O(NlogN)

Binary Search
-------------
binary_search  O(logN)
lower_bound    O(logN)
upper_bound    O(logN)

**********************************************************************/


/**********************************************************************
23. INTERVIEW MUST-KNOW STL

★★★★★ vector
★★★★★ unordered_map
★★★★★ unordered_set
★★★★★ map
★★★★★ set
★★★★★ priority_queue
★★★★★ stack
★★★★★ queue
★★★★★ pair
★★★★★ sort()
★★★★★ lower_bound()
★★★★★ upper_bound()
★★★★★ binary_search()
★★★★★ reverse()
★★★★★ accumulate()
★★★★★ next_permutation()
★★★★★ max_element()
★★★★★ min_element()
★★★★★ __gcd()
★★★★★ __builtin_popcount()

**********************************************************************/