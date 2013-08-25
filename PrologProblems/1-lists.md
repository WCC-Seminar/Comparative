Prolog Problems - 1. Prolog Lists
-------------------------
problems from https://sites.google.com/site/prologsite/prolog-problems/1
/2 はまた別ファイルにしようかなと


###1.01 Find the last element of a list.
List は a (= [a0,a1,..., an]) として 
####C++

######配列
```c++
//int a[n+1];
a[sizeof(a)/sizeof(a[0])-1]
*(a+sizeof(a)-sizeof(a[0]))
```
######STL
```c++
//I used <list> this time. However, you can use <vector>, <set>, <map>, <deck>, or <array> in the same way.
//#include<list>
//std::list<int> a;
*(--a.end()) //or use *(--a.cend()) as a constant.
*a.rbegin()

//if you want to use 2-bit lists, use <bitset>.
//#include<bitset>
//std::bitset<n> a;
a[a.size()-1]
```

#### Python
```python
a[-1]
```
#### Ruby
```ruby
a[-1]
```
```ruby
a.at(-1)
```
```ruby
a.last
```

#### Haskell
```haskell
last a
```
```haskell
head.reverse $ a
```

#### Lua
```lua
a[#a]
```

### 1.02 Find the last but one element of a list.
list は (ry

#### Python
```python
a[-2]
```
#### Ruby
```ruby
a[-2]
```
```ruby
a.at(-2)
```
#### Haskell
```haskell
last.init $ a
```
```haskell
head.tail.reverse $ a
```
