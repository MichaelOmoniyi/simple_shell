#include "shell.h"

char *sh_getenv(const char *name)
{
extern char **environ;
char **env;
char *equals; 
if (name == NULL) {
return NULL;
}

for(env = environ; *env != NULL; env++) {
equals = _strchr(*env, '=');
if (equals == NULL) {
continue;
}

if (strncmp(*env, name, equals - *env) == 0) {
return equals + 1;
}
}

return NULL;
}
