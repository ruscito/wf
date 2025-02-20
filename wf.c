/* wf.c*/ 
#include "wf.h"

#define MAX_CMD         100
#define MAX_ARGUMENTS   10

static char input[MAX_CMD];
static int running = 1;

int print_command_help()
{
    printf("Available commands:\n");
    printf("  help                          - Show this message\n");
    printf("  exit                          - Exit program\n");
    printf("  add-task <description> [exp]  - Add task with optional expiration date (YYY-MM-DD)\n");
    printf("                                   or omit for no exparation\n");
    printf("  remove-task <task id>         - Remove a task\n");
    printf("  list-task                     - Show list of active tasks\n");
    return 1;
}

int print_error()
{ 
    printf("Command unknown ...\n");
    return 1;
}

int process_task(int varg, char** argc)
{
    // Usage message
    char* help = "Usage: task <add/remove/list> [task id]\n";
    
    // check if arguments have been provided
    if (varg < 2) {
        printf("%s",help);
        return 1;
    }
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

int process_command(int argc, char** argv)  
{
    // isolate the command
    const char* cmd = argv[0];

    if (strcmp(cmd, "exit") == 0 || strcmp(cmd, "quit") == 0) return 0;

    if (strcmp(cmd, "help") == 0) return print_command_help();
    
    if (strcmp(cmd, "task") == 0) return process_task(argc, argv);
    return print_error();
}

int parse_arguments(char* input, char** args)
{
    int argc = 0;

    char* token = strtok(input, " ");

    while (token != NULL && argc < MAX_ARGUMENTS) {
        args[argc] = token;
        token = strtok(NULL, " ");
        argc ++;
    }

    return argc;
}


int main(int varg, char **argc)
{
    if (varg > 1) {
        return process_prompt(varg, argc);
    }
    
    // Run iteractive mode
    char* args[MAX_ARGUMENTS];
    int arg_count = 0;

    printf("Type 'help' for commands, 'exit' to quit\n");
    while (running) {
        printf("> ");
        fgets(input, MAX_CMD, stdin);
        
        // remove new line
        input[strcspn(input, "\n")] = '\0';
    
        // parse the arguments
        arg_count = parse_arguments(input, args);

        // process command and any arguments
        running = process_command(arg_count, args);
    }

    return 0;
}
