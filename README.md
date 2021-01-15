# MonkeyTyper

This program is designed to simulate the [Infinite monkey theorem
](https://en.wikipedia.org/wiki/Infinite_monkey_theorem) by generating sentences comprised of words created through random combination of letters. Once sentences have been generated, the program finds the simulated monkey's English word generation success rate, calculated by:

```c++
(successfulWords / ((double)failedWords + successfulWords)) * 100 
```

For a large number of word attempts, the rate of successful English word generations for a monkey is ~1%.

## Sentence Construction

Letters are randomly assembled into words of varying length.
Verified words are then conjoined into sentences of varying length.
The program's user inputs the desired number of sentences to be generated.


## Word Verification

Possible words are compared to a modified dictionary from the [JUST WORDS! website](http://www.gwicks.net/dictionaries.htm) for verification. 
The dictionary was modified to remove several acronyms for better sentence construction.
