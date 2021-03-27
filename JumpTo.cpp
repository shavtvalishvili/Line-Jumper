#include <ifstream>

// Given current line number as cursor, function jumps
// to the start of the dest-th line of the given file
void JumpTo(int dest, ifstream &my_file, int &cursor) {
    char c;
    int difference = dest - cursor;
    // If Jump to the Beginning
    if (dest - 1 == -1) my_file.seekg(0, my_file.beg);
    else {
        if (difference != 1) {
            if (difference <= 0) {
                // If END OF FILE
                if (my_file.tellg() == -1) {
                    my_file.clear();
                    my_file.seekg(0, my_file.end);
                    difference -= 1;
                } else difference -= 2;
            } else difference -= 1;
            int sign = difference / abs(difference);
            for (int i = 0; i < abs(difference);) {
                my_file.seekg(sign, my_file.cur);
                c = my_file.peek();
                if (c == '\n') i++;
                // cout << "[" << c << "] "; // DBG
            }
            my_file.seekg(1, my_file.cur);
        }
    }
}