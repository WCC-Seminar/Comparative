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

### 1.03 Find the k'th element of a list.

#### C++

#### Python
```python
a[k]
```

#### Ruby
```ruby
a[k]
a.at(k)
```

#### Haskell
```haskell
a !! k
```

### 1.04 Find the number of elements of a list.

#### Python
```python
len(a)
```

#### Ruby
```ruby
a.length
a.length()  # similar variants everywhere.
a.count
```

#### Haskell
```haskell
length a
```

### 1.05 Reverse a list.

#### Python
```python
a.reverse()       # reverses in place
reversed(a)       # returns iterator
list(reversed(a)) # returns reversed list
a[::-1]           # slicing
```

#### Ruby
```ruby
a.reverse  # returns reversed list.
a.reverse! # returns reversed list AND reverses the list in place.
```

#### Haskell
```haskell
reverse a
```

### 1.06 Find out whether a list is a palindrome.
A palindrome can be read forward or backward: e.g. [x,a,m,a,x].

#### Python
```python
a == a[::1]
```
The following script checks one by one.
```python
def is_palindrome(l):
    for i in range(len(l)//2):
        if l[i] != l[-1-i]:
            return False
    return True
```

### 1.07 Flatten a nested list structure.
Transform a list, possibly holding lists as elements into a 'flat' list by replacing each list with its elements (recursively).

#### Ruby
Ruby has a built-in function:
```ruby
a.flatten  # returns the flattened list.
a.flatten! # flattens in place.
```
