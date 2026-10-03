#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define RESET       "\033[0m"
#define TITLE       "\033[1;97;44m"
#define PROMPT      "\033[1;30;103m"
#define HINT        "\033[1;97;45m"
#define SUCCESS     "\033[1;30;102m"
#define RESULT      "\033[1;97;46m"

static void enable_ansi_colors(void) {
#ifdef _WIN32
    HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD console_mode;

    if (output_handle != INVALID_HANDLE_VALUE &&
        GetConsoleMode(output_handle, &console_mode)) {
        SetConsoleMode(output_handle,
                       console_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }
#endif
}

int main() {
    int Randnum;
    int guess;
    int no_of_guess=0;

    enable_ansi_colors();
    srand(time(0));  // Seed the random number generator

    Randnum = (rand() % 100) + 1;

    printf(TITLE "\n  NUMBER GUESSING GAME  " RESET "\n");
    printf("Guess a number between 1 and 100.\n");

    do {
        printf("\n" PROMPT " Guess the no.: " RESET);
        scanf("%d", &guess);
        no_of_guess++;
        if (guess == 11) {
            Randnum = 5;
            printf("cheat activated\n");
            no_of_guess -= 1;
        }
        if (guess < Randnum) {
            printf(HINT " Greater number, please. " RESET "\n");
        } else if (guess > Randnum) {
            printf(HINT " Lower number, please. " RESET "\n");
        } else {
            printf(SUCCESS "\n Congratulations! You guessed the number. " RESET "\n");
        }
    } while (guess != Randnum);

    printf(RESULT "\n The number was %d. " RESET, Randnum);
    printf(RESULT " You guessed it in %d attempt%s. " RESET "\n",
           no_of_guess, no_of_guess == 1 ? "" : "s");
    return 0;
}