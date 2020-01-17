# Contributing

* [Description of the program](#Description)
* [Adding new languages](#AddingNewLanguages)
* [Adding examples to existing languages](#AddingExamples)
* [Changing existing examples](#ChangingExamples)

### <a name="Description"></a>Description of the program
Your program should define a random integer number between (inclusive) 1 and 100. Then it 
should start to find that number by doing some kind of binary-like search. This is, start
with 50, if the random number is greater than 50, continue with 75, otherwise with 25. 
Continue that way until the random number has been found. Count the number of steps your
program needs. Print some output so that all the steps can be reconstructed. Here is an
example output how it could/should look like with the random number of 63:

```
The number to guess is greater than 50
The number to guess is less than 75
The number to guess is greater than 62
The number to guess is less than 69
The number to guess is less than 65
The number to guess was 63
You won!
That was a fun game! It needed 6 guesses
```

Please add a comment block at the beginning of your file explaining at least
* how to compile / run the example
* version requirements
* any other things noteworthy

You are encouraged to add extensive inline comments to explain the code!

If for some reason the language does not allow comments in the code, please add
a text file instead. Please note the subdirectory requirement in the next
section if you need more than one file for your code example. 

### <a name="AddingNewLanguages"></a>Adding new languages
This is quite simple. Add a directory with the name of the language you are using.
Add the source file using `guess` as file name, followed by the version of the language
and the file ending (if needed). Example for a source file written in php 7.4: `php\guess-74.php`

If you need more than one source file, please add another subdirectory like `php\complexexample-74\index.php` 

### <a name="AddingExamples"></a>Adding examples to existing languages
This is also quite simple. Basically, follow the naming rules mentioned above. If you
want to add an example for the same version, use a suffix like `php\guess-74_example2.php`

### <a name="ChangingExamples"></a>Changing existing examples
Changes to existing examples should only be commited if the code is buggy with the 
compiler/language version noted in the example, or if there are typos or other minor
issues like that. Please do not change the example just because you disapprove with
the way the code has been written. In general, there are many ways leading to the 
desired result. If you are unhappy with the code, please consider [adding an example](#AddingExamples) 
instead of rewriting an existing one.
