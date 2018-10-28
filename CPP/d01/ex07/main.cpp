#include <iostream>
#include <fstream>

std::string	read_file ( std::string filename ) {

	std::ifstream	ifs(filename);
	std::string		line;
	std::string		file = "";

	if (!ifs.is_open())
		throw std::ios_base::failure("Error when opening intput.");

	while (getline(ifs, line))
	{
		file += line;
		if (!ifs.eof())
			file.push_back('\n');
 	}
 	ifs.close();
 	return (file);
}

void		replace_all ( std::string & content, std::string s1, std::string s2 ) {
	size_t start_pos = 0;
	while((start_pos = content.find(s1, start_pos)) != std::string::npos) {
		content.replace(start_pos, s1.length(), s2);
		start_pos += s2.length();
	}
	return ;
}

int			write_in_file( std::string output_file, std::string content ) {

	std::ofstream ofs(output_file);

	if (!ofs.is_open())
		throw std::ios_base::failure("Error when opening output.");

	ofs << content;
	ofs.close();
	return 0 ;
}

int			main ( int argc, char ** argv ) {

	if ( argc != 4 )
	{
		std::cerr << "usage: ./replace file s1 s2" << std::endl;	
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (!s1.length() || !s1.length())
	{
		std::cerr << "Error: s2 and s2 must not be empty." << std::endl;	
		return 1;
	}

	std::string	input_file  = argv[1];
	std::string	output_file = input_file + ".replace";

	try
	{
		std::string content = read_file(input_file);
		replace_all(content, s1, s2);
		write_in_file(output_file, content);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}