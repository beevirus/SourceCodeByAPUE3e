#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passswd* mygetpwnam(const char* name)
{
    struct passwd* ptr;

    setpwent();
    while ((ptr = getpwent()) != NULL)
        if (strcmp(name, ptr->pw_name) == 0)
            break; /* found a match */
    endpwent();
    return (ptr); /* ptr is NULL if no match found */
}
