#include <queue>
#include <fstream>
#include <string>
#include <iostream>


/*
** For an application of a queue, consider the following poem written by Lewis Carroll:
** 	Round the wondrous globe I wander wild,
** 	Up and down-hell--age succeeds to youth--
** 	Toiling all in vain to find a child
** 	Half so loving, half so dear as Ruth
** The poem is dedicated to RUTH Dymes, which is indicated not only by the last word of the poem
** but also by reading in sequence the first litters of each line, which also spell Ruth.
** This type of poem is called an acrostic. To see wether a poem is a acristic,
** we devise a simple algorithm that reads a poem, echoprints it, retieves and stores
** the first letters from each line on a queue, and after the poem is processed, all the stored first letters are printed in order.
*/


void acrosticIndecator(std::ifstream & file) {

	std::queue<char> que;
	std::string Line;
	if (file.is_open()) {
		while (std::getline(file, Line)) {
			if (!Line.empty()) {
				que.push(Line[0]);
				std::cout << Line << '\n';
			}
		}
		while (!que.empty()) {
			std::cout << que.front() << ' ';
			que.pop();
		}
		std::cout << '\n';
	}
}


int main(int argc, char **argv) {

	if (argc != 2)
		return 1;
	std::ifstream file;
	file.open(argv[1]);
	acrosticIndecator(file);
	return 0;
}
