# the program

We've talked to several *very* expensive consultants, and now we're convinced that the future isn't building solvers for wordle anymore. The world has moved on, and the shareholders are demanding that we move into the next big thing, which is of course e-commerce businesses that sell both snacks and shoes, using hash tables.

This program will allow us to see a represenation of a simple database of our customers and the information we know about them. This database also has an interface that gives us the ability to read a database file from the disk, add customers, delete customers, and save the database back to the file.

**supported commands:**

  `add`: prompt the user for an email address, a display name, a shoe size, and a favorite food. If that email address is already present, then it will replace the data that was already in the hash table with the new entry.

  `lookup`: prompt the user for an email address, then display all the information we have about that user if the specified customer is found.

  `delete`: prompt the user for an email address, then delete all information we have about that user if the specified customer is found.

  `list`: display every user in the database.

  `save`: write the current state of the database back to customers.tsv.

  `quit`: exit the program.

# how to run it

In order to compile this program we will need the Makefile, c source files, and header files.

To build all the programs, run:

`$ make all`

To run the program:

`$ ./businessdb`

To remove binary files, run:

`$ make clean`
