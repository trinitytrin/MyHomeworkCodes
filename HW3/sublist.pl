
sublist([], _,0).
sublist([H|T], [H|TT], I):- sublist(T, TT,I).
sublist([H|T], [_|TT], I1):- sublist([H|T],TT,I),I1 is I+1.

