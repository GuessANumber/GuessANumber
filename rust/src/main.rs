use rand::Rng;
use std::cmp::Ordering;

const MIN: u32 = 0;
const MAX: u32 = 100;

fn main() {
    let random_number = rand::thread_rng().gen_range(MIN, MAX);

    guess(random_number, MIN, MAX, 1);
}

fn guess(
    random_number: u32,
    current_min_guess: u32,
    current_max_guess: u32,
    number_of_guesses: u32,
) {
    let current_guess = (current_max_guess + current_min_guess) / 2;

    match current_guess.cmp(&random_number) {
        Ordering::Less => {
            println!("The number to guess is greater than {}", current_guess);
            guess(
                random_number,
                current_guess,
                current_max_guess,
                number_of_guesses + 1,
            );
        }
        Ordering::Greater => {
            println!("The number to guess is less than {}", current_guess);
            guess(
                random_number,
                current_min_guess,
                current_guess,
                number_of_guesses + 1,
            );
        }
        Ordering::Equal => {
            println!("The number to guess was {}", random_number);
            println!("You won!");
            println!(
                "That was a fun game! It needed {} guesses",
                number_of_guesses
            )
        }
    }
}
