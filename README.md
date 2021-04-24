# k-and-r-solutions

This repository features solutions to the exercises of the book [The C Programming Language](https://www.goodreads.com/book/show/515601.The_C_Programming_Language), by Brian W. Kernighan and Dennis M. Ritchie (**K & R**).

## Running the exercises

```bash
# All exercises
./run.sh

# Exercises in a specific chapter
./run.sh 1

# Specific exercise, eg 1-5
./run.sh 1 5
```

Each exercise features a docblock at its top, featuring:

- The `@description` of the exercise
- For some exercises: an `@interactive` annotation

Interactive exercises will be skipped when multiple exercises are run at once (eg when running all exercises in a chapter). Non-interactive exercises usually feature automated tests that check their correctness, for example:

- Single exercise results<br/>
  ![Single exercise results](./img/single_exercise_results.JPG)

- Multiple exercises result summary<br/>
  ![Multiple exercises result summary](./img/multiple_exercises_result_summary.JPG)
