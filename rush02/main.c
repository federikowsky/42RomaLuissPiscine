#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "utils.h"

int check_input(int argc, char **argv) {
    int i;

    i = -1;
    if (argc == 2) 
    {
        while(argv[1][++i])
            if (argv[1][i] < '0' || argv[1][i] > '9' )
                return 0;
    }
    if (argc == 3)
    {
        while(argv[2][++i])
            if (argv[2][i] < '0' || argv[2][i] > '9' )
                return 0;
    }
    return 1;
}



int main(int argc, char **argv) {
    char temp[10000];
    int fd; 
    PointSCL scl;
    int val;
    
    scl = NULL;
    fd = open("numbers.dict", O_RDONLY);
    if (argc > 1) {
        val = ft_atoi(argv[1]);
        while (read(fd, temp, 1) > 0);
        control_dict(temp);
        fill_SCL(scl, temp);
        print_nb(val, take_val(scl, nbr_len(val)), scl);
    }
    close(fd);
    return 0;
}