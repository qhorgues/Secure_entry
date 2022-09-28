#include <iostream>
#include <Secure_entry.hpp>

int main(void)
{
    int a;
    std::cout << "Entrez un nombre entre 1 et 20 : ";
    do
    {
        try
        {
            secure_entry(a, [](int const value) -> bool
            {
                return value > 0 && value <= 20;
            });
            break;
        }
        catch(std::invalid_argument const &)
        {
            std::cout << "Entree invalide recommence : ";
        }
        catch(std::exception const &)
        {
            std::cerr << "Une erreur fatal est survenu !" << std::endl;
            std::exit(-1);
        }
    } while (true);
    
    std::cout << "L'entier entree est " << a << std::endl;
}