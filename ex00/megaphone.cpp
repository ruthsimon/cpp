#include <iostream>

int main (int argc, char **argv)
{
    int i =1;
    int j =0;
    if (argc == 1)
    {
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std :: endl;
        return (0);
    }
    while (argv[i]!=NULL)
    {
        j=0;
        while(argv[i][j])
        {
            if (argv[i][j]>='a' && argv[i][j] <='z')
                argv[i][j] = argv[i][j] - 32;
            std :: cout << argv[i][j];
            j++;
        }
        std :: cout << " ";
        i++;
    }
    std :: cout << std :: endl;
}