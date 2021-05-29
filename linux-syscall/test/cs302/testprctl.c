#include <sys/prctl.h>
#include <stdio.h>
#include <syscall.h>
#include <assert.h>

int main(){
    char name[32];
    char *name_new = "new_name";
    syscall(SYS_prctl, PR_GET_NAME, (unsigned long)name);
    printf("old name: %s\n", name);

    assert(0 != strcmp(name,name_new));

    syscall(SYS_prctl, PR_SET_NAME, (unsigned long)name_new);
    syscall(SYS_prctl, PR_GET_NAME, (unsigned long)name);
    printf("new name: %s\n", name);

    assert(0 == strcmp(name,name_new));

    return 0;
}