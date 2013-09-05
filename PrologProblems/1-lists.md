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

#### Ruby
Direct translation from python:
```ruby
def compress(l)
  compressed = []
  while l != []
    begin 
      if l[0] == compressed.last then
        l.delete_at(0)
      else
        compressed.push(l.delete_at(0))
      end
    rescue
      compressed.push(l.delete_at(0))
    end
  end
  return compressed
end
```
This looks much more ruby-ish (and is one-liner!).
```ruby
def compress(l)
  return l.select.each_with_index {|x,i| i == 0 or l[i-1] != x}
end
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
and with Data.List
```haskell
import Data.List
compress xs = map (\x-> head x ) (group xs)
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
List comprehension or filter makes your life easier. (Inspired by ruby solution)
```python
def pack(l):
    packed = [l[0]]
    packed.extend( [ l[i] for i in range(1,len(l)) if l[i] != l[i-1]] )
    return packed
```

#### Ruby
```ruby
def pack(l)
  buff = Array.new
  packed = Array.new
  l.each_with_index do |x,i|
    if i == 0 or l[i-1] == x then
      buff << x
    else
      packed << buff
      buff = [x]
    end
  end
  return packed
end
```
Using ```drop_while``` seems better?
```ruby
def pack(l)
  buff = Array.new(l)
  packed = Array.new
  until buff.empty?
    packed << buff.first
    buff = buff.drop_while {|i| i == buff.first}
  end
  return packed
end
```

#### Haskell
using Data.List
```haskell
import Data.List
group a
```

### 1.10 Run-length encoding of a list.

Use the result of problem 1.09 to implement the so-called run-length encoding data comopression method. Consequtive duplicates of elements are encoded as terms [N, E] where N is the number of duplicates of the element E.

(Do we have to use the result of problem 1.09?)

#### Python
If we use the result of problem 1.09:
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

#### Ruby
With ```pack``` defined in problem 1.09 at hand:
```ruby
def encode(l)
  return pack(l).collect {|i| [i.length, i.first]}
end
```
Direct solution
```ruby
def encode(l)
  encoded = Array.new
  buff = Array.new(l)
  until buff.empty?
    encoded << [ buff.take_while { |i| i==buff.first}.length, buff.first]
    buff = buff.drop_while {|i| i == buff.first}
  end
  return encoded
end
```

#### Haskell
```haskell
encode [] = []
encode (x:xs) = [1 + length ( takeWhile (==x) xs ), x] 
                 : encode ( dropWhile (==x) xs )
```
again, Data.List works well.
```haskell
import Data.List
encode :: (Eq a) => [a] -> [ (Int, a) ]
encode xs = map  (\x -> (length x, head x))  (group xs)
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

#### Ruby
```ruby
def decode(code)
  decoded = Array.new
  decoded = code.inject(Array.new) do |d, x|
    if x.kind_of?(Array) and x.length == 2
      d + [x.last]*x.first
    else
      d << x
    end
  end
  return decoded
end
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

#### Ruby
```ruby
def dupli(l)
  return l.map {|i| [i]*2}.flatten
end
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

#### Ruby
```ruby
def dupli(l, n)
  return l.map {|i| [i]*n}.flatten
end
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
```concatMap``` works as well.
```haskell
dupli' :: Int -> [a] -> [a]
dupli' n xs = concatMap (dup'' n) xs
    where
        dup'' 0 x = []
        dup'' n x = x:dup'' (n-1) x
```

### 1.16 Drop every n'th element from a list.

Example:
```prolog
?- drop([a,b,c,d,e,f,g,h,i,k],3,X).
X = [a,b,d,e,g,h,k]
```
#### Python
```python
def drop(l,n):
    return [ x[i] for i in range(len(l)) if (i+1)%n != 0]
```

#### Ruby
```ruby
def drop(n,l)
  return l.select.each_with_index{ |x,i| ! ((i+1)%n).zero?}
end
```
In case you hate ```%``` ...
```ruby
def drop2(n,l)
  roller = 0
  dropped = Array.new
  l.each do |i|
    roller += 1
    if roller == n then roller = 0
    else dropped << i
    end
  end
  return dropped
end
```

#### Haskell

Prelude contains a function ```drop```: ```drop n xs``` returns the suffix of xs after the first n elements, or [] if n > length xs.  
```haskell
drop'  :: (Integral n) => [a] -> n -> n -> [a]
mydrop :: (Integral n) => [a] -> n -> [a]

drop' [] n m = [] 
drop' (x:xs) n m 
    | m `mod` n /= 0 = x : drop' xs n (m+1)
    | otherwise      = drop' xs n 1

mydrop l n = drop' l n 1 -- drop 2 [1,2,3,4,5,6] -> [2,3,4,5,6]
```

### 1.17 Split a list into two parts; the length of the first part is given.

#### Python
```python
def mysplit(l,n):
    return l[:n], l[n:]
```

#### Ruby
```ruby
def split_at(l,n)
  return l.take(n), l.drop(n)
end

def split_at2(l,n)
  return l[0..n-1], l[n..-1]
end
```

#### Haskell
there's a built-in function
```haskell
splitAt n xs
```
or 
```haskell
split :: Int -> [a] -> ([a], [a])
split n xs = (take n xs, drop n xs) 
```

