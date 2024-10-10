# Part D

## Simple text-based game

The file `game/data.txt` contains data for a simple game. 

<pre>
XXXXZXXXXX
X        X
X XX XXX X
X XX     X
X XX XXXXX
X    XXXXX
XXXX XXXXX
XXXX XXXXX
XXXXAXXXXX
XXXXXXXXXX
</pre>
 
* Each `X` represents a wall. 
* `A` represents the player's location
* `Z` represents the exit
* Each space character represents a corridor where the player can walk


### What you should do

* Think about how to represent this data, and create a class for doing so
* Write a main program in `hw.c++` that 
    * reads this data from a file
    * stores it in an instance of your class
    * prints the data

Your code should include `operator<<` and `operator>>` functions to read and write your class using instances of `std::ostream` and `std::istream`


### What the results should look like

Your code should successfully compile, link, and run with no errors and no warnings .
<pre>$ ./hw game/data.txt
Read data from game/data.txt into variable
Writing data to standard output stream
XXXXZXXXXX
X        X
X XX XXX X
X XX     X
X XX XXXXX
X    XXXXX
XXXX XXXXX
XXXX XXXXX
XXXXAXXXXX
XXXXXXXXXX
</pre>

