between(L,H,L) :- L =< H.
between(L,H,V) :- L < H, L1 is L+1, between(L1,H,V).

next(_,Y) :- between(0,9,Y).

nth(1,[X|_],X).
nth(N,[_|T],X) :- N > 1, N1 is N-1, nth(N1,T,X).

no(X) :- X, !, fail.
no(_) :- true.

prime(1,2).
prime(2,3).
prime(3,5).
prime(4,7).
prime(5,11).
prime(6,13).
prime(7,17).



search(_) :- search(_,[]).

search(_,Path) :- length(Path,L), L == 10, write(Path), nl, !, fail.
search(Now,Path) :- length(Path,L), L =< 2, 
		    next(Now,Next), no( member(Next,Path) ),
		    append(Path,[Next],Path_Next), search(Next,Path_Next).
search(Now,Path) :- length(Path,L), L >= 3, L1 is L-1, L2 is L-2, 
		    next(Now,Next), no( member(Next,Path) ),
		    nth(L1,Path,S1), nth(L,Path,S2), Dig is 100*S1 + 10*S2 + Next, prime(L2,P),Dig_2 is Dig/P, integer(Dig_2), 
		    append(Path,[Next],Path_Next), search(Next,Path_Next).
