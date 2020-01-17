<?php
/**
 * Guess a Number - Example in PHP(7.4)
 *
 * Start via cli: php guess-74.php
 */

$min = 1;
$max = 100;
$randomNumber = \random_int($min, $max);
$currentGuess = (int)($max / 2);
$lastMin = 0;
$lastMax = $max;
$solved = false;
$numberOfGuesses = 0;
while (!$solved) {
    $numberOfGuesses++;
    if ($randomNumber > $currentGuess) {
        $lastMin = $currentGuess;
        echo sprintf('The number to guess is greater than %s%s', $currentGuess, PHP_EOL);
        $currentGuess = $currentGuess + (int)ceil(abs($lastMax - $currentGuess) / 2);
    } elseif ($randomNumber < $currentGuess) {
        $lastMax = $currentGuess;
        echo sprintf('The number to guess is less than %s%s', $currentGuess, PHP_EOL);
        $currentGuess = $currentGuess - (int)ceil(abs($lastMin - $currentGuess) / 2);
    } else {
        echo sprintf('The number to guess was %s%s', $randomNumber, PHP_EOL);
        echo sprintf('You won!%s', PHP_EOL);
        $solved = true;
    }
    $lastGuess = $currentGuess;
    if ($numberOfGuesses >= 10) {
        $solved = true;
    }
}
echo sprintf('That was a fun game! It needed %s guesses%s', $numberOfGuesses, PHP_EOL);
