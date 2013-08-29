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
  (0 .. l.length/2).each do |i|
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
Yay itertools!
```python
import itertools
def compress(l):
    return [key for (key,group) in itertools.groupby(l)]
```

#### Haskell

```haskell
compress (x:[]) = x:[]
compress (x:xs) 
       | x == head xs = compress xs
       | otherwise    = x:compress xs
```
tail recursion (?)
```haskell
compresstail [] compressed = reverse compressed
compresstail (x:xs) []   = compresstail xs [x]
compresstail (x:xs) compressed
    | x == (head compressed) = compresstail xs compressed
    | otherwise              = compresstail xs (x:compressed)

compress l = compresstail l []
```

### 1.09 Pack consecutive duplicates of list elements into sublists.
If a list contains repeated elements they should be placed in separate sublists.

#### Python
itertools.
```python
import itertools
def pack(l):
    return [list(group) for (key,group) in itertools.groupby(l) ]
```
of course, we can do something like
```python
def pack(l):
    packed = []
    buff = []
    while l != []:
        try:
            if l[0] == buff[0]:
                buff.append( l.pop(0) )
            else:
                packed.append( buff )
                buff = []
        except:
            buff.append( l.pop(0) )
    if buff != []:
        packed.append( buff )
    return packed
```

### 1.10 Run-length encoding of a list.

Use the result of problem 1.09 to implement the so-called run-length encoding data comopression method. Consequtive duplicates of elements are encoded as terms [N, E] where N is the number of duplicates of the element E.

(Do we have to use the result of problem 1.09?)

#### Python
If we use the result of previous problem:
```python
def encode(l):
    return [ [len(g), g[0] ] for g in pack(l) ] 
```
without that:
```python
import itertools
def encode(l):
    return [ [len(list(group)),key] for (key,group) in itertools.groupby(l) ]
```

#### Haskell
```haskell
encode [] = []
encode (x:xs) = [1 + length ( takeWhile (==x) xs ), x] 
                 : encode ( dropWhile (==x) xs )
```

### 1.11 Modified run-length encoding.

Modify the result of problem 1.10 in such a way that if an element has no duplicates it is simply copied into the result list. 
Only elements with duplicates are transferred as [N,E] terms.

#### Python
```python
def encode_modified(l):
    return map(lambda g: g[0] if len(g) == 1 else [len(g), g[0]], pack(l))
```

### 1.12 Decode a run-length encoded list.

Given a run-length code list generated as specified in problem 1.11, Construct its uncompressed version.

 Note : ```[[3,2], [1,3], [1,3]]``` -> compressed : [[3,2], [2,[1,3]]] -> decode : ```[2,2,2, [1,3], [1,3]``` ... AAgh!
Thus let us assume 'good faith'. Nothing unpleasant shall be given.

#### Python
Using higher functions. One-liner but doesn't seem to be clever nor standard.
```python
def decode(code):
    return reduce(lambda x,y: x+y,
         map(lambda x: [x[1]] * x[0] if isinstance(x,list) and len(x)==2 
                    else [x],code) )
```

#### Haskell
as the 'modified' encoding is rather hard to handle in haskell (for me),
here we assume the encoded list is given as
```haskell
[ (N0,E0),(N1,E1),(N2,E2), .. (Nn,En) ]
```
, non-modified version.
AND all the Ei's are of the same type.
```haskell
decode [] = []
decode (x:xs) = smalldecode (snd x) (fst x) ++ decode xs
    where -- I think there must be a built-in for this.
        smalldecode x 0 = []
        smalldecode x n = x:smalldecode x (n-1) 
```

### 1.13 Run-length encoding of a list (direct solution).
-> see 1.10.

### 1.14 Duplicate the elements of a list. 

example:
```prolog
?- dupli([a,b,c,c,d],X).
X = [a,a,b,b,c,c,c,c,d,d]
```

#### Python

```python
def dupli(l):
    return reduce(lambda x,y: x+y, [ [element] * 2 for element in l ])

def dupli2(l):
    return reduce( lambda x,y : x+y, zip(l,l))

def dupli3(l):
    return [ element for element in l for n in (0,1) ]

def dupli4(l):
    duplicated = []
    for el in l:
        duplicated.extend([el]*2)
    return duplicated
```

#### Haskell

```haskell
dupli :: [a] -> [a]
dupli []     = []
dupli (x:xs) = x:x:dupli xs
```

### 1.15 Duplicate the elements of a list a given number of times.

#### Python
```python
def dupli(l, n):
    return [ element for element in l for i in range(n) ]

def dupli2(l, n):
    return reduce(lambda x,y: x+y, [ [element] * n for element in l ])

def dupli3(l, n):
    duplicated = []
    for el in l:
        duplicated.extend([el]*n)
    return duplicated
```

#### Haskell

```haskell
dupli :: (Integral b) => [a] -> b -> [a]
dupli [] n     = []
dupli (x:xs) n = (dup' x n ) ++ dupli xs n
    where
        dup' x 0 = []
        dup' x n = x: dup' x (n-1)
```

