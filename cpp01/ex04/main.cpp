/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:19:16 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/28 14:23:16 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}

	std::cout << argv[1] << std::endl;
	std::string inputfile = argv[1];
	std::string outputfile = std::string(argv[1]) + ".replace";
	std::string str1 = argv[2];
	std::string str2 = argv[3];

	std::ifstream inputFile;
	std::ofstream outputFile;

	inputFile.open(inputfile.c_str());

	outputFile.open(outputfile.c_str());

	if (!inputFile) {
		std::cerr << "Error opening input file: " << inputfile << std::endl;
		return 1;
	}
	if (!outputFile) {
		std::cerr << "Error opening output file: " << outputfile << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		std::string modifiedline = stringReplace(line, str1, str2);
		outputFile << modifiedline << std::endl;
	}
	inputFile.close();
	outputFile.close();

	std::cout << "Done. Content written to " << outputfile << std::endl;
	return 0;
}