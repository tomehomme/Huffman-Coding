//used https://kamilmysliwiec.com/implementation-of-huffman-coding-algorithm-with-binary-trees/
//used https://www.techiedelight.com/huffman-coding/
#include <iostream>
#include <exception>
#include <string>
#include <bits/stdc++.h> 
#include <sstream>
#include <queue>
#include <fstream>
#include <unordered_map>
using namespace std;

int totalchar = 0;
// A Tree node
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

// Comparison object to be used to order the heap
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

// traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, string str, ofstream& outFile)
{
	
	if (root == nullptr) {
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		outFile << root->ch;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str, outFile);
	else
		decode(root->right, index, str, outFile);
}

// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string inputFile, const string& fileName)
{
	 ifstream iFile(inputFile);
   	 while (!iFile.is_open()){
        cout << "Unable to open file" << endl;
        cout << "Re-enter input file name.." << endl;
        cin >> inputFile;
	}
	

	// count frequency of appearance of each character
	// and store it in a map
	unordered_map<char, int> freq;
	char ch;
	while (iFile.get(ch)) {
		totalchar++;
		freq[ch]++;
	}
		iFile.close();
	// Create a priority queue to store live nodes of
	// Huffman tree;
	priority_queue<Node*, vector<Node*>, comp> pq;

	// Create a leaf node for each character and add it
	// to the priority queue.
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// root stores pointer to root of Huffman Tree
	Node* root = pq.top();

	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Huffman Codes are :\n" << '\n';
	for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}

	// encoded stream to a file
	ofstream oFile(fileName);
	iFile.open(inputFile);
	while (iFile.get(ch)) {
		oFile << huffmanCode[ch];
	}
	iFile.close();
		
	// traverse the Huffman Tree again and this time
	// decode the encoded string
	// int index = -1;

	// string fileName2;
	// cout << "FOR TESTING PURPOSEES: What would you like the decoded file to be named?: " << endl;
	// ifstream encodedFile(fileName);
	// string str;
	// encodedFile >> str;
	// encodedFile.close();
	// cin >> fileName2;
	// ofstream decodeFile(fileName2);
	// while (index < (int)str.size() - 2) {
	// 	decode(root, index, str, decodeFile);
	// }
	// decodeFile.close();
	cout << "finished." << endl;
}

void binaryFile (const string& inputfile, const string& outfile){
	ifstream inputs(inputfile);
	string str;
	ofstream outputs(outfile);
	while (inputs>>str){
		for (size_t i = 0; i < str.size(); ++i){
			outputs << bitset<8>(str.c_str()[i]) << endl;
		}
	}
	inputs.close();
}


streamsize get_file_size(const string& filename){
    ifstream file(filename, ios::binary | ios::ate); //ios::ate initial position is at end of file
    return file.tellg(); //returns position of current character in input stream
}

// Huffman coding algorithm
int main()
{
	cout << "Huffman coding is a data compression algorithm." << endl;
	//change to the filepath you want to compress..
	string input = "C:\\Users\\hommp\\OneDrive\\Desktop\\CS14\\challenges\\c4a\\moby_dick.txt";

	cout << "Compressing the following file: " << input<<endl;
    string output = "moby_dick_compressed.bin";
	cout << "The compressed file is named: " << output << endl;

   
	buildHuffmanTree(input, output);
	ifstream file(input);
		stringstream stream;
		stream << file.rdbuf();
		file.close();
		string binaryfile = "binaryTxt.bin";
		binaryFile (input, binaryfile);
		const auto file_content = stream.str();
		const auto file_size = get_file_size(binaryfile);
		const auto after_file_size = get_file_size(output);
		cout << "Before compression: " << file_size << " bytes" << endl;
	//need to calculate the bits ratio
	// cout << "Before compression: " << totalchar*8 << endl;// get_file_size(input) << endl;
	cout << "After compression: " << after_file_size << " bytes" << endl;
	cout << "Change of size: " << after_file_size - file_size << " bytes" << endl;
	cout << "Ratio of compression (Before:After): " << static_cast<double>(file_size)/after_file_size*100 << "% compression" << endl;
	

	return 0;
}
