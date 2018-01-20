#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    string file;
    string dup=".dup";
    bool h=0;
    int i=0;
    int mini=1;
    int reset;
    char w;

    if(argc==2){
        ifstream from;
        ofstream to;
        from.open(argv[1]);
        to.open((argv[1]+dup).c_str());
        getline(from,file);
        string filer="{<C:";
        filer=filer+file[4]+">}";
        if(file==filer){
            reset=file[4]-48;
        }
        while(!from.eof()){
            getline(from,file);
            i=0;
            while(i<file.size()){
                if(file.compare(i, 3,"<E>")==0){
                    to<<endl;
                    i+=2;
                }else{
                    if(h==0){
                        w=file[i]-mini;
                    }else{
                        w=file[i]+mini;
                        mini++;
                    }
                    to<<w;
                    h=!h;
                    if(mini>reset/2)
                        mini=1;
                }
                i++;
            }
        }
        to.close();
    }else{
        cout<<"No file"<<endl;
    }
    return 0;
}
