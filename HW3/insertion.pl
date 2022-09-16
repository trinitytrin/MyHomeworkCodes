
insert(X, [], [X]).
insert(X, [H|T], [X|L]):- X =< H, insert(H, T, L).
insert(X, [H|T], [H|L]):- X > H, insert(X, T, L).

insertionSort([], []).
insertionSort([H|T], R):- insertionSort(T, W), insert(H, W, R).
