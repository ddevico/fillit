# fillit
42 School PROJECT

Fillit is a project which allows to discover and/or familiarize yourself with a recurring
problematic in programming : searching for the optimal solution among a huge set of possibilities.
In this particular project, it has been charged to create an algorithm which
fits some Tetriminos together into the smallest possible square.

The purpose of this project is to make the smallest possible "square" (which can contain holes) with a 
given list of tetriminos read from a file. A valid figure contains only '.' and '#', 4 characters in a line, 
four lines per figure; all fiures separated by one newline. The disposition within the smallest square must be 
as such that it returns the first possible solution when placing them recursively from the top left.

The program uses an array of strings to contain all the set of Tetriminos and does not use recursion to solve the map.
