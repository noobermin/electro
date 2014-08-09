#include "docopt.cpp"
#include <string>
#include <stdexcept>
#include <iostream>
double
convert_arg(const char* in,std::string name, double def)
{
  if (in)
    {
      try
	{
	  return std::stod(in);
	}
      catch (std::invalid_argument &e)
	{
	  std::cout << "argument to --" << name << "\""
		    << in
		    << "\" is not a number." << std::endl;
	  exit(EXIT_FAILURE);
	}
    }
  return def;
}

int
convert_arg(const char* in,std::string name, int def)
{
  if (in)
    {
      try
	{
	  return std::stoi(in);
	}
      catch (std::invalid_argument &e)
	{
	  std::cout << "argument to --" << name << "\""
		    << in
		    << "\" is not a number." << std::endl;
	  exit(EXIT_FAILURE);
	}
    }
  return def;
}
