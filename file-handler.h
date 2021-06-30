#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class File {
    
 	private:
     fstream file;
     char* filename;

    public:
        File() {}

        File(char* name) {
            filename = name;
            open(filename);
        }

        ~File() {
            file.close();
        }


        void open(char* name, int METHOD=1) {
            (METHOD == 1)  ?
             file.open(name, ios::out)
            : file.open(name, ios::in);
        }

        void close() {
            file.close();
        }

        void write(string data) {
            cout << filename << endl;
             ifstream fin;
  

            fin.open("sample.txt");

            // file.open(filename, 1);

            file << data << "/n";

            
            close();
        }

        void read() {
            ifstream filer;

            filer.open(filename);

                    string line;
                    while (getline(filer, line)) {
                        // using printf() in all tests for consistency
                        cout << "jksdf";
                        cout << line.c_str();
                    }
                    filer.close();
        
        }



        char* getFileName() { return filename; }
        void setFileName(char* name) { filename = name; };

    
};
