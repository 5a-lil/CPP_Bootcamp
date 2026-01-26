#include "Graph.hpp"
#define EXISTS true
#define NOT_EXISTS false

const char* Graph::NegativeOrZeroConstructorError::what() const throw () { return "Constructor parameters are negative or equal to 0"; }
const char* Graph::TooLargeConstructorError::what() const throw () { return "Constructor parameters are too large must be <=10"; }
const char* Graph::OutOfBoundsPoint::what() const throw () { return "Point trying to be added to graph is out of bounds of graph size"; }
const char* Graph::FailOpeningInputFile::what() const throw () { return "Failed to open given input file"; }
const char* Graph::InputFileSyntaxNotCorrect::what() const throw () { return "Given input file syntax error"; }

Graph::Graph(Vector2 size) : _size(size) { if (size.getX() <= 0 || size.getY() <= 0) throw NegativeOrZeroConstructorError(); 
                                           if (size.getX() > 10 || size.getY() > 10) throw TooLargeConstructorError();}

Graph::~Graph() {}

// void Graph::setSize(Vector2 size) { this->_size = size; }

// void Graph::setPoints(std::map<Vector2, bool> points) { this->_points = points; }

const Vector2& Graph::getSize() { return this->_size; }

const std::map<Vector2, bool>& Graph::getPoints() { return this->_points; }

void Graph::addPoints(Vector2 point) 
{ 
    if (point.getX() >= this->_size.getX() || // error checks if coor is outside of graph size
        point.getY() >= this->_size.getY() ||
        point.getX() < 0 ||
        point.getY() < 0) throw OutOfBoundsPoint();
    this->_points[Vector2((int)point.getX(), (int)point.getY())] = true; // adding the point to the _points map attribute
}

void Graph::addPoints(std::string input_file_name)
{
    std::ifstream input_file_stream(input_file_name); // input-file-stream-from-file-passed-as-arg
    if (!input_file_stream) 
        throw FailOpeningInputFile();

    std::string parse_line_buffer; // string-used-to-store-getline()-line-to-then-parse-it

    // Defines-used-in-parsing
    #define INDEX_TO_SKIP_FIRST_PAR 1
    #define INDEX_TO_SKIP_LAST_PAR 2
    #define CORRECT_FORMAT (parse_line_buffer.front() == '(' /*check-if-first-char-is-parentheses*/ \
                           && count_occurences(parse_line_buffer, '|') == 1 /*check if there is only one pipe*/ \
                           && parse_line_buffer.back() == ')' /*check if last char is parentheses*/ \
                           && *(parse_line_buffer.end() - INDEX_TO_SKIP_LAST_PAR) != '|' /*check if pipe is aside the last parentheses*/ \
                           && *(parse_line_buffer.begin() + INDEX_TO_SKIP_FIRST_PAR) != '|') /*check if pipe is aside the front parentheses*/

    // Parse-line-by-line
    while (std::getline(input_file_stream, parse_line_buffer))
    {
        std::cout << "Input file line: \"" << parse_line_buffer << '\"' << std::endl; // logging
        if (!CORRECT_FORMAT)
            throw InputFileSyntaxNotCorrect();

        // istringstream taking the line without parentheses
        std::istringstream parse_line_iss(parse_line_buffer.substr(INDEX_TO_SKIP_FIRST_PAR, parse_line_buffer.length() - INDEX_TO_SKIP_LAST_PAR));
        std::string iss_word; // string to store below getline()
        double x_coor(0), y_coor(0); // coor variables for new point

        std::getline(parse_line_iss, iss_word, '|'); // parsing left side
        if (!(std::istringstream(iss_word) >> x_coor)) // check if number
            throw InputFileSyntaxNotCorrect();
        std::getline(parse_line_iss, iss_word); // parsing right side
        if (!(std::istringstream(iss_word) >> y_coor)) // check if number
            throw InputFileSyntaxNotCorrect();
        std::cout << "x:" << x_coor << " y:" << y_coor << std::endl; // logging

        this->addPoints(Vector2(x_coor, y_coor)); // adding the point to Graph _points attribute
    }
}

void Graph::displayGraph()
{
    int width = this->_size.getX();
    int height = this->_size.getY();

    for (int y = 0; y < height; y++)
    {
        std::cout << std::abs(height - y - 1) << " ";
        for (int x = 0; x < width; x++)
        {
            if (this->_points[Vector2(x, height - y - 1)])
            {
                std::cout << "X "; continue;
            }
            std::cout << ". ";
        }
        std::cout << std::endl;
    }

    std::cout << "  ";
    for (int i = 0; i < width; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}