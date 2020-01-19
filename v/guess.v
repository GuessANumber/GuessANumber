/*
 * Guess A Number - Example in v (0.1)
 * 
 * Compile and run: v run guess.v
 * 
 */

import rand
import time
import math

fn main() {
    rand.seed(time.now().unix) // the rng is flawed, the results are predictable and only change once very second

    min := 1
    max := 100
    random_number := rand.next(max - min) + min // rand.next is zero inclusive, so we have to adjust
    mut current_guess := max / 2
    mut last_min := 0
    mut last_max := max
    mut number_of_guesses := 0

    for { // there are no while-loop in v
        number_of_guesses++
        if random_number > current_guess {
            last_min = current_guess
	    println('The number to guess is greater than $current_guess')
	    current_guess = current_guess + (int(math.abs(last_max - current_guess)) / 2)  // math.abs() returns f64, so we need to cast
        } else if random_number < current_guess {
	    last_max = current_guess
	    println('The number to guess is less than $current_guess')
	    current_guess = current_guess - (int(math.abs(last_min - current_guess)) / 2)
	} else {
	    println('The number to guess was $random_number')
	    println('You won!')
	    break // the exit of the for-loop
	}
    }
    
    println('That was a fun game! It needed $number_of_guesses guesses')
}
