

eats(tom,snake).
eats(sue,Y):- eats(tom,Y).
eats(john, X):- food(X).

food(apple).
food(oyster).
food(Z):- eats(_,Z),!.



