Prolog Problems - 1. Prolog Lists
-------------------------
problems from https://sites.google.com/site/prologsite/prolog-problems/1
/2 はまた別ファイルにしようかなと


### 1.01 Find the last element of a list.
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

#### Ruby
```ruby
a == a.reverse
```
check one by one?
```ruby
def is_palindrome(l)
  (1 .. l.length/2).each do |i|
    unless l[i] == l[-1-i]
      return false
    end
  end
  return true
end
```

#### Haskell
```haskell
a == reverse a
```

### 1.07 Flatten a nested list structure.
Transform a list, possibly holding lists as elements into a 'flat' list by replacing each list with its elements (recursively).

#### Python
Recursion.
```python
def flatten_tail(l, heads):
    while l != []:
        if isinstance(l[0], list):
            try:
                return flatten_tail( l[0] + l[1:], heads)
            except:
                return flatten_tail( l[0], heads)
        else:
            heads.append(l.pop(0))
    return heads

def flatten(l):
    return flatten_tail(l,[])

flatten(a)
```
Knowing this is a kind of cheating: the following script first converts the list to string ('[1,2,[3,[4,5]]]'), remove all the '[' ']'s, then re-evaluates with surrounding [].
```python
def flatten(l):
    return eval('['+repr(l).replace('[','').replace(']','')+']')
```
Never knew this
```python
from compiler.ast import flatten
flatten(a)
```

#### Ruby
Ruby has a built-in function:
```ruby
a.flatten  # returns the flattened list.
a.flatten! # flattens in place.
```

### 1.08 Eliminate consecutive duplicates of list elements.
If a list contains repeated elements they should be replaced with a single copy of the element.
The order of the elements should not be changed. 

#### Python
```python
def compress(l):
    compressed = []
    while l != []:
        try:
            if l[0] == compressed[-1]:
                l.pop(0)
            else:
                compressed.append( l.pop(0) )
        except:
            compressed.append( l.pop(0) )
    return compressed
```

#### Haskell
```haskell
compresstail [] compressed = reverse compressed
compresstail (x:xs) []   = compresstail xs [x]
compresstail (x:xs) compressed
    | x == (head compressed) = compresstail xs compressed
    | otherwise              = compresstail xs (x:compressed)

compress l = compresstail l []
```
