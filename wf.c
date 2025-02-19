/* wf.c*/ 
#include "wf.h"

#define MAX_CMD 100

static char input[MAX_CMD];
static int running = 1;

int print_command_help()
{
    printf("Available commands:\n");
    printf("  help  - Show this message\n");
    printf("  exit  - Exit program\n");
    return 1;
}

int process_prompt(int varg, char **argc)
{
    printf("varg %d\n", varg);
    for (int i = 0; i < varg; i++) {
        printf("arcg[%d]: %s\n", i, argc[i]);
    }

    return 0;
}

int process_command(char cmd[MAX_CMD]) 
{
    if (strcmp(cmd, "exit") == 0 || strcmp(cmd, "quit") == 0) return 0;

    return print_command_help();
}


int main(int varg, char **argc)
{
    if (varg > 1) {
        return process_prompt(varg, argc);
    }
    
    while (running) {
        printf("> ");
        fgets(input, MAX_CMD, stdin);
        
        // remove new line
        input[strcspn(input, "\n")] = '\0';

        running = process_command(input);
    }

    return 0;
}