### 1.18 Extract a slice from a list.
Given two indices, I and K, the slice is the list containing the elements between the I'th and K'th element of the original list (both limits included). Start counting the elements with 1.

Example:
```prolog
?- slice([a,b,c,d,e,f,g,h,i,k],3,7,L).
X = [c,d,e,f,g]
```

#### Python
```python
a[i-1:k]
```

#### Ruby
```ruby
def slice(l,i,k)
  return l[i-1..k-1]
end

def slice2(l,i,k)
  return l.drop(i-1).take(k-i+1)
end
```

#### Haskell
```haskell
slice :: Int -> Int -> [a] -> [a]
slice i k list = take (k-i+1) $ drop (i-1) list
```

### 1.19 Rotate a list N places to the left.

Examples:
```prolog
?- rotate([a,b,c,d,e,f,g,h],3,X).
X = [d,e,f,g,h,a,b,c]

?- rotate([a,b,c,d,e,f,g,h],-2,X).
X = [g,h,a,b,c,d,e,f]
```

#### Python
Naturally,
```python
def rotate(l,n):
    return l[n:] + l[:n]
```
or python has this for you
```python
import collections
def rotate(l,n):
    deq = collections.deque(l)
    deq.rotate(-n)
    return list(deq)
```

#### Ruby
Yay!
```ruby
a.rotate(n)
```

#### Haskell

```haskell
rotate' n xs = (drop n xs) ++ (take n xs) -- works only for 0 <= n <= length xs.
```
using cycle 
```haskell
rotate n xs = take (length xs) . drop n . cycle $ xs -- works only for n >= 0.
```
and this should work for all n.
```haskell
rotate'' n xs 
    | n < 0     = rotate (length xs + n) xs
    | otherwise = rotate n xs
```


### 1.20 Remove the K'th element from a list.
(Note: the example seems to return the removed element too.)

#### Python
```python
def remove_at(l,n):
    return l.pop(n-1),l # return l.pop(n-1) for X ( == b in the example).

def remove_at2(l,n):
    return l[n-1], l[:n-1] + l[n:]
```

#### Ruby
If you want to delete in place, 
```ruby
a.delete_at(n-1)
```
should do the job. Otherwise
```ruby
def remove_at(l,n)
  j=Array.new(l) # as delete_at method is destrctive
  return j, j.delete_at(n-1)
end
```
or
```ruby
def remove_at(l,n)
  return l.take(n-1) + l.drop(n)
end
```

#### Haskell
```haskell
removeAt :: Int -> [a] -> [a]
removeAt n xs = take (n-1) xs ++ drop n xs
```

### 1.21 Insert an element at a given position into a list.

#### Python
```python
def insert_at(a, li, loc):
    return li[:loc-1] + [a] + li[loc-1:]
```

#### Ruby
```ruby
a.insert(2,'a') # inserts in place
```
or
```ruby
def insert_at(a, li, loc)
  return li.take(loc-1) + [a] + li.drop(loc-1)
end
```
You can always use ```li[0..n]```, blah blah blah.

#### Haskell
```haskell
insertAt :: a -> [a] -> Int -> [a]
insertAt x xs n =  take (n-1) xs ++ [x] ++ drop (n-1) xs
```

### 1.22 Create a list containing all integers within a given range.

Example:
```prolog
?- range(4,9,L).
L = [4,5,6,7,8,9]
```

#### Python
```python
range(n, m+1)  # list (python 2.x), generator (python 3.x)
xrange(n, m+1) # generator (python 2.x)
```

#### Ruby
```ruby
(n..m).to_a    # to_a if you really need an array.

def range2(n,m)
  return Array.new(m+1-n){|i| i+n}
end
```

#### Haskell
```haskell
[n..m]
```

### 1.23 Extract a given number of randomly selected elements from a list.

#### Python
```python
import random

[random.choice(l) for i in range(n)] # if duplicates are allowed
random.sample(l, n)                  # if not
```

#### Ruby
```ruby
a.sample(n)
```

### 1.24 Lotto: Draw N different random numbers from the set 1..M.

#### Python
```python
import random
random.sample(range(1,m+1), N)
```

#### Ruby
```ruby
(1..m).to_a.sample(n)

Array.new(m){|i| i+1}.sample(n)
```

### 1.25 Generate a random permutation of the elements of a list.

Example:
```prolog
?- rnd_permu([a,b,c,d,e,f],L).
L = [b,a,d,c,e,f]
```

#### Python
```python
import random
def random_sample(l):
    return random.sample(l, len(l))

def random_permutation(l):
    shuffled = list(l)       # makes a shallow copy
    random.shuffle(shuffled) # shuffles in place
    return shuffled

def my_random_permutation(l):
    length = len(l)
    buff = list(l)
    return [ buff.pop(random.randint(0,len(buff)-1)) 
                    for i in range(length)]
```

#### Ruby
```ruby
a.sample(a.length)
```

### 1.26 Generate the combinations of K distinct objects chosen from the N elements of a list.

#### Python
itertools. again.
```python
import itertools
list(itertools.combinations(li, k))  # it.combinations returns a generator.
```

#### Haskell

```haskell
combination :: Int -> [a] -> [[a]]
combination n [] = [[]]
combination 0 xs = [[]]
combination n (x:xs)
    | length xs == (n-1) = [x:xs]
    | otherwise          = combination n xs ++ map (x:) (combination (n-1) xs) 
```
