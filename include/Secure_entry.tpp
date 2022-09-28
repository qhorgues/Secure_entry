#include <iostream>
#include <stdexcept>
#include <limits>
#include <concepts>

template <typename T>
concept ReadObject = requires(T & obj)
{
    std::cin >> obj;
};

template<ReadObject T>
void secure_entry(T& var)
{
	if (!(std::cin >> var))
	{
		if (std::cin.eof())
		{
			throw std::runtime_error("The stream has been closed");
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			throw std::invalid_argument("Invalid entry");
		}
		else
		{
			throw std::invalid_argument("The predicate is not respected");
		}
	}
}

template <ReadObject T, typename Predicat> requires std::predicate<Predicat, T>
void secure_entry(T & var, Predicat predicat)
{
    while (!(std::cin >> var) || !predicat(var))
    {
        if (std::cin.eof())
        {
            throw std::runtime_error("The stream has been closed");
        }
        else if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Invalid entry");
        }
        else
        {
            throw std::invalid_argument("The predicate is not respected");
        }
    }
}